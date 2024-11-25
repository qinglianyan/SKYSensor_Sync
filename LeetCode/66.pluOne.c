#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize) {
    int *out;
    int i, j;
    for(i=0;i<digitsSize;i++){
        if(digits[i]!=9){
            break;
        }
    }
    if(i==digitsSize){
        out=(int *)malloc(sizeof(int)*(digitsSize+1));
        out[0]=1;
        for(i=1;i<digitsSize+1;i++){
            out[i]=0;
        }
        (*returnSize)=digitsSize+1;
        return out;
    }
    for(i=digitsSize-1;digits[i]==9;i--){
        digits[i]=0;
    }
    digits[i]++;
    (*returnSize)=digitsSize;
    return digits;
}

int main(){
    int i, j;
    int *out;
    int digits[3]={1, 9, 9};
    int digitsSize=3;
    int *returnSize=(int *)malloc(sizeof(int));

    *returnSize=0;
    out=plusOne(digits, digitsSize, returnSize);
    for(i=0;i<(*returnSize);i++){
        printf("%d ", out[i]);
    }
    return 0;
}