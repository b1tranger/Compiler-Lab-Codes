#include "../main.h"

main {
  detach_C();

  out << "====================================================\n";
  out << " Sample 3: Nested Loops & Multiplication Matrix     \n";
  out << "====================================================\n\n";

  int size = 5;

  out << "Multiplication Grid (" << size << "x" << size << "):\n\n";

  // Header row
  out << "   * |";
  loop2(col, 1, size, col++) {
    out << "   " << col;
  }
  out << "\n-----+";
  loop2(col, 1, size, col++) {
    out << "----";
  }
  out << "\n";

  // Nested loop traversal: Outer loop represents rows, inner loop represents columns
  loop2(row, 1, size, row++) {
    out << "   " << row << " |";
    loop2(col, 1, size, col++) {
      int product = mul(row, col);

      // Highlight diagonal elements using is_eq helper
      if (is_eq(row, col)) {
        // Diagonal element (square)
        out << " [" << (product < 10 ? " " : "") << product << "]";
      } else {
        out << "  " << (product < 10 ? " " : "") << product << " ";
      }
    }
    out << "\n";
  }

  out << "\nLegend: [x] denotes main diagonal squares (row == col).\n";
  out << "====================================================\n";

  return 0;
}

/*
================================================================================
Theory Summary & Algorithmic Notes (Ref: doc/Assignments/learning/A4_theory.md)
================================================================================
- Problem: Construct 2D arithmetic multiplication grid using nested custom
  preprocessor loop constructs and b1t_Lang mathematical helpers.
- Technique:
  1. Nested Macro Loops: loop2(row, 1, size, row++) nesting loop2(col, 1, size, col++).
  2. Variadic Multiplication: mul(row, col) evaluating product.
  3. Diagonal Matrix Identification: is_eq(row, col) identifying perfect squares.
- Complexity:
  * Time: O(R * C) where R = rows, C = columns.
  * Space: O(1) auxiliary stack space.
- Edge Cases & Safety:
  * Proper identifier scoping across nested loop variables (row vs col).
  * Safe formatted spacing for single vs double-digit values.
================================================================================
*/
