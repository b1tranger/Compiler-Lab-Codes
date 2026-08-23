# Compiler Lab Theory Notes (`3-theory.md`)

This document provides a comprehensive guide to **String Functions and String Manipulation Techniques** in C, C++, and Python. String processing is a core requirement in compiler design—especially during **Lexical Analysis (Scanning)**, where source code text is parsed, tokenized, and classified into lexemes (keywords, identifiers, literals, operators, and comments).

---

## 1. Role of String Functions in Compiler Design

During the scanning/lexical analysis phase, the compiler reads character streams from source files and performs operations such as:
- **Token Classification**: Determining if a string is a reserved keyword (e.g., `int`, `if`, `while`), valid identifier, or numeric literal.
- **Delimiter & Symbol Recognition**: Finding operators (`+`, `-`, `==`) and punctuation (`;`, `,`, `{`, `}`).
- **Whitespace & Comment Stripping**: Removing spaces, tabs, newlines, and ignoring comment blocks (`//`, `/* ... */`).
- **Lexeme Extraction & Substring Processing**: Extracting variable names, string constants, or numeric constants from raw lines of code.

---

## 2. String Functions in C (`<string.h>` & `<ctype.h>`)

In C, strings are null-terminated (`'\0'`) character arrays (`char[]` or `char*`). String functions are provided by `<string.h>` for string operations and `<ctype.h>` for individual character inspection.

### 2.1 Summary of `<string.h>` Functions

| Function | Purpose | Time Complexity | Safety Note |
| :--- | :--- | :--- | :--- |
| `strlen(s)` | Returns length of string (excluding `'\0'`) | $\mathcal{O}(N)$ | Ensure string is null-terminated |
| `strcpy(dest, src)` | Copies `src` to `dest` | $\mathcal{O}(N)$ | Risk of buffer overflow; use `strncpy` |
| `strncpy(dest, src, n)` | Copies up to `n` characters | $\mathcal{O}(n)$ | May not append `'\0'` if `src` length $\ge n$ |
| `strcat(dest, src)` | Appends `src` to `dest` | $\mathcal{O}(N + M)$ | Risk of buffer overflow |
| `strncat(dest, src, n)` | Appends at most `n` characters | $\mathcal{O}(n)$ | Always null-terminates `dest` |
| `strcmp(s1, s2)` | Lexicographically compares `s1` & `s2` | $\mathcal{O}(N)$ | Returns `<0`, `0`, or `>0` |
| `strncmp(s1, s2, n)` | Compares first `n` characters | $\mathcal{O}(n)$ | Ideal for prefix matching |
| `strchr(s, ch)` | Finds first occurrence of character `ch` | $\mathcal{O}(N)$ | Returns `char*` pointer or `NULL` |
| `strrchr(s, ch)` | Finds last occurrence of character `ch` | $\mathcal{O}(N)$ | Returns `char*` pointer or `NULL` |
| `strstr(haystack, needle)` | Finds first occurrence of substring `needle` | $\mathcal{O}(N \cdot M)$ | Returns `char*` pointer or `NULL` |
| `strtok(str, delim)` | Splits string into tokens by delimiters | $\mathcal{O}(N)$ | Modifies original string; not thread-safe |
| `strtok_r(str, delim, saveptr)` | Reentrant version of `strtok` | $\mathcal{O}(N)$ | Safe for nested loops / multithreading |

### 2.2 Detailed Explanation & Code Examples of String Concatenation: `strcat()` and `strncat()`

#### 1. Function Syntax & Mechanism
- **`char *strcat(char *dest, const char *src)`**:
  - **Behavior**: Appends the string pointed to by `src` to the end of the string pointed to by `dest`.
  - **How it works**:
    1. Finds the null-terminator `'\0'` at the end of `dest`.
    2. Overwrites `dest`'s null-terminator with the first character of `src`.
    3. Copies all remaining characters from `src` to `dest`.
    4. Appends a new null-terminator `'\0'` at the end of the combined string.
    5. Returns the pointer `dest`.

