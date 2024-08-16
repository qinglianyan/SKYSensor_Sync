#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
/**
 * 邻接矩阵写法
*/
void dfs(){
    int i, j;

    return ;
}
int main(){
    int m, n;
    int i, j;
    int from, to;
    scanf("%d%d", &n, &m);
    int map[n+1][n+1];

    memset(map, 0, sizeof(map));
    for(i=0;i<m;i++){
        scanf("%d%d", &from, &to);
        map[from][to]=1;
    }
    for(i=1;i<n+1;i++){
        for(j=1;j<n+1;j++){
            printf("%d ", map[i][j]);
        }printf("\n");
    }
    return 0;
}