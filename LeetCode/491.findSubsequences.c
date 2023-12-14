#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#define MAX_OUT 100000
int path[20];
int pathTop=0;
int cmp(const void *p1, const void *p2){
    return *(int *)p1-*(int *)p2;
}
void backtracking(int *nums, int numsSize, int **out,
                    int index, int *returnSize,
                    int **returnColumnSizes){
    int i, j;
    int hash[202];
    memset(hash, 0, sizeof(int)*202);
    if(pathTop>=2){
        //至少有两个元素
        // for(i=0;i<pathTop;i++){
        //     printf("%d ", path[i]);
        // }printf("\n");
        out[(*returnSize)]=(int *)malloc(sizeof(int)*pathTop);
        (*returnColumnSizes)[(*returnSize)]=pathTop;
        for(i=0;i<pathTop;i++){
            out[(*returnSize)][i]=path[i];
        }
        (*returnSize)++;
        // return ;
    }
    // 单步循环
    for(i=index;i<numsSize;i++){
        // // patch 1 :排除重复元素
        // if(i>index&&nums[i]==nums[i-1]){
        //     continue;
        // }
        // patch 2 :保证非严格递增
        if(pathTop>0&&nums[i]<path[pathTop-1]){
            continue;
        }
        // path 3 :
        if(hash[nums[i]+100]==1){
            continue;
        }
        hash[nums[i]+100]=1;

        path[pathTop++]=nums[i];
        backtracking(nums, numsSize, out, i+1,
                    returnSize, returnColumnSizes);
        pathTop--;
    }
    return ;
}
int** findSubsequences(int* nums, int numsSize, 
    int* returnSize, int** returnColumnSizes) {
    int i , j;
    int **out;
    (*returnSize)=0;
    pathTop=0;
    if(numsSize<=0){
        printf("error!\n");
        return NULL;
    }
    // qsort(nums, numsSize, sizeof(int), cmp);
    out=(int **)malloc(sizeof(int *)*MAX_OUT);
    (*returnColumnSizes)=(int *)malloc(sizeof(int )*MAX_OUT);
    backtracking(nums, numsSize, out, 0, returnSize, returnColumnSizes);
    return out;
}

int main(){
    int nums[15]={1, 2, 3, 4, 5,
                    6, 7, 8, 9, 10,
                    1, 1, 1, 1, 1};
    int numsSize=15;
    // int nums[4]={1, 2, 1, 1};
    // int numsSize=4;
    int **out;
    int *returnSize=(int *)malloc(sizeof(int));
    int **returnColumnSizes=(int **)malloc(sizeof(int *));
    int i, j;

    out=findSubsequences(nums, numsSize, returnSize, returnColumnSizes);
    for(i=0;i<(*returnSize);i++){
        printf("i = %d ||", i);
        for(j=0;j<(*returnColumnSizes)[i];j++){
            printf("%d ", out[i][j]);
        }printf("\n");
    }
    return 0;
}