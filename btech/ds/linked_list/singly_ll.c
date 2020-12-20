#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node *next; //singly linked list
};

struct node *head='\0';

void insert_start(int x){
    struct node *q='\0';
    q = (struct node *)malloc(sizeof(struct node));
    if(q=='\0'){ printf("Memory full error"); exit(5);}
    q->info = x;
    q->next = '\0';
    q->next = head;
    head = q;
}

void insert_end(int x){
    struct node *last, *q;
    last=head;
    while(last->next!='\0'){
        last=last->next;
    }//last will point to last node
    
    q = '\0';
    q = (struct node *)malloc(sizeof(struct node));
    if(q=='\0') { printf("Memory full error"); exit(6); }
    q->info = x;
    q->next ='\0';
    last->next = q;
}

void inset_pos(int pos, int x){
    struct node *p, *q='\0';
    int i=1;
    p = head;
    while(i<pos-1){
        p = p->next;
        ++i;
    }//p is node, before the ith node
    q = (struct node *)malloc(sizeof(struct node));
    if(q=='\0') { printf("Memory full error"); exit(7); }
    q->info = x;
    q->next = p->next;
    p->next = q;
}

void display(){
    struct node *q=head;
    while(q!='\0'){
        printf("%d ",q->info);
        q = q->next;
    }
    printf("\nEnd of display\n");
}

int main()
{
    insert_start(1);
    insert_start(2);
    insert_start(3);
    insert_end(5);
    inset_pos(3,8);
    display();

    return 0;
}
