#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool canPlaceFlowers(int* flowerbed, int flowerbedSize, int n){
    int i, j;
    int count=0;

    for(i=0;i<flowerbedSize;i++){
        if(flowerbed[i]==1){
            if(i==0){
                flowerbed[++i]=1;
            }
            else if (i==flowerbedSize-1)
            {
                flowerbed[i-1]=1;
            }
            
            else{
                flowerbed[i-1]=1;
                flowerbed[++i]=1;
            }
        }
    }
    for(i=0;i<flowerbedSize;i++){
        printf("%d ", flowerbed[i]);
    }
    for(i=0;i<flowerbedSize;i++){
        if(flowerbed[i]==0){
            count++;
        }
    }
    if(count>=n){
        return true;
    }
    else{
        return false;
    }
    return true;
}

int main(){
    int flowerbed[5]={1, 0, 0, 0, 1};
    int flowerbedSize=5;
    int n=2;
    bool output=canPlaceFlowers(flowerbed, flowerbedSize, 1);
    if (output)
    {
        printf("true");
    }
    else{
        printf("false");
    }
    getchar();
    return 0;
}