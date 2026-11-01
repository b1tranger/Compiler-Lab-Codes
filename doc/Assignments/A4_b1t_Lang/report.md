# Technical Report: Architectural & Code Analysis of `b1t_Lang` DSL

This report provides an architectural overview and technical analysis of the **`b1t_Lang`** Domain-Specific Language (DSL) developed for Assignment 4. It details each constituent source and header file in the system: [`test.cpp`](file:///d:/GitHub/UITS/Compiler-Lab-Codes/doc/Assignments/A4_b1t_Lang/test.cpp), [`main.h`](file:///d:/GitHub/UITS/Compiler-Lab-Codes/doc/Assignments/A4_b1t_Lang/main.h), [`main.cpp`](file:///d:/GitHub/UITS/Compiler-Lab-Codes/doc/Assignments/A4_b1t_Lang/main.cpp), [`common.h`](file:///d:/GitHub/UITS/Compiler-Lab-Codes/doc/Assignments/A4_b1t_Lang/common.h), and [`all.h`](file:///d:/GitHub/UITS/Compiler-Lab-Codes/doc/Assignments/A4_b1t_Lang/all.h), highlighting [`test.cpp`](file:///d:/GitHub/UITS/Compiler-Lab-Codes/doc/Assignments/A4_b1t_Lang/test.cpp) as the consumer template and snippet.

---

## Table of Contents
1. [Executive Summary & Purpose](#1-executive-summary--purpose)
2. [System Architecture & Dependency Graph](#2-system-architecture--dependency-graph)
3. [Detailed Code Breakdown](#3-detailed-code-breakdown)
   - [3.1 test.cpp — Minimal Starter Template & Snippet](#31-testcpp--minimal-starter-template--snippet)
   - [3.2 main.h — Core DSL Engine & Demonstration Harness](#32-mainh--core-dsl-engine--demonstration-harness)
   - [3.3 main.cpp — Interactive Navigation Driver](#33-maincpp--interactive-navigation-driver)
   - [3.4 common.h — Curated Lightweight Standard Library](#34-commonh--curated-lightweight-standard-library)
   - [3.5 all.h — Extended Standard Library & Macro Shielding](#35-allh--extended-standard-library--macro-shielding)
4. [Comparative File Matrix](#4-comparative-file-matrix)
5. [Compiler Pipeline & Language Engineering Highlights](#5-compiler-pipeline--language-engineering-highlights)
6. [Conclusion](#6-conclusion)

---

## 1. Executive Summary & Purpose

The `b1t_Lang` DSL project abstracts complex C++ syntax into a clean, intuitive, and concise language tailored for algorithm design, mathematical problem solving, and competitive programming. Instead of requiring a standalone custom compiler from scratch, `b1t_Lang` uses a **Source-Level Embedded DSL (EDSL)** design. By utilizing the C++ preprocessor (`#define`), C++17 variadic fold expressions, template meta-programming, and inline stream references, `b1t_Lang` achieves clean syntax transformations without sacrificing performance or type safety.

The codebase is structured into five cohesive components designed to ensure modularity, fast compilation, and straightforward consumption:
- **`test.cpp`**: Minimal boilerplate snippet and template for creating new programs.
- **`main.h`**: The central DSL engine, macro repository, and built-in demo harness.
- **`main.cpp`**: Interactive demonstration driver with a two-tier menu state machine.
- **`common.h`**: Lightweight, non-redundant core Standard C++ library header bundle.
- **`all.h`**: Extended standard library collection protected with macro shielding.

---

## 2. System Architecture & Dependency Graph

```
┌────────────────────────────────────────────────────────────────────────┐
│                        b1t_Lang Dependency Flow                        │
├────────────────────────────────────────────────────────────────────────┤
│                                                                        │
│   ┌──────────────────────────────┐    ┌────────────────────────────┐   │
│   │           common.h           │    │           all.h            │   │
│   │   (Curated Core STL: Fast)   │    │  (Extended STL + Shield)   │   │
│   └──────────────┬───────────────┘    └────────────────────────────┘   │
│                  │                                                     │
│                  ▼                                                     │
│   ┌──────────────────────────────┐                                     │
│   │            main.h            │                                     │
│   │   - Keyword Macros           │                                     │
│   │   - Stream Aliases (in, out) │                                     │
│   │   - Fold Expressions         │                                     │
│   │   - Demo Harness             │                                     │
│   └──────────────┬───────────────┘                                     │
│                  │                                                     │
│        ┌─────────┴─────────┐                                           │
│        ▼                   ▼                                           │
│   ┌──────────┐       ┌──────────┐                                      │
│   │ main.cpp │       │ test.cpp │ (Template / Snippet)                 │
│   │ (Driver) │       │ (Starter)│                                      │
│   └──────────┘       └──────────┘                                      │
│                                                                        │
└────────────────────────────────────────────────────────────────────────┘
```

The dependency design adheres to **low coupling and high cohesion**:
1. Neither `main.cpp` nor `test.cpp` directly include raw system headers like `<iostream>` or `<vector>`.
2. Both files include only `"main.h"`, gaining immediate access to the full DSL.
3. `main.h` includes only `common.h` (avoiding the monolithic bloat of `<bits/stdc++.h>`).

---

## 3. Detailed Code Breakdown

### 3.1 `test.cpp` — Minimal Starter Template & Snippet

[`test.cpp`](file:///d:/GitHub/UITS/Compiler-Lab-Codes/doc/Assignments/A4_b1t_Lang/test.cpp) is the **official template and code snippet** for any developer writing software in `b1t_Lang`. It establishes a clean slate containing only the required entry point and fast I/O setup.

#### Source Code
```cpp
#include "main.h"

main {
  detach_C();

  return 0;
}
```

#### Key Technical Roles:
- **Starter Snippet**: Provides the minimum required skeleton for competitive programming or algorithmic script development.
- **Entry Point Abstraction**: Replaces `int main()` with the concise DSL token `main`.
- **Fast I/O Detachment**: Calls `detach_C()` (`ios_base::sync_with_stdio(false); cin.tie(NULL);`) to maximize I/O throughput in automated judge environments.
- **Zero Overhead**: Incurs $\mathcal{O}(1)$ initialization time and $\mathcal{O}(1)$ memory overhead.

---

### 3.2 `main.h` — Core DSL Engine & Demonstration Harness

[`main.h`](file:///d:/GitHub/UITS/Compiler-Lab-Codes/doc/Assignments/A4_b1t_Lang/main.h) is the central foundation of the project. It provides keyword definitions, stream bindings, variadic template math operations, loop macros, and the self-contained demonstration suite.

#### Key Modules in `main.h`:

1. **Computed Includes & Entry Points**:
   ```cpp
   #define common "common.h"
   #include common
   #define all "all.h"
   #define main int main()
   using namespace std;
   ```
2. **Type-Safe Stream References**:
   ```cpp
   inline auto &in = std::cin;
   inline auto &out = std::cout;
   ```
   Uses C++17 `inline` references to prevent linker multiple-definition collisions under the One Definition Rule (ODR).
3. **Loop Macro Abstractions**:
   - `loop(var, start, end, step)`: Exclusive forward iteration ($i < n$).
   - `loop2(var, start, end, step)`: Inclusive forward iteration ($i \le n$).
   - `loopr(var, start, end, step)`: Exclusive reverse iteration ($i > n$).
   - `loop2r(var, start, end, step)`: Inclusive reverse iteration ($i \ge n$).
4. **Variadic Templates & C++17 Fold Expressions**:
   - `sum(args...)`: `(args + ...)`
   - `sub(first, rest...)`: `(first - ... - rest)`
   - `mul(args...)`: `(args * ...)`
   - `divi(...)`: Fold-based division with sequential zero-divisor detection.
   - `mx(...)` and `mn(...)`: Fold expressions over the ternary conditional operator.
5. **Dynamic Vector Overloads**:
   Provides overloaded variants of `sum`, `sub`, `mul`, `divi`, `mx`, and `mn` operating over `std::vector<T>` collections with boundary protection.
6. **Built-in Inspection & Demo Harness**:
   - `show_function_table()`: Renders a structured ASCII catalog displaying all 21 available DSL functions, their signatures, and behaviors.
   - `demo_specific(int id)`: Executes an isolated demonstration for any chosen function ID.
   - `demo_all()`: Runs the comprehensive test suite exercising dynamic vector reductions, loop macros, logic checks, and math operators.

---

### 3.3 `main.cpp` — Interactive Navigation Driver

[`main.cpp`](file:///d:/GitHub/UITS/Compiler-Lab-Codes/doc/Assignments/A4_b1t_Lang/main.cpp) serves as the interactive driver and verification vehicle for the language. To keep the base code minimal, all execution logic is delegated to `main.h`.

#### Source Code Structure
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

#### Key Technical Roles:
- **Two-Tier State Machine**:
  - **Tier 1 (Outer Menu)**: Routes between complete demonstration (`demo_all`), catalog table exploration, and clean shutdown.
  - **Tier 2 (Choice 2 Loop)**: Allows repeated execution of individual functions. Following each execution, it evaluates user input:
    - `1`: Re-displays the function table and stays in the loop for continued profiling.
    - `0`: Exits the inner loop and transitions back to Tier 1, redisplaying Choice 1, 2, and 3.
- **Interactive Stream Synchronization**: Leaves `cin.tie` enabled so that CLI prompts flush immediately before blocking user extractions.

---

### 3.4 `common.h` — Curated Lightweight Standard Library

[`common.h`](file:///d:/GitHub/UITS/Compiler-Lab-Codes/doc/Assignments/A4_b1t_Lang/common.h) solves the problem of header compilation bloat. Instead of pulling in massive monolithic headers, it curates the 15 most frequent standard library headers.

#### Included Facilities:
- **Core I/O & Formatting**: `<iostream>`, `<iomanip>`
- **Sequence Containers**: `<vector>`, `<string>`, `<deque>`
- **Associative & Adapter Containers**: `<map>`, `<set>`, `<queue>`, `<stack>`
- **Algorithms & Mathematics**: `<cmath>`, `<algorithm>`, `<numeric>`
- **Utilities & Types**: `<utility>`, `<climits>`, `<cstdint>`

#### Key Technical Roles:
- **Rapid Compilation**: Drastically cuts down compilation time compared to monolithic headers.
- **Centralized Dependency**: Guarantees that all basic container and algorithm types are consistently available across the entire DSL.

---

### 3.5 `all.h` — Extended Standard Library & Macro Shielding

[`all.h`](file:///d:/GitHub/UITS/Compiler-Lab-Codes/doc/Assignments/A4_b1t_Lang/all.h) provides access to advanced, specialized standard library headers (e.g. `<unordered_map>`, `<sstream>`, `<fstream>`, `<chrono>`, `<thread>`, `<filesystem>`). It is strictly decoupled from `common.h` to prevent duplicate inclusion.

#### Preprocessor Shielding Mechanism
Because `b1t_Lang` defines short macros like `all` and `common`, including standard headers that declare identifiers matching those names (such as `std::filesystem::perms::all`) could lead to syntax errors. `all.h` solves this using compiler macro shielding:

```cpp
#pragma push_macro("all")
#pragma push_macro("common")
#undef all
#undef common

// Include extended standard headers cleanly
#include <unordered_map>
#include <sstream>
#include <filesystem>
// ... other extended headers ...

#pragma pop_macro("common")
#pragma pop_macro("all")
```

#### Key Technical Roles:
- **Extended STL Support**: Provides regex, file systems, concurrency, and hash maps when complex problem domains require them.
- **Macro Hygiene**: Guarantees zero namespace pollution or preprocessor collisions with standard library symbols.

---

## 4. Comparative File Matrix

| File Name | File Type | Primary Purpose | Role in Architecture |
| :--- | :--- | :--- | :--- |
| [`test.cpp`](file:///d:/GitHub/UITS/Compiler-Lab-Codes/doc/Assignments/A4_b1t_Lang/test.cpp) | Source (`.cpp`) | Consumer template / snippet | Starter boilerplate for authoring new algorithms |
| [`main.h`](file:///d:/GitHub/UITS/Compiler-Lab-Codes/doc/Assignments/A4_b1t_Lang/main.h) | Header (`.h`) | Core DSL engine & demo harness | Defines syntax, math operators, loops, and test suites |
| [`main.cpp`](file:///d:/GitHub/UITS/Compiler-Lab-Codes/doc/Assignments/A4_b1t_Lang/main.cpp) | Source (`.cpp`) | Interactive CLI driver | Coordinates menu navigation and function profiling |
| [`common.h`](file:///d:/GitHub/UITS/Compiler-Lab-Codes/doc/Assignments/A4_b1t_Lang/common.h) | Header (`.h`) | Lightweight STL bundle | Core headers for fast, bloat-free compilation |
| [`all.h`](file:///d:/GitHub/UITS/Compiler-Lab-Codes/doc/Assignments/A4_b1t_Lang/all.h) | Header (`.h`) | Extended STL bundle | Specialized headers with preprocessor macro shielding |

---

## 5. Compiler Pipeline & Language Engineering Highlights

1. **Lexical & Preprocessor Substitution Phase**:
   - `b1t_Lang` abstracts keywords at translation phase 4. Tokens like `main`, `loop(...)`, and `common` are expanded prior to semantic analysis.
2. **Template Expansion & Compile-Time Code Generation**:
   - Fold expressions (`args + ...`) generate optimized, linear machine code sequences without recurring function call frames or dynamic heap allocations.
3. **Stream Buffer Lifecycle & Terminal Interactivity**:
   - In competitive environments, `detach_C()` severs stream coupling for raw throughput.
   - In interactive environments, preserving stream ties guarantees that output buffers flush before keyboard inputs block execution.
4. **Strict Memory & Hardware Safety**:
   - Safe division (`divi`) and modulo (`rem`) validate operands to prevent fatal CPU zero-division traps (`SIGFPE`).

---

## 6. Conclusion

The architecture of `b1t_Lang` demonstrates how modern C++ features can be combined with structured preprocessor designs to build a robust, expressive Embedded Domain-Specific Language. By separating core definitions (`main.h`), curated includes (`common.h`, `all.h`), interactive drivers (`main.cpp`), and starter snippets ([`test.cpp`](file:///d:/GitHub/UITS/Compiler-Lab-Codes/doc/Assignments/A4_b1t_Lang/test.cpp)), the project achieves modularity, safety, and ease of use.

