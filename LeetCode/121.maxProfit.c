#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


int maxProfit(int* prices, int pricesSize) {
    int i, j;
    int min=10001;
    int out=0;
    for(i=0;i<pricesSize;i++){
        if(prices[i]<min){
            min=prices[i];
        }
        if(prices[i]-min>out){
            out=prices[i]-min;
        }
    }
    return out;
}

int main(){
    int i, j;
    // int prices[6]={7, 1, 5, 3, 6, 4};
    // int pricesSize=6;
    int prices[5]={7, 6, 4, 3, 1};
    int pricesSize=5;
    int out=0;
    // for(i=0;i<pricesSize;i++){
    //     printf("%d ", prices[i]);
    // }
    out=maxProfit(prices, pricesSize);
    printf("\n__out = %d__\n", out);
    return 0;
}