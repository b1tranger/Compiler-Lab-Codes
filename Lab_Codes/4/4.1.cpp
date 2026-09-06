#include <bits/stdc++.h>
using namespace std;

int main() {
  string text;
  getline(cin, text);
  //   string temp;
  //   text += " ";

  string temp = "";
  for (int i = 0; i < text.size() - 1; i++) {
    // strcat(temp, text[i]);
    temp.push_back(text[i]);
    if (text[i] == " ") {
      if (temp == "+" || temp == "-" || temp == "*" || temp == "/" ||
          temp == "=") {
        cout << temp << " is an operator" << endl;

        temp = "";
      } else {
        cout << temp << " is an identifier" << endl;

        temp = "";
      }
    }
  }

  return 0;
}