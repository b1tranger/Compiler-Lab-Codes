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
   - [6. Mandatory Source Code Theory Summary Footers](#6-mandatory-source-code-theory-summary-footers)
5. [Build, Toolchain & Execution Standards](#build-toolchain--execution-standards)
6. [Conversation & Prompt Archiving Guidelines (`doc/prompts/`)](#6-conversation--prompt-archiving-guidelines-docprompts)
   - [1. Destination & Serial Folder Naming](#1-destination--serial-folder-naming)
   - [2. Required Files Inside Each Session Folder](#2-required-files-inside-each-session-folder)
   - [3. Summary Markdown Format (`summary.md`)](#3-summary-markdown-format-summarymd)
   - [4. Update Cadence (Keeping the Archive Current)](#4-update-cadence-keeping-the-archive-current)

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
│   ├── 8.ValidateMathExpression/          # Infix mathematical expression validation
│   │   ├── 8.1.cpp                        # Lab implementation
│   │   └── 8.1_alt.cpp                    # Canonical corrected implementation
│   └── learning/                          # Lab theory documentation
│       ├── 1-cpp-environment-setup.md     # Toolchain & compiler setup
│       ├── 2-theory.md                    # String reading & comment parsing
│       ├── 3-theory.md                    # String functions in compiler design
│       ├── 4-theory.md                    # Identifier classification
│       ├── 5-theory.md                    # Header files & stream handling
│       └── 8-theory.md                    # Mathematical expression validation & CFG
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

### 6. Mandatory Source Code Theory Summary Footers
- **Requirement**: Every newly added or modified source code file (`.c`, `.cpp`, `.py`) across the workspace (including `Lab_Codes/`, `doc/Assignments/`, and `doc/Assignments/Courtesy/`) **MUST include a standardized explanatory comment block at the very bottom** of the file summarizing the concepts from its corresponding theory documentation.
- **Content Requirements**:
  1. **Problem Statement**: Brief, clear description of the computational or compiler task.
  2. **Core Technique / Algorithm**: Data structures, automata, or language constructs utilized.
  3. **Complexity Profile**: Asymptotic time and auxiliary space bounds ($\mathcal{O}$).
  4. **Edge Cases & Pitfalls**: Buffer safety, overflow protection, character domains, or stream delimiters.
  5. **Theory Documentation Link**: Markdown link referencing the authoritative theory note in `learning/`.
- **Standard Format**:
  - **C / C++ (`.c`, `.cpp`)**:
    ```cpp
    /*
    ================================================================================
    Theory Summary & Algorithmic Notes (Ref: doc/Assignments/learning/<TheoryNote>.md)
    ================================================================================
    - Problem: <Task description>
    - Technique: <Core algorithm, lookup table, or CFG rule>
      1. <Step 1 mechanics>
      2. <Step 2 mechanics>
    - Complexity:
      * Time: O(...)
      * Space: O(...)
    - Edge Cases & Safety:
      * <Key boundary or overflow considerations>
    ================================================================================
    */
    ```
  - **Python (`.py`)**:
    ```python
    """
    ================================================================================
    Theory Summary & Algorithmic Notes (Ref: doc/Assignments/learning/<TheoryNote>.md)
    ================================================================================
    - Problem: <Task description>
    - Technique: <Core data structure or method>
    - Complexity: Time O(...), Space O(...)
    ================================================================================
    """
    ```

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

To preserve debugging journeys, algorithmic reasoning, and interactive sessions verbatim across development turns:

### 1. Destination & Serial Folder Naming
* **Target Directory**: [`doc/prompts/`](file:///d:/GitHub/UITS/Compiler-Lab-Codes/doc/prompts/)
* **Serial Session Folder Convention**: `doc/prompts/<N>. <Session Title>/`
  - Example: `doc/prompts/13. Lexical_Token_Classification/`
* **Determining `<N>`**: Inspect `doc/prompts/` to find the highest existing major integer prefix across both existing session folders and legacy flat `<N>. ...md` files, and assign `N = N_max + 1` for a new conversation session.
* **Session Continuity**: Always update **the same session folder** across turns or when resuming a conversation; do NOT create a new major folder per turn.

### 2. Required Files Inside Each Session Folder
Inside `doc/prompts/<N>. <Session Title>/`:
1. **`transcript_full.jsonl`**: An exact, unmodified UTF-8 copy of `<appDataDir>/brain/<conversation-id>/.system_generated/logs/transcript_full.jsonl`. Never truncate, edit, or reformat lines in `transcript_full.jsonl`.
2. **`conversation.md`**: A verbatim Markdown rendering generated directly from `transcript_full.jsonl`, including **every step exactly** without summarizing or omitting content: metadata (`Conversation ID`, `Session Folder`, `Continued From` if applicable), all `USER_INPUT.content`, all `PLANNER_RESPONSE.thinking` verbatim, all `PLANNER_RESPONSE.tool_calls` and tool/system outputs (`GENERIC` / `SYSTEM_MESSAGE`), and all `PLANNER_RESPONSE.content` verbatim.
3. **`summary.md` (Conversation Summary Markdown)**: Maintained alongside `transcript_full.jsonl` and `conversation.md` in the same folder (including a clickable Table of Contents at the top per repo rules).
4. **Companion Plans & Walkthroughs (Optional, Fractional Suffixes)**: Stored in the same folder as `<N>.1 Implementation Plan - <Plan Title>.md` and `<N>.2 Walkthrough - <Title>.md` if generated.

### 3. Summary Markdown Format (`summary.md`)
Include a clickable Table of Contents, session metadata, and concise structured sections:
```markdown
# <N>. <Session Title>

- **Conversation ID**: `<conversation-id>`
- **Timestamp**: `<YYYY-MM-DDTHH:MM:SS+Offset>`
- **Model**: `<Model Name>`
- **Target File**: [`<filename>`](file:///path/to/file)

## 1. User Request Summary
## 2. Code Inspected / Modified
## 3. Analysis & Key Insights
## 4. Final Solution & Outcomes
```

### 4. Update Cadence (Keeping the Archive Current)
Because the runtime writes a turn's final `PLANNER_RESPONSE` (final `thinking` and `content`) to `transcript_full.jsonl` after the turn finishes:
1. **At the start of each turn (or when continuing from a prior `<conversation-id>`):** Copy `<appDataDir>/brain/<conversation-id>/.system_generated/logs/transcript_full.jsonl` to `doc/prompts/<N>. <Session Title>/transcript_full.jsonl` and regenerate `conversation.md` so the previous turn's finalized `thinking` and `content` are captured verbatim (and sync the prior conversation's folder if continuing).
2. **Before sending each new final response:** Re-copy `transcript_full.jsonl`, regenerate `conversation.md` to capture all completed steps of the current turn, append the exact final response under `## Pending Final Response (Pre-Commit)` (noting it will be replaced verbatim from `transcript_full.jsonl` on the next sync), and create or update `summary.md` in the same folder.
