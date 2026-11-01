# `b1t_Lang` — Custom C++ Domain-Specific Language (Assignment 4)

`b1t_Lang` is an expressive C++ Domain-Specific Language (DSL) and syntax abstraction engine designed for competitive programming, algorithm scripting, and mathematical computing. It simplifies C++ syntax through preprocessor keyword aliasing, type-safe stream binding, variadic fold expressions, custom loop macros, and optimized dynamic vector calculators.

---

## Table of Contents
1. [Project Architecture](#-project-architecture)
   - [File Map](#file-map)
   - [Header Hierarchy & Decoupling](#-header-hierarchy--decoupling)
2. [Master API & Syntax Reference](#-master-api--syntax-reference)
3. [Starter Template Snippet (`test.cpp`)](#-starter-template-snippet-testcpp)
4. [Interactive Demonstration Driver (`main.cpp`)](#-interactive-demonstration-driver-maincpp)
5. [Compilation & Execution](#-compilation--execution)
6. [Technical Highlights & Compiler Design Principles](#-technical-highlights--compiler-design-principles)

---

## 📂 Project Architecture

### File Map

```
Assignments/A4_b1t_Lang/
├── common.h       # Curated lightweight Standard C++ Library (<iostream>, <vector>, etc.)
├── all.h          # Extended Standard C++ Library (shielded with pragma push/pop_macro)
├── main.h         # Core DSL Engine: macros, stream aliases, math & vector functions, demo suite
├── main.cpp       # Interactive CLI driver with menu navigation (Choices 1, 2, 3)
├── test.cpp       # Minimal starter template / snippet for new b1t_Lang programs
├── report.md      # Comprehensive technical code report and breakdown
└── README.md      # Project overview and documentation reference
```

### 🧩 Header Hierarchy & Decoupling

```
┌─────────────────────────────────────────────────────────────────────────┐
│                           Header Architecture                           │
├─────────────────────────────────────────────────────────────────────────┤
│                                                                         │
│   ┌────────────────────────────────┐    ┌───────────────────────────┐   │
│   │            common.h            │    │           all.h           │   │
│   │   (Fast, standard C++ headers) │    │   (Extended STL headers)  │   │
│   └───────────────┬────────────────┘    └───────────────────────────┘   │
│                   │                                                     │
│                   ▼                                                     │
│   ┌────────────────────────────────┐                                    │
│   │             main.h             │   (Core DSL Engine & Demo Suite)   │
│   └───────────────┬────────────────┘                                    │
│                   │                                                     │
│         ┌─────────┴─────────┐                                           │
│         ▼                   ▼                                           │
│   ┌──────────┐        ┌──────────┐                                      │
│   │ main.cpp │        │ test.cpp │ (Starter Template / Snippet)         │
│   └──────────┘        └──────────┘                                      │
│                                                                         │
└─────────────────────────────────────────────────────────────────────────┘
```

1. **`common.h`**: Loads curated everyday standard headers (`<iostream>`, `<vector>`, `<string>`, `<cmath>`, `<algorithm>`, `<numeric>`, `<iomanip>`, `<map>`, `<set>`, `<queue>`, `<stack>`, `<deque>`, `<utility>`, `<climits>`, `<cstdint>`).
2. **`all.h`**: Loads extended standard headers without duplicating `common.h`. Employs `#pragma push_macro` / `#pragma pop_macro` to shield STL symbols (such as `std::filesystem::perms::all`) from macro collisions.
3. **`main.h`**: The central DSL engine and demonstration harness (`show_function_table`, `demo_specific`, `demo_all`). Depends **only** on `common.h`, preventing compilation bloat.
4. **`main.cpp`**: The interactive driver program providing top-level menu routing and targeted function inspection.
5. **`test.cpp`**: The minimal boilerplate template / snippet for rapidly developing new algorithms in `b1t_Lang`.

---

## 🛠️ Master API & Syntax Reference

| Category | `b1t_Lang` Syntax | Standard C++ Syntax | Description |
| :--- | :--- | :--- | :--- |
| **Entry Point** | `main { ... }` | `int main() { ... }` | Macro-based custom entry point |
| **Fast I/O** | `detach_C();` | `ios_base::sync_with_stdio(false); cin.tie(NULL);` | Disables C stdio sync for high-speed I/O |
| **Stream Aliases** | `in >> x;` | `std::cin >> x;` | Fast, type-safe console input |
| | `out << x;` | `std::cout << x;` | Fast, type-safe console output |
| **Header Includes** | `#include common` | `#include <iostream>`, etc. | Imports curated core headers |
| | `#include all` | `#include <unordered_map>`, etc. | Imports extended STL headers |
| **Forward Loops** | `loop(i, 0, n, i++)` | `for (int i = 0; i < n; i++)` | Exclusive forward loop ($i < n$) |
| | `loop2(i, 0, n, i++)` | `for (int i = 0; i <= n; i++)` | Inclusive forward loop ($i \le n$) |
| **Reverse Loops** | `loopr(i, n, 0, i--)` | `for (int i = n; i > 0; i--)` | Exclusive reverse loop ($i > 0$) |
| | `loop2r(i, n, 0, i--)` | `for (int i = n; i >= 0; i--)` | Inclusive reverse loop ($i \ge 0$) |
| **Variadic Math** | `sum(a, b, c, ...)` | `(a + b + c + ...)` | Variadic addition across $N$ elements |
| | `sub(a, b, c, ...)` | `(a - b - c - ...)` | Variadic sequential subtraction |
| | `mul(a, b, c, ...)` | `(a * b * c * ...)` | Variadic multiplication across $N$ elements |
| | `divi(a, b, c, ...)` | `((a / b) / c)` *(with zero check)* | Variadic division with 0-divisor protection |
| | `rem(a, b)` | `a % b` *(with zero check)* | Safe integer modulo / remainder |
| **Variadic Extremes** | `mx(a, b, c, d, ...)` | `std::max({a, b, c, d})` | Variadic maximum across $N$ arguments |
| | `mn(a, b, c, d, ...)` | `std::min({a, b, c, d})` | Variadic minimum across $N$ arguments |
| **Math & Powers** | `pwr(base, exp)` | `std::pow(base, exp)` | $\mathcal{O}(\log n)$ Fast Binary Exponentiation |
| | `sqr(x)` | `(x * x)` | Square of a number ($x^2$) |
| | `cube(x)` | `(x * x * x)` | Cube of a number ($x^3$) |
| | `abs_val(x)` | `std::abs(x)` | Absolute value ($\|x\|$) |
| | `fact(n)` | Factorial loop | Factorial ($n!$) with negative protection |
| | `sum_n(n)` | $\frac{n(n+1)}{2}$ | $\mathcal{O}(1)$ Gauss sum of $1 \dots n$ with 64-bit guard |
| **Logic & Checks** | `is_even(n)` | `(n % 2 == 0)` | Checks if integer is even |
| | `is_odd(n)` | `(n % 2 != 0)` | Checks if integer is odd |
| | `is_pos(n)` | `(n > 0)` | Checks if number is positive |
| | `is_neg(n)` | `(n < 0)` | Checks if number is negative |
| | `is_eq(a, b)` | `(a == b)` | Generic equality check |
| **Utilities** | `swp(a, b)` | `std::swap(a, b)` | In-place reference value swap |
| **Vector Overloads** | `sum(vector<T>)` | `std::accumulate(...)` | Dynamic vector summation |
| | `sub(vector<T>)` | Dynamic subtraction | Dynamic sequential vector subtraction |
| | `mul(vector<T>)` | Dynamic product | Dynamic vector multiplication |
| | `divi(vector<T>)` | Dynamic division | Dynamic safe vector division |
| | `mx(vector<T>)` | `*std::max_element(...)` | Maximum element in vector |
| | `mn(vector<T>)` | `*std::min_element(...)` | Minimum element in vector |

---

## 📝 Starter Template Snippet (`test.cpp`)

[`test.cpp`](file:///d:/GitHub/UITS/Compiler-Lab-Codes/doc/Assignments/A4_b1t_Lang/test.cpp) serves as the standard template or snippet for quickly authoring new code utilizing `b1t_Lang`:

```cpp
#include "main.h"

main {
  detach_C();

  // Write your b1t_Lang code here
  return 0;
}
```

---

## 💻 Interactive Demonstration Driver (`main.cpp`)

[`main.cpp`](file:///d:/GitHub/UITS/Compiler-Lab-Codes/doc/Assignments/A4_b1t_Lang/main.cpp) provides an interactive command-line interface structured into a two-tier state machine:

```cpp
#include "main.h"

main {
  int choice;
  while (true) {
    out << "\n==========================================" << endl;
    out << "     b1t_Lang Custom DSL Demonstration    " << endl;
    out << "==========================================" << endl;
    out << "1. Show all function usage" << endl;
    out << "2. See specific function usage from table" << endl;
    out << "3. Exit" << endl;
    out << "Enter your choice (1-3): ";

    if (!(in >> choice)) break;

    if (choice == 1) {
      demo_all();
    } else if (choice == 2) {
      show_function_table();
      while (true) {
        out << "\nEnter function number (1-21) to demo (or 0 to go back): ";
        int func_id;
        if (!(in >> func_id) || func_id == 0) break;

        demo_specific(func_id);

        out << "\nPress '0' to go back, '1' to see the table: ";
        int sub_choice;
        while (in >> sub_choice) {
          if (sub_choice == 0 || sub_choice == 1) break;
          out << "Invalid input! Press '0' to go back, '1' to see the table: ";
        }
        if (sub_choice == 0) break;
        else if (sub_choice == 1) show_function_table();
      }
    } else if (choice == 3) {
      out << "Exiting b1t_Lang Demonstration. Goodbye!" << endl;
      break;
    }
  }
  return 0;
}
```

---

## 🚀 Compilation & Execution

### Requirements
- A modern C++ compiler supporting C++17 or C++20 (`g++`, `clang++`, or MSVC).

### Commands

```bash
# Navigate to the assignment folder
cd doc/Assignments/A4_b1t_Lang

# Compile the interactive driver (C++20 recommended)
g++ -Wall -Wextra -std=c++20 main.cpp -o main.exe

# Compile the starter template snippet
g++ -Wall -Wextra -std=c++20 test.cpp -o test.exe

# Run the executable
./main.exe
```

---

## 🧠 Technical Highlights & Compiler Design Principles

1. **C++17 Fold Expressions**: Variadic math operations (`sum`, `sub`, `mul`, `divi`, `mx`, `mn`) expand at compile-time with zero function-call overhead.
2. **Zero-Division Safety**: Division and modulo routines inspect divisors before execution, preventing hardware exceptions (`SIGFPE`).
3. **Macro Hygiene & Shielding**: Short preprocessor tokens like `all` and `common` are temporarily shielded via `#pragma push_macro` and `#pragma pop_macro` in `all.h` to prevent corrupting internal standard library namespaces (e.g. `std::filesystem::perms::all`).
4. **One Definition Rule (ODR) Compliance**: Stream references use `inline auto &in = std::cin;` in headers to allow safe multi-file inclusion without multiple-definition linker errors.
5. **Decoupled Architecture**: `main.h` depends strictly on `common.h`, preventing the compile-time slowdowns associated with monolithic `<bits/stdc++.h>` includes.
6. **Synchronous Interactive Stream Tying**: In interactive CLI mode, keeping `cin` tied to `cout` guarantees console prompts flush to the screen immediately before blocking extractions.
