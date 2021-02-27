#include <stdio.h>
#include<stdlib.h>

void selection_sort(int a[],int n)
{
    int i,j,min,temp,min2;
    for(j=0;j<n;j++)
    {
        min = a[j];
        min2=j;
        for(i=j+1;i<n;i++)
        {
            if(a[i]<min)
            {
                min = a[i];
                min2= i;
            }
        }//end of for i
        
        /*swap min with element*/
        temp=a[j];
        a[j]=a[min2];
        a[min2]=temp;
        /*swap min with element*/
        
        printf("\nitr %d =",j);
        for(i=0;i<n;i++)
        {
            if(i==0) printf(" %d ",a[i]);
            else printf(", %d ",a[i]);
        }
        printf("\nmin = %d",min);
        
        printf("\n");
    }//end of for j

    
}

int main()
{
    int i;
    int a[]={45 ,75 ,15 ,75 ,24 ,76 ,34 ,94 ,18};
    int size = sizeof(a)/sizeof(int);

    printf("Original List = ");
    for(i=0;i<size;i++)
    {
        if(i==size-1) printf(" %d",a[i]);
        else printf(" %d ,",a[i]);
    }
    printf("\n");
    
    selection_sort(a,size);
    
    printf("\n\nSorted List = ");
    for(i=0;i<size;i++)
    {
        if(i==size-1) printf(" %d",a[i]);
        else printf(" %d ,",a[i]);
    }

    return 0;
}
