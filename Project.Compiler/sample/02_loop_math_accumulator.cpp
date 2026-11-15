#include "../main.h"

main {
  detach_C();

  out << "====================================================\n";
  out << " Sample 2: Mathematical Series & Vector Reductions  \n";
  out << "====================================================\n\n";

  int n = 6;
  vector<int> numbers;
  long long iterative_sum = 0;

  out << "Iterating from 1 to " << n << " and gathering statistics:\n";
  loop2(i, 1, n, i++) {
    numbers.push_back(i);
    iterative_sum = sum(iterative_sum, i); // Variadic sum(a, b)

    out << "  Step " << i << ":"
        << " fact(" << i << ") = " << fact(i)
        << " | pwr(2, " << i << ") = " << pwr(2, i)
        << " | running sum = " << iterative_sum
        << "\n";
  }

  out << "\n--- Vector Template Reductions ---\n";
  out << "Vector Elements   : ";
  loop(idx, 0, static_cast<int>(numbers.size()), idx++) {
    out << numbers[idx] << " ";
  }
  out << "\n";

  // Vector reductions defined in main.h
  out << "Vector Sum (sum(v))     : " << sum(numbers) << "\n";
  out << "Gauss Formula sum_n(" << n << ") : " << sum_n(n) << "\n";
  out << "Verification (is_eq)    : "
      << (is_eq(sum(numbers), sum_n(n)) ? "MATCH" : "MISMATCH") << "\n";
  out << "Vector Max (mx(v))      : " << mx(numbers) << "\n";
  out << "Vector Min (mn(v))      : " << mn(numbers) << "\n";
  out << "Vector Product (mul(v)) : " << mul(numbers) << "\n";

  out << "====================================================\n";

  return 0;
}

/*
================================================================================
Theory Summary & Algorithmic Notes (Ref: doc/Assignments/learning/A4_theory.md)
================================================================================
- Problem: Accumulate mathematical sequences using b1t_Lang loops and compare
  scalar fold reductions against dynamic vector overloads.
- Technique:
  1. Forward Inclusive Loop: loop2(i, 1, n, i++) for [1, N] sequence progression.
  2. Iterative Function Calls: fact(i), pwr(2, i), and variadic sum(acc, x).
  3. Dynamic Vector Overload Resolution: Automatic dispatch to container-based
     sum(const vector<T>&), mx(const vector<T>&), and mul(const vector<T>&).
  4. Closed-form Validation: Cross-verifying loop sum against sum_n(n) via is_eq.
- Complexity:
  * Time: O(N) linear iteration for vector collection and reductions.
  * Space: O(N) dynamic storage for vector elements.
- Edge Cases & Safety:
  * Safe exponentiation handling in pwr() via binary exponentiation.
  * Safe boundary checks preventing out-of-bounds in vector reductions.
================================================================================
*/
