#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_N 19
int numTrees(int n) {
    int i, j;
    int out=0;
    int dp[MAX_N+1];
    for(i=0;i<=MAX_N;i++){
        dp[i]=0;
    }
    dp[0]=1, dp[1]=1, dp[2]=2;
    // dp[3]=5;
    for(i=3;i<=n;i++){
        dp[i]=0;
        for(j=0;j<=i-1;j++){
            dp[i]+=dp[i-1-j]*dp[j];
        }
    }

    // for(i=0;i<=n;i++){
    //     printf("%d ", dp[i]);
    // }

    return dp[n];
}

int main(){
    int n=3;
    int i, j;
    int out=0;
    out=numTrees(n);
    printf("___out = %d___\n", out);
    return 0;
}