#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

/**
 * Approach: Hash Map with Sorted Character Signature
 * 
 * Algorithm:
 * 1. For each word in the input list, sort its characters to create a canonical anagram key
 *    (e.g., "eat" -> "aet", "tea" -> "aet").
 * 2. Store the original word in an unordered_map bucket keyed by the sorted signature:
 *    map["aet"] = ["eat", "tea", "ate"]
 * 3. Extract all bucket vectors into the final grouped 2D list.
 * 
 * Time Complexity:  O(N * K log K) where N is word count and K is max string length.
 * Space Complexity: O(N * K) to store hash table buckets and grouped output.
 */
vector<vector<string>> groupAnagramsHashMap(const vector<string> &words)
{
    unordered_map<string, vector<string>> anagram_map;

    for (const string &word : words)
    {
        string sorted_key = word;
        sort(sorted_key.begin(), sorted_key.end());
        anagram_map[sorted_key].push_back(word);
    }

    vector<vector<string>> grouped;
    grouped.reserve(anagram_map.size());

    for (auto &[key, group] : anagram_map)
    {
        grouped.push_back(move(group));
    }

    return grouped;
}

// Formats 2D string vector to look like Python's nested list representation
void printGrouped(const vector<vector<string>> &grouped)
{
    cout << "[";
    for (size_t i = 0; i < grouped.size(); i++)
    {
        cout << "[";
        for (size_t j = 0; j < grouped[i].size(); j++)
        {
            cout << "'" << grouped[i][j] << "'";
            if (j + 1 < grouped[i].size())
                cout << ", ";
        }
        cout << "]";
        if (i + 1 < grouped.size())
            cout << ", ";
    }
    cout << "]" << endl;
}

int main()
{
    vector<string> words = {"eat", "tea", "tan", "ate", "nat", "bat"};

    cout << "Input Words: [\"eat\", \"tea\", \"tan\", \"ate\", \"nat\", \"bat\"]" << endl;

    vector<vector<string>> result = groupAnagramsHashMap(words);

    cout << "Grouped Anagrams (Optimal Hash Map O(N * K log K)):" << endl;
    printGrouped(result);

    return 0;
}
