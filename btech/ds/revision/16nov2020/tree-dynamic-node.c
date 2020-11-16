#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left, *right;
};

struct node* getnode(){
    return (struct node*) malloc(sizeof(struct node));
}

struct node* maketree(int x){
    struct node *q;
    q = getnode();
    q->data = x;
    q->left = q->right = '\0';
    if(q=='\0') exit(11);
    return q;
}

struct node* setleft(struct node *p, int x){
    struct node *q;
    if(p=='\0') exit(12);
    if(p->left!='\0') exit(13);
    q=maketree(x);
    p->left = q;
    return q;
}

struct node* setright(struct node *p,int x){
    struct node *q;
    if(p=='\0') exit(14);
    if(p->right!='\0')  exit(15);
    q=maketree(x);
    p->right = q;
    return q;
}

void pretrav(struct node *p){
    if(p=='\0') return;
    printf("%d ",p->data);
    pretrav(p->left);
    pretrav(p->right);
}

void intrav(struct node *p){
    if(p=='\0') return;
    intrav(p->left);
    printf("%d ",p->data);
    intrav(p->right);
}

void postrav(struct node *p){
    if(p=='\0') return;
    postrav(p->left);
    postrav(p->right);
    printf("%d ",p->data);
}

void main(){
    struct node *tree, *a, *b;
    tree = maketree(0);
    a = setleft(tree,1);
    b = setright(tree,2);
    setleft(a,3);
    setright(a,4);
    setleft(b,5);
    setright(b,6);
    
    printf("pretrav= ");pretrav(tree);printf("\n");
    printf("Intrav= ");intrav(tree);printf("\n");
    printf("postrav= ");postrav(tree);
    
}
