#include<iostream>
#include<string>
using namespace std;

int main()
{
    string input;
    cin>>input;

    for(int i=0; i< input.length(); i++)
    {
        if(input[i]=='+' && input[i+1]=='+')
        {
            cout<<input[i]<<endl<<"Increment"<<endl;
            i++;
        }
        else if(input[i]=='>' && input[i+1]=='>')
        {
            cout<<input[i]<<endl<<"Relational"<<endl;
            i++;
        }

        else if(input[i]=='!' && input[i+1]=='=')
        {
            cout<<input[i]<<endl<<"Relational"<<endl;
            i++;
        }
        else if(input[i]=='&' && input[i+1]=='&')
        {
            cout<<input[i]<<endl<<"Logical"<<endl;
            i++;
        }

        else  if(input[i]=='=')
        {
            cout<<input[i]<<endl<<"Assignment"<<endl;
        }

        else if(input[i]=='+' | input[i]=='*' | input[i]=='/' )
        {
            cout<<input[i]<<endl<<"Arithmetic"<<endl;
        }
        else if(input[i] >='a' && input[i]<= 'z')
        {
            string n="";
            while(input[i]>='a' && input[i]<= 'z')
            {
                n+=input[i];
                i++;
            }
            i--;
            if(n!="int" && n!="if")
            {
                cout<<endl<<n<<endl<<"Identifier"<<endl;
            }
        }
    }
    return 0;
}
