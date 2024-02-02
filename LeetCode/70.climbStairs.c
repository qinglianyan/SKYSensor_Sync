#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_N 45
int climbStairs(int n) {
    int i, j;
    int out=0;
    int dp[MAX_N+1];
    dp[0]=0, dp[1]=1, dp[2]=2;
    if(n<=2) return dp[n];
    else{
        for(i=3;i<=n;i++){
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[n];
    }
}

int main(){
    int n, out, i, j;
    printf("n = ");
    scanf("%d", &n);
    printf("input n = %d\n", n);
    out=climbStairs(n);
    printf("out = %d\n", out);
    return 0;
}