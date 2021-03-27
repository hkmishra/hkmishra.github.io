#include <stdio.h>
#include <stdlib.h>
#define N 8

int count=0;

//print Solution + intermediate array
void printArray(int a[N][N])
{
    int i,j;
    printf("\nArrray = \n");
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            printf("%d\t",a[i][j]);
        }
        printf("\n");
    }
}

//only print Solution : -1 is printed as 0
void printArray2(int a[N][N])
{
    int i,j;
    printf("\nArrray = \n");
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            if(a[i][j]==-1)
                printf("-\t");
            else
                printf("%d\t",a[i][j]);
        }
        printf("\n");
    }
}

void setDiagonal(int a[N][N],int pos1,int pos2)
{
    int i,j;
    for(i=pos1,j=pos2;i>=0&&j>=0;i--,j--)
    {
        if(a[i][j]==0)
            a[i][j]=-1;
    }
    for(i=pos1,j=pos2;i>=0 && j<N;i--,j++)
    {
        if(a[i][j]==0)
            a[i][j]=-1;
    }
    for(i=pos1,j=pos2;i<N&&j>=0;i++,j--)
    {
        if(a[i][j]==0)
            a[i][j]=-1;
    }
    for(i=pos1,j=pos2;i<N && j<N;i++,j++)
    {
        if(a[i][j]==0)
            a[i][j]=-1;
    }
}

void setQueen(int a[N][N],int pos1,int pos2)
{
    int i,j;

    for(i=0;i<N;i++){
        if(a[i][pos2]==0)
            a[i][pos2]=-1;
    }
    for(i=0;i<N;i++){
        if(a[pos1][i]==0)
            a[pos1][i]=-1;
    }
    
    setDiagonal(a,pos1,pos2);
    a[pos1][pos2]=1;
}

int no_of_queen(int a[N][N])
{
    int count=0;
    int i,j;
    for(i=0;i<N;i++){
        for(j=0;j<N;j++)
        {
            if(a[i][j]==1)
                count++;
        }
    }
    return count;
}


void setZero(int a[N][N])
{
    int i,j;
    for(i=0;i<N;i++){
        for(j=0;j<N;j++)
        {
            a[i][j]=0;
        }
    }
}


void test_ok(int a[N][N]){
    if(no_of_queen(a)==N){
        count++;
        printf("\nSolution %d : ",count);
        printf("\n================================");
        printArray2(a);
        printf("================================\n");
        //exit(0);
    }
}


int test_ok_code(int a[N][N]){
    if(no_of_queen(a)==N){
        return 1;   //passed
    }
    return 0;   //failed
}


void copy_array(int a[N][N],int b[N][N]){
    int i,j;
    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            a[i][j]=b[i][j];
        }
    }
}

void nqueen(int a[N][N],int c)
{
    int i=0;
    int b[N][N];
    setZero(b);
    for(i=0;i<N;i++){
        if(c==0){
            setZero(a);
        }
       
        if(c==N){
            return;
        }
        if(a[c][i]==0){
            copy_array(b,a);
            setQueen(a,c,i);
//                printf("\nsuccess part: %d",i);
//                printArray(a);

            if(c==N-1){
                return;
            }
            
            nqueen(a,c+1);
            
             if(test_ok_code(a))
            {
                test_ok(a);
                //exit(0);      //exit in backtracking
            }
            
            copy_array(a,b);
        }
        
//        printf("\nreturning... %d : %d\n",c,i);
        
    }
    return;
}



int main()
{
    int a[N][N];
    setZero(a);
    printf("N Queen Problem General Iterative Solution");
    printf("\nBy: Harsh Kumar");
    printf("\n  Btech/60314/19 CSE");
    printf("\n\n\n");
    
    nqueen(a,0);
    
    printf("\n\nTotal No of solutions found: %d",count);
    
    return 0;
}
    
