# Compiler Design & Construction Lab (`Compiler-Lab-Codes`)

Course repository containing lab codes, term assignments, language implementations, and theoretical documentation for the **Compiler Design & Construction Lab** course at the **University of Information Technology and Sciences (UITS)**.

## Table of Contents
1. [Overview](#overview)
2. [Project Directory Structure](#project-directory-structure)
3. [Lab Codes Index](#lab-codes-index)
4. [Assignments Index](#assignments-index)
5. [Environment Setup & Toolchain](#environment-setup--toolchain)
   - [C++ Compilation](#c-compilation)
   - [C Compilation](#c-compilation-1)
   - [Python Scripts](#python-scripts)
6. [Theory Notes & Learning Resources](#theory-notes--learning-resources)
7. [Agent Guidelines](#agent-guidelines)

---

## Overview

This repository documents hands-on implementations and theoretical explorations covering the phases of compiler construction:
- **Lexical Analysis (Scanning)**: Token identification, lexemes, whitespace/comment stripping (single-line `//` & multi-line `/* ... */`), symbol tables, and identifier recognition.
- **Regular Expressions & Automata**: Deterministic (DFA) and Non-Deterministic (NFA) Finite Automata state machine models.
- **Syntax Analysis (Parsing)**: Context-Free Grammars (CFGs), recursive descent parsing, and predictive parsing tables.
- **Custom DSL & Compiler Projects**: Full-pipeline custom language and DSL engineering (e.g. `A4_b1t_Lang` Banglish Compiler).
- **Core Languages**: C, C++ (C++20), and Python 3.

---

## Project Directory Structure

```
Compiler-Lab-Codes/
├── .vscode/                               # VS Code workspace settings
├── .gitattributes                         # Git line-ending normalization
├── .gitignore                             # Ignored build outputs and caches
├── AGENTS.md                              # Agent development & documentation rules
├── README.md                              # Project documentation and navigation
├── Lab_Codes/                             # Lab exercise source code
│   ├── 1.1.c, 1.1-alt.c, 1.2.cpp          # Basic I/O & character frequency
│   ├── 2.1.cpp                            # Comment recognition & string scanning
│   ├── 4.1.cpp                            # Identifier validation
│   ├── 5.Header_File/                     # Modular C++ header & source files
│   ├── 6.1.cpp                            # Lexical tokenization & classification
│   ├── ANKUR_lexical analysis_16-8-26.c   # Lexical analyzer implementation
│   └── learning/                          # Lab theory documentation
│       ├── 1-cpp-environment-setup.md     # Toolchain & environment guide
│       ├── 2-theory.md                    # Comment parsing & string reading
│       ├── 3-theory.md                    # String library functions in compilers
│       ├── 4-theory.md                    # Identifier classification rules
│       └── 5-theory.md                    # Header files & arithmetic handling
└── doc/
    ├── Assignments/                       # Coursework assignments & submissions
    │   ├── A1/                            # Assignment 1: Anagrams & char counts
    │   ├── A2/                            # Assignment 2: Lexical classification
    │   ├── A3/                            # Assignment 3: Token recognition & CFG
    │   ├── A4_b1t_Lang/                   # Custom Banglish Compiler project
    │   ├── A5/                            # Assignment 5
    │   ├── Courtesy/                      # Reference implementations
    │   ├── backup/                        # Temporary scripts and backups
    │   └── learning/                      # Assignment theory notes
    │       ├── A1.2_theory.md             # Character frequencies
    │       ├── A1.3_theory.md             # Group Anagrams algorithm
    │       ├── A2.2_theory.md             # DFA state machines
    │       ├── A3.1_theory.md             # String operations & grammar rules
    │       ├── A3.3-3.5_theory.md         # Advanced lexical tokens
    │       └── A4_theory.md               # Custom compiler architecture
    └── prompts/                           # Interactive prompt and chat history
        ├── 1. A1.3.md
        ├── 2. A1.2.md
        ├── 3. 2.md
        ├── 4. A4_b1t_Lang.md
        └── recovered_chats/               # Recovered interaction sessions
```

---

## Lab Codes Index

| Lab | Source Files | Description | Theory Note |
| :--- | :--- | :--- | :--- |
| **Lab 1** | [`1.1.c`](file:///d:/GitHub/UITS/Compiler-Lab-Codes/Lab_Codes/1.1.c), [`1.2.cpp`](file:///d:/GitHub/UITS/Compiler-Lab-Codes/Lab_Codes/1.2.cpp) | Character counting & basic string I/O | [`1-cpp-environment-setup.md`](file:///d:/GitHub/UITS/Compiler-Lab-Codes/Lab_Codes/learning/1-cpp-environment-setup.md) |
| **Lab 2** | [`2.1.cpp`](file:///d:/GitHub/UITS/Compiler-Lab-Codes/Lab_Codes/2.1.cpp) | Comment classification (`//` and `/* ... */`) | [`2-theory.md`](file:///d:/GitHub/UITS/Compiler-Lab-Codes/Lab_Codes/learning/2-theory.md) |
| **Lab 3** | — | String processing functions in C/C++/Python | [`3-theory.md`](file:///d:/GitHub/UITS/Compiler-Lab-Codes/Lab_Codes/learning/3-theory.md) |
| **Lab 4** | [`4.1.cpp`](file:///d:/GitHub/UITS/Compiler-Lab-Codes/Lab_Codes/4.1.cpp) | Identifier validation and naming rules | [`4-theory.md`](file:///d:/GitHub/UITS/Compiler-Lab-Codes/Lab_Codes/learning/4-theory.md) |
| **Lab 5** | [`5.Header_File/`](file:///d:/GitHub/UITS/Compiler-Lab-Codes/Lab_Codes/5.Header_File/) | Modular C++ compilation using `.h` & `.cpp` | [`5-theory.md`](file:///d:/GitHub/UITS/Compiler-Lab-Codes/Lab_Codes/learning/5-theory.md) |
| **Lab 6** | [`6.1.cpp`](file:///d:/GitHub/UITS/Compiler-Lab-Codes/Lab_Codes/6.1.cpp) | Multi-token lexical analyzer & tokenizer | — |

---

## Assignments Index

| Assignment | Directory | Core Topic | Documentation |
| :--- | :--- | :--- | :--- |
| **A1** | [`doc/Assignments/A1/`](file:///d:/GitHub/UITS/Compiler-Lab-Codes/doc/Assignments/A1/) | Group Anagrams & Character Frequency | [`A1.2_theory.md`](file:///d:/GitHub/UITS/Compiler-Lab-Codes/doc/Assignments/learning/A1.2_theory.md), [`A1.3_theory.md`](file:///d:/GitHub/UITS/Compiler-Lab-Codes/doc/Assignments/learning/A1.3_theory.md) |
| **A2** | [`doc/Assignments/A2/`](file:///d:/GitHub/UITS/Compiler-Lab-Codes/doc/Assignments/A2/) | Lexical classification & DFA modeling | [`A2.2_theory.md`](file:///d:/GitHub/UITS/Compiler-Lab-Codes/doc/Assignments/learning/A2.2_theory.md) |
| **A3** | [`doc/Assignments/A3/`](file:///d:/GitHub/UITS/Compiler-Lab-Codes/doc/Assignments/A3/) | Multi-token parsing & CFG production rules | [`A3.1_theory.md`](file:///d:/GitHub/UITS/Compiler-Lab-Codes/doc/Assignments/learning/A3.1_theory.md), [`A3.3-3.5_theory.md`](file:///d:/GitHub/UITS/Compiler-Lab-Codes/doc/Assignments/learning/A3.3-3.5_theory.md) |
| **A4** | [`doc/Assignments/A4_b1t_Lang/`](file:///d:/GitHub/UITS/Compiler-Lab-Codes/doc/Assignments/A4_b1t_Lang/) | `b1t_Lang` Custom Banglish Compiler project | [`A4_theory.md`](file:///d:/GitHub/UITS/Compiler-Lab-Codes/doc/Assignments/learning/A4_theory.md), [`README.md`](file:///d:/GitHub/UITS/Compiler-Lab-Codes/doc/Assignments/A4_b1t_Lang/README.md) |
| **A5** | [`doc/Assignments/A5/`](file:///d:/GitHub/UITS/Compiler-Lab-Codes/doc/Assignments/A5/) | Upcoming term coursework | — |

---

## Environment Setup & Toolchain

Detailed system toolchain instructions are available in [`Lab_Codes/learning/1-cpp-environment-setup.md`](file:///d:/GitHub/UITS/Compiler-Lab-Codes/Lab_Codes/learning/1-cpp-environment-setup.md).

### C++ Compilation
```bash
# Compile with C++20 standard and strict diagnostic warnings
g++ -Wall -Wextra -std=c++20 Lab_Codes/2.1.cpp -o Lab_Codes/2.1
./Lab_Codes/2.1
```

### C Compilation
```bash
gcc -Wall -Wextra -std=c17 Lab_Codes/1.1.c -o Lab_Codes/1.1
./Lab_Codes/1.1
```

### Python Scripts
```bash
python doc/Assignments/A1/A1.3.py
```

---

## Theory Notes & Learning Resources
Theory notes are split into two organized collections:
1. **Lab Practice Theory**: [`Lab_Codes/learning/`](file:///d:/GitHub/UITS/Compiler-Lab-Codes/Lab_Codes/learning/)
2. **Assignment Theory**: [`doc/Assignments/learning/`](file:///d:/GitHub/UITS/Compiler-Lab-Codes/doc/Assignments/learning/)

All theory notes include runnable code snippets across C, C++, and Python, algorithm traces, and edge-case analyses.

---

## Agent Guidelines
AI assistants and agents contributing to this codebase must adhere to the rules outlined in [`AGENTS.md`](file:///d:/GitHub/UITS/Compiler-Lab-Codes/AGENTS.md), including:
- Automatic theory note generation upon discussing lab problems.
- Mandatory clickable Table of Contents (TOC) on all documentation files.
- Conversation and prompt archiving under `doc/prompts/`.
- Safe memory handling and compiler diagnostic standards.
