#include <bits/stdc++.h>
using namespace std;

int main()
{
    string text;
    cin >> text;
    int tsize = text.size();
    bool flag = false;
    char rep[0];

    for(int i=0; i<tsize; i++)
    {
        rep[0]=text[i];
        for(int j=1; j<tsize-i; j++)
        {
            if(text[j]==rep[0])
            {
                continue;
            }
            else
            {
                cout << rep[0];
                flag= true;
                break;

            }
        }
        if(flag)
        {
            break;
        }
    }

    return 0;
}


//-   **`char rep[0]`** causes critical undefined behavior by creating an illegal zero-size array.
//-   **`j < tsize - i`** cuts off the inner loop range, failing to check earlier characters in the string.
//-   **Premature break** outputs a character the moment it finds _any_ single mismatch, instead of checking if it is unique globally.



