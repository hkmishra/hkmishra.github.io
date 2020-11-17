#include <stdio.h>
#include <stdlib.h>>

int stack[1000];
int top=-1;

void push(int x){
    if(top==100-1)  exit(11);
    stack[++top]=x;
}

int pop(){
    if(top<0)   exit(12);
    return stack[top--];
}

/* It prints the prime factor of the number
void display_stack(){
    int x;int top2=top;
    if(top2<0) {  printf("nothing to display"); exit(15); }
    while(top2>-1){
        
        x=stack[top2--];
        printf("%d ",x);
    }
}
*/

int count_unique_stack(){
    int x,y,count=0;
    if(top<0) {  printf("nothing to display2"); exit(15); }
    while(top>-1){
        y=x;
        x=pop();
        if(x!=y)    count++;
    }
    return count;
}

int prime(int x){
    int i=1,count=0;
    for(i=1;i<=x;i++){
        if(x%i==0)
            count++;
    }
    if(count==2){
        return 1;
    }
    return 0;
}

int next_prime(int pn,int no_itself){
    int x=pn+1;
    while(1){
        if(x>no_itself) return -1;
        if(prime(x)) return x;
        x++;
    }
}

int pc2(int n){
    int a = 2;
    
    while(1){
        if(n<2) break;
        if(prime(n)) {
            push(n);
            break;
        }
        if(n%a==0){
            push(a);
           // printf("a= %d n = %d\n",a,n);
            n = n/a;
            // printf("n= %d\n====\n",n);
        }else{
            a=next_prime(a,n);
        //    printf("next_prime= %d\n",a);
            if(a==-1) break;
        }    
    }
    // printf("\nend of pc2");
    
}

int pc(int x){
    int y;
    pc2(x);
//    display_stack();  //it displays the prime factor of the numnber
    y = count_unique_stack();
    top = -1; //set stack empty
    return y;
    
}

void copf(int data[],int n,int cpf[]){
    int i,n1;
    
    for(i=0;i<n;i++){
        n1=pc(data[i]);
        cpf[i]=n1;
    }
     
    
}

int main()
{
    int n,i; int *data, *cpf;
    printf("n = ");
    scanf("%d",&n);
    if(n<1 || n>1000){
        printf("Illegal Entery");
        exit(16);
    }
    data = (int *)malloc(n*sizeof(int));
    cpf = (int *)malloc(n*sizeof(int));
    
    printf("Enter data one by one:\n");
    for(i=0;i<n;i++){
        scanf("%d",&data[i]);
    }
    
    printf("\nInput =\t");
    for(i=0;i<n;i++){
        printf("%d\t",data[i]);
    }
    
    copf(data,n,cpf);
    
    printf("\ncpf =\t");
    for(i=0;i<n;i++){
        printf("%d\t",cpf[i]);
    }
    
    return 0;
}
