#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/**
 * 给你一个下标从 0 开始、长度为 n 的整数数组 nums ，其中 n 是班级中学生的总数。
 * 班主任希望能够在让所有学生保持开心的情况下选出一组学生：
 * 
 * 如果能够满足下述两个条件之一，则认为第 i 位学生将会保持开心：
 * 
 * 这位学生被选中，并且被选中的学生人数 严格大于 nums[i] 。
 * 这位学生没有被选中，并且被选中的学生人数 严格小于 nums[i] 。
 * 返回能够满足让所有学生保持开心的分组方法的数目。
*/
int cmp(const void * in1, const void * in2){
    return *(int *)in1 - *(int *)in2;
}
int countWays(int* nums, int numsSize){
    int i, j;
    int nowCount=0;
    int successCount=0;
    /**
     * 如果nums[i]=x选中，那么当前被选中人数一定 > x，那么所有nums[j] < x的同学都要被选中
     * 同理，如果nums[i]=x不被选中，当前选中人数 < x，所有nums[j] > x的同学都不被选中
    */
    qsort(nums, numsSize, sizeof(nums[0]), cmp);
    // for(i=0;i<numsSize;i++){
    //     printf("%d ", nums[i]);
    // }
    if(nums[0]>0){
        successCount++;
    }
    for(i=0;i<numsSize;i++){
        nowCount++;
        if(i<numsSize-1){
            if(nums[i+1]>nums[i] && nowCount>nums[i] && nowCount<nums[i+1]){
                successCount++;
            }
        }
        else{
            if(nowCount>nums[i]){
                successCount++;
            }
        }
    }
    return successCount;
}

int main(){
    int i,j;
    int numsSize=8;
    int nums[8]={6, 0, 3, 3, 6, 7, 2, 7};
    // for(i=0;i<numsSize;i++){
    //     printf("%d ", nums[i]);
    // }
    int out=countWays(nums, numsSize);
    printf("__out = %d__\n", out);
    return 0;
}