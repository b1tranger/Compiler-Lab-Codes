# C++ Environment Setup & Execution Guide (`1-cpp-environment-setup.md`)

This guide documents the setup, verification, toolchain configuration, and practical instructions on how to compile and run C and C++ files for compiler lab work.

---

## 1. Installed Toolchain Overview

The system comes pre-configured with modern C and C++ compilers, debugging utilities, and language servers.

| Tool | Binary Path | Version / Description |
| :--- | :--- | :--- |
| **GNU C++ Compiler (`g++`)** | `/usr/bin/g++` | `16.2.1` (Supports C++20 & C++23) |
| **GNU C Compiler (`gcc`)** | `/usr/bin/gcc` | `16.2.1` |
| **LLVM Clang Compiler (`clang++` / `clang`)** | `/usr/bin/clang++` | `22.1.8` |
| **GNU Debugger (`gdb`)** | `/usr/bin/gdb` | `17.2` |
| **Build Automation (`make`)** | `/usr/bin/make` | GNU Make |
| **LSP Language Server (`clangd`)** | `/usr/bin/clangd` | Code completion, diagnostics & indexing |
| **Package Config (`pkg-config`)** | `/usr/bin/pkg-config` | Library dependency tracking |

---

## 2. Toolchain Verification Commands

To check the availability and versions of the installed compilers and tools on your system:

```bash
# Check binary locations
which g++ gcc clang++ clang make gdb clangd pkg-config

# Check compiler versions
g++ --version
gcc --version
clang++ --version
gdb --version
```

---

## 3. How to Compile & Run C and C++ Files

### Option A: Single C++ File (`.cpp`) — Direct Command Line

For compiling and running individual C++ files (e.g., `Lab_Codes/2.1.cpp`):

```bash
# 1-Liner: Compile and run immediately
g++ Lab_Codes/2.1.cpp -o Lab_Codes/2.1 && ./Lab_Codes/2.1

# Step-by-step with standard flags (-std=c++20, -Wall warnings)
g++ -Wall -Wextra -std=c++20 Lab_Codes/2.1.cpp -o Lab_Codes/2.1
./Lab_Codes/2.1
```

Using **Clang**:
```bash
clang++ -Wall -std=c++20 Lab_Codes/2.1.cpp -o Lab_Codes/2.1 && ./Lab_Codes/2.1
```

---

### Option B: Single C File (`.c`) — Direct Command Line

For compiling and running individual C files (e.g., `Lab_Codes/1.1.c`):

```bash
# 1-Liner: Compile and run immediately
gcc Lab_Codes/1.1.c -o Lab_Codes/1.1 && ./Lab_Codes/1.1

# Step-by-step with warnings
gcc -Wall -Wextra Lab_Codes/1.1.c -o Lab_Codes/1.1
./Lab_Codes/1.1
```

Using **Clang**:
```bash
clang -Wall Lab_Codes/1.1.c -o Lab_Codes/1.1 && ./Lab_Codes/1.1
```

---

### Option C: Implicit `make` (No `Makefile` Required)

GNU `make` has implicit built-in rules for compiling `.cpp` and `.c` files without needing a `Makefile`:

```bash
# Navigate to your source directory
cd Lab_Codes/

# Automatically compiles 2.1.cpp -> binary 2.1 using g++
make 2.1
./2.1

# Automatically compiles 1.1.c -> binary 1.1 using gcc
make 1.1
./1.1
```

> [!WARNING]
> **Understanding `make: *** No rule to make target 'run'. Stop.`**:
>
> Running `make run` requires a file named `Makefile` in the current working directory that explicitly defines a `run:` target rule (e.g. `run: \n\t ./2.1`).
>
> If you run `make run` in a directory without a `Makefile` or without a `run:` rule, `make` will fail.
>
> **Solution**: For standalone lab files, use **Option A** (`g++ file.cpp -o file && ./file`) or **Option C** (`make 2.1 && ./2.1`).

---

## 4. Configuring VS Code "Code Runner" Extension

### Problem: Read-Only Output Tab Issue
By default, the **Code Runner** extension executes code inside VS Code's **Output** tab. The Output tab is **read-only**, meaning programs requiring user input (`cin >> ...` in C++ or `scanf(...)` in C) cannot receive keyboard input and will appear stuck or frozen.

### Solution: Enable "Run In Terminal"

To allow interactive input (`cin` / `scanf`) when clicking the Code Runner Play button:

1. **Workspace Configuration** (Automated):
   A workspace configuration file has been created at `.vscode/settings.json`:
   ```json
   {
     "code-runner.runInTerminal": true,
     "code-runner.saveFileBeforeRun": true,
     "code-runner.clearPreviousOutput": true,
     "code-runner.executorMap": {
       "c": "cd $dir && gcc -Wall $fileName -o $fileNameWithoutExt && $dir$fileNameWithoutExt",
       "cpp": "cd $dir && g++ -std=c++20 -Wall $fileName -o $fileNameWithoutExt && $dir$fileNameWithoutExt"
     }
   }
   ```

2. **Global VS Code Settings** (Manual):
   If configuring across all your projects in VS Code:
   - Open Settings (`Ctrl + ,` or `Cmd + ,`).
   - Search for `code-runner.runInTerminal`.
   - Check the box for **"Code-runner: Run In Terminal"**.

---

## 5. Multi-File Projects & Custom `Makefile`

When working on larger multi-file projects, create a `Makefile` in the project root:

### Example Project Structure
```text
cpp_demo/
├── main.cpp
└── Makefile
```

### `Makefile` Example
```makefile
CXX = g++
CXXFLAGS = -std=c++20 -Wall -Wextra -O2
TARGET = demo

all: $(TARGET)

$(TARGET): main.cpp
	$(CXX) $(CXXFLAGS) main.cpp -o $(TARGET)

clean:
	rm -f $(TARGET)

run: all
	./$(TARGET)

.PHONY: all clean run
```

With this `Makefile` present, `make run` works as expected:
```bash
make run
```

---

## 6. Summary of Useful Flags & Tips

1. **Recommended Flags**:
   - `-std=c++20` (C++) or `-std=c17` (C): Sets the modern language standard.
   - `-Wall -Wextra`: Enables warnings to catch common mistakes (uninitialized variables, type mismatches).
   - `-g`: Generates debug symbols for `gdb`.
   - `-O2`: Enables optimization for standard execution.

2. **Debugging with GDB**:
   ```bash
   # 1. Compile with debug symbols (-g)
   g++ -g Lab_Codes/2.1.cpp -o Lab_Codes/2.1_debug

   # 2. Launch GDB
   gdb ./Lab_Codes/2.1_debug
   ```

3. **IDE Code Completion (`clangd`)**:
   - `clangd` provides fast autocompletion and diagnostic checks for C and C++ files in VS Code / IDEs.
