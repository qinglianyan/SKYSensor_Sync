#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
/**
 * 不确定循环次数，用回溯
 * 1、参数
 * 2、停止条件。目前拿的数字和大于target，或者等于target
 * 3、单次循环
*/
int path[100];
int pathTop=0;
int pathSum=0;

void backtracking(int *candidates, int candidatesSize, int target, int index, int **out, int *returnSize, int **returnColumnSizes){
    int i, j;
    if(pathTop>150){
        // 题目给的额外的出错条件
        printf("error : pathTop TOO LARGE!\n");
        return ;
    }
    if(pathSum>=target){// 停止条件
        if(pathSum==target){
            //找到了目标值，要记录在out里
            for(i=0;i<pathTop;i++){
                printf("%d ", path[i]);
            }printf("\n");
            return ;
        }
        else if(pathSum>target){
            //超出了
            return ;
        }
    }
    //单步循环
    for(i=0;i<candidatesSize;i++){
        path[pathTop]=candidates[i];
        pathSum+=candidates[i];
        pathTop++;
        backtracking(candidates, candidatesSize, target, index+1, out, returnSize, returnColumnSizes);
        pathSum-=candidates[i];
        pathTop--;
    }
    return ;
}

int** combinationSum(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes) {
    int **out;
    *returnSize=0;
    pathTop=0;
    pathSum=0;
    if(candidatesSize<=0){
        return NULL;
    }
    out=(int **)malloc(sizeof(int *)*151);
    returnColumnSizes=(int **)malloc(sizeof(int *));
    (*returnColumnSizes)=(int *)malloc(sizeof(int )*151);
    backtracking(candidates, candidatesSize, target, 0, out, returnSize, returnColumnSizes);

    return out;
}

int main(){
    int i, j;
    int **out;
    int candidates[4]={2, 3, 6, 7};
    int target=7;
    int candidatesSize=4;

    int *returnSize=(int *)malloc(sizeof(int));
    int **returnColumnSizes;
    *returnSize=0;
    out=combinationSum(candidates, candidatesSize, target, returnSize, returnColumnSizes);
    for(i=0;i<(*returnSize);i++){
        for(j=0;j<(*returnColumnSizes)[i];j++){
            printf("%d ", out[i][j]);
        }printf("\n");
    }
    return 0;
}