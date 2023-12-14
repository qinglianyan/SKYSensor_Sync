#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

char path[1000][20];
int pathTop=0;

bool isHuiwen(char *s, int left, int right){
    int i, j;
    if(left==right){
        return true;
    }
    while(s[left]==s[right]){
        left++;right--;
        if(left>=right){
            return true;
        }
    }
    return false;
}

void backtracking(char *s, char ***out, int index, int *returnSize, int **returnColumnSizes){
    int i, j;
    if(index>=strlen(s)){
        /**
         * 终止条件,找到的回文串就全放在path里面
         * index到字符串尾就算找到了一个
         * 要存储到out里
        */
        // for(i=0;i<pathTop;i++){
        //     printf("||%s|| ", path[i]);
        // }printf("\n");
        
        out[(*returnSize)]=(char **)malloc(sizeof(char *)*pathTop);
        (*returnColumnSizes)[(*returnSize)]=pathTop;
        // printf("pathTop = %d, *returnSize = %d\n", pathTop, (*returnSize));
        for(i=0;i<pathTop;i++){
            out[(*returnSize)][i]=(char *)malloc(sizeof(char)*17);
            strcpy(out[(*returnSize)][i], path[i]);
        }
        (*returnSize)++;
        return ;
    }
    //单步循环
    for(i=index;i<strlen(s);i++){
        if(isHuiwen(s, index, i)){
            for(j=0;j<=(i-index);j++){
                path[pathTop][j]=s[j+index];
            }
            // printf("left = %d, right = %d", index, i);
            path[pathTop][j]='\0';
            // printf("  path = %s\n", path[pathTop]);
            pathTop++;
            // index=i;
        }
        else{
            continue;
        }
        backtracking(s, out, i+1, returnSize, returnColumnSizes);
        pathTop--;
    }
    return ;
}
char*** partition(char* s, int* returnSize, int** returnColumnSizes) {
    int i, j, k;
    char ***out;
    int sLen=strlen(s);
    *returnSize=0;
    if(sLen==0){
        return NULL;
    }
    pathTop=0;
    /**
     * 注意多维指针
     * 1、char*指向一个字符串
     * 2、char**指向一个字符串数组
     * 3、char***指向out
    */
    out=(char ***)malloc(sizeof(char **)*50000);
    *returnColumnSizes=(int *)malloc(sizeof(int)*50000);
    backtracking(s, out, 0, returnSize, returnColumnSizes);
    return out;
}

int main(){
    char ***out;
    int i, j, k;
    char s[20]="bbbbbbbbbbbbbbbb";
    int *returnSize=(int *)malloc(sizeof(int));
    int **returnColumnSizes=(int **)malloc(sizeof(int *));
    *returnSize=0;

    out=partition(s, returnSize, returnColumnSizes);
    // for(i=0;i<(*returnSize);i++){
    //     for(j=0;j<(*returnColumnSizes)[i];j++){
    //         printf("||%s|| ", out[i][j]);
    //     }printf("\n");
    // }

    return 0;
}