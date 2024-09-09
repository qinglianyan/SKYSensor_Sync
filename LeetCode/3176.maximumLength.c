#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

/**
 * 给你一个整数数组 nums 和一个 非负 整数 k 。
 * 如果一个整数序列 seq 满足在下标范围 [0, seq.length - 2] 中
 * 最多只有 k 个下标 i 满足 seq[i] != seq[i + 1] ，
 * 那么我们称这个整数序列为 好 序列。
 * 请你返回 nums 中 好 子序列的最长长度。
 * 
示例 1：
输入：nums = [1,2,1,1,3], k = 2
输出：4
解释：
最长好子序列为 [1,2,1,1,3] 。

示例 2：
输入：nums = [1,2,3,4,5,1], k = 0
输出：2
解释：
最长好子序列为 [1,2,3,4,5,1] 。

提示：

1 <= nums.length <= 500
1 <= nums[i] <= 10^9
0 <= k <= min(nums.length, 25)
*/

int maximumLength(int* nums, int numsSize, int k) {
    int i, j;
    int ret;
    int dp[numsSize][k];
    /**
     * dp[i][j]表示
    */
    return 0;
}

int main(){
    int i,j;
    int out;
    int numsSize=5;
    int nums[5]={1, 2, 1, 1, 3};
    int k=2;
    out=maximumLength(nums, numsSize, k);
    printf("__out = %d__\n", out);
    return 0;
}