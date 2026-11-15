# Sample Programs: b1t_Lang Custom DSL Loops & Functions

This directory contains standalone sample programs demonstrating how to use the custom preprocessor loop constructs, type-generic mathematical helpers, and dynamic vector overloads provided by [`Project.Compiler/main.h`](file:///d:/GitHub/UITS/Compiler-Lab-Codes/Project.Compiler/main.h).

---

## Table of Contents
1. [Overview of Samples](#1-overview-of-samples)
2. [Compilation & Execution Guide](#2-compilation--execution-guide)
3. [Sample Descriptions](#3-sample-descriptions)
   - [Sample 1: Basic Custom Loops (01_loop_basics.cpp)](#sample-1-basic-custom-loops-01_loop_basicscpp)
   - [Sample 2: Math Series & Vector Reductions (02_loop_math_accumulator.cpp)](#sample-2-math-series--vector-reductions-02_loop_math_accumulatorcpp)
   - [Sample 3: Nested Loops & Matrix Grid (03_nested_loop_grid.cpp)](#sample-3-nested-loops--matrix-grid-03_nested_loop_gridcpp)
4. [Custom Loop Reference Table](#4-custom-loop-reference-table)

---

## 1. Overview of Samples

| File | Primary Focus | Key Functions & Macros Used |
| :--- | :--- | :--- |
| [`01_loop_basics.cpp`](file:///d:/GitHub/UITS/Compiler-Lab-Codes/Project.Compiler/sample/01_loop_basics.cpp) | 4 macro loops, forward & reverse iteration | `loop`, `loop2`, `loopr`, `loop2r`, `sqr`, `cube`, `is_even` |
| [`02_loop_math_accumulator.cpp`](file:///d:/GitHub/UITS/Compiler-Lab-Codes/Project.Compiler/sample/02_loop_math_accumulator.cpp) | Sequence accumulation & vector template reductions | `loop2`, `fact`, `pwr`, `sum_n`, `sum(v)`, `mx(v)`, `mn(v)`, `mul(v)` |
| [`03_nested_loop_grid.cpp`](file:///d:/GitHub/UITS/Compiler-Lab-Codes/Project.Compiler/sample/03_nested_loop_grid.cpp) | Nested 2D loop traversal & matrix formatting | Nested `loop2`, `mul`, `is_eq`, `out` |

---

## 2. Compilation & Execution Guide

All samples can be compiled using GCC with the C++20 standard:

```bash
# Compile Sample 1
g++ -Wall -Wextra -std=c++20 Project.Compiler/sample/01_loop_basics.cpp -o Project.Compiler/sample/01_loop_basics
./Project.Compiler/sample/01_loop_basics

# Compile Sample 2
g++ -Wall -Wextra -std=c++20 Project.Compiler/sample/02_loop_math_accumulator.cpp -o Project.Compiler/sample/02_loop_math_accumulator
./Project.Compiler/sample/02_loop_math_accumulator

# Compile Sample 3
g++ -Wall -Wextra -std=c++20 Project.Compiler/sample/03_nested_loop_grid.cpp -o Project.Compiler/sample/03_nested_loop_grid
./Project.Compiler/sample/03_nested_loop_grid
```

---

## 3. Sample Descriptions

### Sample 1: Basic Custom Loops (`01_loop_basics.cpp`)
Demonstrates all four fundamental loop macros:
- **`loop(i, 0, 5, i++)`**: Forward exclusive loop $[0, 5)$.
- **`loop2(i, 1, 5, i++)`**: Forward inclusive loop $[1, 5]$.
- **`loopr(i, 5, 0, i--)`**: Reverse exclusive loop $(5, 0]$.
- **`loop2r(i, 5, 0, i--)`**: Reverse inclusive loop $[5, 0]$.
Integrated with arithmetic parity checks (`is_even`, `is_odd`) and exponent helpers (`sqr`, `cube`).

### Sample 2: Math Series & Vector Reductions (`02_loop_math_accumulator.cpp`)
Demonstrates gathering statistics across a sequence:
- Accumulates numbers into a `std::vector<int>`.
- Evaluates `fact(i)` and binary exponentiation `pwr(2, i)`.
- Dispatches to vector template overloads: `sum(v)`, `mx(v)`, `mn(v)`, and `mul(v)`.
- Verifies summation against the closed-form Gauss formula `sum_n(n)` using `is_eq`.

### Sample 3: Nested Loops & Matrix Grid (`03_nested_loop_grid.cpp`)
Demonstrates 2D iteration:
- Nests outer row `loop2` with inner column `loop2`.
- Computes element products via variadic `mul(row, col)`.
- Identifies main diagonal squares using `is_eq(row, col)`.

---

## 4. Custom Loop Reference Table

| Macro Signature | Standard C++ Equivalent | Range Classification | Typical Use Case |
| :--- | :--- | :--- | :--- |
| `loop(var, start, end, step)` | `for (int var = (start); (var) < (end); (step))` | Half-open $[start, end)$ | Array & 0-indexed vector traversal |
| `loop2(var, start, end, step)` | `for (int var = (start); (var) <= (end); (step))` | Closed $[start, end]$ | 1-based counting, factorials, math sums |
| `loopr(var, start, end, step)` | `for (int var = (start); (var) > (end); (step))` | Half-open $(start, end]$ | Reverse countdown without 0 |
| `loop2r(var, start, end, step)` | `for (int var = (start); (var) >= (end); (step))` | Closed $[start, end]$ | Reverse countdown down to 0 |
