#include <bits/stdc++.h>
using namespace std;

int main() {
  cout << "Enter an expression: ";
  string text;
  getline(cin, text);
  text += " ";

  vector<string> id, op, assig, arith, relat, logic, inc, dec;

  for (int i = 0; i < text.size();) {
    if (isspace(text[i])) {
      i++;
      continue;
    }

    // Check 2-character operators first
    if (i + 1 < text.size()) {
      string op2 = text.substr(i, 2);
      if (op2 == "++" || op2 == "--" || op2 == "<=" || op2 == ">=" ||
          op2 == "!=" || op2 == "==" || op2 == "||" || op2 == "&&") {
        op.push_back(op2);
        if (op2 == "++") {
          inc.push_back(op2);
        } else if (op2 == "--") {
          dec.push_back(op2);
        } else if (op2 == "<=" || op2 == ">=" || op2 == "!=" || op2 == "==") {
          relat.push_back(op2);
        } else if (op2 == "||" || op2 == "&&") {
          logic.push_back(op2);
        }
        i += 2;
        continue;
      }
    }

    // Check 1-character operators
    char c = text[i];
    if (c == '+' || c == '-' || c == '*' || c == '/' || c == '=' ||
        c == '<' || c == '>' || c == '!' || c == '~' || c == '%') {
      string op1(1, c);
      op.push_back(op1);
      if (op1 == "=") {
        assig.push_back(op1);
      } else if (op1 == "+" || op1 == "-" || op1 == "*" || op1 == "/" ||
                 op1 == "%") {
        arith.push_back(op1);
      } else if (op1 == "<" || op1 == ">") {
        relat.push_back(op1);
      } else if (op1 == "!" || op1 == "~") {
        logic.push_back(op1);
      }
      i++;
      continue;
    }

    // Check identifiers / alphanumeric words
    if (isalnum(c) || c == '_') {
      string word = "";
      while (i < text.size() && (isalnum(text[i]) || text[i] == '_')) {
        word += text[i];
        i++;
      }
      id.push_back(word);
      continue;
    }

    // Skip delimiters/punctuation (;, (, ), {, }, etc.)
    i++;
  }

  cout << endl << "Identifiers (" << id.size() << "):\n";
  for (int i = 0; i < id.size(); i++) {
    cout << id[i] << endl;
  }

  cout << endl << "Operators (" << op.size() << "):\n";
  for (int i = 0; i < op.size(); i++) {
    cout << op[i] << endl;
  }

  cout << endl << "Operator Classification:\n";

  cout << "Assignment (" << assig.size() << "):\n";
  for (int i = 0; i < assig.size(); i++) {
    cout << "  " << assig[i] << endl;
  }

  cout << "Arithmetic (" << arith.size() << "):\n";
  for (int i = 0; i < arith.size(); i++) {
    cout << "  " << arith[i] << endl;
  }

  cout << "Relational (" << relat.size() << "):\n";
  for (int i = 0; i < relat.size(); i++) {
    cout << "  " << relat[i] << endl;
  }

  cout << "Logical (" << logic.size() << "):\n";
  for (int i = 0; i < logic.size(); i++) {
    cout << "  " << logic[i] << endl;
  }

  cout << "Increment (" << inc.size() << "):\n";
  for (int i = 0; i < inc.size(); i++) {
    cout << "  " << inc[i] << endl;
  }

  cout << "Decrement (" << dec.size() << "):\n";
  for (int i = 0; i < dec.size(); i++) {
    cout << "  " << dec[i] << endl;
  }

  return 0;
}
