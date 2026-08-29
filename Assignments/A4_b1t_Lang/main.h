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

#endif // MAIN_H
