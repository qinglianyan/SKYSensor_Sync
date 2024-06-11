#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX(a, b) (a<b?(b):(a))
// 冷冻期1天, 不能同时参与多笔交易
int maxProfit(int* prices, int pricesSize) {
    
}

int main(){
    int i, j;
    int pricesSize=5;
    int prices[5]={1, 2, 3, 0, 2};

    // int pricesSize=1;
    // int prices[1]={1};
    int max=0;
    max=maxProfit(prices, pricesSize);
    printf("__max = %d__\n", max);
    return 0;
}