#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int evalRPN(char** tokens, int tokensSize) {
    
}

int main(){
    char tokens[5]={"2", "1", "+", "3", "*"};
    int i, j;
    for(i=0;i<5;i++){
        printf("tokens[%d] = %c\n", i, tokens[i]);
    }
    return 0;
}