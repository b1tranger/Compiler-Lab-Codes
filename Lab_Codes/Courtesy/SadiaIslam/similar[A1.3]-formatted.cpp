#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

int main() {
    vector<string> st = {"eat", "tea", "tan", "ate", "nat", "bat"};
    unordered_map<string, vector<string>> mp;
    vector<string> order; // Tracks insertion order of unique anagram keys

    for (const string &s : st) {
        string temp = s;
        sort(temp.begin(), temp.end());
        if (mp.find(temp) == mp.end()) {
            order.push_back(temp); // Record key on first occurrence to preserve input order
        }
        mp[temp].push_back(s);
    }

    // Format output as 2D list preserving input order
    cout << "[\n";
    for (size_t i = 0; i < order.size(); i++) {
        const vector<string> &group = mp[order[i]];
        cout << "[";
        for (size_t j = 0; j < group.size(); j++) {
            cout << "\"" << group[j] << "\"";
            if (j + 1 < group.size()) cout << ",";
        }
        cout << "]";
        if (i + 1 < order.size()) cout << ",";
        cout << "\n";
    }
    cout << "]\n";

    return 0;
}

/*
================================================================================
Theory Summary & Algorithmic Notes (Ref: doc/Assignments/learning/A1.3_theory.md)
================================================================================
- Problem: Group Anagrams (clustering words that share the exact same characters).
- Technique: Hash Map with Canonical Sorted Signatures + Insertion Order Tracker.
  1. Canonical Key: Sorting each word's characters (e.g. "eat" -> "aet", "tea" -> "aet")
     yields an identical signature for all mutual anagrams.
  2. Map Storage: `unordered_map<string, vector<string>> mp` maps each signature
     key to its list of matching original words.
  3. Insertion-Order Preservation: `std::unordered_map` does NOT maintain key
     arrival order due to internal bucket hashing. A companion `vector<string> order`
     tracks keys when first encountered to guarantee input-order output.
  4. 2D List Formatting: Prints bracketed groups `["word1","word2"]` with quotes
     and comma delimiters matching standard Python/JSON nested list representation.
- Complexity:
  * Time: O(N * K log K) where N = number of words, K = maximum word length.
  * Space: O(N * K) to store keys, word vectors, and order indices.
================================================================================
*/
