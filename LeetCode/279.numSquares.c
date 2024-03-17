#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define MIN(a,b) (a<b?a:b)

int numSquares(int n) {
    int i, j;
    int m;
    int dp[n+1];

    memset(dp, 0x3f3f3f3f, sizeof(dp));
    dp[0]=0;
    for(i=0;i*i<=n;i++){
        for(j=0;j<=n;j++){
            if(j>=i*i && dp[j-i*i]!=0x3f3f3f3f){
                dp[j]=MIN(dp[j], dp[j-i*i]+1);
            }
        }
        // log
        printf("------------\n");
        for(m=0;m<=n;m++){
            printf("%d ", dp[m]);
        }printf("\n");
    }
    if(dp[n]==0x3f3f3f3f){
        return 0;
    }
    return dp[n];
}
int main(){
    int n=12;
    int i, j;
    int out;

    out=numSquares(n);
    printf("__out = %d__\n", out);
    return 0;
}