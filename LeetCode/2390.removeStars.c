#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

char* removeStars(char* s) {
    int i, j;
    int len=strlen(s);
    int nowindex=strlen(s)-1;
    int countStar=0;
    for(i=nowindex;i>=0;){
        if(s[i]=='*'){
            countStar++;
            i--;
        }
        else{
            if(countStar>0){
                countStar--;
                i--;
            }
            else{
                s[nowindex]=s[i];
                i--;
                nowindex--;
            }
        }
    }
    return s+(nowindex+1)*sizeof(char);
}

int main(){
    int i, j;
    char s[50]="leet**cod*e";
    //printf("%s", s);
    char *output;
    output=removeStars(s);
    printf("__out = %s__\n", output);
    return 0;
}