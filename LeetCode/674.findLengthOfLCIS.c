#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


int findLengthOfLCIS(int* nums, int numsSize) {
    
}

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
            if(numsStore[i]>maxLength){
                maxLength=numsStore[i];
            }
        }
        else{
            numsStore[i]=1;
        }
        printf("nums=%d, numsStore=%d, max=%d\n", nums[i], numsStore[i], maxLength);
    }
    return maxLength;
}

int main(){
    int i, j;
    // int numsSize=8;
    // int nums[8]={10, 9, 2, 5, 3, 7, 101, 18};

    int numsSize=5;
    int nums[5]={1, 3, 5, 4, 7};

    // int numsSize=7;
    // int nums[7]={7, 7, 7, 7, 7, 7, 7};
    int out=0;
    out=lengthOfLIS(nums, numsSize);
    printf("__out = %d__\n", out);
    return 0;
}