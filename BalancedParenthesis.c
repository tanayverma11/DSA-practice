#include<stdio.h> 
#include<stdlib.h> 
#include<string.h> 
#define MAX 1000
 
int top = -1; 
char st[MAX]; 
 
void push(char val){ 
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
 
char peek(){ 
    if(top == -1){ 
        printf("Stack is Empty..."); 
        return '\0'; 
    } 
    return st[top]; 
} 
 
int isBalanced(char str[]){ 
    int n = strlen(str); 
    int cntCircularBracket = 0; 
    int cntSquareBracket = 0; 
    int cntAngularBracket = 0; 
    int cntCurleyBracket = 0; 
    for(int i=0; i<n; ++i){ 
        char ch = str[i]; 
        if(ch=='(' || ch=='<' || ch=='[' || ch=='{' || ch==')' || ch=='>' || 
ch==']' || ch=='}') { 
            if(ch=='(' || ch=='<' || ch=='[' || ch=='{'){ 
                push(ch); 
            } 
            else { 
                if(top == -1) { //stack is empty 
                    return 0; 
                } 
                else if(ch==')'&&peek()=='('){ 
                    ++cntCircularBracket; 
                    pop(); 
                } 
                else if(ch==']'&&peek()=='['){ 
                    ++cntSquareBracket; 
                    pop(); 
                } 
                else if(ch=='}'&&peek()=='{'){ 
                    ++cntCurleyBracket; 
                    pop(); 
                } 
                else if(ch=='>'&&peek()=='<'){ 
                    ++cntAngularBracket; 
                    pop(); 
                } 
                else return 0; 
            } 
        } 
    } 
    if(top == -1) { 
        if(cntCircularBracket<5 || cntAngularBracket<5 || cntCurleyBracket<5 
|| cntSquareBracket<5){ 
            printf("Insufficient number of pairs...\n"); 
        } 
        else if(cntCircularBracket<=10 || cntAngularBracket<=10 || 
cntCurleyBracket<=10 || cntSquareBracket<=10){ 
            printf("Moderate number of pairs...\n"); 
        } 
        else{ 
            printf("Sufficient number of pairs for each parenthesis...\n"); 
        } 
        return 1; 
    } 
    else return 0; 
} 
 
int main(){ 
    char str[10000]; 
    FILE *fptr = fopen("example.txt","r"); 
    int i=0; 
    char ch = getc(fptr); 
    while(ch != EOF){ 
        str[i++] = ch; 
        ch = getc(fptr); 
    } 
    fclose(fptr); 
    printf("%d",isBalanced(str)); 
    return 0; 
}