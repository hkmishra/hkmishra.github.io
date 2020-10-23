#include <stdio.h>
#include <stdlib.h>
#define STACKSIZE 100

struct stacktype {
    int top;
    char s[STACKSIZE];
}stack;



void push(struct stacktype* stack2,char x){
    if(stack2->top==STACKSIZE-1)
        exit(0);
    stack2->s[++(stack2->top)]=x;
}

void display(struct stacktype* stack2){
    int i=0;
    for(i=stack2->top;i!=-1;i--){
        printf("%c ",stack2->s[i]);
    }
}

char pop(struct stacktype* stack2){
    if(stack2->top==-1)
        exit(0);
    return stack2->s[stack2->top--];
}

void main(){
    stack.top=-1;
    char string[STACKSIZE];
    int i=0;
    scanf("%s",&string);
    printf("Original String = %s\n",string);
    while(string[i]!='\0')
        push(&stack,string[i++]);
        
    printf("Reversed string = ");
    while(stack.top!=-1)
        printf("%c",pop(&stack));
    
    display(&stack);
}
