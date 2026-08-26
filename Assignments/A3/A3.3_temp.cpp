#include <bits/stdc++.h>
using namespace std;

int main()
{
    cout << "Enter an expression: ";
    string text;
    getline(cin, text);
    string id[text.size()-1], op[text.size()-1], assig[text.size()-1], arith[text.size()-1], relat[text.size()-1], logic[text.size()-1];
    text += " ";

    string temp = "";
    for (int i = 0; i < text.size(); i++)
    {
        if (text[i] == ' ')
        {
            if (!temp.empty())
            {
                if (temp == "+" || temp == "-" || temp == "*" || temp == "/" || temp == "=" || temp == "<" || temp == ">" || temp == "<=" || temp == ">=" || temp == "!="  || temp == "==" || temp == "||" || temp == "&&" || temp[0] == "~")
                {
                    op.push_back(temp);
                    if(temp == "=")
                    {
                        assig.push_back(temp);
                    }
                    else if(temp == "+" || temp == "-" || temp == "*" || temp == "/" )
                    {
                        arith.push_back(temp);
                    }
                    else if(temp == "<" || temp == ">" || temp == "<=" || temp == ">=" || temp == "!="  || temp == "==")
                    {
                        relat.push_back(temp);
                    }
                    else if(temp == "||" || temp == "&&" || temp[0] == "~")
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

    cout << endl <<"Identifiers:\n";
    for (int i = 0; i < id.size()-1; i++)
    {
        cout << id[i] <<endl;
    }
    cout << endl <<"Operators:\n";
    for (int i = 0; i < op.size()-1; i++)
    {
        cout << op[i] <<endl;
    }

    cout << endl <<"Operator Classification:\n";

    int assig_cnt = 0,arith_cnt = 0,relat_cnt = 0,logic_cnt = 0;

    for (int i = 0; i < op.size()-1; i++)
    {
        if(temp == "=")
        {
            cout << assig[assig_cnt] <<endl;
            assig_cnt++;
        }
        else if(temp == "+" || temp == "-" || temp == "*" || temp == "/" )
        {
            cout << arith[arith_cnt] <<endl;

            arith_cnt++;
        }
        else if(temp == "<" || temp == ">" || temp == "<=" || temp == ">=" || temp == "!="  || temp == "==")
        {
            cout << relat[relat_cnt] <<endl;
            relat_cnt++;
        }
        else if(temp == "||" || temp == "&&" || temp[0] == "~")
        {
            cout << logic[logic_cnt] <<endl;
            logic_cnt++;
        }
    }

    return 0;
}
