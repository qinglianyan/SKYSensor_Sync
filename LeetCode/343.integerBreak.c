#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_N 58
int integerBreak(int n) {
    int i, j;
    int out=0;
    int tempMax=0, temp;
    int dp[MAX_N+1];//dp[i]表示数字i拆分后的乘积最大值
    for(i=0;i<=n;i++){
        dp[i]=0;
    }
    dp[0]=0, dp[1]=1;//但是这两个数字是非法的
    dp[2]=1;
    for(i=3;i<=n;i++){
        tempMax=0;
        for(j=1;j<i;j++){
            temp=j*dp[i-j]>j*(i-j)?j*dp[i-j]:j*(i-j);
            if(temp>tempMax){
                tempMax=temp;
            }
        }
        dp[i]=tempMax;
    }
    // for(i=0;i<=n;i++){
    //     printf("%d ", dp[i]);
    // }

    return dp[n];
}

int main(){
    int n=10;
    int i, j;
    int out=0;
    out=integerBreak(n);
    printf("___out = %d___\n", out);
    return 0;
}