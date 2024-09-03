#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * 一个非负整数 x 的 强数组 指的是
 * 满足元素为 2 的幂且元素总和为 x 的最短有序数组。
 * 下表说明了如何确定 强数组 的示例。可以证明，x 对应的强数组是独一无二的。
 * 
 * 数字	二进制表示	强数组
 * 1	00001	    [1]
 * 8	01000	    [8]
 * 10	01010	    [2, 8]
 * 13	01101	    [1, 4, 8]
 * 23	10111	    [1, 2, 4, 16]
 * 
 * 我们将每一个升序的正整数 i （即1，2，3等等）的 强数组 连接得到数组 big_nums
 * big_nums 开始部分为 [1, 2, 1, 2, 4, 1, 4, 2, 4, 1, 2, 4, 8, ...] 。
 * 
 * 给你一个二维整数数组 queries ，其中 queries[i] = [fromi, toi, modi],你需要计算
 * (big_nums[fromi] * big_nums[fromi + 1] * ... * big_nums[toi]) % modi 。
 * 
 * 请你返回一个整数数组 answer ，其中 answer[i] 是第 i 个查询的答案。
示例 1：
输入：queries = [[1,3,7]]
输出：[4]

解释：
只有一个查询。
big_nums[1..3] = [2,1,2] 。它们的乘积为 4。结果为 4 % 7 = 4。

示例 2：
输入：queries = [[2,5,3],[7,7,4]]
输出：[2,2]

解释：
有两个查询。
第一个查询：big_nums[2..5] = [1,2,4,1] 。它们的乘积为 8 。结果为  8 % 3 = 2。
第二个查询：big_nums[7] = 2 。结果为 2 % 4 = 2。

 

提示：

1 <= queries.length <= 500
queries[i].length == 3
0 <= queries[i][0] <= queries[i][1] <= 1015
1 <= queries[i][2] <= 105

*/
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findProductsOfElements(long long** queries, int queriesSize, 
                            int* queriesColSize, int* returnSize) {
    int i,j;
    int *ret=(int *)malloc(sizeof(int)*queriesSize);
    

    
}

int main(){
    int i,j;
    int *out;
    long long **queries;
    int queriesSize;
    int *queriesColSize, returnSize;
    returnSize=0;

    queriesSize=2;
    queries=(long long **)malloc(sizeof(long long *)*queriesSize);
    queriesColSize=(int *)malloc(sizeof(int)*queriesSize);
    for(i=0;i<queriesSize;i++){
        queries[i]=(long long *)malloc(sizeof(long long)*3);
        queriesColSize[i]=3;
    }
    queries[0][0]=2, queries[0][1]=5, queries[0][2]=3;
    queries[1][0]=7, queries[1][1]=7, queries[1][2]=4;

    out=findProductsOfElements(queries, queriesSize, queriesColSize, &returnSize);
    printf("returnSize = %d\n", returnSize);
    for(i=0;i<returnSize;i++){
        printf("%d ", out[i]);
    }
    printf("\n");
    
    
    return 0;
}