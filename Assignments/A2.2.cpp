#include <bits/stdc++.h>
using namespace std;

int main() {

  int n;
  cout << "How many lines to consider?\n>> ";
  cin >> n;
  cin.ignore(); // clears input buffer that ignores text[0] input
  cout << endl << "Input each line and press Enter / add Newline:\n>>\n";

  string text[n];

  int cmt_cnt = 0;

  for (int i = 0; i < n; i++) {
    getline(cin, text[i]);
    if (text[i][0] == '/' && text[i][1] == '/') {
      cmt_cnt++;
    }
  }

  cout << endl << "Total Comments: " << cmt_cnt << endl;

  return 0;
}
