#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int change(int amount, int* coins, int coinsSize) {
    int i, j;
    int m, n;
    int count=-1;
    // dp[j]表示coins正好是j价值的组合数
    // 这一段可以改为用malloc和calloc，注意二者区别
    int dp[amount+1];
    memset(dp, 0, sizeof(dp));
    
    /** init
     * 这里好像是有一个"恰好完全装满背包 VS 不要求装满背包"的问题
    */
    dp[0]=1;
    
    // loop
    for(i=0;i<coinsSize;i++){
        /**
         * 一维数组就不用考虑二维的时候要有一个0行了
        */
        // 下面这段改成后面未注释掉的了
        // for(j=1;j<amount+1;j++){
        //     if(j>=coins[i]){
        //         dp[j]+=dp[j-coins[i]];
        //     }
        // }
        for(j=coins[i];j<amount+1;j++){
            dp[j]+=dp[j-coins[i]];
        }
        // // --- log ---
        // printf("----------\n");
        // for(n=0;n<=amount;n++){
        //     printf("%d ", dp[n]);
        // }printf("\n");
    }
    return dp[amount];
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