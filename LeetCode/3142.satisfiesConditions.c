#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool satisfiesConditions(   int** grid, int gridSize, 
                            int* gridColSize) {
    int i, j;
    int m=gridSize, n=gridColSize[0];
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            if(i!=m-1){
                if(grid[i][j]!=grid[i+1][j]){
                    return false;
                }
            }
            if(j!=n-1){
                if(grid[i][j]==grid[i][j+1]){
                    return false;
                }
            }
        }
    }
    return true;
}

int main(){
    int i, j;
    bool out;
    int **grid;
    int gridSize=2;
    int gridColSize[]={3, 3};
    grid=(int **)malloc(sizeof(int *)*2);
    grid[0]=(int *)malloc(sizeof(int)*3);
    grid[1]=(int *)malloc(sizeof(int)*3);
    grid[0][0]=1, grid[0][1]=0, grid[0][2]=2;
    grid[1][0]=1, grid[1][1]=0, grid[1][2]=2;
    for(i=0;i<2;i++){
        for(j=0;j<3;j++){
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
    out=satisfiesConditions(grid, gridSize, gridColSize);
    if(out){
        printf("true\n");
    }
    else{
        printf("false\n");
    }
    return 0;
}