#include <bits/stdc++.h>
using namespace std;

int sum(int a, int b) { return a + b; }

int sub(int a, int b) { return a - b; }

int mul(int a, int b) { return a * b; }

float divi(float a, float b) {
  if (b == 0) {
    cout << "Division of 0 --> Invalid" << endl;
    return 0;
  }
  return a / b;
}
