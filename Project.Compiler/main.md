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
