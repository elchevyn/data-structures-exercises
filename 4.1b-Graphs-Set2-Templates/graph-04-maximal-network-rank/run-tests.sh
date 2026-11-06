#!/usr/bin/env bash
set -u

CXX=${CXX:-g++}
CXXFLAGS=${CXXFLAGS:--std=c++17 -O2}
TOTAL=0
PASS=0
FAIL=0

preview() {
  local file="$1"
  local line=""
  IFS= read -r line < "$file" || true
  if (( ${#line} > 120 )); then
    printf '%s...\n' "${line:0:120}"
  else
    printf '%s\n' "$line"
  fi
}

compile() {
  if [[ -f harness.cpp ]]; then
    $CXX $CXXFLAGS harness.cpp template.cpp -o prog
  else
    $CXX $CXXFLAGS template.cpp -o prog
  fi
}

run_all() {
  shopt -s nullglob
  local inputs=(tests/*.in)
  for in_file in "${inputs[@]}"; do
    local base
    base="$(basename "$in_file" .in)"
    local out_file="tests/$base.out"
    local got_file="tests/$base.got"

    TOTAL=$((TOTAL+1))
    ./prog < "$in_file" > "$got_file"

    if diff -q "$out_file" "$got_file" >/dev/null 2>&1; then
      echo "[PASS] $base"
      printf '  Expected: '; preview "$out_file"
      printf '  Got     : '; preview "$got_file"
      PASS=$((PASS+1))
      rm -f "$got_file"
    else
      echo "[FAIL] $base"
      printf '  Expected: '; preview "$out_file"
      printf '  Got     : '; preview "$got_file"
      FAIL=$((FAIL+1))
    fi
  done
}

echo ""
echo "==============================="
echo "Graph Exercise - Local Tests"
echo "==============================="
echo ""

compile || { echo "[COMPILE FAIL]"; read -r -p "Press Enter to close..." _; exit 1; }
if [[ ! -d tests ]]; then
  echo "[MISSING] tests folder"
  read -r -p "Press Enter to close..." _
  exit 1
fi

run_all

echo ""
echo "==============================="
echo "Summary"
echo "  Total: $TOTAL"
echo "  Pass : $PASS"
echo "  Fail : $FAIL"
echo "==============================="
echo ""
read -r -p "Press Enter to close..." _

if [[ $FAIL -ne 0 ]]; then exit 1; fi
exit 0
