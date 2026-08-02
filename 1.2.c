#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int compare(const void *a, const void *b)
{
    return (*(int*)a - *(int*)b);
}

int main()
{

    int n;

    printf("Input n: ");
    scanf("%d",&n);
    int arr[n];

    printf("\n(input array must be taken from 0 to n)\n\nInput Array: ");

    for(int i=0; i<n; i++)
    {
        scanf("%d",&arr[i]);
    }
    int max = arr[0];

    // max value

    for(int i=1; i<n; i++)
    {
        if(arr[i]>max)
        {
            max = arr[i];
        }
    }

    printf("\nmax = %d\n",max);

    int arr2[max];
    int arr3[n];
    int offset=0;
    int j=0;

    // sorting

    int size = sizeof(arr) / sizeof(arr[0]);
    qsort(arr, size, sizeof(int), compare);

    printf("\nsorted: \n");

    for(int i=0; i<n; i++)
    {
        printf("%d\n",arr[i]);
    }

    for(int i=0; i<=max; i++)
    {
        if(arr[i]!=i)
        {
            arr3[j]=i;
        }
        j++;
        offset++;
    }

//    for(int i=0; i<=max; i++)
//    {
////        if(i>n-1)
////        {
////            arr2[j]=i;
////        }
////        else if(arr[i]!=i)
//        if(arr[i]!=i)
//        {
//            arr2[j]=i;
//        }
//        j++;
//    }

    printf("\n\n\n");

    int length = sizeof(arr2) / sizeof(arr2[0]);

    for(int i=0; i<length; i++)
    {
        printf("%d\n",arr2[i]);
    }


    return 0;
}



