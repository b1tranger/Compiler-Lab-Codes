#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main()
{
    string text;
    cin >> text;

    unordered_map<char, int> freq;


    for (char c : text)
    {
        freq[c]++;
    }

    // looping through text and matching the count in map

    for (char c : text)
    {
        if (freq[c] == 1)
        {
            cout << "First non-repeating character: " << c << endl;
            break;
        }
    }

    return 0;
}

/*
================================================================================
Theory Summary & Algorithmic Notes (Ref: doc/Assignments/learning/A1.2_theory.md)
================================================================================
- Problem: Finding the first non-repeating character in an arbitrary input string.
- Technique: Two-Pass Hash Map (std::unordered_map<char, int>).
  1. Pass 1 (Lines 15-18): Counts occurrences of each character with freq[c]++.
  2. Pass 2 (Lines 22-29): Scans original string left-to-right to find the first
     character with freq[c] == 1, preserving input arrival order.
- Complexity:
  * Time: O(N) average where N is string length.
  * Space: O(U) auxiliary space where U is the number of unique characters.
- Alternative:
  * Fixed direct-addressing array `count[26]` for lowercase-only inputs (see
    Lab_Codes/Courtesy/SadiaIslam/non-repeating[A1.2].cpp).
================================================================================
*/
