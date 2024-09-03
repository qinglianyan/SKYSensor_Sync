#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int findPermutationDifference(char* s, char* t) {
    int i, j;
    int hash[26];
    int sum=0;
    int len=strlen(s);
    memset(hash, 0, sizeof(hash));
    for(i=0;s[i]!='\0';i++){
        hash[s[i]-'a']=i;
    }
    for(i=0;i<len;i++){
        sum+=abs(i-hash[t[i]-'a']);
    }
    return sum;
}

int main(){
    int i, j;
    int out;
    char s[50]="abc";
    char t[50]="bac";
    printf("s = %s\n", s);
    printf("t = %s\n", t);

    out=0;
    out=findPermutationDifference(s, t);
    printf("__out = %d__\n", out);
    return 0;
}