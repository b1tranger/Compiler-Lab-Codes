#include<iostream>
#include<string>
 using namespace std;

 int main(){
 string s= "swiss";
int count[26] = {0};

for(char c : s){
    count[c - 'a']++;
}

for (char c : s){
    if (count[c - 'a'] == 1){
        cout<<c;
        return 0;
    }
}
cout<<-1;
return 0;
 }

/*
================================================================================
Theory Summary & Algorithmic Notes (Ref: doc/Assignments/learning/A1.2_theory.md)
================================================================================
- Problem: Finding the first non-repeating (unique) character in a string.
- Technique: Two-Pass Direct-Addressing Frequency Table.
  1. Frequency Array: `int count[26] = {0}` tracks lowercase characters ('a'-'z').
  2. Index Mapping (`c - 'a'`): Offsets ASCII code (e.g., 'a' -> 0, 's' -> 18).
  3. Pass 1 (Lines 9-11): Tallies frequency of each character in O(N) time.
  4. Pass 2 (Lines 13-18): Scans original string left-to-right to find the first
     character with count == 1, guaranteeing original sequential order.
  5. Fallback (Line 19): Outputs -1 if all characters repeat.
- Complexity:
  * Time: O(N) where N is string length.
  * Space: O(1) auxiliary space (fixed 26 integers on stack = 104 bytes).
- Robustness Notice:
  * Assumes lowercase ASCII input ('a'-'z'). Uppercase letters or symbols cause
    negative indices / out-of-bounds access. Generalize with count[256] if needed.
================================================================================
*/
