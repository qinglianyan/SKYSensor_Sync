#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/**
 * Note: The returned array must be malloced, 
 * assume caller calls free().
 */
int* searchRange(int* nums, int numsSize, 
                 int target, int* returnSize){
    //二分查找找出现，然后左右遍历找起始点、终止点
    int left, right, mid;
    int* ret = (int * )malloc( sizeof(int) * 2 );

    *returnSize=2;
    left = 0, right = numsSize - 1;
    //目标target在[left, right]中
    while(left <= right){
        mid = (left + right) / 2;
        if(nums[mid] == target){
            ret[0] = ret[1] = mid;
            while(ret[0] >= 0 && nums[ret[0]] == target){
                ret[0]--;
            }
            ret[0]++;
            while(ret[1] <= numsSize-1 && nums[ret[1]] == target){
                ret[1]++;
            }
            ret[1]--;
            return ret;
        }
        else if(nums[mid] < target){
            left = mid + 1;
        }
        else if(nums[mid] > target){
            right = mid - 1;
        }
        else{
            ret[0] = ret[1] = -2;
            return ret;
        }
    }
    //没找到
    ret[0] = ret[1] = -1;
    return ret;
}

int main(){
    int nums[]={5, 7, 7, 8, 8, 10};
    int numsSize, target;
    int i, j;
    int* output;
    int returnSize;

    numsSize = 6;
    target = 8;
    returnSize=2;
    output = searchRange(nums, numsSize, target, &returnSize);
    for(i = 0;i < 2;i++){
        printf("%d ", output[i]);
    }
    return 0;
}