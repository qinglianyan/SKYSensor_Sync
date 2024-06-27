#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

/**
 * 给两个整数数组 nums1 和 nums2 ，返回两个数组中公共的 
 * 长度最长的子数组的长度 。
示例 1：
输入：nums1 = [1,2,3,2,1], nums2 = [3,2,1,4,7]
输出：3
解释：长度最长的公共子数组是 [3,2,1] 

示例 2：
输入：nums1 = [0,0,0,0,0], nums2 = [0,0,0,0,0]
输出：5
 
*/
int findLength(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int i, j;
    int out=0;
    int dp[nums1Size+1][nums2Size+1];
    memset(dp, 0, sizeof(dp));
    /**
     * dp[i][j]表示以nums1[i]结尾，以nums2[j]结尾的相同的子数组的长度
     * if nums1[i]==nums2[j]
     *      dp[i][j]=dp[i-1][j-1]+1;
     * else dp[i][j]=0;
     * 初始化全0
    */
    // printf("nums1 = ");
    // for(i=0;i<nums1Size;i++){
    //     printf("%d ", nums1[i]);
    // }printf("\n");

    // printf("nums2 = ");
    // for(i=0;i<nums1Size;i++){
    //     printf("%d ", nums2[i]);
    // }printf("\n");

    for(i=1;i<=nums1Size;i++){
        for(j=1;j<=nums2Size;j++){
            if(nums1[i-1]==nums2[j-1]){
                dp[i][j]=dp[i-1][j-1]+1;
                if(dp[i][j]>out){
                    out=dp[i][j];
                }
            }
            else{
                dp[i][j]=0;
            }
            // printf("%d ", dp[i][j]);
        }
        // printf("\n");
    }
    return out;
}

int main(){
    int i, j;
    int nums1Size, nums2Size;
    nums1Size=5, nums2Size=5;
    int nums1[5]={1, 2, 3, 2, 1};
    int nums2[5]={3, 2, 1, 4, 7};

    // int nums1[5]={0, 0, 0, 0, 0};
    // int nums2[5]={0, 0, 0, 0, 0};
    int out = 0;

    out=findLength(nums1, nums1Size, nums2, nums2Size);
    printf("__out = %d__\n", out);

    return 0;
}