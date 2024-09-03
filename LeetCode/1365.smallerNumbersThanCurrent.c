#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int cmp(const void *a, const void *b){
    return *(int *)a-*(int *)b;
}
int* smallerNumbersThanCurrent(int* nums, int numsSize, int* returnSize) {
    int i, j;
    int *ret=(int *)malloc(sizeof(int)*numsSize);
    int *tmp=(int *)malloc(sizeof(int)*numsSize);
    int hash[101]={0};
    *returnSize=numsSize;

    memcpy(tmp, nums, sizeof(nums[0])*numsSize);
    qsort(tmp, numsSize, sizeof(tmp[0]), cmp);
    // for(i=0;i<numsSize;i++){
    //     printf("%d ", nums[i]);
    // }printf("\n------\n");
    for(i=numsSize-1;i>=0;i--){
        hash[tmp[i]]=i;
    }
    for(i=0;i<numsSize;i++){
        ret[i]=hash[nums[i]];
    }

    return ret;
}

int main(){
    int i, j;
    int numsSize;
    int nums[5]={8, 1, 2, 2, 3};
    int returnSize=0;
    int *out;
    numsSize=5;
    out=smallerNumbersThanCurrent(nums, numsSize, &returnSize);
    for(i=0;i<returnSize;i++){
        printf("%d ", out[i]);
    }
    return 0;
}