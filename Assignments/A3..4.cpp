#include <bits/stdc++.h>
using namespace std;

int main() {
  cout << "\n\n[ Code does not recognize prefix increment or decrement. Also, "
          "strictly add spaces before endlines `;` ]\n\nEnter an expression: ";
  string text, inc_text;
  getline(cin, text);
  text += " ";

  vector<string> id, op, assig, arith, relat, logic, inc, dec, key, con;

  string temp = "";
  for (int i = 0; i < text.size(); i++) {
    if (text[i] == ' ') {
      if (!temp.empty()) {
        if (temp == "+" || temp == "-" || temp == "*" || temp == "/" ||
            temp == "=" || temp == "<" || temp == ">" || temp == "<=" ||
            temp == ">=" || temp == "!=" || temp == "==" || temp == "||" ||
            temp == "&&" || temp == "~" || temp == "!" ||
            temp[temp.size() - 1] == '+' || temp[temp.size() - 1] == '-' ||
            temp == "int" || temp == "float" || temp == "double" ||
            temp == "char" || temp == "bool" || temp == "void" ||
            temp == "auto" || temp == "nullptr" || temp == "if" ||
            temp == "else" || temp == "for" || temp == "while" ||
            temp == "do" || temp == "switch" || temp == "case" ||
            temp == "default" || temp == "break" || temp == "continue" ||
            temp == "return" || temp == "class" || temp == "struct" ||
            temp == "public" || temp == "private" || temp == "protected" ||
            temp == "this" || temp == "virtual" || temp == "friend" ||
            temp == "new" || temp == "delete" || temp == "const" ||
            temp == "static" || temp == "namespace" || temp == "using" ||
            all_of(temp.begin(), temp.end(), ::isdigit)) {
          // op.push_back(temp);
          if (temp == "=") {
            assig.push_back(temp);
            op.push_back(temp);
          } else if (temp == "+" || temp == "-" || temp == "*" || temp == "/") {
            arith.push_back(temp);
            op.push_back(temp);
          } else if (temp == "<" || temp == ">" || temp == "<=" ||
                     temp == ">=" || temp == "!=" || temp == "==") {
            relat.push_back(temp);
            op.push_back(temp);
          } else if (temp == "||" || temp == "&&" || temp == "~" ||
                     temp == "!") {
            logic.push_back(temp);
            op.push_back(temp);
          } else if (temp.size() >= 2 && ((temp[temp.size() - 2] == '+' &&
                                           temp[temp.size() - 1] == '+') ||
                                          (temp[temp.size() - 2] == '-' &&
                                           temp[temp.size() - 1] == '-'))) {
            // inc_text += temp;
            for (int j = 0; j < temp.size() - 1; j++) {

              if (temp[j] == '+') {
                inc_text += "++";
                inc.push_back(inc_text);
                break;
              } else if (temp[j] == '-') {
                inc_text += "--";
                dec.push_back(inc_text);
                break;
              }
            }
            inc_text = "";
          } else if (temp == "int" || temp == "float" || temp == "double" ||
                     temp == "char" || temp == "bool" || temp == "void" ||
                     temp == "auto" || temp == "nullptr" || temp == "if" ||
                     temp == "else" || temp == "for" || temp == "while" ||
                     temp == "do" || temp == "switch" || temp == "case" ||
                     temp == "default" || temp == "break" ||
                     temp == "continue" || temp == "return" ||
                     temp == "class" || temp == "struct" || temp == "public" ||
                     temp == "private" || temp == "protected" ||
                     temp == "this" || temp == "virtual" || temp == "friend" ||
                     temp == "new" || temp == "delete" || temp == "const" ||
                     temp == "static" || temp == "namespace" ||
                     temp == "using") {
            key.push_back(temp);
          } else if (all_of(temp.begin(), temp.end(), ::isdigit)) {
            con.push_back(temp);
          }
        } else if (temp != "(" && temp != ")" && temp != ";" && temp != "{" &&
                   temp != "}") {
          if (find(id.begin(), id.end(), temp) == id.end()) {
            id.push_back(temp);
          }
        }
        temp = "";
      }
    } else {
      temp.push_back(text[i]);
    }
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

  cout << "Keyword (" << key.size() << "):\n";
  for (int i = 0; i < key.size(); i++) {
    cout << "  " << key[i] << endl;
  }

  cout << "Constant (" << con.size() << "):\n";
  for (int i = 0; i < con.size(); i++) {
    cout << "  " << con[i] << endl;
  }

  return 0;
}
