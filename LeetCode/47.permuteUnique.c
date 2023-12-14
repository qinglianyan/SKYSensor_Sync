#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#define MAX_OUT 800
int path[10];
int pathTop=0;
int hash[22];
int cmp(const void *p1, const void *p2){
    return *(int *)p1-*(int *)p2;
}
void backtracking(int *nums, int numsSize, int **out,
                int index, int *returnSize, 
                int **returnColumnSizes){
    int i, j;
    /**
     * -10<=nums[i]<=10
    */
    
    if(pathTop==numsSize){
        // 返回条件
        // 找到了三个数字，一种排列
        // for(i=0;i<pathTop;i++){
        //     printf("%d ", path[i]);
        // }printf("\n");
        out[(*returnSize)]=(int *)malloc(sizeof(int)*pathTop);
        (*returnColumnSizes)[(*returnSize)]=pathTop;
        for(i=0;i<pathTop;i++){
            out[(*returnSize)][i]=path[i];
        }
        (*returnSize)++;
        return;
    }
    // 单步循环
    for(i=0;i<numsSize;i++){
        // if(hash[i]==1){
        //     continue;
        // }
        if(i>0&&nums[i]==nums[i-1]&&hash[i-1]==1){
            continue;
        }
        if(hash[i]==0){
            hash[i]=1;
            path[pathTop++]=nums[i];
            backtracking(nums, numsSize, out, index+1, returnSize, returnColumnSizes);
            hash[i]=0;
            pathTop--;
        }
    }

    return ;
}

int** permuteUnique(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
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
    backtracking(nums, numsSize, out, 0, returnSize, returnColumnSizes);
    return out;
}

int main(){
    int i, j;
    int nums[3]={1, 1, 2};
    int numsSize=3;
    int **out;
    int *returnSize=(int *)malloc(sizeof(int));
    int **returnColumnSizes=(int **)malloc(sizeof(int *));
    (*returnSize)=0;
    out=permuteUnique(nums, numsSize, returnSize, returnColumnSizes);
    for(i=0;i<(*returnSize);i++){
        for(j=0;j<(*returnColumnSizes)[i];j++){
            printf("%d ", out[i][j]);
        }printf("\n");
    }
    return 0;
}