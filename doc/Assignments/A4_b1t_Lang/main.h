#ifndef MAIN_H
#define MAIN_H
#define common "common.h"

#include common

#define all "all.h"

#define main int main()
using namespace std;

// detach_C
inline void detach_C() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}

// in, out
inline auto &in = std::cin;
inline auto &out = std::cout;

// loop, loop2, loopr, loop2r
#define loop(var, start, end, step)                                            \
  for (int var = (start); (var) < (end); (step))
#define loop2(var, start, end, step)                                           \
  for (int var = (start); (var) <= (end); (step))
#define loopr(var, start, end, step)                                           \
  for (int var = (start); (var) > (end); (step))
#define loop2r(var, start, end, step)                                          \
  for (int var = (start); (var) >= (end); (step))

// sum
template <typename... Args> auto sum(Args... args) { return (args + ...); }

// sub
template <typename T, typename... Args> auto sub(T first, Args... rest) {
  return (first - ... - rest);
}

// mul
template <typename... Args> auto mul(Args... args) { return (args * ...); }

// divi
template <typename T, typename... Args> auto divi(T first, Args... rest) {
  auto res = static_cast<double>(first);
  bool has_zero = false;

  auto divide_one = [&](auto val) {
    if (val == 0) {
      has_zero = true;
    } else if (!has_zero) {
      res /= val;
    }
  };

  (divide_one(rest), ...);

  if (has_zero) {
    cout << "Division of 0 --> Invalid" << endl;
    return 0.0;
  }
  return res;
}

// mx
template <typename T, typename... Args>
constexpr auto mx(T first, Args... rest) {
  auto res = first;
  ((res = (rest > res ? rest : res)), ...);
  return res;
}

// mn
template <typename T, typename... Args>
constexpr auto mn(T first, Args... rest) {
  auto res = first;
  ((res = (rest < res ? rest : res)), ...);
  return res;
}

// rem
inline int rem(int a, int b) {
  if (b == 0) {
    cout << "Modulo of 0 --> Invalid" << endl;
    return 0;
  }
  return a % b;
}

// pwr
inline double pwr(double base, int exp) {
  double res = 1.0;
  long long p = exp;
  if (p < 0) {
    base = 1.0 / base;
    p = -p;
  }
  while (p > 0) {
    if (p & 1)
      res *= base;
    base *= base;
    p >>= 1;
  }
  return res;
}

// sqr
template <typename T> inline auto sqr(T x) { return x * x; }

// cube
template <typename T> inline auto cube(T x) { return x * x * x; }

// abs_val
template <typename T> inline auto abs_val(T x) { return (x < 0) ? -x : x; }

// fact
inline long long fact(int n) {
  if (n < 0) {
    cout << "Factorial of negative number --> Invalid" << endl;
    return 0;
  }
  long long res = 1;
  for (int i = 1; i <= n; ++i)
    res *= i;
  return res;
}

// sum_n
inline long long sum_n(int n) {
  if (n <= 0)
    return 0;
  return (1LL * n * (n + 1)) / 2;
}

// is_even
inline bool is_even(long long n) { return (n % 2 == 0); }

// is_odd
inline bool is_odd(long long n) { return (n % 2 != 0); }

// is_pos
inline bool is_pos(double n) { return n > 0; }

// is_neg
inline bool is_neg(double n) { return n < 0; }

// is_eq
template <typename T1, typename T2> inline bool is_eq(T1 a, T2 b) {
  return a == b;
}

// swp
template <typename T> inline void swp(T &a, T &b) {
  T temp = a;
  a = b;
  b = temp;
}

// sum (vector)
template <typename T> T sum(const vector<T> &v) {
  if (v.empty())
    return 0;
  T total = 0;
  for (const auto &x : v)
    total += x;
  return total;
}

// sub (vector)
template <typename T> T sub(const vector<T> &v) {
  if (v.empty())
    return 0;
  T res = v[0];
  for (size_t i = 1; i < v.size(); ++i)
    res -= v[i];
  return res;
}

// mul (vector)
template <typename T> T mul(const vector<T> &v) {
  if (v.empty())
    return 0;
  T total = 1;
  for (const auto &x : v)
    total *= x;
  return total;
}

