#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct node {
    int data;
    struct node *left, *right;
};

struct node* getnode(){
    return (struct node*)malloc(sizeof(struct node));
}

struct node* maketree(int x){
    struct node *q;
    q=getnode();
    q->data=x;
    q->left='\0';
    q->right='\0';
    return q;
}

struct node* setleft(struct node *p,int x){
    struct node *q;
    if(p=='\0')
        exit(1);
    if(p->left!='\0')
        exit(2);
    q=maketree(x);
    if(q=='\0')
        exit(3);
    p->left=q;
    return q;
}

struct node* setright(struct node *p, int x){
    struct node *q;
    if(p=='\0')
        exit(4);
    if(p->right!='\0')
        exit(5);
    q=maketree(x);
    if(q=='\0')
        exit(6);
    p->right=q;
    return q;
}

void intrav(struct node *p){
    if(p=='\0')
        return;
    intrav(p->left);
    printf("%d ",p->data);
    intrav(p->right);
}

void main(){
    struct node *tree, *a, *b;
    tree=maketree(0);
    a=setleft(tree,1);
    b=setright(tree,2);
    setleft(a,3);
    setright(a,4);
    setleft(b,5);
    setright(b,6);
    
    intrav(tree);
}