#### 2. Critical Requirements & Common Pitfalls
1. **Buffer Overflow Risk**: `dest` MUST have enough allocated memory space to store its current contents + `src` contents + 1 byte for `'\0'`. If `dest` array size is too small, `strcat` will overwrite adjacent memory, leading to **Undefined Behavior / Segmentation Fault**.
2. **Null-Termination Requirement**: `dest` must be a valid, null-terminated string before `strcat` is called. Uninitialized `char dest[100]` without `dest[0] = '\0'` will cause `strcat` to search infinitely for `'\0'`.
3. **C vs C++ Compatibility**: `strcat` expects C-style character arrays (`char*` or `char[]`). Passing a C++ `std::string` object (like `strcat(temp, text[i])`) directly will result in a **compilation error**. In C++, use `+`, `+=`, `.append()`, or `.push_back()`.

#### 3. Safer Alternative: `strncat()`
- **`char *strncat(char *dest, const char *src, size_t n)`**:
  - Appends at most `n` characters from `src` to `dest`.
  - **Always appends a null-terminator `'\0'`**, making it much safer against buffer overflows.

#### 4. Code Example (C & C++ Concatenation Comparison)

##### C Example using `strcat` and `strncat`:
```c
#include <stdio.h>
#include <string.h>

int main() {
    // 1. dest MUST be initialized with enough buffer space
    char dest[100] = "Compiler ";
    char src[] = "Design Lab";

    // strcat: appends src to dest
    strcat(dest, src);
    printf("After strcat: %s\n", dest); // Output: "Compiler Design Lab"

    // 2. strncat: safe concatenation appending max N characters
    char title[100] = "Lexical ";
    char word[] = "Analysis Phase";
    strncat(title, word, 8); // Appends only "Analysis"
    printf("After strncat: %s\n", title); // Output: "Lexical Analysis"

    // 3. Appending a single character in C using strcat
    char token[50] = "";
    char ch_str[2] = {'a', '\0'}; // Character wrapped in null-terminated string
    strcat(token, ch_str);
    printf("Token after single char append: %s\n", token); // Output: "a"

    return 0;
}
```

##### C++ Concatenation (`std::string` equivalents):
```cpp
#include <iostream>
#include <string>

using namespace std;

int main() {
    string text = "Compiler Lab";
    string temp = "";

    // In C++, do NOT use strcat() on std::string!
    // WRONG:  temp = strcat(temp, text[i]); // Compilation Error!
    
    // CORRECT C++ Methods:
    
    // Method 1: Append single character
    char c = text[0];
    temp.push_back(c);   // Appends 'C'
    temp += 'o';          // Operator += with char

    // Method 2: Append entire string / substring
    temp += "mpiler";     // Operator += with string literal
    temp.append(" Lab");  // .append() member function

    cout << "C++ Concatenated String: " << temp << endl; // Output: "Compiler Lab"

    return 0;
}
```

---

### 2.3 Summary of `<ctype.h>` Character Inspection Functions

| Function | Condition Checked | Example True Characters |
| :--- | :--- | :--- |
| `isalpha(c)` | Alphabet character | `'a'`–`'z'`, `'A'`–`'Z'` |
| `isdigit(c)` | Decimal digit | `'0'`–`'9'` |
| `isalnum(c)` | Alphanumeric character | Letters or digits |
| `isspace(c)` | Whitespace character | `' '`, `'\t'`, `'\n'`, `'\r'`, `'\v'`, `'\f'` |
| `islower(c)` | Lowercase letter | `'a'`–`'z'` |
| `isupper(c)` | Uppercase letter | `'A'`–`'Z'` |
| `isxdigit(c)`| Hexadecimal digit | `'0'`–`'9'`, `'a'`–`'f'`, `'A'`–`'F'` |
| `ispunct(c)` | Punctuation / symbol | `'!'`, `';'`, `'+'`, `'='`, etc. |
| `tolower(c)` | Converts character to lowercase | `'A'` $\rightarrow$ `'a'` |
| `toupper(c)` | Converts character to uppercase | `'a'` $\rightarrow$ `'A'` |

