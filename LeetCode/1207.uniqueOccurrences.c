#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool uniqueOccurrences(int* arr, int arrSize) {
    int i, j;
    int hash[2001]={0};
    int count[1001]={0};
    for(i=0;i<arrSize;i++){
        hash[arr[i]+1000]++;
    }

    for(i=0;i<2001;i++){
        if(hash[i]>0){
            if(count[hash[i]]>0){
                return false;
            }
            count[hash[i]]=1;
        }
    }
    return true;
}

int main(){
    int i, j;
    bool out;
    int arrSize=6;
    int arr[6]={1, 2, 2, 1, 1, 3};
    out=uniqueOccurrences(arr, arrSize);
    if(out){
        printf("__out = true__\n");
    }
    else{
        printf("__out = flase__\n");
    }
    return  0;
}