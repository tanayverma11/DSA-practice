#include<stdio.h>

int main(){
    char text[100000];
    printf("Enter text in upper case: ");
    scanf("%s",text);
    int shift;
    printf("Enter a number between 0-25: ");
    scanf("%d",&shift);
    for(int i=0; text[i]!='\0'; ++i){
        text[i] = ((text[i]-'A'+shift)%26)+'A';
    }
    printf("%s",text);
}