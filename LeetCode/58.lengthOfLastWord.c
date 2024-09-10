#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>



int lengthOfLastWord(char* s) {
    int i, j;
    int len=strlen(s);
    int left, right;
    i=len-1;
    while(s[i]==' '){
        i--;
    }
    right=i;
    while( (s[i]>='a'&&s[i]<='z') || (s[i]>='A'&&s[i]<='Z')){
        i--;
        if(i==-1){
            left=0;
            break;
        }
    }
    left=i;
    return right-left;
}

int main(){
    int i, j;
    char s[200]="a";
    int out;
    out=lengthOfLastWord(s);
    printf("__out = %d__\n", out);
    return 0;
}