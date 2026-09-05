# C++ Environment Setup & Execution Guide (`1-cpp-environment-setup.md`)

This guide documents the setup, verification, toolchain configuration, and practical instructions on how to compile and run C and C++ files for compiler lab work.

## Table of Contents
1. [Installed Toolchain Overview](#1-installed-toolchain-overview)
2. [Toolchain Verification Commands](#2-toolchain-verification-commands)
3. [How to Compile & Run C and C++ Files](#3-how-to-compile--run-c-and-c-files)
   - [Option A: Single C++ File (.cpp) — Direct Command Line](#option-a-single-c-file-cpp--direct-command-line)
   - [Option B: Single C File (.c) — Direct Command Line](#option-b-single-c-file-c--direct-command-line)
   - [Option C: Implicit make (No Makefile Required)](#option-c-implicit-make-no-makefile-required)
   - [Option D: Automated PowerShell Runner (run.ps1)](#option-d-automated-powershell-runner-runps1)
4. [Configuring VS Code & IDE Integration](#4-configuring-vs-code--ide-integration)
   - [Problem: Read-Only Output Tab Issue](#problem-read-only-output-tab-issue)
   - [PowerShell 5.1 Command Chaining Rule](#powershell-51-command-chaining-rule)
   - [Workspace Configuration (.vscode/settings.json)](#workspace-configuration-vscodesettingsjson)
   - [Native VS Code Build & Run Tasks (.vscode/tasks.json)](#native-vs-code-build--run-tasks-vscodetasksjson)
   - [C/C++ IntelliSense Configuration (.vscode/c_cpp_properties.json)](#cc-intellisense-configuration-vscodec_cpp_propertiesjson)
5. [Multi-File Projects & Custom Makefile](#5-multi-file-projects--custom-makefile)
6. [Summary of Useful Flags & Tips](#6-summary-of-useful-flags--tips)

---

## 1. Installed Toolchain Overview

The Windows environment comes equipped with modern GCC C and C++ compilers through MSYS2:

| Tool | Windows Binary Path | Version / Description |
| :--- | :--- | :--- |
| **GNU C++ Compiler (`g++`)** | `C:\msys64\usr\bin\g++.exe` | `15.2.0` (Supports C++20 & C++23) |
| **GNU C Compiler (`gcc`)** | `C:\msys64\usr\bin\gcc.exe` | `15.2.0` (Supports C17 & C23) |
| **Build Automation (`make`)** | `C:\msys64\usr\bin\make.exe` | GNU Make `4.4.1` |
| **PowerShell Runner** | `.\run.ps1` | Interactive compile-and-run automation |

---

## 2. Toolchain Verification Commands

To check the availability and versions of the installed compilers and tools in PowerShell:

```powershell
# Check binary locations in PATH
where.exe g++ gcc make

# Check compiler versions
g++ --version
gcc --version
make --version
```

---

## 3. How to Compile & Run C and C++ Files

### Option A: Single C++ File (`.cpp`) — Direct Command Line

For compiling and running individual C++ files (e.g., `Lab_Codes/2.1.cpp`):

```powershell
# PowerShell: Compile with C++20 and execute if successful
g++ -Wall -Wextra -std=c++20 Lab_Codes/2.1.cpp -o Lab_Codes/2.1.exe; if ($?) { .\Lab_Codes\2.1.exe }
```

---

### Option B: Single C File (`.c`) — Direct Command Line

For compiling and running individual C files (e.g., `Lab_Codes/1.1.c`):

```powershell
# PowerShell: Compile with C17 and execute if successful
gcc -Wall -Wextra -std=c17 Lab_Codes/1.1.c -o Lab_Codes/1.1.exe; if ($?) { .\Lab_Codes\1.1.exe }
```

---

### Option C: Implicit `make` (No `Makefile` Required)

GNU `make` has implicit built-in rules for compiling `.cpp` and `.c` files without needing a `Makefile`:

```powershell
# Navigate to your source directory
cd Lab_Codes/

# Automatically compiles 2.1.cpp -> binary 2.1 using g++
make 2.1
.\2.1.exe
```

---

### Option D: Automated PowerShell Runner (`run.ps1`)

A dedicated root script [`run.ps1`](file:///c:/Users/gsmur/OneDrive/Documents/GitHub/Compiler-Lab-Codes/run.ps1) is included in the project root to compile and execute any `.cpp` or `.c` file with interactive `cin` / `scanf` support:

```powershell
# Run a specific C++ file
.\run.ps1 Lab_Codes\2.1.cpp

# Run an assignment file
.\run.ps1 doc\Assignments\A1\A1.1_xor.cpp

# Run without arguments (automatically selects the most recently edited .cpp/.c file)
.\run.ps1
```

---

## 4. Configuring VS Code & IDE Integration

### Problem: Read-Only Output Tab Issue
By default, the **Code Runner** extension executes code inside VS Code's **Output** tab. The Output tab is **read-only**, meaning programs requiring user input (`cin >> ...` in C++ or `scanf(...)` in C) cannot receive keyboard input and will appear stuck or frozen.

### PowerShell 5.1 Command Chaining Rule
In Windows PowerShell 5.1, the POSIX `&&` operator is invalid syntax (`The token '&&' is not a valid statement separator in this version`). Commands must be chained using `;` and the success check `if ($?)`:
```powershell
cd "$dir"; g++ -Wall -Wextra -std=c++20 "$fileName" -o "$fileNameWithoutExt.exe"; if ($?) { .\"$fileNameWithoutExt.exe" }
```

### Workspace Configuration (`.vscode/settings.json`)
The project includes a pre-configured [`.vscode/settings.json`](file:///c:/Users/gsmur/OneDrive/Documents/GitHub/Compiler-Lab-Codes/.vscode/settings.json):
```json
{
  "terminal.integrated.defaultProfile.windows": "PowerShell",
  "code-runner.runInTerminal": true,
  "code-runner.saveFileBeforeRun": true,
  "code-runner.clearPreviousOutput": true,
  "code-runner.preserveFocus": false,
  "code-runner.ignoreSelection": true,
  "code-runner.executorMap": {
    "c": "cd \"$dir\"; gcc -Wall -Wextra -std=c17 \"$fileName\" -o \"$fileNameWithoutExt.exe\"; if ($?) { .\\\"$fileNameWithoutExt.exe\" }",
    "cpp": "cd \"$dir\"; g++ -Wall -Wextra -std=c++20 \"$fileName\" -o \"$fileNameWithoutExt.exe\"; if ($?) { .\\\"$fileNameWithoutExt.exe\" }",
    "python": "python -u \"$fileName\""
  }
}
```

### Native VS Code Build & Run Tasks (`.vscode/tasks.json`)
For developers using VS Code's standard **Run / Build** commands without Code Runner:
- Press **`Ctrl + Shift + B`** to trigger the default build task (`g++ -Wall -Wextra -std=c++20`).
- Use **Terminal > Run Task > `C/C++: g++ build and run active file`** to build and run in the integrated terminal.

### C/C++ IntelliSense Configuration (`.vscode/c_cpp_properties.json`)
To eliminate false include errors and provide C++20 autocompletion, [`.vscode/c_cpp_properties.json`](file:///c:/Users/gsmur/OneDrive/Documents/GitHub/Compiler-Lab-Codes/.vscode/c_cpp_properties.json) points to `C:/msys64/usr/bin/g++.exe` with `c++20` standard mode.

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
