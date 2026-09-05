#include<iostream>
using namespace std;
int main()
{
    string input;
    cin>>input;
    for(int i=0; i<input.length(); i++)
    {
        if(input[i]>='a' && input[i]<='z')
        {
            string n=" ";
            while(input[i]>='a' && input[i]<='z')
            {
                n+=input[i];
                i++;
            }
            cout<<n<<endl<<"identifier"<<endl;
            i--;

        }
        else if(input[i]=='=' | input[i]=='+' | input[i]=='*' | input[i]=='/')
        {
            cout<<input[i]<<endl<<"operator"<<endl;
        }
        else
        {

            cout<<input[i]<<endl<<"numeric number"<<endl;
        }
    }
}
