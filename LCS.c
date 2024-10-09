/* Ques. : Longest Common Subsequence

The longest common subsequence (LCS) is defined as the longest subsequence that is common 
to all the given sequences, provided that the elements of the subsequence are not required 
to occupy consecutive positions within the original sequences.

If S1 and S2 are the two given sequences then, 
Z is the common subsequence of S1 and S2 
    if Z is a subsequence of both S1 and S2. 
    Furthermore, Z must be a strictly increasing sequence of the indices of both S1 and S2.

If
S1 = {B, C, D, A, A, C, D}
S2 = {A, C, D, B, A, C}
Then, common subsequences are {B, C}, {C, D, A, C}, {D, A, C}, {A, A, C}, {A, C}, {C, D}
Among these subsequences, {C, D, A, C} is the longest common subsequence.

*/

#include<stdio.h>
#include<string.h>

int lcs(char s1[], char s2[], int m, int n){
    if(m==0 || n==0) return 0; //base case
    if(s1[m-1]==s2[n-1]){
        return 1 + lcs(s1,s2,m-1,n-1);  //include this character
    }
    else{   //exclude the character, return the greater of the worst cases
        return (lcs(s1,s2,m-1,n) > lcs(s1,s2,m,n-1)) ? lcs(s1,s2,m-1,n) : lcs(s1,s2,m,n-1);
    }
}

int main(){
    char s1[] = "BCDAACD";
    char s2[] = "ACDBAC";
    int m=strlen(s1);
    int n=strlen(s2);
    printf("Length of Longest Common Subsequence is: %d", lcs(s1,s2,m,n));
    return 0;
}