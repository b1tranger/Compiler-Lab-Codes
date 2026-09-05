#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;

int main(){
vector<string> st = {"eat","tea","tan","ate","nat","bat",};
unordered_map<string,vector<string>> mp;

for(string s : st){
    string temp = s;
    sort(temp.begin(),temp.end());
    mp[temp].push_back(s);
}

for(auto pair :mp){
    for(string word : pair.second){
        cout<<word<<" ";
    }
    cout<<endl;
}
return 0;
}

/*
================================================================================
Theory Summary & Algorithmic Notes (Ref: doc/Assignments/learning/A1.3_theory.md)
================================================================================
- Problem: Group Anagrams (clustering words that share the exact same characters).
- Technique: Hash Map with Canonical Sorted String Signatures.
  1. Canonical Key: Sorting each word's characters (e.g. "eat" -> "aet", "tea" -> "aet")
     yields an identical signature for all mutual anagrams.
  2. Map Storage: `unordered_map<string, vector<string>> mp` maps each signature
     key to its list of matching original words.
  3. Range-Based Loops:
     - `for(string s : st)`: Sequentially traverses input vector `st`.
     - `for(auto pair : mp)`: Traverses each `std::pair<const string, vector<string>>`
       where `pair.first` is the sorted key and `pair.second` is the anagram list.
- Complexity:
  * Time: O(N * K log K) where N = number of words, K = maximum word length.
  * Space: O(N * K) to store keys and word vectors in the hash map.
- Modern C++ Tip:
  * Use `const auto &[key, group] : mp` (C++17 structured bindings) to avoid
    deep-copying the dynamic vector on every iteration.
================================================================================
*/
