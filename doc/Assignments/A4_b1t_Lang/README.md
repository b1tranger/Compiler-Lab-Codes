# `b1t_Lang` — Custom C++ Domain-Specific Language (Assignment 4)

`b1t_Lang` is an expressive C++ Domain-Specific Language (DSL) and syntax abstraction engine designed for competitive programming, algorithm scripting, and mathematical computing. It simplifies C++ syntax through preprocessor keyword aliasing, type-safe stream binding, variadic fold expressions, custom loop macros, and optimized dynamic vector calculators.

---

## 📂 Project Architecture

```
Assignments/A4_b1t_Lang/
├── common.h       # Curated lightweight Standard C++ Library (<iostream>, <vector>, etc.)
├── all.h          # Extended Standard C++ Library (shielded with pragma push/pop_macro)
├── main.h         # Core DSL Engine: macros, stream aliases, math & vector functions
├── main.cpp       # Demonstration program exercising all DSL features
└── README.md      # Project documentation & API reference
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
│   │             main.h             │   (Core DSL Engine & Math Library) │
│   └───────────────┬────────────────┘                                    │
│                   │                                                     │
│                   ▼                                                     │
│   ┌────────────────────────────────┐                                    │
│   │            main.cpp            │   (Consumer Program)               │
│   └────────────────────────────────┘                                    │
│                                                                         │
└─────────────────────────────────────────────────────────────────────────┘
```

1. **`common.h`**: Loads curated everyday standard headers (`<iostream>`, `<vector>`, `<string>`, `<cmath>`, `<algorithm>`, `<numeric>`, `<iomanip>`, `<map>`, `<set>`, `<queue>`, `<stack>`, `<deque>`, `<utility>`, `<climits>`, `<cstdint>`).
2. **`all.h`**: Loads extended standard headers without duplicating `common.h`. Employs `#pragma push_macro` / `#pragma pop_macro` to shield STL symbols (such as `std::filesystem::perms::all`) from macro collisions.
3. **`main.h`**: The central DSL engine. Depends **only** on `common.h`, preventing compilation bloat.
4. **`main.cpp`**: The user application. Requires only `#include "main.h"`.

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
| **Math & Powers** | `pwr(base, exp)` | `std::pow(base, exp)` | $O(\log n)$ Fast Binary Exponentiation |
| | `sqr(x)` | `(x * x)` | Square of a number ($x^2$) |
| | `cube(x)` | `(x * x * x)` | Cube of a number ($x^3$) |
| | `abs_val(x)` | `std::abs(x)` | Absolute value ($\|x\|$) |
| | `fact(n)` | Factorial loop | Factorial ($n!$) with negative protection |
| | `sum_n(n)` | $\frac{n(n+1)}{2}$ | $O(1)$ Gauss sum of $1 \dots n$ with 64-bit guard |
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

## 💻 Example Usage (`main.cpp`)

```cpp
#include "main.h"

main {
  detach_C();

  int count;
  out << "How many numbers do you want to calculate? ";
  in >> count;

  if (count <= 0) {
    out << "Invalid count! Please enter a number > 0." << endl;
    return 0;
  }

  vector<double> nums(count);
  loop(i, 0, count, i++) {
    out << "Enter number " << (i + 1) << ": ";
    in >> nums[i];
  }

  out << "\n--- Calculation Results (From Dynamic Input) ---" << endl;
  out << "Sum: " << sum(nums) << endl;
  out << "Sub: " << sub(nums) << endl;
  out << "Mul: " << mul(nums) << endl;
  out << "Div: " << divi(nums) << endl;
  out << "Max: " << mx(nums) << endl;
  out << "Min: " << mn(nums) << endl;

  // Variadic operations
  out << "Variadic Max (10, 45, 22, 99, 5): " << mx(10, 45, 22, 99, 5) << endl;
  out << "Power 2^5: " << pwr(2, 5) << endl;
  out << "Sum 1 to 10: " << sum_n(10) << endl;

  int a = 10, b = 20;
  swp(a, b);
  out << "Swapped a: " << a << ", b: " << b << endl;

  return 0;
}
```

---

## 🚀 Compilation & Running

### Requirements
- A standard C++17 compliant compiler (`g++`, `clang++`, or MSVC).

### Commands

```bash
# Navigate to the assignment folder
cd Assignments/A4_b1t_Lang

# Compile with C++17 support
g++ -std=c++17 -Wall main.cpp -o main.exe

# Run the executable
./main.exe
```

---

## 🧠 Technical Highlights

1. **C++17 Fold Expressions**: Variadic math (`sum`, `sub`, `mul`, `divi`, `mx`, `mn`) unfolds at compile-time with zero runtime function call overhead.
2. **Zero-Division Safety**: Division and modulo functions inspect divisor values before CPU execution, preventing fatal hardware exceptions (SIGFPE).
3. **Macro Hygiene & Shielding**: Short macros like `all` are temporarily isolated with `#pragma push_macro` and `#pragma pop_macro` in `all.h` to prevent corrupting internal STL tokens like `std::filesystem::perms::all`.
4. **One Definition Rule (ODR) Compliance**: Stream references use `inline auto &in = std::cin;` in headers to allow safe multi-file inclusion without linker collisions.
5. **Decoupled Architecture**: `main.h` only includes curated headers (`common.h`), eliminating compile-time bloat from monolithic headers like `<bits/stdc++.h>`.
