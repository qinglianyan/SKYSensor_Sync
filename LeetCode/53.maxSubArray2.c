#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MIN_RET -10000
#define MAX(a, b) (a>b?a:b)
int maxSubArray(int* nums, int numsSize) {
    int i, j;
    int out=MIN_RET;// 记录返回值
    int dp[numsSize+1];
    memset(dp, 0, sizeof(dp));
    /**
     * dp[i]表示以nums[i-1]为结尾的最大连续子数组
     * 递推公式：
     * dp[i]=max(dp[i-1]+nums[i-1], nums[i-1])
    */
    memset(dp, 0, sizeof(dp));
    for(i=1;i<=numsSize;i++){
        dp[i]=MAX(dp[i-1]+nums[i-1], nums[i-1]);
        if(dp[i]>out){
            out=dp[i];
        }
    }
    

    return out;
}

int main(){
    int i, j;
    // int nums[]={-2, 1, -2, 4, -1, 2, 1, -5, 4};
    int nums[]={-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int numsSize=9;
    int out=0;

    out=maxSubArray(nums, numsSize);
    printf("out = %d\n", out);
    return 0;
}