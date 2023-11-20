#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* topKFrequent(int* nums, int numsSize, int k, int* returnSize) {
    int i, j;
    
}

int main(){
    int nums[6]={1, 1, 1, 2, 2, 3};
    int numsSize=6;
    int k=2;

    // int nums[1]={1};
    // int numsSize=1;
    // int k=1;

    int * returnSize=(int *)malloc(sizeof(int));
    int *out;
    int i;
    out=topKFrequent(nums, numsSize, k, returnSize);
    for(i=0;i<(*returnSize);i++){
        printf("%d ", out[i]);
    }
    return 0;
}