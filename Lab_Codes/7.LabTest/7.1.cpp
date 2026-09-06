#include "7.2.h"
using namespace std;

int main()
{
//    char id[50];
    string id;
    string rea[100];
    cout << "\n\nEnter Test Case: \n>> ";
//    getline(cin,id);
    cin >> id;

    int ids = id.size();
//    int ids = sizeof(id)/sizeof(id[0]);
//    int ids = sizeof(id);

    cout << "\n[ String Size: " << ids << " ]"<<endl;

    bool flag = false;

    if(ids >10)
    {
        inv3();
        flag = true;
    }
    else if(ids < 5)
    {
        inv5();
        flag = true;
    }

    if(id[0] < 'a' && id[0] > 'z' || id[0] < 'A' && id[0] > 'Z' )
    {
        inv1();

        flag = true;
    }
    int flag2 = false; // Capital Check
    int flag3 = false; // Special Check
    int flag4 = false; // Underscore Check
    for(int i=0; i<ids; i++)
    {
        if(id[i] >= 'A' && id[i] <= 'Z')
        {
            flag2 = true;
            flag = true;
        }
        if(ids > 1 && id[i]!='_')
        {
            if(i==0)
            {
                continue;
            }
            else
            {
                flag4 = true;
                flag = true; /////////////////////  ISSUE HERE. DOES NOT SHOW `VALID` AS OUTPUT
            }
        }
        if(id[i]=='@' || id[i]=='#'  || id[i]=='$')
        {
            flag3 = true;;
            flag = true;
        }
    }
    if(!flag2)
    {
        inv7();
    }
    if(!flag4)
    {
        inv6();
    }
    if(flag3)
    {
        inv8();
    }
    if(id == "int" ||id == "for" ||id == "while")
    {

        inv2();
        flag = true;
    }
//    if(id[0]=='_' && id[ids-1]=='_')
//    {
//        inv6();
//        flag = true;
//    }

    if(!flag)
    {
        val();
    }





    return 0;
}
