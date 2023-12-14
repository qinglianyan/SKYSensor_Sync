#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MIN_RET -10000

int maxSubArray(int* nums, int numsSize) {
    int i, j;
    int out=MIN_RET;// 记录返回值
    int count=0;
    for(i=0;i<numsSize;i++){
        count+=nums[i];
        if(count>out){
            out=count;
        }
        if(count<=0) count=0;
    }
    return out;
}

int main(){
    int i, j;
    int nums[]={-2, 1, -2, 4, -1, 2, 1, -5, 4};
    int numsSize=9;
    int out=0;

    out=maxSubArray(nums, numsSize);
    printf("out = %d\n", out);
    return 0;
}