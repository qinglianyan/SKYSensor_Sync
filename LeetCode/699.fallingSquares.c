#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* fallingSquares(int** positions, int positionsSize, int* positionsColSize, int* returnSize) {
    int i, j;
    
}

int main(){
    int i, j;
    int * out;
    int data[3][2]={
        {1, 2}, {2, 3}, {6, 1}
    };
    int positionsSize=3;
    int positionsColSize[]={2, 2, 2};
    int returnSize;
    int ** positions=(int **)malloc(sizeof(int *)*positionsSize);
    for(i=0;i<positionsSize;i++){
        positions[i]=(int *)malloc(sizeof(int )*positionsColSize[i]);
    }
    for(i=0;i<positions;i++){
        for(j=0;j<positionsColSize[i];j++){
            positions[i][j]=data[i][j];
        }
    }
    out=fallingSquares(positions, positionsSize, positionsColSize, &returnSize);
    for(i=0;i<returnSize;i++){
        printf("%d ", out[i]);
    }
    
    return 0;
}