#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX(a, b) (a<b?(b):(a))
int maxProfit(int k, int* prices, int pricesSize) {
    int i, j;
    int dp[pricesSize][2*k+1];

    // init
    for(i=0;i<=k;i++){
        dp[0][2*i]=0;
        if(i==k) break;
        dp[0][2*i+1]=-prices[0];
    }
    for(i=1;i<pricesSize;i++){
        dp[i][0]=dp[i-1][0];
        for(j=1;j<2*k+1;j++){
            if(j%2==1){
                dp[i][j]=MAX(dp[i-1][j], dp[i-1][j-1]-prices[i]);
            }
            else{
                dp[i][j]=MAX(dp[i-1][j], dp[i-1][j-1]+prices[i]);
            }
        }
    }
    return dp[pricesSize-1][2*k];
}

int main(){
    int i, j;
    int k;
    int out;
    int prices[3]={2, 4, 1};
    int pricesSize=3;

    // int prices[6]={3, 2, 6, 5, 0, 3};
    // int pricesSize=6;

    k=2;
    out=maxProfit(k, prices, pricesSize);
    printf("__out = %d__\n", out);
    return 0;
}