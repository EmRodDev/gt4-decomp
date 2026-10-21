#!/bin/bash
# Compile to assembly with GCC, then assemble with another toolchain's assembler.
# Usage (as a compile command): cc_as.sh AS "GCC [flags]" input -o out.o
# AS is a path (assembled with -EL -march=r5900 -mabi=eabi) or a command with its own flags
# ("PATH -G0 -O2 -mabi=eabi": the 2.96 ee-as, which knows no -march).
# Each call works in its own temporary directory: build.py compiles many sources in parallel.
set -eo pipefail
[ "$#" -ge 2 ] || { echo 'cc_as.sh: expected assembler and compiler command' >&2; exit 2; }
as=$1; gcc=$2
shift 2
args=()
out=
while [ "$#" -gt 0 ]; do
  case "$1" in
    -o)
      [ "$#" -ge 2 ] || { echo 'cc_as.sh: missing output path' >&2; exit 2; }
      out=$2; shift 2 ;;
    *) args+=("$1"); shift ;;
  esac
done
[ -n "$out" ] || { echo "cc_as.sh: missing output path" >&2; exit 2; }
rm -f -- "$out"
tmp="$(mktemp -d)"
trap 'rm -rf "$tmp"' EXIT
$gcc -S "${args[@]}" -o "$tmp/out.s"
if [[ "$as" == *" "* ]]; then $as "$tmp/out.s" -o "$tmp/out.o"
else "$as" -EL -march=r5900 -mabi=eabi "$tmp/out.s" -o "$tmp/out.o"; fi
mv -f "$tmp/out.o" "$out"
