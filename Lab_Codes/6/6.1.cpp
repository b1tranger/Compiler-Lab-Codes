#include <bits/stdc++.h>
using namespace std;

int main()
{
    string n;
    cin >> n;
    cout << endl << endl;

    int ns = n.size();
    string temp;

    // (ab)*
    if(n[0] == '(' && n[ns-2] == ')' && n[ns-1] == '*')
    {

        cout << "[ (ab)* ]" << endl << endl;
        cout << "epsilon , ";
        temp += n[1];
        temp += n[2];
        for(int i = 0; i<3; i++)
        {
            cout << temp << " , ";
            temp += temp;
        }
        cout << " ... ";

    }
      // a?b+

        else if(n[1] == '?' && n[ns-1] =='+')
    {
        cout << "[ a?b+ ]" << endl << endl;
        cout << n[2] << " , ";
//        temp += n[0];
        temp += n[ns-2];
//        temp =+ 'b';
        for(int i = 0; i<3; i++)
        {
            cout << n[0] << temp << " , ";
            temp += n[ns-2];
//            temp =+ 'b';
        }
        cout << " ... ";

    }

    //ab+

    else if(n[ns-1] == '+')
    {
        cout << "[ ab+ ]" << endl << endl;
//        cout << n[0] << " , ";
        temp += n[0];
        temp += n[1];
        for(int i = 0; i<3; i++)
        {
            cout << temp << " , ";
            temp += n[1];
        }
        cout << " ... ";

    }

    // a+b

    else if(n[1] == '+')
    {
        cout << "[ a+b ]" << endl << endl;
//        cout << n[0] << " , ";
        temp += n[0];
//        temp += n[1];
        for(int i = 0; i<3; i++)
        {
            cout << temp << n[2] << " , ";
            temp += temp;
        }
        cout << " ... ";

    }





    cout << endl << endl;

    return 0;
}
