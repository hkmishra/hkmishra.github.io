#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define STACKSIZE 100

struct stacktype {
    int top;
    int s[STACKSIZE];
};

void push(struct stacktype* stk,int x){
    if(stk->top==STACKSIZE-1)
        exit(1);
    stk->s[++stk->top]=x;
}

int pop(struct stacktype* stk){
    if(stk->top<0)
        exit(2);
    return stk->s[stk->top--];
}

void main(){
    struct stacktype stack;
    stack.top=-1;
    
    push(&stack,1);
    push(&stack,2);
    push(&stack,3);
    
    printf("%d ",pop(&stack));
    printf("%d ",pop(&stack));
    printf("%d ",pop(&stack));
}
