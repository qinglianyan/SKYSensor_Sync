#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_N 1000
int minCostClimbingStairs(int* cost, int costSize) {
    int out=0;
    int i, j;
    int dp[MAX_N+1];
    dp[0]=0, dp[1]=0;
    if(costSize<=1) return dp[costSize];
    else{
        for(i=2;i<=costSize;i++){
            dp[i]=(dp[i-1]+cost[i-1])<(dp[i-2]+cost[i-2])?(dp[i-1]+cost[i-1]):(dp[i-2]+cost[i-2]);
        }
        // for(i=0;i<=costSize;i++){
        //     printf("dp[%d] = %d\n", i, dp[i]);
        // }
        return dp[costSize];
    }

    return out;
}

int main(){
    int cost[10]={1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
    int costSize=10;
    int i, j, out;
    out=minCostClimbingStairs(cost, costSize);
    printf("out = %d\n", out);
    return 0;
}