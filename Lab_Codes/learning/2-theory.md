# Compiler Lab Theory Notes (`2-theory.md`)

This document collects and summarizes key programming concepts, algorithms, data structures, and compiler design topics discussed during chat sessions. Entries are arranged in numeric sequence, with related and similar topics updated dynamically under their respective sections.

## Table of Contents
1. [Reading String Inputs with Spaces & Comment Classification (C, C++, Python)](#1-reading-string-inputs-with-spaces--comment-classification-c-c-python)
   - [Overview](#overview)
   - [Key Concepts & Pitfalls](#key-concepts--pitfalls)
   - [Language Comparison & Input Functions](#language-comparison--input-functions)
   - [Code Examples](#code-examples)
     - [1. C++ Solution (Handling Spaces & Comments)](#1-c-solution-handling-spaces--comments)
     - [2. C++ Multi-Line Stream Processing (Reading Spanning Lines)](#2-c-multi-line-stream-processing-reading-spanning-lines)
     - [3. C Implementation](#3-c-implementation)
     - [4. Python Implementation](#4-python-implementation)

---

## 1. Reading String Inputs with Spaces & Comment Classification (C, C++, Python)

### Overview
In compiler design (lexical analysis), checking whether an input line is a single-line comment (`// ...`) or a multi-line comment (`/* ... */`) requires reading the full string **including spaces**. 

A common bug occurs when using formatted extraction like `cin >> text` (C++) or `scanf("%s")` (C), which **stop reading at the first whitespace character** (space, tab, newline). Consequently, inputs like `/* hello world */` are truncated to just `"/*"`, breaking suffix checks like `text[size-2] == '*'` and `text[size-1] == '/'`.

---

### Key Concepts & Pitfalls

1. **Whitespace Truncation Issue**:
   - `cin >> text` (C++) / `scanf("%s", str)` (C): Delimited by space/tab/newline. Skips leading spaces and stops reading at the first space.
   - `getline(cin, text)` (C++) / `fgets(str, size, stdin)` (C) / `input()` (Python): Reads the entire line including spaces.

2. **Single-Line Comment Recognition**:
   - Length $\ge 2$ and starts with `//`: `text[0] == '/' && text[1] == '/'`.

3. **Multi-Line Comment Recognition**:
   - Single-line format (`/* ... */`): Length $\ge 4$, starts with `/*` and ends with `*/`: `text[0] == '/' && text[1] == '*' && text[len-2] == '*' && text[len-1] == '/'`.
   - Across actual multiple lines: Read input continuously (until `*/` or EOF).

4. **Safety Check**: Always check `size >= 2` (for `//`) and `size >= 4` (for `/* ... */`) before inspecting `text[size-2]` to avoid out-of-bounds array access.

---

### Language Comparison & Input Functions

| Operation | C | C++ | Python |
| :--- | :--- | :--- | :--- |
| **Reads spaces?** | `fgets()`: Yes \| `scanf("%s")`: No | `getline()`: Yes \| `cin >>`: No | `input()`: Yes \| `sys.stdin.read()`: Yes |
| **Start Check** | `str[0] == '/' && str[1] == '/'` | `str[0] == '/' && str[1] == '/'` | `s.startswith("//")` |
| **Multi-line End** | `str[len-2] == '*' && str[len-1] == '/'` | `str[len-2] == '*' && str[len-1] == '/'` | `s.endswith("*/")` |

---

### Code Examples

#### 1. C++ Solution (Handling Spaces & Comments)
```cpp
#include <iostream>
#include <string>

using namespace std;

int main() {
    string text;
    
    // FIX 1: Use getline instead of cin >> text to preserve spaces
    getline(cin, text);
    
    size_t size = text.size();
    cout << "Text Size is " << size << endl;

    if (size >= 2) {
        cout << "Last character: '" << text[size - 1] << "'\n";

        // Single Line Comment: starts with //
        if (text[0] == '/' && text[1] == '/') {
            cout << "\"" << text << "\" is a Single Line Comment" << endl;
        }
        // Multi-Line Comment (on one line): starts with /* and ends with */
        else if (size >= 4 && text[0] == '/' && text[1] == '*' && 
                 text[size - 2] == '*' && text[size - 1] == '/') {
            cout << "\"" << text << "\" is a Multiple Line Comment" << endl;
        }
        else {
            cout << "\"" << text << "\" is Not Comment" << endl;
        }
    } else {
        cout << "\"" << text << "\" is Not Comment" << endl;
    }

    return 0;
}
```

#### 2. C++ Multi-Line Stream Processing (Reading Spanning Lines)
```cpp
#include <iostream>
#include <string>

using namespace std;

int main() {
    string full_input = "", line;
    cout << "Enter code (Ctrl+D / Ctrl+Z then Enter to finish):\n";

    // Read full multi-line block including newlines and spaces
    while (getline(cin, line)) {
        full_input += line + "\n";
    }

    // Trim trailing whitespace/newlines for boundary checking
    while (!full_input.empty() && (full_input.back() == '\n' || full_input.back() == ' ')) {
        full_input.pop_back();
    }

    size_t n = full_input.size();
    if (n >= 4 && full_input[0] == '/' && full_input[1] == '*' &&
        full_input[n - 2] == '*' && full_input[n - 1] == '/') {
        cout << "Valid Multi-Line Comment detected across lines!\n";
    } else if (n >= 2 && full_input[0] == '/' && full_input[1] == '/') {
        cout << "Single-Line Comment detected!\n";
    } else {
        cout << "Not a Comment!\n";
    }

    return 0;
}
```

#### 3. C Implementation
```c
#include <stdio.h>
#include <string.h>

int main() {
    char text[200];

    // Read line including spaces
    if (fgets(text, sizeof(text), stdin) != NULL) {
        // Strip trailing newline
        text[strcspn(text, "\n")] = '\0';
        size_t len = strlen(text);

        if (len >= 2 && text[0] == '/' && text[1] == '/') {
            printf("\"%s\" is a Single Line Comment\n", text);
        } else if (len >= 4 && text[0] == '/' && text[1] == '*' &&
                   text[len - 2] == '*' && text[len - 1] == '/') {
            printf("\"%s\" is a Multiple Line Comment\n", text);
        } else {
            printf("\"%s\" is Not Comment\n", text);
        }
    }
    return 0;
}
```

#### 4. Python Implementation
```python
import sys

def check_comment():
    text = input("Enter text: ")  # reads line including spaces
    
    if text.startswith("//"):
        print(f'"{text}" is a Single Line Comment')
    elif len(text) >= 4 and text.startswith("/*") and text.endswith("*/"):
        print(f'"{text}" is a Multiple Line Comment')
    else:
        print(f'"{text}" is Not Comment')

if __name__ == "__main__":
    check_comment()
```