// divi (vector)
template <typename T> double divi(const vector<T> &v) {
  if (v.empty())
    return 0.0;
  double res = static_cast<double>(v[0]);
  for (size_t i = 1; i < v.size(); ++i) {
    if (v[i] == 0) {
      cout << "Division of 0 --> Invalid" << endl;
      return 0.0;
    }
    res /= v[i];
  }
  return res;
}

// mx (vector)
template <typename T> T mx(const vector<T> &v) {
  if (v.empty())
    return 0;
  T m = v[0];
  for (const auto &x : v)
    if (x > m)
      m = x;
  return m;
}

// mn (vector)
template <typename T> T mn(const vector<T> &v) {
  if (v.empty())
    return 0;
  T m = v[0];
  for (const auto &x : v)
    if (x < m)
      m = x;
  return m;
}

// ============================================================================
// Demonstration & Inspection Harness for b1t_Lang DSL
// ============================================================================

// Display formatted catalog of all available DSL functions
inline void show_function_table() {
  out << "\n+-----+-------------------------------+----------------------------"
         "----------------+\n";
  out << "| No. | Function / Macro Name         | Description                  "
         "              |\n";
  out << "+-----+-------------------------------+------------------------------"
         "--------------+\n";
  out << "|  1  | sum(...) / sum(vector)        | Variadic & dynamic vector "
         "summation        |\n";
  out << "|  2  | sub(...) / sub(vector)        | Variadic & dynamic vector "
         "subtraction      |\n";
  out << "|  3  | mul(...) / mul(vector)        | Variadic & dynamic vector "
         "multiplication   |\n";
  out << "|  4  | divi(...) / divi(vector)      | Variadic & vector safe "
         "division (no div 0) |\n";
  out << "|  5  | mx(...) / mx(vector)          | Maximum element (variadic & "
         "vector)        |\n";
  out << "|  6  | mn(...) / mn(vector)          | Minimum element (variadic & "
         "vector)        |\n";
  out << "|  7  | rem(a, b)                     | Safe modulo / remainder "
         "(checks b == 0)    |\n";
  out << "|  8  | pwr(base, exp)                | Power via binary "
         "exponentiation O(log N)   |\n";
  out << "|  9  | sqr(x)                        | Square of a number (x * x)   "
         "              |\n";
  out << "| 10  | cube(x)                       | Cube of a number (x * x * x) "
         "              |\n";
  out << "| 11  | abs_val(x)                    | Absolute value (|x|)         "
         "              |\n";
  out << "| 12  | fact(n)                       | Factorial of n (n!)          "
         "              |\n";
  out << "| 13  | sum_n(n)                      | Sum of 1 to N via Gauss "
         "formula O(1)       |\n";
  out << "| 14  | is_even(n)                    | Boolean check if number is "
         "even            |\n";
  out << "| 15  | is_odd(n)                     | Boolean check if number is "
         "odd             |\n";
  out << "| 16  | is_pos(n)                     | Boolean check if number is "
         "positive (> 0)  |\n";
  out << "| 17  | is_neg(n)                     | Boolean check if number is "
         "negative (< 0)  |\n";
  out << "| 18  | is_eq(a, b)                   | Equality check between two "
         "values          |\n";
  out << "| 19  | swp(a, b)                     | In-place reference swap of "
         "two variables   |\n";
  out << "| 20  | loop / loop2 / loopr / loop2r | Custom preprocessor for-loop "
         "constructs    |\n";
  out << "| 21  | detach_C / in / out           | Fast I/O & type-safe stream "
         "aliases        |\n";
  out << "+-----+-------------------------------+------------------------------"
         "--------------+\n";
}

