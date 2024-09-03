#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool validMountainArray(int* arr, int arrSize){
    /**
     * Mountain Arr:
     * 1. arr.length >= 3
     * 2. 在 0 < i < arr.length - 1 条件下，存在 i 使得：
     * arr[0] < arr[1] < ... arr[i-1] < arr[i] 
     * arr[i] > arr[i+1] > ... > arr[arr.length - 1]
    */
    int i, j;
    int upgrow=0;
    int topped=0;
    if(arrSize<3) return false;
    if(arr[1]-arr[0]<0){
        return false;
    }
    for(i=1;i<arrSize;i++){
        upgrow=arr[i]-arr[i-1];
        if(upgrow == 0){
            return false;
        }
        if(i>=2){
            if( (arr[i]-arr[i-1])*(arr[i-1]-arr[i-2]) <0 ){
                topped++;
                if(topped==2){
                    return false;
                }
            }
        }
    }
    if(topped!=1) return false;
    return true;

}

int main(){
    int i, j;
    int arrSize=3;
    int arr[3]={2, 0, 2};
    bool out;

    out=validMountainArray(arr, arrSize);
    if(out){
        printf("__out = true__\n");
    }
    else{
        printf("__out = false__\n");
    }
    return 0;
}