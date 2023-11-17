#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void pushStack(int * stack, int * top, int num){
    stack[(*top)++]=num;
    return ;
}
int popStack(int * stack, int * top){
    return stack[--(*top)];
}
int peekStack(int * stack, int * top){
    return stack[(*top)-1];
}

int evalRPN(char** tokens, int tokensSize) {
    int i, j;
    int stack[10000];
    int top=0;
    int index=0;
    int tmpNum=0;
    int num1, num2, num3;
    for(index=0;index<tokensSize;index++){
        if(tokens[index][1]=='\0'&&tokens[index][0]=='+'){
            num1=popStack(stack, &top);
            num2=popStack(stack, &top);
            pushStack(stack, &top, num1+num2);
        }
        else if(tokens[index][1]=='\0'&&tokens[index][0]=='-'){
            num1=popStack(stack, &top);
            num2=popStack(stack, &top);
            pushStack(stack, &top, num2-num1);
        }
        else if(tokens[index][1]=='\0'&&tokens[index][0]=='*'){
            num1=popStack(stack, &top);
            num2=popStack(stack, &top);
            pushStack(stack, &top, num1*num2);
        }
        else if(tokens[index][1]=='\0'&&tokens[index][0]=='/'){
            num1=popStack(stack, &top);
            num2=popStack(stack, &top);
            pushStack(stack, &top, num2/num1);
        }
        else{
            tmpNum=atoi(tokens[index]);
            pushStack(stack, &top, tmpNum);
        }
    }
    if(top!=1){
        return -1;
    }
    return stack[top-1];
}

int main(){
    // char tokens[5][5]={"4", "13", "5", "/", "+"};
    char ** tokens;
    int i, j;
    int out=0;
    int tokensize=13;
    tokens=(char **)malloc(13*sizeof(char *));
    for(i=0;i<13;i++){
        tokens[i]=(char *)malloc(5*sizeof(char));
    }
    tokens[0]="10";
    tokens[1]="6";
    tokens[2]="9";
    tokens[3]="3";
    tokens[4]="+";
    tokens[5]="-11";
    tokens[6]="*";
    tokens[7]="/";
    tokens[8]="*";
    tokens[9]="17";
    tokens[10]="+";
    tokens[11]="5";
    tokens[12]="+";
    
    
    // for(i=0;i<5;i++){
    //     printf("tokens[%d] = %s\n", i, tokens[i]);
    // }
    //printf("atoi=%d\n", atoi(tokens[1]));
    out=evalRPN(tokens, tokensize);
    printf("out=%d\n", out);
    return 0;
}