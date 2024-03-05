#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

/**
 * 有N件物品和一个最多能背重量为W的背包。第i件物品的重量是weight[i]，得到的价值是value[i] 。
 * 每件物品都有无限个（也就是可以放入背包多次），求解将哪些物品装入背包里物品价值总和最大。
 * 完全背包和01背包问题唯一不同的地方就是，每种物品有无限件
 * 
 * 例子：
 * 背包最大重量为4，物品重量分别为：1， 3， 4
 *                 物品价值分别为：15，20，30
 * 如果是0-1背包：
 * for(int i = 0; i < weight.size(); i++) { // 遍历物品
 *  for(int j = bagWeight; j >= weight[i]; j--) { // 遍历背包容量
 *      dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
 *  }
 * }
 * 完全背包：
 * for(int i = 0; i < weight.size(); i++) { // 遍历物品
 *  for(int j = weight[i]; j <= bagWeight ; j++) { // 遍历背包容量
 *      dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
 *  }
 * }
 * 
*/

int main(){

    return 0;
}