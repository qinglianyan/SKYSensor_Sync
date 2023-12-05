#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** combine(int n, int k, int* returnSize, int** returnColumnSizes) {
    int **out;


    return out;
}

int main(){
    int i, j, n, k;
    int **out;
    int *returnSize=(int *)malloc(sizeof(int));
    int **returnColumnSizes;
    *returnSize=0;

    out=combine(n, k, returnSize, returnColumnSizes);
    for(i=0;i<(*returnSize);i++){
        for(j=0;j<(*returnColumnSizes)[i];j++){
            printf("%d ", out[i][j]);
        }printf("\n");
    }
    return 0;
}