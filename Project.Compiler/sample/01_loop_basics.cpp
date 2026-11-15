#include "../main.h"

main {
  detach_C();

  out << "====================================================\n";
  out << "  Sample 1: Basic Custom Loops & Helper Functions   \n";
  out << "====================================================\n\n";

  // 1. Forward Exclusive Loop: loop(var, start, end, step) -> [0, 5)
  out << "[1] Forward Exclusive: loop(i, 0, 5, i++)\n";
  out << "    Values: ";
  loop(i, 0, 5, i++) {
    out << i << " ";
  }
  out << "\n\n";

  // 2. Forward Inclusive Loop: loop2(var, start, end, step) -> [1, 5]
  out << "[2] Forward Inclusive: loop2(i, 1, 5, i++)\n";
  out << "    Values and Properties:\n";
  loop2(i, 1, 5, i++) {
    out << "    - i = " << i
        << " | sqr = " << sqr(i)
        << " | cube = " << cube(i)
        << " | " << (is_even(i) ? "EVEN" : "ODD")
        << "\n";
  }
  out << "\n";

  // 3. Reverse Exclusive Loop: loopr(var, start, end, step) -> (5, 0]
  out << "[3] Reverse Exclusive: loopr(i, 5, 0, i--)\n";
  out << "    Values: ";
  loopr(i, 5, 0, i--) {
    out << i << " ";
  }
  out << "\n\n";

  // 4. Reverse Inclusive Loop: loop2r(var, start, end, step) -> [5, 0]
  out << "[4] Reverse Inclusive: loop2r(i, 5, 0, i--)\n";
  out << "    Values: ";
  loop2r(i, 5, 0, i--) {
    out << i << " ";
  }
  out << "\n";
  out << "====================================================\n";

  return 0;
}

/*
================================================================================
Theory Summary & Algorithmic Notes (Ref: doc/Assignments/learning/A4_theory.md)
================================================================================
- Problem: Demonstration of custom preprocessor-defined loop syntax and
  integrated type-generic helper functions within the b1t_Lang DSL.
- Technique:
  1. Token Replacement Loops:
     - loop(var, s, e, step)  -> for (int var = (s); (var) < (e); (step))
     - loop2(var, s, e, step) -> for (int var = (s); (var) <= (e); (step))
     - loopr(var, s, e, step) -> for (int var = (s); (var) > (e); (step))
     - loop2r(var, s, e, step)-> for (int var = (s); (var) >= (e); (step))
  2. Type-Generic Arithmetic Helpers: sqr(i), cube(i), is_even(i), is_odd(i).
  3. Stream Aliasing: Utilizing 'out' and 'detach_C()' for fast, safe I/O.
- Complexity:
  * Time: O(N) linear iteration across bounded loop ranges.
  * Space: O(1) auxiliary stack memory.
- Edge Cases & Safety:
  * Parenthesized macro arguments prevent precedence hijacking: (var) < (end).
  * Strict loop bounds prevent off-by-one boundary overruns.
================================================================================
*/
