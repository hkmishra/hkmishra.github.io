#include <stdio.h>
#include <conio.h>

int insertion_sort(int a[],int n)
{
    int i,key,j;
    for(j=1;j<=n-1;j++)
    {
        key = a[j];
        i = j-1;
        while(i>=0 && a[i]>key)
        {
            a[i+1] = a[i];
            i--;
        }
        a[i+1] = key;
    }
}

int main()
{   
    int a[] = {4,9,2,4,5,7,8,1};
    int n = 8;
    int i=0;
    insertion_sort(a,n);
    
    for(i=0;i<n;i++){
        printf("%d ",a[i]);
    }

    return 0;
}
