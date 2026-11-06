@echo off
setlocal EnableExtensions EnableDelayedExpansion

REM Runs every graph-* exercise folder, including visible and h* tests.
set CXX=g++
set CXXFLAGS=-std=c++17 -O2
set ROOT=%~dp0
set TOTAL=0
set PASS=0
set FAIL=0
set COMPILE_FAIL=0

echo.
echo =======================================
echo Graph Set - All Local Tests
echo =======================================

pushd "%ROOT%"
for /d %%D in (graph-*) do call :run_problem "%%D"
popd

echo.
echo =======================================
echo Final Summary
echo   Tests run    : !TOTAL!
echo   Tests passed : !PASS!
echo   Tests failed : !FAIL!
echo   Compile fail : !COMPILE_FAIL!
echo =======================================
echo.
echo Press any key to close...
pause >nul

if !FAIL! NEQ 0 exit /b 1
if !COMPILE_FAIL! NEQ 0 exit /b 1
exit /b 0

:run_problem
set FOLDER=%~1
echo.
echo --- !FOLDER! ---
pushd "!FOLDER!"

if not exist template.cpp (
  echo [SKIP] template.cpp not found
  popd
  goto :eof
)
if not exist tests (
  echo [SKIP] tests folder not found
  popd
  goto :eof
)

if exist harness.cpp (
  %CXX% %CXXFLAGS% harness.cpp template.cpp -o __local_test.exe
) else (
  %CXX% %CXXFLAGS% template.cpp -o __local_test.exe
)

if errorlevel 1 (
  echo [COMPILE FAIL]
  set /a COMPILE_FAIL+=1
  popd
  goto :eof
)

for %%F in ("tests\*.in") do (
  set /a TOTAL+=1
  set CASE=%%~nF
  set EXPECTED=tests\!CASE!.out
  set GOT=tests\!CASE!.got

  __local_test.exe < "%%F" > "!GOT!"
  fc /n "!EXPECTED!" "!GOT!" >nul
  if errorlevel 1 (
    echo [FAIL] !CASE!
    set "EXPECTED_LINE="
    set /p "EXPECTED_LINE=" < "!EXPECTED!"
    set "GOT_LINE="
    set /p "GOT_LINE=" < "!GOT!"
    echo   Expected: !EXPECTED_LINE:~0,120!
    echo   Got     : !GOT_LINE:~0,120!
    set /a FAIL+=1
  ) else (
    echo [PASS] !CASE!
    set "EXPECTED_LINE="
    set /p "EXPECTED_LINE=" < "!EXPECTED!"
    set "GOT_LINE="
    set /p "GOT_LINE=" < "!GOT!"
    echo   Expected: !EXPECTED_LINE:~0,120!
    echo   Got     : !GOT_LINE:~0,120!
    set /a PASS+=1
    del /q "!GOT!" >nul 2>&1
  )
)

del /q __local_test.exe >nul 2>&1
popd
goto :eof
