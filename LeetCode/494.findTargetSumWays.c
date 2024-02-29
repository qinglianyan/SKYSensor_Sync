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
    // 用一个大小为left的背包，从nums里面选物品，有多少种选法正好拿满
    // 物品的质量和价值是其本身数值
    if((sum+target)%2==1) return 0;
    if(abs(target)>sum) return 0;
    //
    int dp[numsSize][left+1];
    memset(dp, 0, sizeof(dp));

    dp[0][0]=1;
    if(nums[0]<=left){
        dp[0][nums[0]]=1;
    }
    // 下面这个自己没想出来
    if(nums[0]==0){
        dp[0][0]=2;
    }

    for(i=1;i<numsSize;i++){
        for(j=left;j>=nums[i];j--){
           dp[i][j]=dp[i-1][j]+dp[i-1][j-nums[i]]; 
        }
    }
    for(i=0;i<numsSize;i++){
        for(j=0;j<=left;j++){
            printf("%d ", dp[i][j]);
        }
        printf("\n");
    }
    //
    return dp[numsSize-1][left];
}

int main(){
    int i, j;
    int out;
    // int nums[5]={1, 1, 1, 1, 1};
    // int numsSize=5;
    // int target=3;

    int nums[9]={0, 0, 0, 0, 0, 0, 0, 0, 1};
    int numsSize=9;
    int target=1;

    out=findTargetSumWays(nums, numsSize, target);
    printf("__out = %d__\n", out);

    return 0;
}