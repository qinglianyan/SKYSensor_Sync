#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


#define MAX_NUMS 200
/** 
 * 一个是恰好值问题：拿出的元素的和恰好是所有和的一半
 * 一个是最值  问题：0-1背包要求在有限的背包中拿到最高价值的物品
 * 交集点在于：用所有和一半大小的背包拿元素恰好拿满的时候也是最高价值的时候
 * 有没有可能的反例点呢，这个情况成立的前提是什么？
 * ///
 * 之后再想，先用0-1背包写出来一遍
 * 一维dp有没有必要初始化，之前模板例子有初始化，但是这个题目只有初始0
*/
#define MAX_NUMS 200
bool canPartition(int* nums, int numsSize){
    int i, j;
    int total=0, half=0;
    int dp[20001];
    int tempVal1, tempVal2;
    memset(dp, 0, sizeof(dp));

    for(i=0;i<numsSize;i++){
        total+=nums[i];
    }
    if(total%2==1){
        return false;
    }
    half=total/2;
    // 到此，该问题变成了一个容量为half的背包
    // 物品的质量和价值都是数值
    for(i=0;i<numsSize;i++){
        for(j=half;j>=nums[i];j--){
            tempVal1=dp[j];
            tempVal2=dp[j-nums[i]]+nums[i];
            dp[j]=tempVal1>tempVal2?tempVal1:tempVal2;
        }
    }
    if(dp[half]==half) return true;
    return false;
}

int main(){
    // int nums[4]={1, 5, 11, 5};
    // int numsSize=4;
    int nums[8]={100, 100, 100, 100, 100, 100, 100, 100};
    int numsSize=8;
    int i, j;
    bool out;
    out=canPartition(nums, numsSize);
    if(out) printf("out = true!\n");
    else printf("out = false!\n");
    return 0;
}