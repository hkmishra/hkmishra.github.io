#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define SIZE 100

int data[SIZE];

void maketree(int x){
    int i=1;
    data[0]=x;
    while(i<SIZE)
        data[i++]=-1;
}

int setleft(int p,int x){
    int q=2*p+1;
    if(data[p]==-1)
        exit(1);
    if(data[q]!=-1)
        exit(2);
    data[q]=x;
    return q;
}

int setright(int p,int x){
    int q=2*p+2;
    if(data[p]==-1)
        exit(3);
    if(data[q]!=-1)
        exit(4);
    data[q]=x;
    return q;
}

void intrav(int p){
    if(data[p]==-1)
        return;
    intrav(2*p+1);
    printf("%d ",data[p]);
    intrav(2*p+2);
}

void main(){
    int a,b,tree=0;
    maketree(0);
    a=setleft(tree,1);
    b=setright(tree,2);
    setleft(a,3);
    setright(a,4);
    setleft(b,5);
    setright(b,6);
    
    intrav(tree);
}
