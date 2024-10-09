#include<stdio.h>
#define MAX 100

int top = -1;
int st[MAX];

void push(int val){
    if(top == MAX-1) {
        printf("Stack is full...");
        return;
    }
    ++top;
    st[top] = val;
}

void pop(){
    if(top == -1){
        printf("Stack is Empty...");
        return;
    }
    --top;
}

int peek(){
    if(top == -1){
        printf("Stack is Empty...");
        return -1;
    }
    return st[top];
}

int main(){
    int pushed[100];
    int popped[100];
    int n;
    printf("Enter size of sequence: \n");
    scanf("%d",&n);
    printf("Enter the sequence of pushed elements: \n");
    for(int i=0; i<n; ++i){
        scanf("%d",&pushed[i]);
    }
    printf("Enter the sequence of popped elements: \n");
    for(int i=0; i<n; ++i){
        scanf("%d",&popped[i]);
    }
    
    //checking for valid sequences
    int j=0;
    for(int i=0; i<n; ++i){
        push(pushed[i]);
        while(top!=-1 && peek()==popped[j]) {
            pop();
            ++j;
        }
    }
    if(top == -1) printf("1");
    else printf("0");
    return 0;
}