// Demonstrate a specific function by its table ID
inline void demo_specific(int id) {
  out << "\n------------------------------------------------------------\n";
  switch (id) {
  case 1: {
    out << "[1] sum(...) / sum(vector)\n";
    out << "  - Variadic: sum(10, 20, 30, 40) = " << sum(10, 20, 30, 40)
        << "\n";
    vector<double> v = {10.5, 20.5, 30.0};
    out << "  - Vector {10.5, 20.5, 30.0}: sum(v) = " << sum(v) << "\n";
    break;
  }
  case 2: {
    out << "[2] sub(...) / sub(vector)\n";
    out << "  - Variadic: sub(100, 20, 15) = " << sub(100, 20, 15) << "\n";
    vector<double> v = {100.0, 30.0, 20.0};
    out << "  - Vector {100.0, 30.0, 20.0}: sub(v) = " << sub(v) << "\n";
    break;
  }
  case 3: {
    out << "[3] mul(...) / mul(vector)\n";
    out << "  - Variadic: mul(2, 3, 4, 5) = " << mul(2, 3, 4, 5) << "\n";
    vector<double> v = {2.5, 4.0, 3.0};
    out << "  - Vector {2.5, 4.0, 3.0}: mul(v) = " << mul(v) << "\n";
    break;
  }
  case 4: {
    out << "[4] divi(...) / divi(vector)\n";
    out << "  - Variadic: divi(100, 2, 5) = " << divi(100, 2, 5) << "\n";
    out << "  - Zero-Division Guard: divi(100, 0, 5) -> ";
    double z = divi(100, 0, 5);
    out << "Returned: " << z << "\n";
    vector<double> v = {100.0, 2.0, 5.0};
    out << "  - Vector {100.0, 2.0, 5.0}: divi(v) = " << divi(v) << "\n";
    break;
  }
  case 5: {
    out << "[5] mx(...) / mx(vector)\n";
    out << "  - Variadic: mx(10, 45, 22, 99, 5) = " << mx(10, 45, 22, 99, 5)
        << "\n";
    vector<int> v = {14, 88, 3, 91, 55};
    out << "  - Vector {14, 88, 3, 91, 55}: mx(v) = " << mx(v) << "\n";
    break;
  }
  case 6: {
    out << "[6] mn(...) / mn(vector)\n";
    out << "  - Variadic: mn(10, 45, 22, 99, 5) = " << mn(10, 45, 22, 99, 5)
        << "\n";
    vector<int> v = {14, 88, 3, 91, 55};
    out << "  - Vector {14, 88, 3, 91, 55}: mn(v) = " << mn(v) << "\n";
    break;
  }
  case 7: {
    out << "[7] rem(a, b)\n";
    out << "  - Valid Modulo: rem(17, 5) = " << rem(17, 5) << "\n";
    out << "  - Zero Guard: rem(17, 0) -> ";
    int r = rem(17, 0);
    out << "Returned: " << r << "\n";
    break;
  }
  case 8: {
    out << "[8] pwr(base, exp)\n";
    out << "  - Positive Exp: pwr(2, 5) = " << pwr(2, 5) << "\n";
    out << "  - Zero Exp: pwr(5, 0) = " << pwr(5, 0) << "\n";
    out << "  - Negative Exp: pwr(2, -3) = " << pwr(2, -3) << "\n";
    break;
  }
  case 9: {
    out << "[9] sqr(x)\n";
    out << "  - Integer: sqr(6) = " << sqr(6) << "\n";
    out << "  - Floating-point: sqr(3.5) = " << sqr(3.5) << "\n";
    break;
  }
  case 10: {
    out << "[10] cube(x)\n";
    out << "  - Integer: cube(3) = " << cube(3) << "\n";
    out << "  - Floating-point: cube(2.5) = " << cube(2.5) << "\n";
    break;
  }
  case 11: {
    out << "[11] abs_val(x)\n";
    out << "  - Negative Input: abs_val(-15) = " << abs_val(-15) << "\n";
    out << "  - Positive Input: abs_val(23.4) = " << abs_val(23.4) << "\n";
    break;
  }
  case 12: {
    out << "[12] fact(n)\n";
    out << "  - Valid Input: fact(5) = " << fact(5) << "\n";
    out << "  - Negative Guard: fact(-3) -> ";
    long long f = fact(-3);
    out << "Returned: " << f << "\n";
    break;
  }
  case 13: {
    out << "[13] sum_n(n)\n";
    out << "  - Gauss Formula O(1): sum_n(10) = " << sum_n(10) << "\n";
    out << "  - Large Input: sum_n(100) = " << sum_n(100) << "\n";
    break;
  }
  case 14: {
    out << "[14] is_even(n)\n";
    out << "  - is_even(8): " << (is_even(8) ? "True" : "False") << "\n";
    out << "  - is_even(7): " << (is_even(7) ? "True" : "False") << "\n";
    break;
  }
  case 15: {
    out << "[15] is_odd(n)\n";
    out << "  - is_odd(7): " << (is_odd(7) ? "True" : "False") << "\n";
    out << "  - is_odd(8): " << (is_odd(8) ? "True" : "False") << "\n";
    break;
  }
  case 16: {
    out << "[16] is_pos(n)\n";
    out << "  - is_pos(5): " << (is_pos(5) ? "True" : "False") << "\n";
    out << "  - is_pos(-3): " << (is_pos(-3) ? "True" : "False") << "\n";
    break;
  }
  case 17: {
    out << "[17] is_neg(n)\n";
    out << "  - is_neg(-3): " << (is_neg(-3) ? "True" : "False") << "\n";
    out << "  - is_neg(5): " << (is_neg(5) ? "True" : "False") << "\n";
    break;
  }
  case 18: {
    out << "[18] is_eq(a, b)\n";
    out << "  - is_eq(10, 10): " << (is_eq(10, 10) ? "True" : "False") << "\n";
    out << "  - is_eq(10, 20): " << (is_eq(10, 20) ? "True" : "False") << "\n";
    break;
  }
  case 19: {
    out << "[19] swp(a, b)\n";
    int a = 10, b = 20;
    out << "  - Before Swap: a = " << a << ", b = " << b << "\n";
    swp(a, b);
    out << "  - After swp(a, b): a = " << a << ", b = " << b << "\n";
    break;
  }
  case 20: {
    out << "[20] loop / loop2 / loopr / loop2r\n";
    out << "  - loop(i, 0, 3, i++): ";
    loop(i, 0, 3, i++) { out << i << " "; }
    out << "\n  - loop2(i, 0, 3, i++): ";
    loop2(i, 0, 3, i++) { out << i << " "; }
    out << "\n  - loopr(i, 3, 0, i--): ";
    loopr(i, 3, 0, i--) { out << i << " "; }
    out << "\n  - loop2r(i, 3, 0, i--): ";
    loop2r(i, 3, 0, i--) { out << i << " "; }
    out << "\n";
    break;
  }
  case 21: {
    out << "[21] detach_C() / in / out\n";
    out << "  - Stream Aliasing: 'in' aliases std::cin, 'out' aliases "
           "std::cout.\n";
    out << "  - detach_C(): Unties std::cin and std::cout for fast competitive "
           "programming I/O.\n";
    out << "    (In interactive CLI mode, keeping streams tied guarantees "
           "instant prompt flushing!)\n";
    break;
  }
  default:
    out << "Invalid function ID: " << id
        << ". Please choose between 1 and 21.\n";
    break;
  }
  out << "------------------------------------------------------------\n";
}

