#include <stdio.h>
#include<stdlib.h>

void min_heap(int a[],int x,int n)//n points to last index
{
    int i,j,temp;
    j = n;
    a[n]=x;
    
    
    while(j>=2 && a[j/2]>a[j])
    {
        //swap starts
        temp = a[j];
        a[j]=a[j/2];
        a[j/2]=temp;
        //swap ends
        j = j/2;
    }

}//end of function


int delete_heap(int a[],int *last)//n points to last index
{
    int p,j,l,r,temp,n;
    n=*last;
    if(n<1){ exit(5); }
    if(n==1){ *last-=1; return a[1]; }
    p = a[1];
    a[1]=a[n];
    
    j=1;
    while(j<n && 2*j<n)
    {
        l=2*j;
        r=2*j+1;
        if(r>=n){
            if(a[l]<a[j]){
                //swap start here
                temp=a[l];
                a[l]=a[j];
                a[j]=temp;
                //swap ends here
                j=l;
            }
            break;
        }
        if(a[l]<a[r])//left child is min
        {
            if(a[l]<a[j])
            {
                //swap start here
                temp=a[l];
                a[l]=a[j];
                a[j]=temp;
                //swap ends here
                j=l;
            }
        }else{//right child is min
            if(a[r]<a[j])
            {
                //swap start here
                temp=a[r];
                a[r]=a[j];
                a[j]=temp;
                //swap ends here
                j=r;
            }
        }
        
        
    }
    
    *last-=1;
    return p;
}


void heap_sort(int a[],int *n)
{
    int i,j;
    j=*n;
    for(i=0;i<j;i++){
        a[j-i]=delete_heap(a,n);
    }
}

int main()
{
    int i,j,x,limit;
    int a[100];
    int n= 0;
    
    printf("Enter no of elements to sort: ");
    scanf("%d",&limit);
    j=limit;
    
    printf("Enter elements: \n");
    for(i=0;i<j;i++){
        scanf("%d",&x);
        min_heap(a,x,++n);
    }
    
    printf("\nHeap Tree = \n");
    for(i=1;i<n+1;i++){
        printf("%d ",a[i]);
    }
    
    
    heap_sort(a,&n);
    
    printf("\nAfter Sorting = \n");
    for(i=1;i<limit+1;i++){
        printf("%d ",a[i]);
    }
  

    return 0;
}
