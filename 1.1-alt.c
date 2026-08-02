#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main()
{

    int n;

    printf("Input n: ");
    scanf("%d",&n);
    int arr[n];

    for(int i=0; i<n; i++)
    {
        scanf("%d",&arr[i]);
    }

    int size = sizeof(arr) / sizeof(arr[0]);

    int sum = n*(n+1)/2;

    for(int i=0; i<n; i++)
    {
        sum = sum - arr[i];
    }

    printf("%d",sum);



    return 0;
}