// Run the complete demonstration of all defined functions
inline void demo_all() {
  out << "\n============================================================\n";
  out << "           Complete b1t_Lang DSL Demonstration              \n";
  out << "============================================================\n";

  int count = 0;
  out << "How many numbers do you want to calculate? ";
  if (in >> count && count > 0) {
    vector<double> nums(count);
    loop(i, 0, count, i++) {
      out << "Enter number " << (i + 1) << ": ";
      in >> nums[i];
    }

    out << "\n--- Calculation Results (From Dynamic Input) ---" << endl;
    out << "JOG Hocche: " << sum(nums) << endl;
    out << "BIYOG Hocche: " << sub(nums) << endl;
    out << "GUN Hocche: " << mul(nums) << endl;
    out << "VAG Hocche: " << divi(nums) << endl;
    out << "MAX Hocche: " << mx(nums) << endl;
    out << "MIN Hocche: " << mn(nums) << endl;
  } else {
    out << "Skipping interactive vector input (invalid or <= 0). Running "
           "default vector demo {10, 20, 5, 2}:"
        << endl;
    in.clear();
    in.ignore(numeric_limits<streamsize>::max(), '\n');
    vector<double> nums = {10, 20, 5, 2};
    out << "JOG Hocche: " << sum(nums) << endl;
    out << "BIYOG Hocche: " << sub(nums) << endl;
    out << "GUN Hocche: " << mul(nums) << endl;
    out << "VAG Hocche: " << divi(nums) << endl;
    out << "MAX Hocche: " << mx(nums) << endl;
    out << "MIN Hocche: " << mn(nums) << endl;
  }

  out << "\n--- Additional DSL Function Demonstrations ---" << endl;
  out << "Variadic Max mx(10, 45, 22, 99, 5): " << mx(10, 45, 22, 99, 5)
      << endl;
  out << "Variadic Min mn(10, 45, 22, 99, 5): " << mn(10, 45, 22, 99, 5)
      << endl;
  out << "Modulo rem(17, 5): " << rem(17, 5) << endl;
  out << "Power pwr(2, 5): " << pwr(2, 5) << endl;
  out << "Square sqr(6): " << sqr(6) << endl;
  out << "Cube cube(3): " << cube(3) << endl;
  out << "Absolute abs_val(-15): " << abs_val(-15) << endl;
  out << "Factorial fact(5): " << fact(5) << endl;
  out << "Sum 1 to 10 sum_n(10): " << sum_n(10) << endl;
  out << "Is 8 Even is_even(8): " << (is_even(8) ? "True" : "False") << endl;
  out << "Is 7 Odd is_odd(7): " << (is_odd(7) ? "True" : "False") << endl;
  out << "Is 5 Positive is_pos(5): " << (is_pos(5) ? "True" : "False") << endl;
  out << "Is -3 Negative is_neg(-3): " << (is_neg(-3) ? "True" : "False")
      << endl;
  out << "Is Equal is_eq(10, 10): " << (is_eq(10, 10) ? "True" : "False")
      << endl;

  int a = 10, b = 20;
  swp(a, b);
  out << "Swap swp(10, 20) -> a: " << a << ", b: " << b << endl;

  out << "\n--- Custom Loop Constructs ---" << endl;
  out << "Forward exclusive loop(i, 0, 4, i++): ";
  loop(i, 0, 4, i++) { out << i << " "; }
  out << "\nForward inclusive loop2(i, 0, 4, i++): ";
  loop2(i, 0, 4, i++) { out << i << " "; }
  out << "\nReverse exclusive loopr(i, 4, 0, i--): ";
  loopr(i, 4, 0, i--) { out << i << " "; }
  out << "\nReverse inclusive loop2r(i, 4, 0, i--): ";
  loop2r(i, 4, 0, i--) { out << i << " "; }
  out << endl;
  out << "============================================================\n";
}

