#include <iostream>
#include <vector>

using namespace std;

/**
 * Approach: Brute Force Search
 * 
 * Algorithm:
 * For every candidate integer from 1 to n, perform a linear scan over the array.
 * The first candidate not present in the array is the missing number.
 * 
 * Time Complexity:  O(n^2) - For each of the n candidates, we do up to n comparisons.
 * Space Complexity: O(1) auxiliary space beyond storing the input.
 */

int findMissingBruteForce(const vector<int> &arr, int n)
{
    for (int candidate = 1; candidate <= n; candidate++)
    {
        bool found = false;
        for (size_t i = 0; i < arr.size(); i++)
        {
            if (arr[i] == candidate)
            {
                found = true;
                break;
            }
        }

        if (!found)
        {
            return candidate; // Found missing number
        }
    }

    return -1; // No missing number found
}

int main()
{
    int n;
    cout << "Input n: ";
    if (!(cin >> n) || n <= 0)
    {
        cerr << "Invalid input for n." << endl;
        return 1;
    }

    cout << "Enter elements (up to " << n << " values): ";
    vector<int> arr;
    for (int i = 0; i < n; i++)
    {
        int x;
        if (cin >> x)
        {
            arr.push_back(x);
        }
        else
        {
            break;
        }
    }

    int missing = findMissingBruteForce(arr, n);

    if (missing != -1)
    {
        cout << "Missing Number (Brute Force): " << missing << endl;
    }
    else
    {
        cout << "No missing number found in range 1 to " << n << "." << endl;
    }

    return 0;
}
