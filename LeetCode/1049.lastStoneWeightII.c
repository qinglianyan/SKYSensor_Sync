#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// 这么理解：将这些石头尽可能分成两个质量相近的堆
int lastStoneWeightII(int* stones, int stonesSize) {
    int i, j;
    int out=-1;
    int total=0, half=0;
    int tmpVal1, tmpVal2;
    int dp[3001];
    memset(dp, 0, sizeof(dp));

    for(i=0;i<stonesSize;i++){
        total+=stones[i];
    }
    half=total/2;
    // 到此为止，问题转化为了用容量half的背包装的物品价值最高的问题
    // 物品的价值与质量都是数值
    for(i=0;i<stonesSize;i++){
        for(j=half;j>=stones[i];j--){
            tmpVal1=dp[j];
            tmpVal2=dp[j-stones[i]]+stones[i];
            dp[j]=tmpVal1>tmpVal2?tmpVal1:tmpVal2;
        }
    }
    printf("%d\n", dp[half]);
    return (total-2*dp[half]);
}

int main(){
    int i, j;
    int out;
    // int stones[6]={2, 7, 4, 1, 8, 1};
    // int stonesSize=6;
    // ----------
    int stones[5]={31, 26, 33, 21, 40};
    int stonesSize=5;

    out=lastStoneWeightII(stones, stonesSize);
    printf("__out = %d__\n", out);
    return 0;
}