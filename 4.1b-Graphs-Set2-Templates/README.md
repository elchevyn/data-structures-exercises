# Data Structures Exercises

C++ practice exercises for the course.

## Requirements

- A C++17 compiler (`g++`).
- **Windows:** use `.bat` scripts.
- **macOS/Linux:** use `.sh` scripts.

## Repository structure

Each activity is stored in its own folder. An activity can cover graphs, trees, heaps, or another topic.

Each exercise folder normally contains:

- `statement.md` — problem statement.
- `template.cpp` — file you must complete.
- `harness.cpp` — provided driver when the exercise asks for a function.
- `tests/` — local test cases.
- `run-tests.bat` — Windows runner.
- `run-tests.sh` — macOS/Linux runner.

## Run one exercise

Open a terminal inside the exercise folder.

**Windows**

```bat
run-tests.bat
```

**macOS/Linux**

```bash
chmod +x run-tests.sh
./run-tests.sh
```

The runner compiles your code, runs the included tests, and prints a summary.

## Run an activity

Some activity folders include a global runner. From the activity folder:

**Windows**

```bat
run-all-tests.bat
```

**macOS/Linux**

```bash
chmod +x run-all-tests.sh
./run-all-tests.sh
```

## VS Code debugging

When an exercise includes a `.vscode/` folder:

1. Open the **individual exercise folder** in VS Code.
2. Open `template.cpp`.
3. Add a breakpoint.
4. Press `F5` and select **Debug test**.

The debugger runs `tests/01.in` by default. To use another case, edit the input path in `debug_harness.cpp`.

> Debugging requires VS Code, the Microsoft C/C++ extension, and `g++` and `gdb` available in your system `PATH`.

## Updating the repository

Before starting a new activity:

```bash
git pull
```

Avoid pulling while you have unfinished changes in the same files. Commit, stash, or back up your work first.
