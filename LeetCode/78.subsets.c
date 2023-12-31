#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int path[11];
int pathTop=0;
int cmp(const void *p1, const void *p2){
    return *(int *)p1-*(int *)p2;
}
void backtracking(int *nums, int numsSize, int index, int **out, int *returnSize, int **returnColumnSizes){
    int i, j;
    // for(i=0;i<pathTop;i++){
    //         printf("%d ", path[i]);
    // }printf("\n");
    out[(*returnSize)]=(int *)malloc(sizeof(int)*pathTop);
    (*returnColumnSizes)[(*returnSize)]=pathTop;
    for(i=0;i<pathTop;i++){
        out[(*returnSize)][i]=path[i];
    }
    (*returnSize)++;

    if(index>=numsSize){
        // 终止条件
        
        return ;
    }
    // 单步循环
    for(i=index;i<numsSize;i++){
        //push [index, i]
        path[pathTop++]=nums[i];
        backtracking(nums, numsSize, i+1, out, returnSize, returnColumnSizes);
        pathTop--;
    }
    return ;
}
int** subsets(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    int **out;
    int i, j;
    (*returnSize)=0;
    pathTop=0;
    if(numsSize<1){
        printf("numsSize Error!\n");
        return NULL;
    }
    out=(int **)malloc(sizeof(int *)*10000);
    (*returnColumnSizes)=(int *)malloc(sizeof(int)*10000);
    //sort 不用sort
    // qsort(nums, numsSize, sizeof(int), cmp);
    //out[0]=[] 不用手动加入空集
    // (*returnColumnSizes)[(*returnSize)++]=0;

    backtracking(nums, numsSize, 0, out, returnSize, returnColumnSizes);
    return out;
}

int main(){
    int **out;
    int i, j;
    int nums[3]={1, 3, 2};
    int numsSize=3;
    int *returnSize=(int *)malloc(sizeof(int));
    int **returnColumnSizes=(int **)malloc(sizeof(int *));

    out=subsets(nums, numsSize, returnSize, returnColumnSizes);
    for(i=0;i<(*returnSize);i++){
        for(j=0;j<(*returnColumnSizes)[i];j++){
            printf("%d ", out[i][j]);
        }printf("\n");
    }
    return 0;
}