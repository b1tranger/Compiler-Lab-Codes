#include <iostream>
#include <string>
#include <stack>
#include <cctype>

using namespace std;

// Helper: check if character is a digit
bool NUM(char n) {
  return isdigit(static_cast<unsigned char>(n));
}

// Helper: check if character is an arithmetic operator
bool OP(char n) {
  return n == '+' || n == '-' || n == '*' || n == '/';
}

// Helper: check if character is an opening bracket
bool isOpenBracket(char n) {
  return n == '(' || n == '[' || n == '{';
}

// Helper: check if character is a closing bracket
bool isCloseBracket(char n) {
  return n == ')' || n == ']' || n == '}';
}

// Helper: check if opening and closing brackets match
bool isMatchingPair(char open, char close) {
  return (open == '(' && close == ')') ||
         (open == '[' && close == ']') ||
         (open == '{' && close == '}');
}

// Validates infix mathematical expression syntax using a DSA Stack
bool isValidExpression(const string& exp) {
  if (exp.empty()) return false;

  int n = static_cast<int>(exp.size());
  stack<char> bracketStack;

  // Rule 1: Expression cannot start or end with a binary operator
  if (OP(exp[0]) || OP(exp[n - 1])) {
    return false;
  }

  for (int i = 0; i < n; i++) {
    char curr = exp[i];

    if (isOpenBracket(curr)) {
      bracketStack.push(curr);
      // Lookahead: cannot have empty brackets `()` or operator immediately after opening bracket
      if (i + 1 < n && (isCloseBracket(exp[i + 1]) || OP(exp[i + 1]))) {
        return false;
      }
    } else if (isCloseBracket(curr)) {
      // Underflow check: closing bracket without a preceding open bracket
      if (bracketStack.empty()) {
        return false;
      }
      // Bracket type mismatch check: e.g. `(]` or `{[)}`
      if (!isMatchingPair(bracketStack.top(), curr)) {
        return false;
      }
      bracketStack.pop();

      // Lookahead: closing bracket cannot be followed by a number or opening bracket without an operator
      if (i + 1 < n && (NUM(exp[i + 1]) || isOpenBracket(exp[i + 1]))) {
        return false;
      }
    } else if (OP(curr)) {
      // Lookahead: operator must be followed by a number or an opening bracket
      if (i + 1 < n && !(NUM(exp[i + 1]) || isOpenBracket(exp[i + 1]))) {
        return false;
      }
    } else if (NUM(curr)) {
      // Lookahead: number cannot be followed immediately by an opening bracket without an operator
      if (i + 1 < n && isOpenBracket(exp[i + 1])) {
        return false;
      }
    } else {
      // Invalid character (spaces, unrecognized symbols)
      return false;
    }
  }

  // All opened brackets must be matched and popped from the stack
  return bracketStack.empty();
}

int main() {
  string exp;
  cout << "Enter expression without Spaces:\n>>\t";
  if (!getline(cin, exp)) {
    return 0;
  }
  cout << endl;

  if (isValidExpression(exp)) {
    cout << "VALID" << endl;
  } else {
    cout << "INVALID" << endl;
  }

  return 0;
}

/*
================================================================================
Theory Summary & Algorithmic Notes (Ref: Lab_Codes/learning/8-theory.md)
================================================================================
- Problem: Validate whether a string is a syntactically correct infix mathematical
  expression containing operands, binary operators (+, -, *, /), and balanced
  nested delimiters ((), [], {}), rejecting invalid syntax and mismatched pairs.
- Technique:
  1. Lexical Token Classification: NUM (digits), OP (+,-,*,/), Bracket Classifiers.
  2. DSA Pushdown Automaton Stack (std::stack<char>):
     - Push opening brackets onto the stack.
     - On closing brackets: verify non-empty stack (underflow check), verify matching
       delimiter pair (e.g. '(' with ')', '[' with ']'), then pop.
     - End-of-stream: Stack must be empty (reject unclosed brackets).
  3. Lookahead Grammar Verification:
     - Disallow leading and trailing binary operators.
     - Disallow consecutive operators and empty brackets (e.g., '()', '[]').
     - Disallow implicit multiplication (e.g., '2(3)', '(2)3', ')(').
- Complexity:
  * Time: O(N) where N = string length (single-pass scan with O(1) stack operations).
  * Space: O(N) auxiliary space in the worst case for bracket stack depth.
- Edge Cases & Safety:
  * Detects cross-bracket mismatches (e.g., '(2+3]') which scalar counters miss.
  * static_cast<unsigned char> protects isdigit from signed negative char UB.
  * static_cast<int>(exp.size()) prevents signed/unsigned comparison warnings.
  * Bounded lookahead (i + 1 < n) prevents out-of-bounds indexing.
================================================================================
*/
