#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char path[20][20];
int pathTop=0;

bool isValidNum(char *s, int left, int right){
    int sLen=right-left+1;
    int i, j;
    int num;
    if(sLen==0){
        return false;
    }
    else if(sLen==1){
        return true;
    }
    else{
        if(s[left]=='0'){
            return false;
        }
        if(sLen>3){
            return false;
        }
        else if(sLen==2){
            return true;
        }
        else if(sLen==3){
            num=(s[left]-'0')*100+(s[left+1]-'0')*10+(s[left+2]-'0');
            if(num>255){
                return false;
            }
            return true;
        }
        else {
            printf("is Valid Error!\n");
            return false;
        }

    }

    return true;
}

void backtracking(char *s, char **out, int index, int *returnSize){
    int i, j;
    if(index>=strlen(s)&&pathTop==4){
        //找到一个满足题意的
        // for(i=0;i<4;i++){
        //     printf("%s ", path[i]);
        // }printf("\n");
        out[(*returnSize)]=(char *)malloc(sizeof(char)*30);
        // printf("sizeof out[] = %d\n", sizeof(out[(*returnSize)]));
        snprintf(out[(*returnSize)], 30, "%s.%s.%s.%s", path[0], path[1], path[2], path[3]);
        out[(*returnSize)][index+3]='\0';
        (*returnSize)++;
        return ;
    }
    // 单步循环
    if(pathTop>=4&&index<strlen(s)){
        return ;
    }
    if(pathTop<4&&index>=strlen(s)){
        return ;
    }
    for(i=index;i<strlen(s);i++){
        if(isValidNum(s, index, i)){
            for(j=0;j<=(i-index);j++){
                path[pathTop][j]=s[j+index];
            }
            // printf("left = %d, right = %d", index, i);
            path[pathTop][j]='\0';
            // printf("  path = %s\n", path[pathTop]);
            pathTop++;
        }
        else{
            break;
        }
        backtracking(s, out, i+1, returnSize);
        pathTop--;
    }

    return ;
}
char** restoreIpAddresses(char* s, int* returnSize) {
    char **out;
    int i, j;
    int sLen=strlen(s);
    (*returnSize)=0;
    if(sLen<4){
        return NULL;
    }
    out=(char **)malloc(sizeof(char *)*20);
    backtracking(s, out, 0, returnSize);
    return out;
}

int main(){
    char **out;
    int i, j, k;
    char s[21]="101023";
    int *returnSize=(int *)malloc(sizeof(int));
    *returnSize=0;
    out=restoreIpAddresses(s, returnSize);
    for(i=0;i<(*returnSize);i++){
        printf("%s \n", out[i]);
    }
    return 0;
}