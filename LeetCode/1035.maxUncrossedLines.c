#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

/**
 * 在两条独立的水平线上按给定的顺序写下 nums1 和 nums2 中的整数。
现在，可以绘制一些连接两个数字 nums1[i] 和 nums2[j] 的直线，这些直线需要同时满足：
·nums1[i] == nums2[j]
·且绘制的直线不与任何其他连线（非水平线）相交。
请注意，连线即使在端点也不能相交：每个数字只能属于一条连线。
以这种方法绘制线条，并返回可以绘制的最大连线数。

示例 1：
输入：nums1 = [1,4,2], nums2 = [1,2,4]
输出：2

示例 2：
输入：nums1 = [2,5,1,2,5], nums2 = [10,5,2,1,5,2]
输出：3
*/
#define MAX(a, b) (a>b?a:b)
int maxUncrossedLines(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int i, j;
    int dp[nums1Size+1][nums2Size+1];
    int max=0;
    /**
     * dp[i][j]表示nums[0--i]和nums2[0--j]有几个连线
     * if nums1[i]==nums2[j] then
     *      dp[i][j]=dp[i-1][j-1]+1
     * else
     *      dp[i][j]=max(dp[i][j-1], dp[i-1][j])
     * 怎么初始化？
     * 
    */
    memset(dp, 0, sizeof(dp));
    for(i=1;i<=nums1Size;i++){
        for(j=1;j<=nums2Size;j++){
            if(nums1[i-1]==nums2[j-1]){
                dp[i][j]=dp[i-1][j-1]+1;
            }
            else{
                dp[i][j]=MAX(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    return dp[nums1Size][nums2Size];
}

int main(){
    int i, j;
    int out=0;
    int nums1Size=3;
    int nums2Size=3;
    int nums1[3]={1, 4, 2};
    int nums2[3]={1, 2, 4};

    out=maxUncrossedLines(nums1, nums1Size, nums2, nums2Size);
    printf("__out = %d__\n", out);
    return 0;
}