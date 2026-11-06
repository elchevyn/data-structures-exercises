#!/usr/bin/env bash
set -u

CXX=${CXX:-g++}
CXXFLAGS=${CXXFLAGS:--std=c++17 -O2}
ROOT="$(cd "$(dirname "$0")" && pwd)"
TOTAL=0
PASS=0
FAIL=0
COMPILE_FAIL=0

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

run_problem() {
  local folder="$1"
  echo ""
  echo "--- $(basename "$folder") ---"
  cd "$folder" || return

  if [[ ! -f template.cpp || ! -d tests ]]; then
    echo "[SKIP] template.cpp or tests/ not found"
    cd "$ROOT" || exit 1
    return
  fi

  if [[ -f harness.cpp ]]; then
    $CXX $CXXFLAGS harness.cpp template.cpp -o __local_test
  else
    $CXX $CXXFLAGS template.cpp -o __local_test
  fi

  if [[ $? -ne 0 ]]; then
    echo "[COMPILE FAIL]"
    COMPILE_FAIL=$((COMPILE_FAIL+1))
    cd "$ROOT" || exit 1
    return
  fi

  shopt -s nullglob
  local inputs=(tests/*.in)
  for in_file in "${inputs[@]}"; do
    local case_name
    case_name="$(basename "$in_file" .in)"
    local expected="tests/$case_name.out"
    local got="tests/$case_name.got"

    TOTAL=$((TOTAL+1))
    ./__local_test < "$in_file" > "$got"

    if diff -q "$expected" "$got" >/dev/null 2>&1; then
      echo "[PASS] $case_name"
      printf '  Expected: '; preview "$expected"
      printf '  Got     : '; preview "$got"
      PASS=$((PASS+1))
      rm -f "$got"
    else
      echo "[FAIL] $case_name"
      printf '  Expected: '; preview "$expected"
      printf '  Got     : '; preview "$got"
      FAIL=$((FAIL+1))
    fi
  done

  rm -f __local_test
  cd "$ROOT" || exit 1
}

echo ""
echo "======================================="
echo "Graph Set - All Local Tests"
echo "======================================="

shopt -s nullglob
for folder in "$ROOT"/graph-*; do
  [[ -d "$folder" ]] && run_problem "$folder"
done

echo ""
echo "======================================="
echo "Final Summary"
echo "  Tests run    : $TOTAL"
echo "  Tests passed : $PASS"
echo "  Tests failed : $FAIL"
echo "  Compile fail : $COMPILE_FAIL"
echo "======================================="
echo ""
read -r -p "Press Enter to close..." _

if [[ $FAIL -ne 0 || $COMPILE_FAIL -ne 0 ]]; then exit 1; fi
exit 0
