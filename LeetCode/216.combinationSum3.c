#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int path[10];
int pathTop=0;

void backtracking(int k, int n, int startIndex, int **out, int *returnSize, int **returnColumnSizes){
    int i, j;
    int sum;
    if(pathTop==k){
        sum=0;
        for(i=0;i<pathTop;i++){
            sum+=path[i];
        }
        if(sum==n){
            //record in out;
            out[(*returnSize)]=(int*)malloc(sizeof(int)*9);
            (*returnColumnSizes)[(*returnSize)]=pathTop;
            for(i=0;i<pathTop;i++){
                out[(*returnSize)][i]=path[i];
            }
            (*returnSize)++;
            return ;
        }
        return ;
    }
    for(i=startIndex;i<=9;i++){
        path[pathTop++]=i;
        backtracking(k, n, i+1, out, returnSize, returnColumnSizes);
        pathTop--;
    }
}
int** combinationSum3(int k, int n, int* returnSize, int** returnColumnSizes) {
    int **out;
    // int **rCSizes=(int **)malloc(sizeof(int *));
    // *rCSizes=(int *)malloc(sizeof(int)*10000);
    out=(int **)malloc(sizeof(int *)*10000);
    *returnColumnSizes=(int *)malloc(sizeof(int)*10000);
    *returnSize=0;

    backtracking(k, n, 1, out, returnSize, returnColumnSizes);
    // *returnColumnSizes=(int *)malloc(sizeof(int)*(*returnSize));
    return out;
}

int main(){
    int k, n, i, j;
    int *returnSize=(int *)malloc(sizeof(int));
    int **returnColumnSizes=(int **)malloc(sizeof(int *));
    int **out;
    *returnSize=0;
    k=3, n=7;

    out=combinationSum3(k, n, returnSize, returnColumnSizes);
    for(i=0;i<(*returnSize);i++){
        for(j=0;j<(*returnColumnSizes)[i];j++){
            printf("%d ", out[i][j]);
        }printf("\n");
    }
    return 0;
}