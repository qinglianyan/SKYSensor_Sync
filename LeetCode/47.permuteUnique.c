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
int path[10];
int pathTop=0;
int cmp(const void *p1, const void *p2){
    return *(int *)p1 - *(int *)p2;
}
void backstacking(  int *nums, int numsSize, int **out, 
                    int index, int *returnSize, 
                    int **returnColumnSizes){
    int i, j;
    if(pathTop>=numsSize){
        for(i=0;i<pathTop;i++){
            printf("%d ", path[i]);
        }printf("\n");
        return ;
    }
    // 单步循环
    for(i=0;i<numsSize;i++){
        if(i>index&&nums[i]==nums[i-1]){
            continue;
        }
        path[pathTop++]=nums[i];
        backstacking(nums, numsSize, out, i+1, returnSize, returnColumnSizes);
        pathTop--;
    }

    return;
}
int** permuteUnique(int* nums, int numsSize, 
                    int* returnSize, 
                    int** returnColumnSizes) {
    int **out;
    int i, j;
    (*returnSize)=0;
    pathTop=0;
    if(numsSize<=0){
        printf("numsSize Error!\n");
        return NULL;
    }
    qsort(nums, numsSize, sizeof(int), cmp);
    out=(int **)malloc(sizeof(int *)*MAX_OUT);
    (*returnColumnSizes)=(int *)malloc(sizeof(int )*MAX_OUT);
    backstacking(nums, numsSize, out, 0, returnSize, returnColumnSizes);
    return out;
}

int main(){
    int i, j;
    int nums[3]={1, 1, 2};
    int numsSize=3;
    int **out;
    int *returnSize=(int *)malloc(sizeof(int));
    int **returnColumnSizes=(int **)malloc(sizeof(int *));

    out=permuteUnique(nums, numsSize, returnSize, returnColumnSizes);
    for(i=0;i<(*returnSize);i++){
        for(j=0;j<(*returnColumnSizes)[i];j++){
            printf("%d ", out[i][j]);
        }printf("\n");
    }
    return 0;
}