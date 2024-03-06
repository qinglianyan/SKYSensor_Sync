#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int change(int amount, int* coins, int coinsSize) {
    int i, j;
    int m, n;
    int count=-1;
    int dp[coinsSize+1][amount+1];
    // dp[i][j]表示[0, i]的coins正好是j价值的组合数
    memset(dp, 0, sizeof(dp));
    /**
     * 之前0-1背包的递推公式是(这个里面dp是背包里面的价值)
     * dp[i][j]=MAX(dp[i-1][j], dp[i-1][j-w[i]]+w[i]);
     * 按照抹茶旦旦冲的理解,完全背包：(这个里面dp也是背包里面的价值)
     * dp[i][j]=MAX(dp[i-1][j], dp[i][j-w[i]]+w[i]);
     *              不拿coin[i]  如果拿coin[i]
     * 如果dp表示组合数的话
     * dp[i][j]=dp[i-1][j]+dp[i][j-w[i]];
     * ——————————————————————————————
     * 画个图
     * 能够发现，如果O表示dp[i][j]的话
     * 需要用到的数据是上一行的X，和同一行的左侧已更新数据
     * 因此需要从上往下，从左往右遍历
     * | | | | | | | | | |
     * | | | | | | |X| | |
     * | |<|-|-|-|-|O| | |
     * | | | | | | | | | |
    */
    /**
     * 抹茶旦旦冲
     * 二维dp更好理解。所谓正序遍历就是把之前的[i-1]都改成
     * 了[i]，也就是在考虑要不要加物品i的时候，可以是已经加
     * 过物品i的，而不一定是只加过前i-1个。也就是可以重复加。
    */
    /** init
     * 这里好像是有一个"恰好完全装满背包 VS 不要求装满背包"的问题
    */
    for(i=0;i<coinsSize+1;i++){
        dp[i][0]=1;
    }
    
    // loop
    for(i=1;i<coinsSize+1;i++){
        for(j=1;j<amount+1;j++){
            if(j<coins[i-1]){
                dp[i][j]=dp[i-1][j];
            }
            else{
                dp[i][j]=dp[i-1][j]+dp[i][j-coins[i-1]];
            }
        }
        //--- log ---
        // printf("-----------\n");
        // for(m=0;m<coinsSize+1;m++){
        //     for(n=0;n<amount+1;n++){
        //         printf("%d ", dp[m][n]);
        //     }printf("\n");
        // }
    }

    return dp[coinsSize][amount];
}

int main(){
    int i, j;
    int out=-1;

    int amount=5;
    int coinsSize=3;
    int * coins=(int *)malloc(sizeof(int)*coinsSize);
    coins[0]=1, coins[1]=2, coins[2]=5;

    out=change(amount, coins, coinsSize);
    printf("__out = %d__\n", out);
    return 0;
}