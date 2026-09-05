# Agent Guidelines: Compiler Design & Construction Lab

## Table of Contents
1. [Purpose & Academic Context](#purpose--academic-context)
2. [Repository Architecture & File Map](#repository-architecture--file-map)
3. [Theory Note Generation & Update Rules](#theory-note-generation--update-rules)
   - [1. File Naming & Destination](#1-file-naming--destination)
   - [2. Automatic Updates](#2-automatic-updates)
   - [3. Mandatory Table of Contents (TOC)](#3-mandatory-table-of-contents-toc)
4. [Content & Technical Formatting Standards](#content--technical-formatting-standards)
   - [1. Compiler Pipeline & Algorithmic Explanations](#1-compiler-pipeline--algorithmic-explanations)
   - [2. Polyglot Comparative Implementations (C, C++, Python)](#2-polyglot-comparative-implementations-c-c-python)
   - [3. Transition Diagrams, State Tables & Visuals](#3-transition-diagrams-state-tables--visuals)
   - [4. Edge Cases, Input Streams & Memory Safety](#4-edge-cases-input-streams--memory-safety)
   - [5. Modular C++ Architecture & Header Standards](#5-modular-c-architecture--header-standards)
5. [Build, Toolchain & Execution Standards](#build-toolchain--execution-standards)
6. [Conversation & Prompt Archiving Guidelines (`doc/prompts/`)](#6-conversation--prompt-archiving-guidelines-docprompts)
   - [1. Destination & Naming](#1-destination--naming)
   - [2. Session Metadata Header](#2-session-metadata-header)
   - [3. Standard Archive Structure](#3-standard-archive-structure)
   - [4. Automatic Archiving Trigger](#4-automatic-archiving-trigger)

---

## Purpose & Academic Context
This document defines operational guidelines for autonomous agents analyzing, authoring, debugging, or documenting source code and theory notes for the **Compiler Design & Construction Lab** (`Compiler-Lab-Codes`) at the University of Information Technology and Sciences (UITS).

The coursework covers the standard compiler front-end and back-end pipeline:
- **Lexical Analysis (Scanning)**: Tokenization, lexeme recognition, comment stripping (single-line `//` vs. multi-line `/* ... */`), identifier validation, keyword lookup tables, and symbol tables.
- **Automata & Pattern Matching**: Regular expressions, Deterministic Finite Automata (DFA), Non-Deterministic Finite Automata (NFA), and state transition matrices.
- **Syntax Analysis (Parsing)**: Context-Free Grammars (CFGs), ambiguity resolution, recursive descent parsers, predictive LL(1) parsers, and LR parsing tables.
- **Abstract Syntax Trees (AST) & Semantic Evaluation**: Expression trees, syntax-directed translation, operator precedence, and type checking.
- **Custom DSL Development**: Developing domain-specific languages (e.g., Banglish compiler project `A4_b1t_Lang`).
- **Core Languages**: **C**, **C++ (C++20/C++23)**, and **Python 3**.

---

## Repository Architecture & File Map

The workspace is structured into dedicated operational directories:

```
Compiler-Lab-Codes/
├── .vscode/                               # Workspace configuration
├── AGENTS.md                              # Agent instructions & curriculum standards
├── README.md                              # Repository overview and guide
├── Lab_Codes/                             # Weekly lab experiments & exercises
│   ├── 1.1.c, 1.2.cpp, 2.1.cpp, etc.     # Lab source implementations
│   ├── 5.Header_File/                     # Modular C++ header & source split
│   │   ├── new.h                          # Custom header declarations & functions
│   │   └── new.cpp                        # Driver implementation
│   └── learning/                          # Lab theory documentation
│       ├── 1-cpp-environment-setup.md     # Toolchain & compiler setup
│       ├── 2-theory.md                    # String reading & comment parsing
│       ├── 3-theory.md                    # String functions in compiler design
│       ├── 4-theory.md                    # Identifier classification
│       └── 5-theory.md                    # Header files & stream handling
└── doc/
    ├── Assignments/                       # Official term assignments & submissions
    │   ├── A1/                            # Assignment 1 (Anagrams, Char frequency)
    │   ├── A2/                            # Assignment 2 (Lexical classification)
    │   ├── A3/                            # Assignment 3 (Token recognition, CFGs)
    │   ├── A4_b1t_Lang/                   # Custom Banglish Compiler project
    │   ├── A5/                            # Assignment 5 (Future coursework)
    │   ├── Courtesy/                      # Reference implementations
    │   ├── backup/                        # Scratch scripts & temporary backups
    │   └── learning/                      # Dedicated assignment theory notes
    │       ├── A1.2_theory.md             # Character counting & frequencies
    │       ├── A1.3_theory.md             # Anagram grouping algorithms
    │       ├── A2.2_theory.md             # DFA state machine models
    │       ├── A3.1_theory.md             # String operations & grammar rules
    │       ├── A3.3-3.5_theory.md         # Advanced lexical tokens
    │       └── A4_theory.md               # Custom compiler architecture
    └── prompts/                           # Chronological prompt & session transcripts
        ├── 1. A1.3.md
        ├── 2. A1.2.md
        ├── 3. 2.md
        ├── 4. A4_b1t_Lang.md
        └── recovered_chats/               # Recovered interaction logs
```

---

## Theory Note Generation & Update Rules

### 1. File Naming & Destination
* **Lab Exercises**: Save theory notes in [`Lab_Codes/learning/`](file:///d:/GitHub/UITS/Compiler-Lab-Codes/Lab_Codes/learning/).
  - Convention: `<LabNumber>-theory.md` (e.g., `2-theory.md`, `3-theory.md`, `6-theory.md`).
  - Toolchain/General Setup: `<topic>-setup.md` or `<topic>-guide.md` (e.g., `1-cpp-environment-setup.md`).
* **Assignments**: Save theory notes in [`doc/Assignments/learning/`](file:///d:/GitHub/UITS/Compiler-Lab-Codes/doc/Assignments/learning/).
  - Convention: `<AssignmentID>_theory.md` (e.g., `A1.2_theory.md`, `A3.3-3.5_theory.md`, `A4_theory.md`).

### 2. Automatic Updates
* Whenever new compiler concepts, algorithmic improvements, debugging explanations, or parsing problems are discussed in a session:
  - Immediately update the corresponding theory markdown file.
  - Preserve all existing content, appending new topics with sequential numbering (`## N. <Topic Title>`) or refining relevant existing sub-sections.

### 3. Mandatory Table of Contents (TOC)
* **Every theory and documentation file added or modified** (including all files in `Lab_Codes/learning/`, `doc/Assignments/learning/`, `doc/prompts/`, `README.md`, and `AGENTS.md`) **MUST include a clickable Table of Contents at the top**, placed immediately after the introductory summary block.
* TOC Requirements:
  - List all primary (`##`) and secondary (`###`) sections using GitHub Flavored Markdown anchor links (e.g. `[1. Overview](#1-overview)`).
  - Synchronize anchor links dynamically whenever sections are added, renamed, or restructured.

---

## Content & Technical Formatting Standards

Follow the format, depth, and presentation demonstrated in [`Lab_Codes/learning/2-theory.md`](file:///d:/GitHub/UITS/Compiler-Lab-Codes/Lab_Codes/learning/2-theory.md), [`Lab_Codes/learning/3-theory.md`](file:///d:/GitHub/UITS/Compiler-Lab-Codes/Lab_Codes/learning/3-theory.md), and [`doc/Assignments/learning/A4_theory.md`](file:///d:/GitHub/UITS/Compiler-Lab-Codes/doc/Assignments/learning/A4_theory.md):

### 1. Compiler Pipeline & Algorithmic Explanations
- **Phase Mapping**: State which phase of the compiler the topic belongs to (Lexical, Syntactic, Semantic, AST/IR, Code Gen, Optimization).
- **Formal Grammar / Definitions**: Provide regular expressions, Context-Free Grammar (CFG) production rules, or Backus-Naur Form (BNF/EBNF) definitions where appropriate.
- **Algorithm Complexity**: Detail the time and space complexity (e.g., $\mathcal{O}(N)$ scanning vs $\mathcal{O}(N^2)$ brute-force substring search).

### 2. Polyglot Comparative Implementations (C, C++, Python)
Whenever introducing string operations, comment filtering, tokenizers, or identifier validation, provide cross-language comparative analysis:
- Provide equivalent, working code snippets for **C**, **C++**, and **Python**.
- Include a Markdown summary table comparing standard functions, method signatures, and behavior differences (e.g. `fgets()` vs `getline()` vs `input()`).

### 3. Transition Diagrams, State Tables & Visuals
- Use ASCII or Mermaid state diagrams for Finite State Automata (DFA/NFA):
  ```mermaid
  stateDiagram-v2
      [*] --> Start
      Start --> Slash : '/'
      Slash --> SingleLine : '/'
      Slash --> MultiLine : '*'
      MultiLine --> StarFound : '*'
      StarFound --> EndComment : '/'
      EndComment --> [*]
  ```
- Include DFA state transition tables mapping States $\times$ Character Classes $\rightarrow$ Next States.

### 4. Edge Cases, Input Streams & Memory Safety
- Highlight critical string & stream pitfalls:
  - Whitespace truncation with `scanf("%s")` or `cin >> str` versus preserving whitespace with `fgets()` or `getline(cin, str)`.
  - Buffer overflow risks (`strcpy` / `strcat` vs `strncpy` / `strncat`).
  - Off-by-one errors when checking boundary characters (`str[size - 1]`, `str[size - 2]`).
  - Missing EOF or newline stripping (`strcspn(str, "\n")`).

### 5. Modular C++ Architecture & Header Standards
- When modularizing C++ compiler components (e.g., Lexer, Parser, Symbol Table):
  - Use `#pragma once` (or standard include guards) in all `.h` header files.
  - Keep definitions separated: declarations in `.h` and implementations in `.cpp`.
  - Avoid putting `using namespace std;` in public header files.

---

## Build, Toolchain & Execution Standards

The development environment utilizes modern C/C++ and Python toolchains:

### 1. Compiling C++
```bash
# Recommended command for C++ files (C++20 standard with strict warnings)
g++ -Wall -Wextra -std=c++20 Lab_Codes/<file>.cpp -o Lab_Codes/<output_name>
./Lab_Codes/<output_name>

# Modular compilation (multiple files or custom headers)
g++ -Wall -Wextra -std=c++20 Lab_Codes/5.Header_File/new.cpp -o Lab_Codes/5.Header_File/new
```

### 2. Compiling C
```bash
gcc -Wall -Wextra -std=c17 Lab_Codes/<file>.c -o Lab_Codes/<output_name>
./Lab_Codes/<output_name>
```

### 3. Running Python
```bash
python doc/Assignments/A1/A1.3.py
```

### 4. Clean Build Practice
- Never commit binary outputs (`.exe`, `.o`, `.out`), editor caches (`.vscode/`, `desktop.ini`), or temporary crash logs to git.
- Keep output binaries in local directories and ensure `.gitignore` patterns remain active.

---

## 6. Conversation & Prompt Archiving Guidelines (`doc/prompts/`)

To preserve debugging journeys, algorithmic reasoning, and interactive sessions across development turns:

### 1. Destination & Naming
* **Target Directory**: [`doc/prompts/`](file:///d:/GitHub/UITS/Compiler-Lab-Codes/doc/prompts/)
* **Naming Convention**: `<index>. <Assignment_or_Lab_Topic>.md`
  - Example: `1. A1.3.md`
  - Example: `2. A1.2.md`
  - Example: `3. 2.md`
  - Example: `4. A4_b1t_Lang.md`
  - Example: `5. Lexical_Token_Classification.md`

### 2. Session Metadata Header
Every archived prompt record must start with standard metadata:
```markdown
# Part N: <Topic Description> (<Target File>)

- **Conversation ID**: `<conversation-id>`
- **Timestamp**: `<YYYY-MM-DDTHH:MM:SS+Offset>`
- **Model**: `<Model Name>`
- **Target File**: [`<filename>`](file:///path/to/file)
```

### 3. Standard Archive Structure
Each entry must include:
1. **`## 1. User Request`**: Exact user input, prompt, and contextual IDE metadata (active file, line range).
2. **`## 2. Code Inspected / Modified`**: Relevant diff blocks or source snippets before and after changes.
3. **`## 3. Analysis & Key Insights`**: Compiler concept breakdown, lexical/parsing grammar insights, bug analysis, or algorithmic proof.
4. **`## 4. Final Solution & Output`**: Verified source code, compilation commands, and test outputs.

### 4. Automatic Archiving Trigger
* Automatically archive or append to `doc/prompts/` whenever a complete debugging sequence, project milestone, or major theoretical discussion concludes.
