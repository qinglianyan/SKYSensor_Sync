#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define NODE_MAX 100001
typedef struct TreeNode {
    int row;
    int col;
}NODE;
int firstCompleteIndex(int* arr, int arrSize, int** mat, int matSize, int* matColSize){
    int out=-1;
    int i, j;
    /**
     * xy是一个哈希表，用来存储各个值对应的xy坐标
    */
    NODE *xy=(NODE *)malloc(sizeof(NODE)*NODE_MAX);
    /**
     * mat[m][n]有m行，n列
    */
    int m=matSize, n=matColSize[0];

    int row[m], col[n];

    memset(row, 0, sizeof(int)*m);
    memset(col, 0, sizeof(int)*n);
    for(i=0;i<m;i++){
        for(j=0;j<matColSize[i]){
            xy[mat[i][j]].row=i;
            xy[mat[i][j]].col=j;
        }
    }
    for(i=0;i<arrSize;i++){
        row[xy[arr[i]].row]++;
        col[xy[arr[i]].col]++;
        if(row[xy[arr[i]].row]==matColSize[xy[arr[i].row]]||)
    }
    return out;
}

int main(){
    int *arr=(int *)malloc(sizeof(int)*9);
    int tarr[9]={2, 8, 7, 4, 1, 3, 5, 6, 9};
    int **mat=(int **)malloc(sizeof(int *)*3);
    int tmat[3][3]={{3, 2, 5}, {1, 4, 6}, {8, 7, 9}};
    int matColSize[3]={3, 3, 3};
    int arrSize=9, matSize=3;
    int i, j;
    int out=-1;

    for(i=0;i<9;i++){
        arr[i]=tarr[i];
    }
    for(i=0;i<3;i++){
        mat[i]=(int *)malloc(sizeof(int)*3);
        for(j=0;j<3;j++){
            mat[i][j]=tmat[i][j];
        }
    }

    printf("arr = \n");
    for(i=0;i<arrSize;i++){
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("mat = \n");
    for(i=0;i<matSize;i++){
        for(j=0;j<matColSize[i];j++){
            printf("%d ", mat[i][j]);
        }printf("\n");
    }


    out=firstCompleteIndex(arr, arrSize, mat, matSize, matColSize);
    printf("out = %d\n", out);
    return 0;
}