---

## 3. String Functions in C++ (`std::string` & `<algorithm>`)

C++ provides the object-oriented `std::string` class (`#include <string>`), offering high-level methods with automatic memory management, dynamic resizing, and rich manipulation member functions.

### 3.1 `std::string` Member Functions

#### 1. Capacity & Size Inspection
- **`s.length()` / `s.size()`**: Returns number of characters ($\mathcal{O}(1)$).
- **`s.empty()`**: Returns `true` if string size is 0.
- **`s.clear()`**: Removes all characters, setting size to 0.

#### 2. Element Access
- **`s[i]`**: Accesses character at index `i` (no bounds checking).
- **`s.at(i)`**: Accesses character with bounds checking (throws `out_of_range` exception).
- **`s.front()`**: Returns reference to first character (`s[0]`).
- **`s.back()`**: Returns reference to last character (`s[s.size()-1]`).

#### 3. Substrings & Searching
- **`s.substr(pos, count)`**: Returns substring starting at `pos` of length `count`. If `count` is omitted, extracts to end of string.
- **`s.find(str, pos)`**: Searches for `str` starting from index `pos`. Returns index or `string::npos`.
- **`s.rfind(str, pos)`**: Reverse search for `str`. Returns last occurrence index or `string::npos`.
- **`s.find_first_of(chars)`**: Finds first occurrence of any character present in `chars`.
- **`s.find_first_not_of(chars)`**: Finds first character *not* present in `chars` (useful for trimming).

#### 4. Modifications
- **`s.append(str)` / `s += str`**: Appends string to `s`.
- **`s.push_back(ch)`**: Appends a single character `ch`.
- **`s.pop_back()`**: Removes the last character.
- **`s.insert(pos, str)`**: Inserts `str` at index `pos`.
- **`s.erase(pos, count)`**: Erases `count` characters starting at `pos`.
- **`s.replace(pos, count, str)`**: Replaces `count` characters at `pos` with `str`.

#### 5. Modern C++ Extensions (C++20)
- **`s.starts_with(prefix)`**: Returns `true` if string starts with `prefix`.
- **`s.ends_with(suffix)`**: Returns `true` if string ends with `suffix`.
- **`s.contains(sub)`**: Returns `true` if string contains `sub` (C++23).

#### 6. Numerical Conversions (`<string>`)
- **`to_string(val)`**: Converts numeric types (`int`, `double`, `long`) to `std::string`.
- **`stoi(s)` / `stod(s)` / `stol(s)`**: Converts string to `int`, `double`, or `long`.

### 3.2 Using `<algorithm>` with Strings
- **`transform(s.begin(), s.end(), s.begin(), ::tolower)`**: Converts entire string to lowercase.
- **`transform(s.begin(), s.end(), s.begin(), ::toupper)`**: Converts entire string to uppercase.
- **`reverse(s.begin(), s.end())`**: Reverses characters in `s`.

---

## 4. String Methods in Python

In Python, strings are **immutable sequence objects** of type `str`. All string methods return a new string rather than modifying the original in-place.

### 4.1 Python String Methods Summary

#### 1. Inspection & Classification
- **`s.isalpha()`**: `True` if all characters are alphabetic.
- **`s.isdigit()` / `s.isnumeric()`**: `True` if all characters are digits.
- **`s.isalnum()`**: `True` if all characters are alphanumeric.
- **`s.isspace()`**: `True` if all characters are whitespace.
- **`s.isidentifier()`**: `True` if string is a valid Python language identifier/keyword structure.
- **`s.startswith(prefix)`**: `True` if string starts with `prefix` (can pass tuple of prefixes).
- **`s.endswith(suffix)`**: `True` if string ends with `suffix`.

