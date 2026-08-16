#include <stdio.h>
#include <ctype.h>
int main()
{   char s[100];
    int i;
    printf("expression dao: ");
    //scanf("%s", s);
    fgets(s,100,stdin);
    printf("identifiers gula: ");
    for(i=0;s[i]!='\0';i++)
    {
        if(isalpha(s[i]))
        {
            printf("%c", s[i]);

            if(!isalpha(s[i+1]))
                printf(" ");
        }
    }
    printf("\noperators gula: ");
    for(i=0;s[i]!='\0';i++)
    {
       if(s[i]=='=' || s[i]=='+' || s[i]=='-' || s[i]=='*' || s[i]=='/'){
          printf("%c ", s[i]);
        }
    }
    printf("\nnumeric value: ");
    for(i=0; s[i]!='\0'; i++)
    {
        if(isdigit(s[i]))
            printf("%c", s[i]);
    }
        return 0;}
ekhane expression e identifier,operator,numeric value koyta ache seta count kore code dao.aager code er output o asbe..niche ai new output gulao asbe.jegula repeat korbe segula print hobe na.ekta error msg asbe jodi same identifier ekadhik bar hoi
