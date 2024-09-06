#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

char* clearDigits(char* s) {
    int i, j;
    int len=strlen(s);
    int nowIndex=0;
    int tmpIndex;
    while(nowIndex<len){
        if(s[nowIndex]>='0' && s[nowIndex] <='9'){
            nowIndex--;
            for(tmpIndex=nowIndex;s[tmpIndex+2]!='\0';tmpIndex++){
                s[tmpIndex]=s[tmpIndex+2];
            }s[tmpIndex]='\0';
            len-=2;
            nowIndex--;
        }
        nowIndex++;
    }
    return s;
}

int main(){
    int i, j;
    char *out;
    char s[10]="cbl34";
    out=clearDigits(s);
    printf("__out = %s__\n", out);
    return 0;
}