#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int lengthOfLIS(int* nums, int numsSize) {
    int i, j;
    int dp[numsSize];
    int maxLength;
    int max=1;
    memset(dp, 0, sizeof(dp));
    /**
     * dp[i]表示的是以nums[i]结尾的严格递增子序列
     * 所以nums[i]对于每个j∈[0, i-1]都有
     *  if nums[i]>nums[j] 
     *      nums[i]=nums[j]+1;
    */
    dp[0]=1;
    for(i=1;i<numsSize;i++){
        dp[i]=1;
        for(j=0;j<i;j++){
            if(nums[i]>nums[j]){
                if(dp[j]+1>dp[i]){
                    dp[i]=dp[j]+1;
                    if(dp[i]>max){
                        max=dp[i];
                    }
                }
            }
        }
    }
    for(i=0;i<numsSize;i++){
        printf("%d ", dp[i]);
    }
    return max;
}

int main(){
    int i, j;
    // int numsSize=8;
    // int nums[8]={10, 9, 2, 5, 3, 7, 101, 18};

    // int numsSize=6;
    // int nums[6]={0, 1, 0, 3, 2, 3};

    int numsSize=7;
    int nums[7]={7, 7, 7, 7, 7, 7, 7};

    // int numsSize=9;
    // int nums[9]={1,3,6,7,9,4,10,5,6};
    int out=0;
    out=lengthOfLIS(nums, numsSize);
    printf("__out = %d__\n", out);
    return 0;
}