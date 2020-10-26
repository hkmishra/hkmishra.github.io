#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define SIZE 100

struct node{
    int data;
    int left;
    int right;
}tree[SIZE];

void maketree(int x){
    int i=2;
    tree[1].data=x;
    while(i<SIZE){
        tree[i].left='\0';
        tree[i].left='\0';
        tree[i++].data='\0';
    }
}

int avail_top=1;
int getnode(){
    return ++avail_top;
}

int setleft(int parent2,int x){
    int q;
    
    if(parent2=='\0') exit(35);
    if(tree[parent2].left!='\0')
        exit(4);
    q=getnode();
    
    tree[q].data=x;
    tree[parent2].left=q;
    return q;
}


int setright(int parent,int x){
    int q;
   if(parent=='\0') exit(30);
    if(tree[parent].right!='\0')
        exit(0);
    q=getnode();
    tree[q].data=x;
    tree[parent].right=q;
    return q;
}

void intrav(int parent){
    if(parent=='\0')
        return;
    intrav(tree[parent].left);
    printf("%d ",tree[parent].data);
    intrav(tree[parent].right);
}

void main(){
    int a,b,c,d;
    maketree(0);
    a=setleft(1,1);
    b=setright(1,2);
    setleft(a,3);
    setright(a,4);
    setleft(b,5);
    setright(b,6);
    intrav(1);
}
