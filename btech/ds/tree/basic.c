#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
};


struct node* getnode(){
    return (struct node*)malloc(sizeof(struct node));
}

struct node* maketree(int x){
    struct node* q;
    q=getnode();
    if(q=='\0'){
        printf("Memory full problem.");
        exit(0);
    }
    
    q->data=x;
    q->left='\0';
    q->right='\0';
    return q;
}

struct node* setleft(struct node* parent,int x){
    struct node* q;
    if(parent=='\0')
        exit(0);
    if(parent->left!='\0')
        exit(0);
    q=maketree(x);
    parent->left=q;
    return q;
}

struct node* setright(struct node* parent, int x){
    struct node* q;
    if(parent=='\0')
        exit(0);
    if(parent->right!='\0')
        exit(0);
    q=maketree(x);
    parent->right=q;
    return q;
}

void intrav(struct node* tree){
    if(tree=='\0')
        return;
    intrav(tree->left);
    printf("%d ",tree->data);
    intrav(tree->right);
}

void pretrav(struct node* tree){
    if(tree=='\0')
        return;
    printf("%d ",tree->data);
    pretrav(tree->left);
    pretrav(tree->right);
}


void postrav(struct node* tree){
    if(tree=='\0')
        return;
    postrav(tree->left);
    postrav(tree->right);
    printf("%d ",tree->data);
}


void main(){
    struct node* tree,*l1,*r1;
    tree = maketree(0);
    l1=setleft(tree,1);
    r1=setright(tree,2);
    setleft(l1,3);
    setright(l1,4);
    setleft(r1,5);
    setright(r1,6);
    
    printf("pretrav =");
    pretrav(tree);
    printf("\nIntrav =");
    intrav(tree);
    printf("\npostrav =");
    postrav(tree);
}
