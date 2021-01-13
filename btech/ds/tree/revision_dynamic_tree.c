#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct node {
  int info;
  struct node *left, *right;
};

struct node* getnode(){
    struct node* q;
    q=(struct node*)malloc(sizeof(struct node));
    return q;
}

struct node* maketree(int x){
    struct node* q;
    q=getnode();
    q->info=x;
    q->left = '\0';
    q->right = '\0';
    return q;
}

struct node* setleft(struct node* p, int x){
    struct node* q;
    q=getnode();
    if(p=='\0')exit(2);
    if(p->left!='\0') exit(3);
    q->info = x;
    p->left = q;
    return q;
}

struct node* setright(struct node* p, int x){
    struct node* q;
    q=getnode();
    if(p=='\0') exit(4);
    if(p->right!='\0') exit(5);
    q->info = x;
    p->right = q;
    return q;
}

int intrav(struct node* p){
    if(p=='\0') return 0;
    intrav(p->left);
    printf("%d ",p->info);
    intrav(p->right);
}

int pretrav(struct node* p){
    if(p=='\0') return 0;
    printf("%d ",p->info);
    pretrav(p->left);
    pretrav(p->right);
}

int postrav(struct node *p){
    if(p=='\0') return 0;
    postrav(p->left);
    postrav(p->right);
    printf("%d ",p->info);
}

int main()
{
    
    struct node* root;
    struct node *a, *b, *c,*d,*e;
    root = maketree(1);
    a= setleft(root,2);
    b= setright(root,3);
    
    setleft(a,4);
    setright(a,5);
    setleft(b,6);
    setright(b,7);
    
    printf("Intrav = ");
    intrav(root);
    printf("\nPretrav = ");
    pretrav(root);
    printf("\nPostrav = ");
    postrav(root);
    
    return 0;
}
