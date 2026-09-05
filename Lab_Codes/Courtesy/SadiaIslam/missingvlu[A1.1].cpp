#include<iostream>
using namespace std;

int main(){
int arr[]={3,0,1};

int n = sizeof(arr)/sizeof(arr[0]);

int sum=n*(n+1)/2;

for(int i=0; i<n; i++){

    sum =sum-arr[i];
}
cout<<sum;
return 0;
}

/*
================================================================================
Theory Summary & Algorithmic Notes (Ref: doc/Assignments/learning/A1.1_theory.md)
================================================================================
- Problem: Finding the single missing number in an array containing n distinct
  integers in the range [0, n].
- Technique: Gauss's Arithmetic Progression Summation Formula.
  1. Formula: Sum of integers 0 through n is: sum = n * (n + 1) / 2.
  2. Array Size: n is computed using sizeof(arr) / sizeof(arr[0]).
  3. Linear Subtraction: Subtracting every existing element in arr from expected
     sum leaves the single omitted value: Missing = (n * (n + 1) / 2) - sum(arr).
- Complexity:
  * Time: O(n) linear scan through array.
  * Space: O(1) auxiliary space (accumulated in-place in scalar integer).
- Edge Cases & Safety:
  * Large n values may cause integer overflow in n * (n + 1) / 2. Use `long long`
    for n >= 65536 to prevent 32-bit signed overflow.
  * Alternative approaches: Bitwise XOR (zero overflow risk) and Hash Set.
================================================================================
*/
