@echo off
setlocal EnableExtensions EnableDelayedExpansion

set CXX=g++
set CXXFLAGS=-std=c++17 -O2

set TOTAL=0
set PASS=0
set FAIL=0

echo.
echo ===============================
echo Graph Exercise - Local Tests
echo ===============================
echo.

set EXE=prog.exe

if exist harness.cpp (
  %CXX% %CXXFLAGS% harness.cpp template.cpp -o %EXE%
) else (
  %CXX% %CXXFLAGS% template.cpp -o %EXE%
)

if errorlevel 1 (
  echo [COMPILE FAIL]
  echo Press any key to close...
  pause >nul
  exit /b 1
)

if not exist tests (
  echo [MISSING] tests folder
  echo Press any key to close...
  pause >nul
  exit /b 1
)

for %%F in ("tests\*.in") do (
  set /a TOTAL+=1
  set BASE=%%~nF
  set IN=%%F
  set OUT=tests\!BASE!.out
  set GOT=tests\!BASE!.got

  %EXE% < "!IN!" > "!GOT!"

  fc /n "!OUT!" "!GOT!" >nul
  if errorlevel 1 (
    echo [FAIL] !BASE!
    set "EXPECTED_LINE="
    set /p "EXPECTED_LINE=" < "!OUT!"
    set "GOT_LINE="
    set /p "GOT_LINE=" < "!GOT!"
    echo   Expected: !EXPECTED_LINE:~0,120!
    echo   Got     : !GOT_LINE:~0,120!
    set /a FAIL+=1
  ) else (
    echo [PASS] !BASE!
    set "EXPECTED_LINE="
    set /p "EXPECTED_LINE=" < "!OUT!"
    set "GOT_LINE="
    set /p "GOT_LINE=" < "!GOT!"
    echo   Expected: !EXPECTED_LINE:~0,120!
    echo   Got     : !GOT_LINE:~0,120!
    set /a PASS+=1
    del /q "!GOT!" >nul 2>&1
  )
)

echo.
echo ===============================
echo Summary
echo   Total: !TOTAL!
echo   Pass : !PASS!
echo   Fail : !FAIL!
echo ===============================
echo.
echo Press any key to close...
pause >nul

if !FAIL! NEQ 0 exit /b 1
exit /b 0
