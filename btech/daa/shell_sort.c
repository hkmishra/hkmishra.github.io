#include <stdio.h>
#include<math.h>

void shell_sort(int a[],int size)
{
    int gap,j,i,temp;
    for(gap = floor(size/2);gap>=1;gap=floor(gap/2))
    {
        for(j=gap;j<size;j++)
        {
            for(i=j-gap;i>=0;i=i-gap)
            {
                if(a[i+gap]>a[i])
                {
                    break;
                }
                else{
                    temp=a[i+gap];
                    a[i+gap]=a[i];
                    a[i]=temp;
                }
            }
        }
    }
}


void shell_sort2(int a[],int size)
{
    int gap,j,i,temp;
    for(gap = floor(size/2);gap>=1;gap=floor(gap/2))
    {
        for(j=gap;j<size;j++)
        {
            i=j-gap;
            while(i>=0 && a[i]>a[i+gap])
            {
                temp=a[i+gap];
                a[i+gap]=a[i];
                a[i]=temp;
                
                i=i-gap;
            }
        }
    }
}


void insertion_sort(int a[],int size)
{
    int i,j,key;
    for(j=1;j<size;j++)
    {
        i = j-1;
        key = a[j];
        while(i>=0 && a[i]>key)
        {
            a[i+1] = a[i];
            i--;
        }
        a[i+1]=key;
    }
}

int main()
{
    int a[]={23,29,15,19,31,7,9,5,2};
    int i,size;
    size= sizeof(a)/sizeof(int);
    
    //insertion_sort(a,size);
    shell_sort2(a,size);
    
    for(i=0;i<size;i++)
    {
        printf("%d ",a[i]);
    }
    return 0;
}
