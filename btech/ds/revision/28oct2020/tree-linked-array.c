#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define SIZE 100

struct node{
    int data;
    int left, right;
};

int getnode(){
    static int count = 2;
    return count++;
}

void maketree(struct node *nd,int x){
    int q=1;
    nd[q].data=x;
    while(q<SIZE){
        nd[q].left='\0';
        nd[q].right='\0';
        q++;
    }
}

int setleft(struct node *nd,int p,int x){
    int q;
    if(p=='\0')
        exit(1);
    if(nd[p].left!='\0')
        exit(2);
    q=getnode();
    if(q=='\0')
        exit(3);
    nd[q].data=x;
    nd[p].left=q;
    return q;
}

int setright(struct node *nd,int p,int x){
    int q;
    if(p=='\0')
        exit(4);
    if(nd[p].right!='\0')
        exit(5);
    q=getnode();
    if(q=='\0')
        exit(6);
    nd[q].data=x;
    nd[p].right=q;
    return q;
}


void intrav(struct node *nd,int p){
    if(p=='\0')
        return;
    intrav(nd,nd[p].left);
    printf("%d ",nd[p].data);
    intrav(nd,nd[p].right);
}

void main(){
    struct node nd[SIZE];
    int a,b,tree=1;
    maketree(nd,0);
    a=setleft(nd,tree,1);
    b=setright(nd,tree,2);
    setleft(nd,a,3);
    setright(nd,a,4);
    setleft(nd,b,5);
    setright(nd,b,6);
    
    intrav(nd,tree);
}
