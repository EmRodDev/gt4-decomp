#!/bin/bash
# Compile to assembly with GCC, then assemble with another toolchain's assembler.
# Usage (as a compile command): cc_as.sh AS "GCC [flags]" input -o out.o
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
$as -EL -march=r5900 -mabi=eabi "$tmp/out.s" -o "$tmp/out.o"
mv -f "$tmp/out.o" "$out"
