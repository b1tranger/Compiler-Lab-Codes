#include <bits/stdc++.h>
using namespace std;



void inv1()
{
    cout << "\n\nInvalid Identifier: does not start with Alphabets\n\n";
}

void inv2()
{
    cout << "\n\nInvalid Identifier: `C` Keywords\n\n";
}

void inv3()
{
    cout << "\n\nInvalid Identifier: Exceeds 10 Chars\n\n";
}
void inv5()
{
    cout << "\n\nInvalid Identifier: Below 5 Chars\n\n";
}
void inv6()
{
    cout << "\n\nInvalid Identifier: All Char Underscore\n\n";
}
void inv7()
{
    cout << "\n\nInvalid Identifier: No Capital Letters\n\n";
}
void inv8()
{
    cout << "\n\nInvalid Identifier: Special Characters\n\n";
}

void val()
{
    cout << "\n\nValid Identifier\n\n";
}

int add(int a, int b)
{
    return a+b;
}
int sub(int a, int b)
{
    return a-b;
}
int mul(int a, int b)
{
    return a*b;
}
float divi(int a, int b)
{
    if(b==0)
    {
        cout << "\nInvalid! Zero Operation\n";
        return 0;
    }
    return a/b;
}
