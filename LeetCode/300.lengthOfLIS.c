#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int lengthOfLIS(int* nums, int numsSize) {
    int i, j;
    int numsStore[numsSize];
    int maxLength;
    memset(numsStore, 0, sizeof(numsStore));
    // numsStore[]表示此处连续递增数量

    numsStore[0]=1;
    maxLength=1;
    for(i=1;i<numsSize;i++){
        if(nums[i]>nums[i-1]){
            numsStore[i]=numsStore[i-1]+1;
            if(numsStore[i]>maxlen)
        }
    }
    return 0;
}

int main(){
    int i, j;
    int numsSize=8;
    int nums[8]={10, 9, 2, 5, 3, 7, 101, 18};

    // int numsSize=6;
    // int nums[6]={0, 1, 0, 3, 2, 3};

    // int numsSize=7;
    // int nums[7]={7, 7, 7, 7, 7, 7, 7};
    int out=0;
    out=lengthOfLIS(nums, numsSize);
    printf("__out = %d__\n", out);
    return 0;
}