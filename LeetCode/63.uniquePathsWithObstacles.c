#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int uniquePathsWithObstacles(int** obstacleGrid, 
    int obstacleGridSize, int* obstacleGridColSize) {
    int out=0, i, j;
    int m=obstacleGridSize, n=obstacleGridColSize[0];
    int dp[m][n];
    if(obstacleGrid[0][0]==1){//被堵第一个
        return 0;
    }
    // if(obstacleGridSize==1){//只有一行
    //     for(j=0;j<n;j++){
    //         if(obstacleGrid[0][j]==1){
    //             return 0;
    //         }
    //     }
    //     return 1;
    // }
    // if(n==1){//只有一列
    //     for(i=0;i<m;i++){
    //         if(obstacleGrid[i][0]==1){
    //             return 0;
    //         }
    //     }
    //     return 1;
    // }
    // printf("m = %d, n = %d\n", m, n);
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            dp[i][j]=0;
        }
    }
    for(i=0;i<m;i++){
        if(obstacleGrid[i][0]==1){
            dp[i][0]=0;
            break;
        }
        else{
            dp[i][0]=1;
        }
    }
    for(j=0;j<n;j++){
        if(obstacleGrid[0][j]==1){
            dp[0][j]=0;
            break;
        }
        else{
            dp[0][j]=1;
        }
    }
    // ---------
    for(i=1;i<m;i++){
        for(j=1;j<n;j++){
            if(obstacleGrid[i][j]==1){
                dp[i][j]=0;
            }
            else{
                dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        }
    }
    // to show dp
    // for(i=0;i<m;i++){
    //     for(j=0;j<n;j++){
    //         printf("%d ", dp[i][j]);
    //     }
    //     printf("\n");
    // }

    return dp[m-1][n-1];
}

int main(){
    int **obstacleGrid=(int **)malloc(sizeof(int *)*3);
    int obstacleGridSize=3;
    int *obstacleGridColSize=(int *)malloc(sizeof(int )*3);
    int i, j;
    int out;
    for(i=0;i<3;i++){
        obstacleGrid[i]=(int *)malloc(sizeof(int)*3);
        obstacleGridColSize[i]=3;
    }
    obstacleGrid[0][0]=0, obstacleGrid[0][1]=0, obstacleGrid[0][2]=0;
    obstacleGrid[1][0]=0, obstacleGrid[1][1]=1, obstacleGrid[1][2]=0;
    obstacleGrid[2][0]=0, obstacleGrid[2][1]=0, obstacleGrid[2][2]=0;

    // for(i=0;i<3;i++){
    //     for(j=0;j<3;j++){
    //         printf("%d ", obstacleGrid[i][j]);
    //     }
    //     printf("\n");
    // }
    out=uniquePathsWithObstacles(obstacleGrid, obstacleGridSize, obstacleGridColSize);
    printf("___out_=_%d___\n", out);
    return 0;
}