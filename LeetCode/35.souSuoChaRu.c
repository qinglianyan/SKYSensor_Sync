#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int searchInsert(int* nums, int numsSize, int target){
    int left, right, mid;
    //二分查找
    left = 0, right = numsSize - 1;
    //判断target是否在[left, right]中
    while(left <= right){
        mid = (left + right) / 2;
        if(nums[mid] == target){
            return mid;
        }
        else if(nums[mid] < target){
            left = mid + 1;
        }
        else if(nums[mid] > target){
            right = mid - 1;
        }
        else{
            //出错了
            return -2;
        }
    }
    //没有找到
    if(nums[mid] < target){
        return mid + 1;
    }
    else{//这里容易错
        return mid;
    }
}

int main(){
    int nums[]={1,3,5,6};
    int numsSize, target;
    int i, j, output;

    numsSize=4;
    target=2;
    output=searchInsert(nums, numsSize, target);
    printf("%d", output);
    return 0;
}