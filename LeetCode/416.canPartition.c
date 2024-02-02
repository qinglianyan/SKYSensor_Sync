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
*/
bool canPartition(int* nums, int numsSize){
    bool out=false;
    int i, j;


    return out;
}

int main(){
    int nums[4]={1, 5, 11, 5};
    int numsSize=4;
    int i, j;
    bool out;
    out=canPartition(nums, numsSize);
    if(out) printf("out = true!\n");
    else printf("out = false!\n");
    return 0;
}