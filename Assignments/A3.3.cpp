#include <bits/stdc++.h>
using namespace std;

int main()
{
    cout << "Enter an expression: ";
    string text;
    getline(cin, text);
    text += " ";

    vector<string> id, op, assig, arith, relat, logic;

    string temp = "";
    for (int i = 0; i < text.size(); i++)
    {
        if (text[i] == ' ')
        {
            if (!temp.empty())
            {
                if (temp == "+" || temp == "-" || temp == "*" || temp == "/" ||
                    temp == "=" || temp == "<" || temp == ">" || temp == "<=" ||
                    temp == ">=" || temp == "!=" || temp == "==" || temp == "||" ||
                    temp == "&&" || temp == "~" || temp == "!")
                {
                    op.push_back(temp);
                    if (temp == "=")
                    {
                        assig.push_back(temp);
                    }
                    else if (temp == "+" || temp == "-" || temp == "*" || temp == "/")
                    {
                        arith.push_back(temp);
                    }
                    else if (temp == "<" || temp == ">" || temp == "<=" ||
                             temp == ">=" || temp == "!=" || temp == "==")
                    {
                        relat.push_back(temp);
                    }
                    else if (temp == "||" || temp == "&&" || temp == "~" || temp == "!")
                    {
                        logic.push_back(temp);
                    }
                }
                else
                {
                    id.push_back(temp);
                }
                temp = "";
            }
        }
        else
        {
            temp.push_back(text[i]);
        }
    }

    cout << endl << "Identifiers (" << id.size() << "):\n";
    for (int i = 0; i < id.size(); i++)
    {
        cout << id[i] << endl;
    }

    cout << endl << "Operators (" << op.size() << "):\n";
    for (int i = 0; i < op.size(); i++)
    {
        cout << op[i] << endl;
    }

    cout << endl << "Operator Classification:\n";

    cout << "Assignment (" << assig.size() << "):\n";
    for (int i = 0; i < assig.size(); i++)
    {
        cout << "  " << assig[i] << endl;
    }

    cout << "Arithmetic (" << arith.size() << "):\n";
    for (int i = 0; i < arith.size(); i++)
    {
        cout << "  " << arith[i] << endl;
    }

    cout << "Relational (" << relat.size() << "):\n";
    for (int i = 0; i < relat.size(); i++)
    {
        cout << "  " << relat[i] << endl;
    }

    cout << "Logical (" << logic.size() << "):\n";
    for (int i = 0; i < logic.size(); i++)
    {
        cout << "  " << logic[i] << endl;
    }

    return 0;
}
