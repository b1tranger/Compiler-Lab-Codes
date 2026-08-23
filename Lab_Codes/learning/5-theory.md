# C++ Lab 5 Theory & Troubleshooting: Header Files & Input Stream Handling

This document provides a comprehensive summary of the concepts, issues, and solutions encountered in **Lab 5 (Header Files & Arithmetic Operations)**.

---

## 1. Custom Header Files (`.h`) in C++

### What is a Header File?
In C++, code is often modularized into separate files:
- **Header Files (`.h` / `.hpp`)**: Contain function declarations, templates, macros, class definitions, and reusable inline functions.
- **Source Files (`.cpp`)**: Contain the actual implementation and execution entry points (e.g., `main()`).

### `#include ""` vs `#include <>`
- `#include <...>`: Tells the preprocessor to search standard library / system include directories first.
- `#include "..."`: Tells the preprocessor to search the **current working directory / local project** first before searching system directories.

```cpp
#include "new.h"        // Local custom header file
#include <iostream>     // Standard C++ library header
```

### Best Practice: Header Guards
To prevent multiple definitions if a header is included multiple times across different translation units, always protect header files with header guards or `#pragma once`:

```cpp
#pragma once

// Declarations and functions
int sum(int a, int b);
```

---

## 2. Issue 1: Compiler Warning — `control reaches end of non-void function`

### The Warning
```text
In file included from new.cpp:1:
new.h: In function 'float divi(float, float)':
new.h:16:1: warning: control reaches end of non-void function [-Wreturn-type]
   16 | }
      | ^
```

### Cause & Mechanism
The function `divi(float a, float b)` declared a non-`void` return type (`float`), but contained an execution path that did not return any value:

```cpp
// Buggy Code:
float divi(float a, float b) {
  if (b == 0) {
    cout << "Division of 0 --> Invalid" << endl;
    // Missing return statement here!
  } else {
    return a / b;
  }
}
```

If `b == 0`, control reaches line 16 and exits the function without returning a `float`. In C++, failing to return a value from a non-void function causes **Undefined Behavior (UB)**.

### Solution
Ensure every control path returns an appropriate `float` value:

```cpp
// Corrected Code:
float divi(float a, float b) {
  if (b == 0) {
    cout << "Division of 0 --> Invalid" << endl;
    return 0.0f; // Return a fallback value
  }
  return a / b;
}
```

---

## 3. Issue 2: Garbage Output & `std::cin` Stream Failure

### The Symptom
When running the program, the terminal displayed:
```text
Enter n1: cd "c:\Users\gsmur\Documents\GitHub\UITS\Compiler-Lab-Codes\Lab_Codes\5.Header_File\" ; if ($?) { g++ new.cpp -o new.exe } ; if ($?) { .\new.exe }
Enter n2: JOG Hocche: -2144582496
BIYOG Hocche: 2144582496
GUN Hocche: 0
VAG Hocche: -0
```

### Why Did This Happen?

1. **Terminal Input Injection**:
   The PowerShell build/run command string (`cd ... ; g++ ... ; .\new.exe`) was accidentally sent/pasted into standard input while the program was waiting at `cin >> n1;`.

2. **`std::cin` Fail State (`failbit`)**:
   `n1` is an integer (`int`). When `cin >> n1` encounters non-numeric string data (such as `"cd"`), the conversion fails. C++ sets the internal error flag on the stream (`cin.fail() == true`).

3. **Cascading Input Failure**:
   Once `std::cin` enters a fail state:
   - `n1` is not populated.
   - All subsequent input operations (like `cin >> n2;`) are **immediately skipped** without prompting the user.

4. **Uninitialized Stack Memory (Garbage Values)**:
   In C++, local variables declared without initializers (e.g., `int n1, n2;`) hold whatever random residual bits were present in that memory location on the stack.
   - `n1` contained garbage (e.g., `0`)
   - `n2` contained garbage (e.g., `-2144582496`)
   - Arithmetic on garbage data yielded nonsensical values:
     - `sum = -2144582496`
     - `sub = 2144582496`
     - `mul = 0`

---

## 4. Recovering from Input Stream Failures

To make C++ console input robust against invalid inputs (e.g., typing letters when numbers are expected), use `cin.fail()`, `cin.clear()`, and `cin.ignore()`:

```cpp
#include <iostream>
#include <limits>

using namespace std;

int getValidInteger(const string& prompt) {
    int value;
    while (true) {
        cout << prompt;
        if (cin >> value) {
            return value; // Input succeeded
        }
        // Input failed: clear error flags and discard invalid buffer
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input! Please enter a valid number.\n";
    }
}
```

---

## 5. Complete Corrected Code Reference

### `new.h`
```cpp
#pragma once
#include <iostream>

using namespace std;

inline int sum(int a, int b) { 
    return a + b; 
}

inline int sub(int a, int b) { 
    return a - b; 
}

inline int mul(int a, int b) { 
    return a * b; 
}

inline float divi(float a, float b) {
    if (b == 0) {
        cout << "Division by 0 --> Invalid" << endl;
        return 0;
    }
    return a / b;
}
```

### `new.cpp`
```cpp
#include "new.h"
#include <iostream>

using namespace std;

int main() {
    int n1 = 0, n2 = 0; // Always initialize variables

    cout << "Enter n1: ";
    if (!(cin >> n1)) {
        cout << "Invalid input for n1." << endl;
        return 1;
    }

    cout << "Enter n2: ";
    if (!(cin >> n2)) {
        cout << "Invalid input for n2." << endl;
        return 1;
    }

    cout << "JOG Hocche: " << sum(n1, n2) << endl;
    cout << "BIYOG Hocche: " << sub(n1, n2) << endl;
    cout << "GUN Hocche: " << mul(n1, n2) << endl;
    cout << "VAG Hocche: " << divi(n1, n2) << endl;

    return 0;
}
```

---

## 6. Key Takeaways Summary

| Concept | Problem / Observation | Best Practice / Fix |
| :--- | :--- | :--- |
| **Return Statements** | Non-void functions missing return paths trigger `-Wreturn-type` warning & UB. | Ensure every conditional branch (`if-else`) returns a value. |
| **Variable Initialization** | Uninitialized locals contain stack garbage data. | Always initialize variables (e.g., `int n1 = 0;`). |
| **`std::cin` State** | Invalid type inputs set `failbit`, causing all subsequent `cin >>` calls to be bypassed. | Check `cin.fail()` or validate `if (cin >> val)`. |
| **Header Modularity** | Custom headers organize reusable math/utility functions. | Include local headers with `#include "header.h"` and use guards. |
