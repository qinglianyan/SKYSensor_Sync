#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#define MAX_OUT 10000
int path[20];
int pathTop=0;
int cmp(const void *p1, const void *p2){
    return *(int *)p1 - *(int *)p2;
}

void backtracking(int *nums, int numsSize, int **out, int index, int *returnSize, int **returnColumnSizes){
    int i, j;
    // for(i=0;i<pathTop;i++){
    //     printf("%d ", path[i]);
    // }printf("\n");
    out[(*returnSize)]=(int *)malloc(sizeof(int )*pathTop);
    (*returnColumnSizes)[(*returnSize)]=pathTop;
    for(i=0;i<pathTop;i++){
        out[(*returnSize)][i]=path[i];
    }
    (*returnSize)++;
    
    if(index>=numsSize){
        return;
    }
    // 单步循环
    for(i=index;i<numsSize;i++){
        if(i>index&&nums[i]==nums[i-1]){
            continue;
        }
        path[pathTop++]=nums[i];
        backtracking(nums, numsSize, out, i+1, returnSize, returnColumnSizes);
        pathTop--;
    }
    return ;
}
int** subsetsWithDup(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    int i, j;
    int **out;
    (*returnSize)=0;
    pathTop=0;
    if(numsSize<=0){
        printf("Error : numsSize!\n");
        return NULL;
    }
    out=(int **)malloc(sizeof(int *)*MAX_OUT);
    (*returnColumnSizes)=(int *)malloc(sizeof(int )*MAX_OUT);
    qsort(nums, numsSize, sizeof(int), cmp);
    backtracking(nums, numsSize, out, 0, returnSize, returnColumnSizes);
    return out;
}

int main(){
    int **out;
    int i, j;
    int nums[3]={2, 1, 2};
    int numsSize=3;
    int *returnSize=(int *)malloc(sizeof(int));
    int **returnColumnSizes=(int **)malloc(sizeof(int *));
    
    out=subsetsWithDup(nums, numsSize, returnSize, returnColumnSizes);
    for(i=0;i<(*returnSize);i++){
        for(j=0;j<(*returnColumnSizes)[i];j++){
            printf("%d ", out[i][j]);
        }printf("\n");
    }
    return 0;
}