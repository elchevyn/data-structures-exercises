// Local VS Code debugger wrapper. Do not submit or modify harness.cpp.
// Change tests/01.in to another test file when needed.
#include <cstdio>

#define main grader_harness_main
#include "harness.cpp"
#undef main

int main() {
    if (freopen("tests/01.in", "r", stdin) == nullptr) return 2;
    return grader_harness_main();
}
