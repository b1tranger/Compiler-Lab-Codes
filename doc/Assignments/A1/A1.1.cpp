#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;

    cout << "Input n: ";
    cin >> n;

    // In C++, dynamic arrays are idiomatically handled using std::vector instead of C99 Variable Length Arrays (VLA)
    vector<int> arr(n);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // In C, array length was computed via sizeof(arr) / sizeof(arr[0]); in C++ std::vector provides .size()
    int size = static_cast<int>(arr.size());

    // Expected sum of numbers from 1 to n: n * (n + 1) / 2
    long long sum = 1LL * n * (n + 1) / 2;

    for (int i = 0; i < size; i++)
    {
        sum = sum - arr[i];
    }

    cout << sum << endl;

    return 0;
}
