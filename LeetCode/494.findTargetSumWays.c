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