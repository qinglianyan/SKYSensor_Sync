#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>


#define MAX(a,b) (a>b?a:b)
#define MIN(a,b) (a<b?a:b)

int maxScore(int** grid, int gridSize, int* gridColSize) {
    int i, j, k;
    int mn;
    int retMax=INT_MIN;
    int m=gridSize, n=gridColSize[0];
    int dp[m+1][n+1];
    /**
     * 参考灵茶山艾府大佬的题解
     * 把gird[i][j]理解为海拔高度，把得分理解为 重力势能的变化量
     * 题目相当于是求重力势能变化量之和
     * dp[i+1][j+1]表示终点为(i,j)
    */
    // 初始化
    memset(dp, 0x3f, sizeof(dp));
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            mn=MIN(dp[i+1][j], dp[i][j+1]);
            retMax=MAX(retMax, grid[i][j]-mn);
            dp[i+1][j+1]=MIN(mn, grid[i][j]);
        }
    }
    
    return retMax;
}

int main(){
    int i, j;
    int out;
    int **grid;
    int gridSize;
    int *gridColSize;

    // ___1_______________
    // gridSize=4;
    // grid=(int **)malloc(sizeof(int *)*gridSize);
    // gridColSize=(int *)malloc(sizeof(int)*gridSize);
    // gridColSize[0]=gridColSize[1]=gridColSize[2]=gridColSize[3]=4;
    // for(i=0;i<gridSize;i++){
    //     grid[i]=(int *)malloc(sizeof(int)*gridColSize[0]);
    // }
    // grid[0][0]=9, grid[0][1]=5, grid[0][2]=7,  grid[0][3]=3;
    // grid[1][0]=8, grid[1][1]=9, grid[1][2]=6,  grid[1][3]=1;
    // grid[2][0]=6, grid[2][1]=7, grid[2][2]=14, grid[2][3]=3;
    // grid[3][0]=2, grid[3][1]=5, grid[3][2]=3,  grid[3][3]=1;
    
    // ___2_______________
    // gridSize=2;
    // grid=(int **)malloc(sizeof(int *)*gridSize);
    // gridColSize=(int *)malloc(sizeof(int)*gridSize);
    // gridColSize[0]=gridColSize[1]=gridColSize[2]=3;
    // for(i=0;i<gridSize;i++){
    //     grid[i]=(int *)malloc(sizeof(int)*gridColSize[0]);
    // }
    // grid[0][0]=4, grid[0][1]=3, grid[0][2]=2;
    // grid[1][0]=3, grid[1][1]=2, grid[1][2]=1;

    // ___3_______________
    // gridSize=4;
    // grid=(int **)malloc(sizeof(int *)*gridSize);
    // gridColSize=(int *)malloc(sizeof(int)*gridSize);
    // gridColSize[0]=gridColSize[1]=gridColSize[2]=gridColSize[3]=5;
    // for(i=0;i<gridSize;i++){
    //     grid[i]=(int *)malloc(sizeof(int)*gridColSize[0]);
    // }
    // grid[0][0]=5, grid[0][1]=4, grid[0][2]=8,  grid[0][3]=6,  grid[0][4]=2;
    // grid[1][0]=1, grid[1][1]=5, grid[1][2]=8,  grid[1][3]=6,  grid[1][4]=10;
    // grid[2][0]=8, grid[2][1]=6, grid[2][2]=9,  grid[2][3]=2,  grid[2][4]=10;
    // grid[3][0]=3, grid[3][1]=7, grid[3][2]=6,  grid[3][3]=10, grid[3][4]=6;
    

    // ___4_______________
    gridSize=2;
    grid=(int **)malloc(sizeof(int *)*gridSize);
    gridColSize=(int *)malloc(sizeof(int)*gridSize);
    gridColSize[0]=gridColSize[1]=2;
    for(i=0;i<gridSize;i++){
        grid[i]=(int *)malloc(sizeof(int)*gridColSize[0]);
    }
    grid[0][0]=100000, grid[0][1]=50000;
    grid[1][0]=50000, grid[1][1]=1;

    for(i=0;i<gridSize;i++){
        for(j=0;j<gridColSize[0];j++){
            printf("%d ", grid[i][j]);
        }printf("\n");
    }
    out=maxScore(grid, gridSize, gridColSize);
    printf("__out = %d__\n", out);
    return 0;
}
