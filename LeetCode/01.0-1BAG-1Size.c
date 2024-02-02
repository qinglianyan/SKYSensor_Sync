#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
/*
    https://programmercarl.com/%E8%83%8C%E5%8C%85%E7%90%86%E8%AE%BA%E5%9F%BA%E7%A1%8001%E8%83%8C%E5%8C%85-2.html#%E6%80%9D%E8%B7%AF
    与[][]相比不同的是，不再使用二位数组，而是用了一维数组做DP
    
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
    int i, j;
    int dp[num][bagweight+1];
    int temVal1, temVal2;
    // dp[i][j]:
    // 表示下表为[0,i]的物品里任意取，放入容量为j的背包
    // 最大价值为多少.
    // 在这个例子中就是三行五列的二维数组

    int dpNow[bagweight+1];
    memset(dpNow, 0, sizeof(int)*(bagweight+1));
    // 相当于是一行一行地更新，这次不用dp了，而用这个dpNow


    // init
    for(j=weight[0];j<bagweight;j++){   // 0 15 15 15 15
        dpNow[j]=value[0];
    }

    // dp
    // 对于[0-i]物品
    // 1、如果不放进去i物品，dp[i][j] = dp[i-1][j]
    // 2、如果放进去i物品，dp[i][j] = value[i]+dp[i-1][j-weight[i]]
    // 对于滚动数组来说，每次一行一行地更新
    // 相当于是这一行计算的时候用上一行的数据来求
    // dp公式可改写为：dp[j]=dp[j]
    //                dp[j]=value[i]+dp[j-weight[i]]
    // :@@@ 为什么优化滚动数组要逆序？：
    // 因为i每加1代表新的一行开始，由于dp[j-num[i]]每次都得使用的是
    // 上一行的数据。但是如果你正序的话，那么你在计算dp[j]的时候用
    // 到的dp[j-num[i]]是本行的，而不是上一行的，所以用逆序，
    // 逆序用到的dp[j-num[i]]是上一行的。
    for(i=1;i<num;i++){
        for(j=bagweight;j>=weight[i];j--){
            temVal1=dpNow[j];
            temVal2=value[i]+dpNow[j-weight[i]];
            dpNow[j]=temVal1 > temVal2 ? temVal1 : temVal2;
        }
    }
    return dpNow[bagweight];
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