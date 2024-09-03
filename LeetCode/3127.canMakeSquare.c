#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool fuhe(char** grid, int lx, int ly, int rx, int ry){
    int bcount=0, wcount=0;
    int i, j;
    for(i=lx;i<=rx;i++){
        for(j=ly;j<=ry;j++){
            if(grid[i][j]=='B'){
                bcount++;
            }
            else if(grid[i][j]=='W'){
                wcount++;
            }
            if(bcount>=3||wcount>=3){
                return true;
            }
        }
    }
    return false;
}
bool canMakeSquare(char** grid, int gridSize, int* gridColSize) {
    if( fuhe(grid, 0, 0, 1, 1) || fuhe(grid, 0, 1, 1, 2) ||
        fuhe(grid, 1, 0, 2, 1) || fuhe(grid, 1, 1, 2, 2)){
        return true;
    }
    
    return false;
}

int main(){
    int i, j;
    bool out;
    int gridSize=3;
    int gridColSize[3]={3, 3, 3};
    // char grid[3][3] = {
    //     {'B', 'W', 'B'},
    //     {'B', 'W', 'W'},
    //     {'B', 'W', 'B'}
    // };
    char *grid[]={"BWB", "BWW", "BWB"};
    // char grid[3][3]={{'B','W','B'}, {'B','W','W'}, {'B','W','B'}};
    
    // for(i=0;i<3;i++){
    //     printf("%s\n", grid[i]);
    // }
    out=canMakeSquare(grid, gridSize, gridColSize);
    if(out){
        printf("TRUE\n");
    }
    else{
        printf("FALSE\n");
    }
    return 0;
}
/**
 * WBB
 * BWW
 * WBB
*/