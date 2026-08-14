#include <bits/stdc++.h>
using namespace std;

int main()
{

    string text;
//    cin >> text;
    getline(cin,text);
    cout << "Text Size is " <<text.size() <<endl;
    cout << text[text.size()-1] <<endl;
    if(text[0]=='/' && text[1]=='/')
    {
        cout << text << " is a Single Line Comment" <<endl;
    }
    else if(text[0]=='/' && text[1]=='*' && text[text.size()-2]=='*' && text[text.size()-1]=='/')
    {
        cout << text << " is a Multiple Line Comment" <<endl;
    }
    else
    {
        cout << text << " is Not Comment" <<endl;
    }



    return 0;
}

