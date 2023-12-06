#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int path[21];
int pathTop=0;
// bool pathEmpty(int *pathTop){
//     if((*pathTop)<=0)    return true;
//     return false;
// }
// void pathPush(int *pathTop, )
void backtracking(int n, int k, int startIndex, int **out, int *returnsize, int **returnColumnSizes){
    int i, j;
    if(pathTop==k){
        out[(*returnsize)]=(int*)malloc(sizeof(int)*21);
        // returnColumnSizes[(*returnsize)]=(int *)malloc(sizeof(int));
        // (*(returnColumnSizes[(*returnsize)]))=pathTop;
        (*returnColumnSizes)[(*returnsize)]=pathTop;
        for(i=0;i<pathTop;i++){
            out[(*returnsize)][i]=path[i];
        }
        // pathTop=0;
        (*returnsize)++;
        return ;
    }
    for(i=startIndex;i<=n;i++){
        path[pathTop++]=i;
        backtracking(n, k, i+1, out, returnsize, returnColumnSizes);
        pathTop--;
    }
}
int** combine(int n, int k, int* returnSize, int** returnColumnSizes) {
    int **out=(int **)malloc(sizeof(int *)*200001);
    *returnColumnSizes=(int *)malloc(sizeof(int)*200001);
    *returnSize=0;
    
    backtracking(n, k, 1, out, returnSize, returnColumnSizes);
    return out;
}

int main(){
    int i, j, n, k;
    int **out;
    int *returnSize=(int *)malloc(sizeof(int));
    int **returnColumnSizes=(int **)malloc(sizeof(int *));
    n=7, k=3;
    *returnSize=0;

    out=combine(n, k, returnSize, returnColumnSizes);
    for(i=0;i<(*returnSize);i++){
        for(j=0;j<(*returnColumnSizes)[i];j++){
            printf("%d ", out[i][j]);
        }printf("\n");
    }
    return 0;
}