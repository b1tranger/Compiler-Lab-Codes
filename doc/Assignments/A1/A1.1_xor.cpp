#include <iostream>
#include <vector>

using namespace std;

/**
 * Approach: Bitwise XOR
 * 
 * Mathematical Principle:
 * - x ^ x = 0  (Any number XORed with itself is 0)
 * - x ^ 0 = x  (Any number XORed with 0 is itself)
 * 
 * By XORing all numbers from 1 to n, and then XORing all elements present in the array,
 * every duplicate number cancels out, leaving exactly the missing number.
 * 
 * Time Complexity:  O(n) - Single pass through numbers 1..n and array elements.
 * Space Complexity: O(1) auxiliary space.
 * Safety Benefit:   Immune to integer overflow (unlike Gauss formula n*(n+1)/2).
 */

int findMissingXOR(const vector<int> &arr, int n)
{
    int xor_all = 0;
    for (int i = 1; i <= n; i++)
    {
        xor_all ^= i;
    }

    int xor_arr = 0;
    for (int val : arr)
    {
        xor_arr ^= val;
    }

    return xor_all ^ xor_arr;
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

    int missing = findMissingXOR(arr, n);
    cout << "Missing Number (Bitwise XOR): " << missing << endl;

    return 0;
}
