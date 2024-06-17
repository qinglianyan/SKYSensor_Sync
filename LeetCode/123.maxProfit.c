#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

/**
 * 给定数组，第i个元素表示股票在第i天的价格
 * 最多完成两笔交易，不能同时持有两个
 * 求最大利润
*/
#define MAX(a, b) (a<b?b:a)
int maxProfit(int* prices, int pricesSize) {
    int i, j;
    int dp[pricesSize][5];
    /**
     * 定义说明
     * dp[i][j]表示在第i天j状态的利润
     * j取值为0, 1, 2, 3, 4,分别表示：
     *  0:还没买股票
     *  1:第一次持有股票状态
     *  2:第一次卖出股票状态
     *  3:第二次持有股票状态
     *  4:第二次卖出股票状态
     * 状态转移方程推导：
     *  dp[i][0]=dp[i-1][0]
     *  dp[i][1]=max( dp[i-1][1], dp[i-1][0]-price[i] )
     *  dp[i][2]=max( dp[i-1][2], dp[i-1][1]+price[i] )
     *  dp[i][3]=max( dp[i-1][3], dp[i-1][2]-price[i] )
     *  dp[i][4]=max( dp[i-1][4], dp[i-1][3]+price[i] )
    */
    // init
    dp[0][0]=0;dp[0][1]=-prices[0];
    dp[0][2]=0;dp[0][3]=-prices[0];
    dp[0][4]=0;

    for(i=1;i<pricesSize;i++){
        dp[i][0]=dp[i-1][0];
        dp[i][1]=MAX( dp[i-1][1], dp[i-1][0]-prices[i] );
        dp[i][2]=MAX( dp[i-1][2], dp[i-1][1]+prices[i] );
        dp[i][3]=MAX( dp[i-1][3], dp[i-1][2]-prices[i] );
        dp[i][4]=MAX( dp[i-1][4], dp[i-1][3]+prices[i] );
        // printf("%d %d %d %d \n", dp[i][1], dp[i][2], dp[i][3], dp[i][4]);
    }
    return dp[pricesSize-1][4];
}
int main(){
    int i, j;
    int out;
    // 示例1
    int prices[8]={3, 3, 5, 0, 0, 3, 1, 4};
    int pricesSize=8;
    // 示例2
    // int prices[5]={1, 2, 3, 4, 5};
    // int pricesSize=5;
    // 示例3
    // int prices[5]={7, 6, 4, 3, 1};
    // int pricesSize=5;

    out=maxProfit(prices, pricesSize);
    printf("\n__out = %d__\n", out);
    return 0;
}