#### 2. Searching & Frequency
- **`s.find(sub)`**: Returns lowest index of `sub`, or `-1` if not found.
- **`s.rfind(sub)`**: Returns highest index of `sub`, or `-1` if not found.
- **`s.index(sub)`**: Like `find()`, but raises `ValueError` if not found.
- **`s.count(sub)`**: Returns number of non-overlapping occurrences of `sub`.

#### 3. Trimming & Splitting
- **`s.strip([chars])`**: Removes leading/trailing characters (default: whitespace).
- **`s.lstrip([chars])`**: Removes leading characters.
- **`s.rstrip([chars])`**: Removes trailing characters.
- **`s.split(sep=None, maxsplit=-1)`**: Splits string into a list of strings around `sep`.
- **`s.rsplit(sep)`**: Splits string starting from the right.
- **`s.partition(sep)`**: Splits into 3-tuple: `(before, sep, after)`.
- **`"delimiter".join(iterable)`**: Concatenates elements of an iterable into a single string.

#### 4. Transformations & Case Conversion
- **`s.lower()` / `s.upper()`**: Returns lowercase / uppercase copy.
- **`s.title()` / `s.capitalize()`**: Converts words/first letter to capital.
- **`s.replace(old, new, count)`**: Replaces occurrences of `old` with `new`.

#### 5. Slicing Syntax (`s[start:stop:step]`)
- **`s[0]`**: First character.
- **`s[-1]`**: Last character.
- **`s[:n]`**: First `n` characters (prefix).
- **`s[-n:]`**: Last `n` characters (suffix).
- **`s[::-1]`**: Reversed string.

---

## 5. Cross-Language String Method Comparison Matrix

| Task / Operation | C (`<string.h>` / `<ctype.h>`) | C++ (`std::string`) | Python (`str`) |
| :--- | :--- | :--- | :--- |
| **Get Length** | `strlen(s)` | `s.size()` / `s.length()` | `len(s)` |
| **Read Full Line** | `fgets(buf, size, stdin)` | `getline(cin, s)` | `input()` |
| **Check Prefix** | `strncmp(s, "if", 2) == 0` | `s.starts_with("if")` / `s.find("if") == 0` | `s.startswith("if")` |
| **Check Suffix** | Custom indexing using `strlen` | `s.ends_with(".cpp")` / custom `back()` | `s.endswith(".cpp")` |
| **Search Substring** | `strstr(s, "val") != NULL` | `s.find("val") != string::npos` | `"val" in s` / `s.find("val") != -1` |
| **Extract Substring** | `strncpy` or pointer offset | `s.substr(pos, len)` | `s[start:end]` |
| **Split by Delimiter** | `strtok(s, " ")` | `stringstream` + `getline` / `find` loop | `s.split(" ")` |
| **Trim Whitespace** | Manual loop / character shift | `find_first_not_of` + `erase` | `s.strip()` |
| **Check Identifier** | `isalpha(s[0])` + loop `isalnum()` | `isalpha(s[0])` + loop `isalnum()` | `s.isidentifier()` |
| **Convert to Int** | `atoi(s)` / `strtol(s, NULL, 10)` | `stoi(s)` | `int(s)` |
| **Convert to Lower** | Loop `tolower(c)` | `transform(..., ::tolower)` | `s.lower()` |

---

## 6. Code Examples for Compiler Lexical Analysis

### 6.1 C Example: Tokenization & Keyword/Identifier Checker

