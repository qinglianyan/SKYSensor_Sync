#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_NUM 1000
#define MAX_NUM_COUNT 20
#define MAX_NUM_SUM 1000

int findTargetSumWays(int* nums, int numsSize, int target) {
    int out=0;
    int i, j;
    int sum=0;
    int left=0;
    for(i=0;i<numsSize;i++){
        sum+=nums[i];
    }
    // 存在left-right=target,left+right=sum
    // 则 left=(sum+target)/2
    left=(sum+target)/2;
    // 到此为止，问题转化为了一个容量为left的背包问题
    // 物品的质量和价值是其本身数值


    return out;
}

int main(){
    int i, j;
    int out;
    int nums[5]={1, 1, 1, 1, 1};
    int numsSize=5;
    int target=3;

    out=findTargetSumWays(nums, numsSize, target);
    printf("__out = %d__\n", out);

    return 0;
}