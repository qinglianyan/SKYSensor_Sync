#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int path[10];
int pathTop=0;
char** letterCombinations(char* digits, int* returnSize) {
    char **out;
    *returnSize=0;
    if(strlen(digits)==0){
        return NULL;
    }
    out=(char **)malloc(sizeof(char *)*(3*3*3*3+1));


    return out;
}

int main(){
    int i, j;
    char digits[10]="23";
    int *returnSize=(int *)malloc(sizeof(int));
    char **out;

    out=letterCombinations(digits, returnSize);
    for(i=0;i<(*returnSize);i++){
        printf("%s\n", out[i]);
    }
    return 0;
}