#endif // MAIN_H

/*
================================================================================
Theory Summary & Algorithmic Notes (Ref: doc/Assignments/learning/A4_theory.md)
================================================================================
- Problem: Core engine, syntax abstraction library, and comprehensive demo
  harness for the b1t_Lang custom C++ Domain-Specific Language (DSL).
- Technique:
  1. Preprocessor Aliasing & Macros: Token substitutions for entry points (main)
     and flexible loop constructs (loop, loop2, loopr, loop2r).
  2. Variadic Templates & Fold Expressions: C++17 fold expressions over comma
     and binary arithmetic operators for arbitrary-length argument reduction.
  3. Safe Mathematical Reductions: Bounds-checked dynamic vector operations with
     integrated division-by-zero guards and fast O(log N) binary exponentiation.
  4. Inspection Harness: Formatted ASCII function catalog (show_function_table),
     individual function profiling (demo_specific), and full language test suite
     (demo_all).
- Complexity:
  * Time: O(1) to O(N) depending on operation; O(log N) for binary
exponentiation.
  * Space: O(1) auxiliary memory for scalar fold operations; O(N) for vectors.
- Edge Cases & Safety:
  * Zero-division protection in scalar divi(), vector divi(), and rem().
  * Negative exponent handling in pwr().
  * Negative argument validation in fact() and sum_n().
================================================================================
*/
