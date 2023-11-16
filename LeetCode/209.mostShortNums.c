#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int Min(int a, int b){
    if(a>b){
        return b;
    }
    else{
        return a;
    }
}

int minSubArrayLen(int target, int* nums, int numsSize){
    int i, j;
    int left, right;
    int sum=0, number;
    int ret=999999;

    left=0, right=0;
    for(right=0;right<numsSize;right++){
        sum+=nums[right];
        while(sum>=target){
            number=right-left+1;
            ret=Min(number, ret);
            sum-=nums[left++];
        }
    }
    if(ret==999999){
        return 0;
    }
    return ret;
}

int main(){
    int nums[]={2, 3, 1, 2, 4, 3};
    int target = 7;
    int numsSize = 6;
    int output;

    output=minSubArrayLen(target, nums, numsSize);
    printf("%d", output);
    return 0;
}