```c
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

// List of basic C keywords
const char *keywords[] = {"int", "float", "char", "if", "else", "while", "return", "void"};
const int num_keywords = 8;

bool is_keyword(const char *str) {
    for (int i = 0; i < num_keywords; i++) {
        if (strcmp(str, keywords[i]) == 0) {
            return true;
        }
    }
    return false;
}

bool is_valid_identifier(const char *str) {
    if (str == NULL || strlen(str) == 0) return false;
    
    // First character must be letter or underscore
    if (!isalpha(str[0]) && str[0] != '_') return false;
    
    // Remaining characters must be letter, digit, or underscore
    for (size_t i = 1; i < strlen(str); i++) {
        if (!isalnum(str[i]) && str[i] != '_') return false;
    }
    return true;
}

int main() {
    char input[200] = "int count_val = 105 ;";
    printf("Original Input: %s\n\n", input);

    // Tokenize string by spaces
    char *token = strtok(input, " ");
    while (token != NULL) {
        if (is_keyword(token)) {
            printf("Token: '%-12s' -> Class: KEYWORD\n", token);
        } else if (is_valid_identifier(token)) {
            printf("Token: '%-12s' -> Class: IDENTIFIER\n", token);
        } else if (isdigit(token[0])) {
            printf("Token: '%-12s' -> Class: NUMBER_LITERAL\n", token);
        } else {
            printf("Token: '%-12s' -> Class: SYMBOL/OPERATOR\n", token);
        }
        token = strtok(NULL, " ");
    }
    return 0;
}
```

---

### 6.2 C++ Example: Substring Search, Trimming, and String Stream Splitting

```cpp
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cctype>

using namespace std;

// Helper: Trim leading and trailing whitespace from std::string
string trim(const string& s) {
    size_t first = s.find_first_not_of(" \t\n\r");
    if (first == string::npos) return "";
    size_t last = s.find_last_not_of(" \t\n\r");
    return s.substr(first, (last - first + 1));
}

int main() {
    string line = "   double   result_val   =   45.89 ;  ";
    cout << "Raw string: \"" << line << "\"\n";

    // 1. Trim whitespace
    string trimmed_line = trim(line);
    cout << "Trimmed string: \"" << trimmed_line << "\"\n\n";

    // 2. Tokenize using stringstream
    stringstream ss(trimmed_line);
    string token;
    vector<string> tokens;

    while (ss >> token) {
        tokens.push_back(token);
    }

    // 3. Inspect extracted tokens
    cout << "Extracted Tokens:\n";
    for (size_t i = 0; i < tokens.size(); ++i) {
        cout << "Index [" << i << "]: " << tokens[i];
        
        // C++20 starts_with check or find check
        if (tokens[i] == "double" || tokens[i] == "int") {
            cout << " (DATA TYPE KEYWORD)";
        } else if (isalpha(tokens[i][0]) || tokens[i][0] == '_') {
            cout << " (IDENTIFIER)";
        } else if (isdigit(tokens[i][0])) {
            cout << " (NUMERIC LITERAL)";
        } else {
            cout << " (OPERATOR/PUNCTUATION)";
        }
        cout << "\n";
    }

    return 0;
}
```

---

### 6.3 Python Example: String Parsing & Token Classification

```python
import keyword

def analyze_lexeme(lexeme: str):
    lexeme = lexeme.strip()
    if not lexeme:
        return "EMPTY"
    
    if lexeme in ["int", "float", "double", "char", "if", "else", "while", "return"] or keyword.iskeyword(lexeme):
        return "KEYWORD"
    elif lexeme.isidentifier():
        return "IDENTIFIER"
    elif lexeme.isdigit():
        return "INTEGER_LITERAL"
    elif lexeme.replace(".", "", 1).isdigit() and lexeme.count(".") == 1:
        return "FLOAT_LITERAL"
    else:
        return "OPERATOR_OR_SYMBOL"

def main():
    code_line = "  float totalAmount = 250.75 ; "
    print(f"Original Line: '{code_line}'")
    
    # Trim and split by whitespace
    tokens = code_line.strip().split()
    
    print("\nToken Analysis:")
    for tok in tokens:
        category = analyze_lexeme(tok)
        print(f"Token: {tok:<15} Category: {category}")

if __name__ == "__main__":
    main()
```
