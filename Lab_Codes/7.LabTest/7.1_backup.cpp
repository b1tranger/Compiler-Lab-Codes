#include "7.2.h"
using namespace std;

void inv1()
{
    cout << "\n\nInvalid Identifier: does not follow Standard Rules\n\n";
}

void inv2()
{
    cout << "\n\nInvalid Identifier: Exceeds 10 Chars\n\n";
}
void inv5()
{
    cout << "\n\nInvalid Identifier: Below 5 Chars\n\n";
}

void val()
{
    cout << "\n\nValid Identifier\n\n";
}


int main()
{
    char id[50];
    string rea[100];
    cout << "\n\nEnter Test Case: \n>> ";
//    getline(cin,id);
    cin >> id;

//    int ids = id.size();
//    int ids = sizeof(id)/sizeof(id[0]);
    int ids = sizeof(id);

    cout << "\n[ String Size: " << ids << endl;

    if(ids >10)
    {
        inv2();
    }
    else if(ids < 5)
    {
        inv5();
    }
    else if(id[0] < 'a' && id[0] > 'z' || id[0] < 'A' && id[0] > 'Z' || id[0] != '_' || id == "int" ||id == "for" ||id == "while")
    {

        inv1();
    }
    else
    {
        val();
    }


    return 0;
}
