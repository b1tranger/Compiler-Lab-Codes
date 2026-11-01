#include "main.h"

main {
  // detach_C(); // Note: cin.tie(NULL) suppresses automatic cout buffer
  // flushing before in >>. In interactive CLI mode, omit detach_C() so prompts
  // display before waiting for user input.

  int choice;
  while (true) {
    out << "\n==========================================" << endl;
    out << "     b1t_Lang Custom DSL Demonstration    " << endl;
    out << "==========================================" << endl;
    out << "1. Show all function usage" << endl;
    out << "2. See specific function usage from table" << endl;
    out << "3. Exit" << endl;
    out << "Enter your choice (1-3): ";

    if (!(in >> choice)) {
      in.clear();
      in.ignore(numeric_limits<streamsize>::max(), '\n');
      break;
    }

    if (choice == 1) {
      demo_all();
    } else if (choice == 2) {
      show_function_table();
      while (true) {
        out << "\nEnter function number (1-21) to demo (or 0 to go back): ";
        int func_id;
        if (!(in >> func_id)) {
          in.clear();
          in.ignore(numeric_limits<streamsize>::max(), '\n');
          break;
        }
        if (func_id == 0) {
          break; // Return to main menu
        }

        demo_specific(func_id);

        out << "\nPress '0' to go back, '1' to see the table: ";
        int sub_choice;
        while (true) {
          if (!(in >> sub_choice)) {
            in.clear();
            in.ignore(numeric_limits<streamsize>::max(), '\n');
            sub_choice = 0;
            break;
          }
          if (sub_choice == 0 || sub_choice == 1) {
            break;
          }
          out << "Invalid input! Press '0' to go back, '1' to see the table: ";
        }

        if (sub_choice == 0) {
          break; // Exit choice 2 loop -> displays choice 1 main menu again
        } else if (sub_choice == 1) {
          show_function_table();
        }
      }
    } else if (choice == 3) {
      out << "Exiting b1t_Lang Demonstration. Goodbye!" << endl;
      break;
    } else {
      out << "Invalid choice! Please choose 1, 2, or 3." << endl;
    }
  }

  return 0;
}

/*
================================================================================
Theory Summary & Algorithmic Notes (Ref: doc/Assignments/learning/A4_theory.md)
================================================================================
- Problem: Interactive driver program for b1t_Lang custom DSL, providing a
  minimal console menu to demonstrate all language abstractions or inspect
  individual functions interactively from a catalog table.
- Technique:
  1. Modular Architecture: Heavy DSL implementation logic and demo harnesses
     are isolated in main.h, keeping main.cpp minimal and focused on CLI flow.
  2. Interactive Menu Navigation: Two-tier state loop supporting complete DSL
     evaluation (Choice 1), table-driven single-function profiling (Choice 2),
     and repeat testing with standard back (0) and inspect (1) commands.
  3. Interactive Stream Synchronization: Default stream ties (cin tied to cout)
     are preserved to ensure synchronous prompt rendering without buffering lags.
- Complexity:
  * Time: O(1) menu dispatch; O(N) for vector calculations; O(log N) for pwr().
  * Space: O(1) auxiliary space for menu state; O(N) for vector test buffers.
- Edge Cases & Safety:
  * Stream extraction validation prevents infinite loops on EOF or invalid types.
  * Sub-menu input validation guards against out-of-range navigation codes.
================================================================================
*/
