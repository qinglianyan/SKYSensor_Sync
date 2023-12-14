#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int findMaxProfit(int *prices, int pricesSize, int now){
    int i, j;
    int out;
    int increase;
    if(now==0){
        return 0;
    }
    increase=prices[now]-prices[now-1];
    if(increase > 0){
        return findMaxProfit(prices, pricesSize, now-1)+increase;
    }
    return findMaxProfit(prices, pricesSize, now-1);

}

int maxProfit(int* prices, int pricesSize) {
    int out=0;
    int i, j;
    out=findMaxProfit(prices, pricesSize, pricesSize-1);

    return out;
}

int main(){
    int prices[]={7, 1, 5, 3, 6, 4};
    int pricesSize=6;
    int out=0;
    int i, j;

    out=maxProfit(prices, pricesSize);
    printf("out = %d\n", out);
    return 0;
}