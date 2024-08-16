#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


#define MAX(a,b) (a>b?a:b)

int maxScore(int** grid, int gridSize, int* gridColSize) {
    int i, j, k;
    int res;
    int mmax;
    int retMax=-100001;
    int m=gridSize, n=gridColSize[0];
    int dp[m][n];
    /**
     * dp[i][j]表示的是以grid[i][j]为终点的最大得分
     * 对于每个dp[i][j],从上面、左面，都要遍历找到max再赋值
     * 
    */
    // 初始化
    memset(dp, 0, sizeof(dp));
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            mmax=0;
            if(i>0){
                if(dp[0][j]>0){
                    mmax=dp[0][j]+grid[i][j]-grid[0][j];
                }
                mmax=grid[i][j]-grid[0][j];
            }
            else if(j>0){
                if(dp[i][0]>0){
                    mmax=dp[i][0]+grid[i][j]-grid[i][0];
                }
                mmax=grid[i][j]-grid[i][0];
            }
            for(k=0;k<i;k++){
                if(dp[k][j]>0){
                    mmax=MAX(mmax, dp[k][j]+grid[i][j]-grid[k][j]);
                }
                else{
                    mmax=MAX(mmax, grid[i][j]-grid[k][j]);
                }
                
            }
            for(k=0;k<j;k++){
                if(dp[i][k]>0){
                    mmax=MAX(mmax, dp[i][k]+grid[i][j]-grid[i][k]);
                }
                else{
                    mmax=MAX(mmax, grid[i][j]-grid[i][k]);
                }
            }
            dp[i][j]=mmax;
            if(i!=0 || j!=0){
                retMax=MAX(retMax, mmax);
            }
            printf("%d ", dp[i][j]);
        }
        printf("\n");
    }
    // for(i=0;i<m;i++){
    //     for(j=0;j<n;j++){
    //         printf("%d ", dp[i][j]);
    //     }printf("\n");
    // }
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