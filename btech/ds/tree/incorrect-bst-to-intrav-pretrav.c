#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
#define SIZE 100


int *tree,*tree2,*tree3;

void maketree(int x){
    int i=1;
    tree[0] = x;
    while(i<SIZE)
        tree[i++]='-1';
}

int setleft(int p,int x){
    int l = 2*p+1;
    if(tree[p]=='-1') return -1;
    if(tree[l]!='-1') return -1;
    if(l>SIZE-1) return 0;
    tree[l]=x;
    return l;
}

int setright(int p,int x){
    int r=2*p+2;
    if(tree[p]=='-1') return 0;
    if(tree[r] != '-1') return 0;
    if(r>SIZE-1) return 0;
    tree[r]=x;
    return r;
}

void intrav(int p){
    if(tree[p]=='-1') return 0;
    intrav(2*p+1);
    printf("%d ",tree[p]);
    intrav(2*p+2);
}

//////////////////////////////////////
void recursion(int start, int stop, int p){
    int middle=  start+floor((stop-start+1)/2);
//    printf("\nM=%d ",middle);
    tree[p] = tree2[middle];
    if(middle<=0||middle>6)
        return;
    if(start<0||stop>6||p>7) return;
    if(p!=0 && p%2==0) {
        recursion(start-1,middle,2*p+1);
    }
    else{
    recursion(0,middle-1,2*p+1);
    }
    
    recursion(middle+1,stop,2*p+2);
}
/////////////////////////////////////

void main(){
    
    
    int tpos = 0;
    int a,b,k=0;
    int no_of_data,count=0,i=-1;
    int last_index;
    printf("Enter size of tree: ");
    scanf("%d",&no_of_data);
    
     tree2 = (int*)malloc(no_of_data * sizeof(int));
     tree = (int*)malloc(no_of_data * sizeof(int));
    
    printf("Enter sorted tree: \npress negative integer to stop entering\n");
    while(count<no_of_data){
        scanf("%d",&tree2[count]);
        count++;
    }
    for(i=0;i<no_of_data;i++)
        printf("%d ",tree2[i]);
    printf("\n-----------\n");
 
 
    maketree(9);
    a = setleft(tpos,1);
    b = setright(tpos,2);
    setleft(a,3);
    setright(a,4);
    setleft(b,5);
    setright(b,6);
    
    
    intrav(tpos);
    
    
    last_index = no_of_data - 1;
    
    printf("\n\n");
    recursion(0, last_index,0);
    for(k=0;k<no_of_data;k++)
        printf("%d ",tree[k]);
    printf("\n=======\n");
    intrav(tpos);
}
