#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int combinationSum4(int* nums, int numsSize, int target) {
    int i, j;
    int m, n;
    // int dp[target+1];
    int *dp=(int *)calloc(target+1, sizeof(int));
    dp[0]=1;

    // loop
    for(j=0;j<=target;j++){
        for(i=0;i<numsSize;i++){
            if(j>=nums[i]&&dp[j]<INT_MAX-dp[j-nums[i]]){
                dp[j]+=dp[j-nums[i]];
            }
        }
        // //loop
        // printf("-----------\n");
        // for(m=0;m<=target;m++){
        //     printf("%d ", dp[m]);
        // }printf("\n");
    }
    return dp[target];
}

int main(){
    int i, j;
    int out;
    int numsSize=3;
    int target=4;
    int *nums=(int *)malloc(sizeof(int)*numsSize);
    nums[0]=1, nums[1]=2, nums[2]=3;
    out=combinationSum4(nums, numsSize, target);
    printf("__out = %d__\n", out);
    return 0;
}