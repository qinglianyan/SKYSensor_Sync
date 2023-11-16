#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int search(int *nums, int numsSize, int target)
{
    int i, j;
    int mid;
    int left = 0, right = numsSize - 1;

    //target是在[left,right]中
    while (left <= right){
        mid = (left + right) / 2;
        if (nums[mid] == target){
            return mid;
        }
        else if (nums[mid] > target){
            right = mid-1;
        }
        else if (nums[mid] < target){
            left = mid+1;
        }
        else{
            //出错了
            return -2;
        }
    }
    return -1;
}

int main()
{
    int nums[] = {-1, 0, 3, 5, 9, 12};
    int numsSize;
    int target;
    int i, j, output;

    numsSize = 6, target = 2;
    output = search(nums, numsSize, target);
    printf("%d\n", output);

    // for(i=0;i<6;i++){
    //     printf("%d ",nums[i]);
    // }
    return 0;
}