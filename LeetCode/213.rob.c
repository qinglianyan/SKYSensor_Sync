#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define MAX(a, b) a>b?a:b

int rob(int* nums, int numsSize) {
    int i, j, m;
    int dp[numsSize+1];
    bool record_1[numsSize+1];// 记录第一家是否被偷了
    /** dp[i]表示从第一家到第i家一共能偷多少钱
     * 两种情况：
     *  如果第i家不偷，d[i]=d[i-1]
     *  如果第i家偷，那么i-1家就不能偷，d[i]=d[i-2]+nums[i];
     * 初始化：d[0]=0, d[1]=nums[1]
    */
    memset(dp, 0, sizeof(dp));
    memset(record_1, 0, sizeof(record_1));
    record_1[1]=true;
    dp[1]=nums[0];
    if(numsSize==1){
        return dp[1];
    }
    for(i=2;i<=numsSize;i++){
        if(i==numsSize){
            if(record_1[i-2]==false){
                return MAX(dp[i-1], dp[i-2]+nums[i-1]);
            }
            else{
                if(record_1[i-1]==true){
                    return dp[i-1];
                }
                else{
                    return MAX(dp[i-1], dp[i-2]);
                }
            }
        }
        else{
            if(dp[i-1]>dp[i-2]+nums[i-1]){
                dp[i]=dp[i-1];
                record_1[i]=record_1[i-1];
            }
            else{
                dp[i]=dp[i-2]+nums[i-1];
                record_1[i]=record_1[i-2];
            }
        }
        printf("dp:\n");
        for(m=0;m<=numsSize;m++){
            printf("%d ", dp[m]);
        }printf("\n");
        printf("record:\n");
        for(m=0;m<=numsSize;m++){
            printf("%d ", record_1[m]);
        }printf("\n");
    }

    return dp[numsSize];
}

int main(){
    int i, j;
    // int numsSize=4;
    int numsSize=3;
    int * nums=(int *)malloc(sizeof(int)*numsSize);
    int out=-1;
    // nums[0]=1, nums[1]=2, nums[2]=3, nums[3]=1;
    nums[0]=1, nums[1]=2, nums[2]=3;
    out=rob(nums, numsSize);
    printf("__out = %d__\n", out);
    return 0;
}