#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char path[10];
int pathTop=0;
char phone[10][10]={
    "",     //0
    "",     //1
    "abc",  //2
    "def",  //3
    "ghi",  //4
    "jkl",  //5
    "mno",  //6
    "pqrs", //7
    "tuv",  //8
    "wxyz"  //9
};

void backtracking(char *digits, char **out, int *returnSize, int index){
    int i, j;
    int num=0;
    if(pathTop==strlen(digits)){
        //找到一个，要存到out里
        // path[pathTop++]='\0';
        // printf("%s\n", path);
        // pathTop--;
        out[(*returnSize)]=(char *)malloc(sizeof(char)*5);
        for(i=0;i<pathTop;i++){
            out[(*returnSize)][i]=path[i];
        }
        out[(*returnSize)][i]='\0';
        (*returnSize)++;
        return;
    }
    num=digits[index]-'0';
    for(i=0;i<strlen(phone[num]);i++){
        path[pathTop]=phone[num][i];
        pathTop++;
        backtracking(digits, out, returnSize, index+1);
        pathTop--;
    }
    return ;
}

char** letterCombinations(char* digits, int* returnSize) {
    char **out;
    *returnSize=0;
    pathTop=0;
    if(strlen(digits)==0){
        return NULL;
    }
    out=(char **)malloc(sizeof(char *)*(4*4*4*4+1));
    backtracking(digits, out, returnSize, 0);

    return out;
}

int main(){
    int i, j;
    char digits[10]="5678";
    int *returnSize=(int *)malloc(sizeof(int));
    char **out;

    out=letterCombinations(digits, returnSize);
    for(i=0;i<(*returnSize);i++){
        printf("%s\n", out[i]);
    }

    // for(i=0;i<10;i++){
    //     printf("%d : %s\n", i, phone[i]);
    // }
    return 0;
}