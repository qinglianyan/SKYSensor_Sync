#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
// n=9的时候，returnSize最大352
#define MAX_OUT 360
#define MAX_N   9
int map[MAX_N][MAX_N];
void putDown(int n, int x, int y){
    int i, j;
    // 横竖 + 2
    for(i=0;i<n;i++){
        map[x][i]++;
        map[i][y]++;
    }
    // 撇   + 2
    i=x, j=y;
    while(i>=0&&i<n&&j>=0&&j<n){
        map[i++][j--]++;
    }
    i=x, j=y;
    while(i>=0&&i<n&&j>=0&&j<n){
        map[i--][j++]++;
    }
    // 捺   + 2
    i=x, j=y;
    while(i>=0&&i<n&&j>=0&&j<n){
        map[i++][j++]++;
    }
    i=x, j=y;
    while(i>=0&&i<n&&j>=0&&j<n){
        map[i--][j--]++;
    }
    map[x][y]-=5;
    return ;
}
void pickUp(int n, int x, int y){
    int i, j;
    // 横竖 - 2
    for(i=0;i<n;i++){
        map[x][i]--;
        map[i][y]--;
    }
    // 撇   - 2
    i=x, j=y;
    while(i>=0&&i<n&&j>=0&&j<n){
        map[i++][j--]--;
    }
    i=x, j=y;
    while(i>=0&&i<n&&j>=0&&j<n){
        map[i--][j++]--;
    }
    // 捺   + 2
    i=x, j=y;
    while(i>=0&&i<n&&j>=0&&j<n){
        map[i++][j++]--;
    }
    i=x, j=y;
    while(i>=0&&i<n&&j>=0&&j<n){
        map[i--][j--]--;
    }
    map[x][y]+=5;
    return ;
}
void showMap(int n){
    int i, j;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("%d ", map[i][j]);
        }
        printf("\n");
    }
    return ;
}
void backstacking(int n, char ***out, int nowRow, 
                int *returnSize, int **returnColumnSizes){
    int i, j;
    if(nowRow==n){
        // for(i=0;i<n;i++){
        //     for(j=0;j<n;j++){
        //         printf("%d ", map[i][j]);
        //     }
        //     printf("\n");
        // }
        out[(*returnSize)]=(char **)malloc(sizeof(char *)*n);
        (*returnColumnSizes)[(*returnSize)]=n;
        for(i=0;i<n;i++){
            out[(*returnSize)][i]=(char *)malloc(sizeof(char)*(n+1));
            for(j=0;j<n;j++){
                if(map[i][j]==1){
                    out[(*returnSize)][i][j]='Q';
                }
                else{
                    out[(*returnSize)][i][j]='.';
                }
            }
            out[(*returnSize)][i][j]='\0';
        }

        (*returnSize)++;
        return ;
    }
    // 单步循环
    for(i=0;i<n;i++){
        if(map[nowRow][i]>0){
            continue;
        }
        putDown(n, nowRow, i);
        // printf("\n");
        // showMap(n);
        backstacking(n, out, nowRow+1, returnSize, returnColumnSizes);
        pickUp(n, nowRow, i);
        // printf("\n");
        // showMap(n);
    }

    return ;
}
char*** solveNQueens(int n, int* returnSize, 
                    int** returnColumnSizes) {
    char ***out;
    int i, j;
    if(n<1||n>9){
        printf("N Error!\n");
        return NULL;
    }
    (*returnSize)=0;
    out=(char ***)malloc(sizeof(char **)*MAX_OUT);
    (*returnColumnSizes)=(int *)malloc(sizeof(int)*MAX_OUT);
    memset(map, 0, sizeof(map));
    backstacking(n, out, 0, returnSize, returnColumnSizes);

    return out;
}

int main(){
    int n=9;
    char ***out;
    int *returnSize=(int *)malloc(sizeof(int));
    int **returnColumnSizes=(int **)malloc(sizeof(int *));
    int i, j;

    (*returnSize)=0;
    out=solveNQueens(n, returnSize, returnColumnSizes);
    for(i=0;i<(*returnSize);i++){
        for(j=0;j<(*returnColumnSizes)[i];j++){
            printf("%s\n", out[i][j]);
        }
    }
    printf("returnSize = %d\n", (*returnSize));
    return 0;
}