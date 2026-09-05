#include<iostream>
#include<string>
 using namespace std;

 int main(){
 string s= "swiss";
int count[26] = {0};

for(char c : s){
    count[c - 'a']++;
}

for (char c : s){
    if (count[c - 'a'] == 1){
        cout<<c;
        return 0;
    }
}
cout<<-1;
return 0;
 }
