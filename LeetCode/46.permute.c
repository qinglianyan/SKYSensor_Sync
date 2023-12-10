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
int hash[22];
void backstacking(int *nums, int numsSize, int **out,
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
        if(hash[nums[i]+11]==1){
            continue;
        }
        hash[nums[i]+11]=1;
        path[pathTop++]=nums[i];
        backstacking(nums, numsSize, out, index+1, returnSize, returnColumnSizes);
        hash[nums[i]+11]=0;
        pathTop--;
    }

    return ;
}
int** permute(int* nums, int numsSize, 
                int* returnSize, int** returnColumnSizes) {
    int **out;
    int i, j;
    (*returnSize)=0;
    pathTop=0;
    if(numsSize<=0){
        printf("numsSize Error!\n");
        return NULL;
    }
    out=(int **)malloc(sizeof(int *)*MAX_OUT);
    (*returnColumnSizes)=(int *)malloc(sizeof(int )*MAX_OUT);
    backstacking(nums, numsSize, out, 0, returnSize, returnColumnSizes);
    return out;
}

int main(){
    int i, j;
    int nums[2]={1, 0};
    int numsSize=2;
    int **out;
    int *returnSize=(int *)malloc(sizeof(int));
    int **returnColumnSizes=(int **)malloc(sizeof(int *));

    out=permute(nums, numsSize, returnSize, returnColumnSizes);
    for(i=0;i<(*returnSize);i++){
        for(j=0;j<(*returnColumnSizes)[i];j++){
            printf("%d ", out[i][j]);
        }printf("\n");
    }
    return 0;
}