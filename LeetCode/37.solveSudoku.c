#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
// 明天再看，到第一行46之后报错返回了
bool isValid(char **board, int boardSize, 
            int x, int y, int in){
    int i, j;
    int row, col;
    for(i=0;i<boardSize;i++){
        if((board[x][i]-'1'+1)==in) return false;
        if((board[i][y]-'1'+1)==in) return false;
    }
    row=x/3, col=y/3;
    for(i=row;i<row+3;i++){
        for(j=col;j<col+3;j++){
            if((board[i][j]-'1'+1)==in) return false;
        }
    }
    return true;
}
bool backtracking(char **board, int boardSize,
                int *boardColSize){
    int i, j, k;
    for(i=0;i<boardSize;i++){
        for(j=0;j<boardColSize[i];j++){
            if(board[i][j]!='.') continue;
            for(k=1;k<=9;k++){
                if(isValid(board, boardSize, i, j, k)){
                    board[i][j]=(char )('1'+k-1);
                    if(backtracking(board, boardSize, boardColSize)) return true;
                    board[i][j]='.';
                }
            }
            return false;
        }
    }
    return true;
}

void solveSudoku(char** board, int boardSize, 
                int* boardColSize){
    int i, j;
    if(boardSize!=9){
        printf("boardSize Error!\n");
        return ;
    }
    if(backtracking(board, boardSize, boardColSize)){
        return ;
    }
    else{
        printf("Not Find Answer!\n");
        return ;
    }
    return ;
}

int main(){
    int i, j;
    char **board;
    int boardSize;
    int *boardColSize;

    board=(char **)malloc(sizeof(char *)*9);
    boardSize=9;
    boardColSize=(int *)malloc(sizeof(int ));
    for(i=0;i<9;i++){
        boardColSize[i]=9;
        board[i]=(char *)malloc(sizeof(char)*10);
    }
    strcpy(board[0], "53..7....");
    strcpy(board[1], "6..195...");
    strcpy(board[2], ".98....6.");
    strcpy(board[3], "8...6...3");
    strcpy(board[4], "4..8.3..1");
    strcpy(board[5], "7...2...6");
    strcpy(board[6], ".6....28.");
    strcpy(board[7], "...419..5");
    strcpy(board[8], "....8..79");
    
    solveSudoku(board, boardSize, boardColSize);
    // printf("%c\n", '1'+2);
    for(i=0;i<9;i++){
        for(j=0;j<9;j++){
            printf("%c", board[i][j]);
            if(j==2||j==5){
                printf("|");
            }
        }
        printf("\n");
        if(i==2||i==5){
            printf("===========\n");
        }
    }
    return 0;
}