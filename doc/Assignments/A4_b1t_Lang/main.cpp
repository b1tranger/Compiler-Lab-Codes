#include "main.h"

main {
  // detach_C(); // Note: cin.tie(NULL) suppresses automatic cout buffer
  // flushing before in >>. In interactive CLI mode, omit detach_C() so prompts
  // display before waiting for user input.

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
  out << "JOG Hocche: " << sum(nums) << endl;
  out << "BIYOG Hocche: " << sub(nums) << endl;
  out << "GUN Hocche: " << mul(nums) << endl;
  out << "VAG Hocche: " << divi(nums) << endl;
  out << "MAX Hocche: " << mx(nums) << endl;
  out << "MIN Hocche: " << mn(nums) << endl;

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

  return 0;
}

/*
================================================================================
Theory Summary & Algorithmic Notes (Ref: doc/Assignments/learning/A4_theory.md)
================================================================================
- Problem: Demonstrate custom C++ DSL (b1t_Lang) syntax abstractions, including
  stream aliasing (in/out), loop macros, variadic fold operations, and dynamic
  vector math operations.
- Technique:
  1. Stream Management & Interactive I/O: C++ ties std::cin to std::cout by
     default so that output buffers are automatically flushed before blocking
input extractions. detach_C() breaks this tie via cin.tie(NULL), which is
optimal for non-interactive competitive programming but causes un-flushed
interactive prompts to buffer until after input.
  2. Variadic Math & Fold Expressions: C++17 fold expressions expand operations
     over parameter packs at compile time.
  3. Safe Vector Calculations: Dynamic vector overloads provide bounds-checked,
     zero-division guarded reductions across arbitrary-sized collections.
- Complexity:
  * Time: O(N) for vector reductions; O(log N) for binary exponentiation pwr().
  * Space: O(N) auxiliary space for vector storage of user inputs.
- Edge Cases & Safety:
  * Zero-division guarded in divi() and rem().
  * Negative exponent handling in binary exponentiation pwr().
  * Prompt buffering: In interactive mode, keeping cin tied to cout guarantees
    immediate console display of input prompts.
================================================================================
*/
