#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int maximizeWin(int* prizePositions, int prizePositionsSize, int k) {
    int i, j;
    int dp[prizePositionsSize+1];
    int lenth=prizePositions[prizePositionsSize-1]-prizePositions[0];
    /**
     * dp[i][j]表示在[0， i]下标范围内，使用两个长度为k的线段
     * 拿到的最多的奖品数目
     * 递推公式：
     * 如果拿下标i的物品，那么第二条线段覆盖[i-k, i]
     *      第一条线段为[j,j+k],j从0 -> i-2k取值,取最大值dp[i]
     * 如果不拿下标i的物品，那么dp[i]=dp[i-1]
    */
    if(2*k>lenth){
        return prizePositionsSize;
    }
    
    // 初始化
    

    return 0;
}

int main(){
    int i, j;
    int prizePositionsSize=7;
    //[1,1,2,2,3,3,5]
    int prizePositions[7]={1, 1, 2, 2, 3, 3, 5};
    int out=0;
    out=maximizeWin(prizePositions, prizePositionsSize);
    printf("__out = %d__\n");
    return 0;
}