#!/bin/bash
# Run the unit tests the way the CI does (python -m unittest discover -s tests -v), with a Python that has
# the dependencies. Several tools import `rabbitizer`; if the default python3 lacks it, use the project's
# virtual environment (created by tools/setup_linux.sh) and say so, instead of failing with
# ModuleNotFoundError.
#
#   bash tools/run_tests.sh
set -uo pipefail
root="$(cd "$(dirname "$0")/.." && pwd)"
cd "$root"
py="${PYTHON:-python3}"
if ! "$py" -c 'import rabbitizer' 2>/dev/null; then
  venv="$HOME/.local/share/gt4/venv/bin/python"
  if [ -x "$venv" ] && "$venv" -c 'import rabbitizer' 2>/dev/null; then
    echo "note: $py has no rabbitizer; using $venv" >&2
    py="$venv"
  else
    echo "error: Python module 'rabbitizer' is missing. Install it with: $py -m pip install rabbitizer" >&2
    echo "       (the README lists it under Setup; tools/setup_linux.sh creates a virtual environment that has it)" >&2
    exit 2
  fi
fi
exec "$py" -m unittest discover -s tests -v
