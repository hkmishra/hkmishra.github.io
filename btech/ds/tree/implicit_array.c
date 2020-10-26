#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define SIZE 100

int tree[SIZE];

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

void main(){
    int tpos = 0;
    int a,b;
    maketree(9);
    a = setleft(tpos,1);
    b = setright(tpos,2);
    setleft(a,3);
    setright(a,4);
    setleft(b,5);
    setright(b,6);
    
    
    intrav(tpos);
}
