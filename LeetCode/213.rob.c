#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define MAX(a, b) a>b?a:b

int robCount(int *nums, int numsSize, int bbegin, int eend){
    int i, j;
    int dp[numsSize];
    memset(dp, 0, sizeof(dp));
    dp[1]=nums[bbegin];
    for(i=2;i<numsSize;i++){
        dp[i]=MAX(dp[i-1], dp[i-2]+nums[i-1+bbegin]);
    }
    return dp[numsSize-1];
}

int rob(int* nums, int numsSize) {
    int i, j;
    /**
     * 对于nums[numsSize],这个题目只有两种情况，
     * 一种是去掉第一家，偷下标1到numsSize-1
     * 另一种是去掉最后一家，投下标0到numsSize-2
    */
    int ret1, ret2;
    if(numsSize==1){
        return nums[0];
    }
    else if(numsSize==2){
        return MAX(nums[0], nums[1]);
    }
    else{
        ret1=robCount(nums, numsSize, 0, numsSize-2);
        ret2=robCount(nums, numsSize, 1, numsSize-1);
        return MAX(ret1, ret2);
    }
    return 0;
}

int main(){
    int i, j;
    int numsSize=3;
    int * nums=(int *)malloc(sizeof(int)*numsSize);
    int out=-1;
    nums[0]=2, nums[1]=3, nums[2]=2;
    out=rob(nums, numsSize);
    printf("__out = %d__\n", out);
    return 0;
}