#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as 
 *      *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array 
 *      must be malloced, assume caller calls free().
 */
int** generateMatrix(int n, int* returnSize, int** returnColumnSizes){
    int maxNum = n * n, minNum = 1;
    int ** ret = (int **)malloc(sizeof(int*) * n);//查了好久的数组越界，结果是因为这里写成sizeof(int)了
    int i, j;
    //drct记录走的方向 1右 2下 3左 4上
    int insert, drct;

    *returnColumnSizes=(int *)malloc(sizeof(int)*n);
    *returnSize=n;
    for(i = 0;i < n; i++){
        (*returnColumnSizes)[i] = n;
        ret[i] = malloc(sizeof(int)*n);
        memset(ret[i], 0, sizeof(int)*n);
    }
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            ret[i][j]=0;
        }
    }
    drct=1, i=j=0;//初始在(0,0) 方向向右
    for(insert=minNum;insert<=maxNum;insert++){
        // updateDrct()
        switch (drct){
            case 1:{
                if(j==n-1||ret[i][j+1]){
                    drct=2;
                    break;
                }
                break;
            }
            case 2:{
                if(i==n-1||ret[i+1][j]){
                    drct=3;
                    break;
                }
                break;
            }
            case 3:{
                if(j==0||ret[i][j-1]){
                    drct=4;
                    break;
                }
                break;
            }
            case 4:{
                if(i==0||ret[i-1][j]){
                    drct=1;
                    break;
                }
                break;
            }
        }
        ret[i][j]=insert;
        switch (drct){
            case 1:{
                j++;
                break;
            }
            case 2:{
                i++;
                break;
            }
            case 3:{
                j--;
                break;
            }
            case 4:{
                i--;
                break;
            }
        }
    }
    return ret;
}

int main(){
    int n, returnSize;
    int * returnColumnSize;
    int ** output;
    int i, j;

    n=5;
    output = generateMatrix(n, &returnSize, &returnColumnSize);
    for(i = 0;i<n;i++){
        for(j = 0;j<n;j++){
            printf("%d ", output[i][j]);
        }
        printf("\n");
    }
    return 0;
}