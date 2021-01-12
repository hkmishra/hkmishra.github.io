#include <stdio.h>

int A[]={1,0,1,0,1};
int B[]={1,1,0,0,1};
int C[6];
int n=5;

int main()
{
    int i,j,carry=0,sum=0;;
    i=n-1;
    
    while(i>-1)
    {
        
        sum=A[i]+B[i]+carry;
//        printf("%d : %d: %d: %d\n",A[i],B[i],carry,sum);
        switch(sum)
        {
            case 0: C[i+1] = 0; carry = 0; break;
            case 1: C[i+1] = 1; carry = 0; break;
            case 2: C[i+1] = 0; carry = 1; break;
            case 3: C[i+1] = 1; carry = 1; break;
        }
        
        
        if(i==0 && carry==1){
//            printf("----");
            C[0] = 1;break;
        }
        
        
        i--;
    }
    
    for(j=0;j<n+1;j++)
        printf("%d ",C[j]);
    return 0;
}
