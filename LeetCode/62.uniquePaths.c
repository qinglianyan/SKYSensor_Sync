#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_NUM 100
int uniquePaths(int m, int n) {
    int i, j;
    int out=0;
    int dp[m][n];
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            dp[i][j]=0;
        }
    }
    for(i=0;i<m;i++){
        dp[i][0]=1;
    }
    for(i=0;i<n;i++){
        dp[0][i]=1;
    }
    for(i=1;i<m;i++){
        for(j=1;j<n;j++){
            dp[i][j]=dp[i-1][j]+dp[i][j-1];
        }
    }
    // for(i=0;i<m;i++){
    //     for(j=0;j<n;j++){
    //         printf("%d ", dp[i][j]);
    //     }printf("\n");
    // }
    return dp[m-1][n-1];
}


int main(){
    int m=3, n=7;
    int out=0;
    out=uniquePaths(m, n);
    printf("out = %d\n", out);
    return 0;
}