#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
/*
    由于leetcode没有原题，在这里做出描述
    0-1背包问题，物品只有一个，分别为：
            |重量   |价值
    ——————————————————————
    物品0   |1      |15     
    物品1   |3      |20
    物品2   |4      |30
    ——————————————————————
    背包最大重量为4，求背包最大能装的物品价值
    : 疑问
    1、给的物品是怎么排序的，初始化之前要不要按照weight进行排序
       初始化第一行的时候是按照第一个weight[0]赋值的
*/

int dynamicprogram(int num, int *weight, int *value, int bagweight){
    int out=-1;
    int i, j;
    int dp[num][bagweight+1];
    int temVal1, temVal2;
    // dp[i][j]:
    // 表示下表为[0,i]的物品里任意取，放入容量为j的背包
    // 最大价值为多少.
    // 在这个例子中就是三行五列的二维数组

    // init
    for(i=0;i<num;i++){ // 0 X X X X
        dp[i][0]=0;     // 0 X X X X
    }                   // 0 X X X X
    for(j=weight[0];j<bagweight;j++){   // 0 15 15 15 15
        dp[0][j]=value[0];              // 0 X  X  X  X
    }                                   // 0 X  X  X  X

    // dp
    // 对于[0-i]物品
    // 1、如果不放进去i物品，dp[i][j] = dp[i-1][j]
    // 2、如果放进去i物品，dp[i][j] = value[i]+dp[i-1][j-weight[i]]
    for(i=1;i<num;i++){
        for(j=1;j<=bagweight;j++){
            if(j<weight[i]){
                dp[i][j]=dp[i-1][j];
            }
            else{
                temVal1=dp[i-1][j];
                temVal2=value[i]+dp[i-1][j-weight[i]];
                dp[i][j]=temVal1 > temVal2 ? temVal1 : temVal2;
            }
        }
    }
    return dp[num-1][bagweight];
}

int main(){
    int num       = 3;
    int weight[3] ={1,  3,  4 };
    int value[3]  ={15, 20, 30};
    int bagweight = 4;
    int out       = -1;

    out=dynamicprogram(num, weight, value, bagweight);
    printf("__out = %d__\n", out);
    
    return 0;
}