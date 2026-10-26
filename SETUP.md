# Setup walkthrough

A tested, step-by-step version of **Setup** in [README.md](README.md), with every place a first
build got stuck and what fixed it. The proof is the same as for any change: `python tools/build.py`
prints `.text OK` and `.data OK`.

| Path | Status |
|---|---|
| Ubuntu 24.04 in Distrobox on Arch Linux (Omarchy 4.0.6) | tested 2026-10-25 at `b1e5cc1f6efc`, full build OK |
| Windows + WSL (Ubuntu) | **not tested yet**, see [the end of this file](#windows--wsl-not-tested-yet) |

Measured times below are from that run (one machine, x86_64, `--jobs 2`); expect different numbers
on other hardware.

## 1. Ubuntu container (Arch-based hosts only)

`tools/setup_linux.sh` uses `apt` and `dpkg`, so on a distribution without them run the project
inside an Ubuntu container. Distrobox shares your home directory with the container, so the clone
and the disc image can stay where they are.

```sh
sudo pacman -S --needed distrobox podman
distrobox create -n gt4 -i docker.io/library/ubuntu:24.04
distrobox enter gt4
```

The first `distrobox enter` installs Ubuntu's base packages (77 s). It may print that it cannot
turn `/etc/resolv.conf` into a symlink (`Device or resource busy`): the container mounts that file
from the host, and the warning is harmless. Every following step runs inside the container.

On Ubuntu or Debian itself, skip this section.

## 2. Packages, clone and Python

```sh
sudo apt update && sudo apt install -y git curl xz-utils python3 python3-venv python3-pip
git clone https://github.com/gustavocanepa/gt4-decomp && cd gt4-decomp
python3 -m venv .venv && . .venv/bin/activate
pip install rabbitizer
pip install toml Levenshtein pynacl
```

Ubuntu 24.04 marks its system Python as externally managed, so the walkthrough uses a virtual
environment. Keep it active for every step below (`. .venv/bin/activate` in each new shell).

**Stuck point: permuter modules.** `tools/setup_linux.sh` installs the permuter's modules with
`apt` (`python3-toml`, `python3-levenshtein`), into the system Python, but then runs the permuter
with whatever `python3` is first on `PATH`, which is the venv's. Without the second `pip install`
above it prints `ModuleNotFoundError: No module named 'toml'`, yet the script still exits 0 and goes
on to splat. With the modules in the venv it prints `permuter ok`. `toml Levenshtein pynacl` is the
prerequisite list of the [decomp-permuter README](https://github.com/simonlindholm/decomp-permuter).

## 3. Disc image and executable

Place your own dump as described in [`orig/README.md`](orig/README.md); a symlink works and leaves
the image where it is:

```sh
mkdir -p orig/SCUS-97328
ln -s "/path/to/Gran Turismo 4 (USA).iso" "orig/SCUS-97328/Gran Turismo 4 (USA) (v1.01).iso"
python tools/iso_extract.py "orig/SCUS-97328/Gran Turismo 4 (USA) (v1.01).iso" CORE.GT4 SYSTEM.CNF SCUS_973.28 -o orig/SCUS-97328/files
python tools/core2elf.py orig/SCUS-97328/files/CORE.GT4 orig/SCUS-97328/CORE.GT4.elf
sha1sum orig/SCUS-97328/files/CORE.GT4 orig/SCUS-97328/files/SCUS_973.28 orig/SCUS-97328/CORE.GT4.elf
```

Compare the three hashes with the table in [`orig/README.md`](orig/README.md) (under a second).

## 4. Compilers, binutils, permuter and splat

```sh
bash tools/setup_linux.sh
```

This installs the MIPS binutils, the 32-bit libc, ee-gcc 2.96 under `~/.local/share/gt4/ee-gcc2.96`,
decomp-permuter and splat (23 s). Check that its output has both `permuter ok` and `splat 0.50.1`
(or later).

**Stuck point: the other compilers.** `setup_linux.sh` installs only ee-gcc 2.96. Sources whose
first line is `/* compiler: NAME */` use the profile `NAME` of `project.toml` (20 profiles at
`b1e5cc1f6efc`), and several of them live in their own directory under
`~/.local/share/gt4/compilers/` (ee-gcc 2.9, unpacked copies of ee-gcc 2.96) or need the ee-gcc 3.2
assembler; those sources cannot be compiled without them. This installs every
directory the current sources need, from the `dir`, `archive` and `needs` entries of
`project.toml`, the way `.github/workflows/check.yml` does (about 4 s):

```sh
for name in $(find src -type f \( -name '*.c' -o -name '*.cpp' \) -exec head -qn1 {} + \
        | sed -n 's|^/\* compiler: \([^ ]*\) \*/.*|\1|p' | sort -u); do
  python3 - "$name" <<'PY'
import os, sys, tomllib
c = tomllib.load(open("project.toml", "rb"))["compilers"][sys.argv[1]]
print(os.path.expanduser(c["dir"]), c["archive"])
for need, url in c.get("needs", {}).items():
    print(os.path.expanduser("~/.local/share/gt4/compilers/" + need), url)
PY
done | sort -u | while read -r dir url; do
  [ -x "$dir/bin/ee-gcc" ] || [ -x "$dir/bin/ee-as" ] && continue
  mkdir -p "$dir" && curl -fsSL "$url" | tar -xJ -C "$dir" && echo "installed $dir"
done
```

## 5. Split, function list and full build

```sh
bash tools/splat.sh
python tools/find_functions.py orig/SCUS-97328/files/CORE.GT4 build/functions.csv
python tools/build.py --jobs 2
bash tools/run_tests.sh
```

- `splat.sh` (43 s) writes one `.s` per function under `build/splat/`. splat 0.50.1 prints
  `Error: Unable to determine a segment for the following user-declared symbols.` for
  `D_006D6050`, `D_0083F5C8`, `D_0083F5E8` and `D_00846468`; it still exits 0 and the build is
  unaffected.
- **Stuck point: `build/functions.csv`.** `build.py` reads it at start-up and fails with
  `FileNotFoundError: ... build/functions.csv` on a fresh checkout, so `find_functions.py` comes
  before the build (under a second, 15,068 functions).
- `build.py` compiled 30,157 sources and linked 29,995 functions in 867 s, with `--jobs 2` (the
  limit in `.claude/skills/gt4-decomp/SKILL.md`). It ends with
  `.text OK  sha1 28422e7e20a6298224294255355487b9a22cef31` and `.data OK`; `build/full/report.json`
  records the commit, `partial: false`, and the SHA-1 of both segments.
- `run_tests.sh`: 108 tests, all passing.

From installing the host packages to the build proof: 19 minutes, most of it the build.

## Windows + WSL (not tested yet)

Nobody has run this walkthrough on WSL yet. Steps 2 to 5 are expected to apply as they are inside
an Ubuntu 24.04 WSL distribution (`wsl --install -d Ubuntu-24.04`), without step 1. If you run it,
replace this section with what you did, how long each step took and where you got stuck.
