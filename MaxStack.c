#include <stdio.h>
#define MAX 1000

int top=-1;
int st[MAX];

void push(int val){
    if(top == MAX-1){
        printf("Stack is full...");
        return; 
    }
    st[++top]=val;
}
int pop(){
    if(top == -1){
        printf("Stack is empty...");
        return -1;
    }
    return st[top--];
}
void display(){
    for(int i=0; i<=top; i++)
        printf("%d ",st[i]);
}

int main(){
    

    return 0;
}