#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>



int *tree,*tree2,*tree3;
int last_index;


void intrav(int p){
    if(p>last_index) return;
    intrav(2*p+1);
    printf("%d ",tree[p]);
    intrav(2*p+2);
}

void pretrav(int p){
    if(p>last_index) return;
    printf("%d ",tree[p]);
    pretrav(2*p+1);
    pretrav(2*p+2);
}

void postrav(int p){
    if(p>last_index) return;
    postrav(2*p+1);
    postrav(2*p+2);
    printf("%d ",tree[p]);
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
    
    printf("Enter size of tree: ");
    scanf("%d",&no_of_data);
    
     tree2 = (int*)malloc(no_of_data * sizeof(int));
     tree = (int*)malloc(no_of_data * sizeof(int));
    
    printf("Enter elements of tree in sorted order: \n");
    while(count<no_of_data){
        scanf("%d",&tree2[count]);
        count++;
    }
    printf("Entered sorted elements = ");
    for(i=0;i<no_of_data;i++)
        printf("%d ",tree2[i]);
    printf("\n-----------\n");

    last_index = no_of_data - 1;
    
    recursion(0, last_index,0);     // this method creates the tree
    printf("\nContent of implicit array: \n");
    for(k=0;k<no_of_data;k++)
        printf("%d ",tree[k]);
    printf("\n=======\n");
    printf("\nPretrav = ");pretrav(tpos);
    printf("\nIntrav = ");intrav(tpos);
    printf("\nPostrav = ");postrav(tpos);
}
