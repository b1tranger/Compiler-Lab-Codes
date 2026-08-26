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
