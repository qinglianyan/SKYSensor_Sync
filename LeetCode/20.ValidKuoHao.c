#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void pushzhan(char * zhan, int *top, char ch){
    if(*top>10000){
        return;
    }
    zhan[(*top)++]=ch;
}
char popzhan(char * zhan, int *top){
    if(*top==0){
        return '\0';
    }
    return zhan[--(*top)];
}

bool isValid(char* s) {
    int i, j;
    int len=strlen(s);
    char zhan[10000];
    int top=0;
    char tmp;
    for(i=0;i<len;i++){
        if(s[i]=='('||s[i]=='['||s[i]=='{'){
            pushzhan(zhan, &top, s[i]);
        }
        else if(s[i]==')'||s[i]==']'||s[i]=='}'){
            tmp=popzhan(zhan, &top);
            if(s[i]==')'&&tmp!='('){
                return false;
            }
            else if((s[i]==']')&&(tmp!='[')){
                return false;
            }
            else if(s[i]=='}'&&tmp!='{'){
                return false;
            }
        }
        else{
            return false;
        }
    }
    if(top!=0){
        return false;
    }

    return true;
}

int main(){
    char input[10]="(]";
    bool output;

    output=isValid(input);
    printf("%d\n", output);
    return 0;
}