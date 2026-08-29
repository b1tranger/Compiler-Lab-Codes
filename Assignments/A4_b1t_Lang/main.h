#include <bits/stdc++.h>
#include "common.h"
#include "all.h"

#define all "all.h"
#define common "common.h"

#define main int main()
using namespace std;

// --- Fast I/O: Detach C Standard Streams from C++ Streams ---
inline void detach_C() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}

// --- I/O Streams Aliasing ---
auto &in = std::cin;
auto &out = std::cout;

// --- Custom Loop Macros ---
// Forward Loops (Incrementing)
#define loop(var, start, end, step)       for (int var = (start); (var) < (end); (step))
#define loop2(var, start, end, step)      for (int var = (start); (var) <= (end); (step))

// Reverse Loops (Decrementing)
#define loopr(var, start, end, step)      for (int var = (start); (var) > (end); (step))
#define loop2r(var, start, end, step)     for (int var = (start); (var) >= (end); (step))

// ============================================================================
// 1. VARIADIC TEMPLATE ARITHMETIC (Method 1: Fold Expressions)
// ============================================================================

// SUM: (args + ...)
template <typename... Args> auto sum(Args... args) { return (args + ...); }

// SUB: (first - rest1 - rest2 ...)
template <typename T, typename... Args> auto sub(T first, Args... rest) {
  return (first - ... - rest);
}

// MUL: (args * ...)
template <typename... Args> auto mul(Args... args) { return (args * ...); }

// DIV: Sequential division with 0-checking
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

// ============================================================================
// 2. VARIADIC MAX & MIN (Fold Expressions for multiple variables)
// ============================================================================

// MAX: Finds maximum across any number of arguments
template <typename T, typename... Args>
constexpr auto mx(T first, Args... rest) {
  auto res = first;
  ((res = (rest > res ? rest : res)), ...);
  return res;
}

// MIN: Finds minimum across any number of arguments
template <typename T, typename... Args>
constexpr auto mn(T first, Args... rest) {
  auto res = first;
  ((res = (rest < res ? rest : res)), ...);
  return res;
}

// ============================================================================
// 3. ADDITIONAL MATH & UTILITY FUNCTIONS
// ============================================================================

// MODULO / REMAINDER: a % b with zero checking
inline int rem(int a, int b) {
  if (b == 0) {
    cout << "Modulo of 0 --> Invalid" << endl;
    return 0;
  }
  return a % b;
}

// POWER: base^exp (handles positive, zero, and negative exponents)
inline double pwr(double base, int exp) {
  double res = 1.0;
  long long p = exp;
  if (p < 0) {
    base = 1.0 / base;
    p = -p;
  }
  while (p > 0) {
    if (p & 1) res *= base;
    base *= base;
    p >>= 1;
  }
  return res;
}

// SQUARE: x * x
template <typename T> inline auto sqr(T x) { return x * x; }

// CUBE: x * x * x
template <typename T> inline auto cube(T x) { return x * x * x; }

// ABSOLUTE VALUE: |x|
template <typename T> inline auto abs_val(T x) { return (x < 0) ? -x : x; }

// FACTORIAL: n!
inline long long fact(int n) {
  if (n < 0) {
    cout << "Factorial of negative number --> Invalid" << endl;
    return 0;
  }
  long long res = 1;
  for (int i = 1; i <= n; ++i) res *= i;
  return res;
}

// SUM FROM 1 TO N: 1 + 2 + ... + n
inline long long sum_n(int n) {
  if (n <= 0) return 0;
  return (1LL * n * (n + 1)) / 2;
}

// EVEN CHECK: true if even
inline bool is_even(long long n) { return (n % 2 == 0); }

// ODD CHECK: true if odd
inline bool is_odd(long long n) { return (n % 2 != 0); }

// POSITIVE CHECK: true if > 0
inline bool is_pos(double n) { return n > 0; }

// NEGATIVE CHECK: true if < 0
inline bool is_neg(double n) { return n < 0; }

// EQUALITY CHECK: true if a == b
template <typename T1, typename T2> inline bool is_eq(T1 a, T2 b) {
  return a == b;
}

// SWAP: swaps values between two variables by reference
template <typename T> inline void swp(T &a, T &b) {
  T temp = a;
  a = b;
  b = temp;
}

// ============================================================================
// 4. OVERLOADS FOR DYNAMIC VECTOR INPUTS (Runtime Loops)
// ============================================================================

template <typename T> T sum(const vector<T> &v) {
  if (v.empty()) return 0;
  T total = 0;
  for (const auto &x : v) total += x;
  return total;
}

template <typename T> T sub(const vector<T> &v) {
  if (v.empty()) return 0;
  T res = v[0];
  for (size_t i = 1; i < v.size(); ++i) res -= v[i];
  return res;
}

template <typename T> T mul(const vector<T> &v) {
  if (v.empty()) return 0;
  T total = 1;
  for (const auto &x : v) total *= x;
  return total;
}

template <typename T> double divi(const vector<T> &v) {
  if (v.empty()) return 0.0;
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

template <typename T> T mx(const vector<T> &v) {
  if (v.empty()) return 0;
  T m = v[0];
  for (const auto &x : v) if (x > m) m = x;
  return m;
}

template <typename T> T mn(const vector<T> &v) {
  if (v.empty()) return 0;
  T m = v[0];
  for (const auto &x : v) if (x < m) m = x;
  return m;
}
