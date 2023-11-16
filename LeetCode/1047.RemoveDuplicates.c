#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 20000
char stack[MAX];
int top=0;
void pushStack(char * stack, int * top, char ch){
    if((*top)>=MAX){
        printf("over stack\n");
        return ;
    }
    stack[(*top)++]=ch;
    return;
}
char popStack(char * stack, int * top){
    if((*top)<=0){
        printf("empty stack\n");
        return '\0';
    }
    return stack[--(*top)];
}

char* removeDuplicates(char* s) {
    int i, j;
    int index=0;
    top=0;
    while(s[index]!='\0'){
        if(top==0){
            pushStack(stack, &top, s[index]);
        }
        else if(s[index]==stack[top-1]){
            popStack(stack, &top);
        }
        else{
            pushStack(stack, &top, s[index]);
        }
        index++;
    }
    pushStack(stack, &top, '\0');
    return stack;
}

int main(){
    char input[10]="azxxzy";
    char * output;
    printf("input = ||%s||\n", input);
    output=removeDuplicates(input);
    printf("output= ||%s||\n", output);
    return 0;
}