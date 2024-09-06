#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/**
 * 你有一个数组 nums它只包含正整数，所有正整数的数位长度都相同。
 * 两个整数的 数位差 指的是两个整数相同位置上不同数字的数目。
 * 请你返回 nums 中 所有 整数对里，数位差之和。
 * 
 * 2 <= nums.length <= 10^5
 * 1 <= nums[i] < 10^9
 * nums 中的整数都有相同的数位长度。
*/

long long sumDigitDifferences(int* nums, int numsSize) {
    long long i, j;
    long long ret=0;
    long long count[10]={0}; // 记录的是这一位中每个数字出现的个数
    long long totalcount[10]={0}; // 记录的是小于当前下标的数字个数
    while(nums[0]>0){
        memset(count, 0, sizeof(count));
        memset(totalcount, 0, sizeof(totalcount));
        for(i=0;i<numsSize;i++){
            count[nums[i]%10]++;
            nums[i]/=10;
        }
        for(i=1;i<10;i++){
            if(i==1){
                totalcount[i]=count[i-1];
                ret+=totalcount[i]*count[i];
            }
            else{
                totalcount[i]=totalcount[i-1]+count[i-1];
                if(count[i]!=0){
                    ret+=totalcount[i]*count[i];
                }
            }
        }
    }
    return ret;
}

int main(){
    int i, j;
    long long out;
    int numsSize=3;
    int *nums=(int *)malloc(sizeof(int)*numsSize);
    nums[0]=50, nums[1]=28, nums[2]=38;

    out=sumDigitDifferences(nums, numsSize);
    printf("__out = %lld__\n", out);
    return 0;
}