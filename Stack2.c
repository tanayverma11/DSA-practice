/* 
Write a C code to implement the operations of stack using arrays. Take a string as an 
input. Read the input string character by character. If the character read is an alphabet 
push it on to the stack. If the character read is an *, pop top three elements from the 
stack and display it. If nothing is popped print numbers in increment count for each 
empty pop. At the end of input string display the contents of stack in the order pushed. 

EXAMPLE 1: 
Input: 
DA**TAST*RUC*TURES* 
Output: 
AD1234TSACURSER 
Stack: 
UTT 

EXAMPLE 2: 
Input: 
LA*ST*INFIR*STOUT* 
Output: 
AL1TS2RIFTOU 
Stack: 
TSNI 
*/

#include <stdio.h>
#include <string.h>
#define MAX 1000

int top = -1;
char st[MAX];

void push(char val){
    if(top == MAX-1){
        printf("Stack is full...");
        return;
    }
    st[++top] = val;
}

char pop(){
    if(top == -1){
        //printf("Stack is empty...");
        return '0';
    }
    return st[top--];
}

int main(){
    printf("Enter the string: \n");
    char s[1000];
    scanf("%s",&s);
    int cnt = 1;
    for(int i=0; i<strlen(s); i++){
        char ch = s[i];
        if(ch>='A' && ch<='Z'){ 
            push(ch);
        }
        else if(ch=='*'){
            for(int j=1; j<=3; j++){
                char popped = pop();
                if(popped == '0'){
                    printf("%d",(cnt++));
                } else{
                    printf("%c",popped);
                }
            }
        }
    }
    return 0;
}