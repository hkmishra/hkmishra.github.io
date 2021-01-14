#include <stdio.h>
#include <conio.h>

void merge(int a[],int p, int q,int r);
void merge_sort(int a[],int p,int r);


void merge_sort(int a[],int p,int r)
{
    int q;
    if(p<r){
        q=(p+r)/2;
        merge_sort(a,p,q);
        merge_sort(a,q+1,r);
        merge(a,p,q,r);
    }
}

void merge(int a[],int p, int q,int r)
{
    int a1 = q-p+1;
    int a2 = r-q;
    int l[a1],ri[a2];
    int i,j,k;
    
    for(i=0;i<a1;i++){
        l[i] = a[p+i];
    }
    
    for(i=0;i<a2;i++){
        ri[i] = a[q+1+i];
    }
    
    j=0;k=0;
    
    for(i=p;i<=r;i++)
    {
        if(j<a1 && k<a2)
        {
            if(l[j]<=ri[k]){
                a[i] = l[j];
                j++;
            }
            else {
                a[i] = ri[k];
                k++;
            }
        }
        else
        {
            if(j==a1){
                a[i]=ri[k];
                k++;
            }
            else{
                a[i]=l[j];
                j++;
            }
        }
    }
    
}

int main()
{
    int a[]={1,5,2,4,5,8,7,6};
    int n = 8;
    int i;
    merge_sort(a,0,7);
    
    for(i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    
    return 0;
}
