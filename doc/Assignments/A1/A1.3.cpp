#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

// Helper function to print 2D vector in Python list format
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
    vector<string> Anagrams = {"eat", "tea", "tan", "ate", "nat", "bat"};

    // =========================================================================
    // Approach 1: Nested Loops & Tracking Vector (Direct C++ port of A1.3.py)
    // Time Complexity: O(N^2 * K log K)
    // =========================================================================
    vector<string> copy_arr = Anagrams;

    vector<vector<string>> grouped;
    size_t gr_cnt = 0; // index for `grouped` list
    grouped.push_back({});

    vector<string> track; // tracking the added values

    // Sorting characters within each string in copy_arr
    for (size_t i = 0; i < copy_arr.size(); i++)
    {
        string text = copy_arr[i];
        sort(text.begin(), text.end()); // C++ equivalent of "".join(sorted(text))
        copy_arr[i] = text;
    }

    // Now `copy_arr` is sorted but `Anagrams` is not.
    // They share identical indices for corresponding elements.
    for (size_t i = 0; i < Anagrams.size(); i++)
    {
        for (size_t j = 0; j < Anagrams.size(); j++)
        {
            // Skips already added values (equivalent to: Anagrams[j] not in track)
            if (find(track.begin(), track.end(), Anagrams[j]) == track.end())
            {
                if (copy_arr[i] == copy_arr[j])
                {
                    grouped[gr_cnt].push_back(Anagrams[j]);
                    // track.extend(grouped[gr_cnt])
                    track.insert(track.end(), grouped[gr_cnt].begin(), grouped[gr_cnt].end());
                }
            }
        }

        // Skip increment when last loop is reached or current group had no matches
        if (i != Anagrams.size() - 1 && !grouped[gr_cnt].empty())
        {
            gr_cnt = gr_cnt + 1;
            grouped.push_back({});
        }
    }

    cout << "Grouped Anagrams (Approach 1 - Tracking Vector):" << endl;
    printGrouped(grouped);

    // =========================================================================
    // Approach 2: Using Hash Map (Masud suggested) <-- Best Approach
    // Time Complexity: O(N * K log K)
    // =========================================================================
    /*
    unordered_map<string, vector<string>> anagram_map;
    for (const string &word : Anagrams)
    {
        string sorted_key = word;
        sort(sorted_key.begin(), sorted_key.end());
        anagram_map[sorted_key].push_back(word);
    }

    vector<vector<string>> grouped_map;
    for (const auto &[key, words] : anagram_map)
    {
        grouped_map.push_back(words);
    }

    cout << "\nGrouped Anagrams (Approach 2 - Hash Map):" << endl;
    printGrouped(grouped_map);
    */

    return 0;
}
