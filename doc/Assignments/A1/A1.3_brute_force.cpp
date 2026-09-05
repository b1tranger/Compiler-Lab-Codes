#include <iostream>
#include <vector>
#include <string>

using namespace std;

/**
 * Helper: Check if two strings are anagrams using a character frequency array.
 * 
 * Time Complexity:  O(K) where K is string length.
 * Space Complexity: O(1) fixed 256-element lookup table.
 */
bool areAnagrams(const string &s1, const string &s2)
{
    if (s1.length() != s2.length())
        return false;

    int count[256] = {0};

    for (char c : s1)
        count[static_cast<unsigned char>(c)]++;

    for (char c : s2)
        count[static_cast<unsigned char>(c)]--;

    for (int i = 0; i < 256; i++)
    {
        if (count[i] != 0)
            return false;
    }

    return true;
}

/**
 * Approach: Pure Brute Force Pairwise Anagram Grouping
 * 
 * Algorithm:
 * 1. Maintain a boolean `visited` array to ensure each word is grouped only once.
 * 2. For each unvisited word `words[i]`, initialize a new group with `words[i]`.
 * 3. Scan all subsequent words `words[j]` (where j > i). If `words[j]` is an anagram of
 *    `words[i]`, add it to the current group and mark it as visited.
 * 4. Append the completed group to the result list.
 * 
 * Time Complexity:  O(N^2 * K) where N is number of words and K is average word length.
 * Space Complexity: O(N) auxiliary space for the visited tracking vector.
 */
vector<vector<string>> groupAnagramsBruteForce(const vector<string> &words)
{
    size_t n = words.size();
    vector<bool> visited(n, false);
    vector<vector<string>> grouped;

    for (size_t i = 0; i < n; i++)
    {
        if (visited[i])
            continue; // Already assigned to an anagram group

        vector<string> current_group;
        current_group.push_back(words[i]);
        visited[i] = true;

        // Compare words[i] with all remaining unvisited words
        for (size_t j = i + 1; j < n; j++)
        {
            if (!visited[j] && areAnagrams(words[i], words[j]))
            {
                current_group.push_back(words[j]);
                visited[j] = true;
            }
        }

        grouped.push_back(current_group);
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

    vector<vector<string>> result = groupAnagramsBruteForce(words);

    cout << "Grouped Anagrams (Brute Force Pairwise O(N^2 * K)):" << endl;
    printGrouped(result);

    return 0;
}
