#include <iostream>
using namespace std;

bool NUM(string n) {
  if (n == '0' || n == '1' || n == '2' || n == '3' || n == '4' || n == '5' ||
      n == '6' || n == '7' || n == '8' || n == '9') {
    return true;
  }
  return false;
}

bool OP(string n) {
  if (n == '+' || n == '*' || n == '-' || n == '/') {
    return true;
  }
  return false;
}

bool BRAC(string n) {
  if (n == '(' || n == ')') {
    return true;
  }
  return false;
}

int main() {
  string exp;
  cout << "Enter expression without Spaces:\n>>\t";
  getline(exp, cin);
  cout << endl;
  int brCnt1 = 0;
  int brCnt2 = 0;
  bool flag = true;
  for (int i = 0; i < exp.size(); i++) {
    if (BRAC(exp[i])) {
      if (i == 0 && exp[i] == ')') {
        flag = false;
        break;
      } else if (exp[i] == '(') {
        brCnt1++;
      } else if (exp[i] == ')') {
        brCnt2++;
      }
      // if brCnt1 == brCnt2 then valid
    } else if (OP(exp[i])) {
      if (NUM(exp[i + 1])) {
        //                flag = false;
        //                break;
        continue;
      }

      flag = false;
      break;
    } else if (NUM(exp[i])) {
      continue;
    } else {
      flag = false;
      break;
    }
  }

  if (brCnt1 != brCnt2) {
    flag = false;
  }

  if (flag == true) {
    cout << "VALID";
  } else if (flag = false) {
    cout << "INVALID";
  }

  return 0;
}

/*
================================================================================
Theory Summary & Algorithmic Notes (Ref: Lab_Codes/learning/8-theory.md)
================================================================================
- Problem: Check validity of mathematical expression with basic operators (+,-,*,/)
  and parentheses.
- Note: This original implementation contains syntax issues (getline argument order,
  type mismatch in NUM/OP/BRAC functions) and logic bugs (assignment in conditional,
  and unhandled bracket ordering). See Lab_Codes/8.ValidateMathExpression/8.1_alt.cpp
  for the fully corrected canonical solution.
- Reference Theory:
  * CFG production rules & follow-sets for infix arithmetic.
  * Pushdown automaton & bracket balancing prefix invariants.
  * Full diagnostic guide in Lab_Codes/learning/8-theory.md.
================================================================================
*/
