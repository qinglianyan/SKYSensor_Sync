#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortedSquares(int* nums, int numsSize, int* returnSize){
    int left = 0, right = numsSize - 1;
    int index = numsSize - 1;
    int * ret = (int *)malloc(sizeof(int)*numsSize);
    int left2, right2;
    *returnSize = numsSize;

    while((left <= right) && (index >= 0)){
        left2 = nums[left] * nums[left];
        right2 = nums[right] * nums[right];
        if(left2 < right2){
            ret[index--] = right2;
            right--;
        }
        else{
            ret[index--] = left2;
            left++;
        }
    }
    return ret;
}

int main(){
    int nums[] = { -4, -1, 0, 3, 10};
    int numsSize = 5;
    int returnSize = 5;
    int * output;
    int i, j;

    output=sortedSquares(nums, numsSize, &returnSize);
    for(i=0;i<returnSize;i++){
        printf("%d ", output[i]);
    }
    return 0;
}