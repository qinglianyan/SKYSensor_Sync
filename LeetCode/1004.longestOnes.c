#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAXSIZE 100001
#define MAX(a,b) (a>b?a:b)
#define MIN(a,b) (a<b?a:b)
int longestOnes(int* nums, int numsSize, int k) {
    int i, j;
    int maxLen=0, zcount=0;
    int l, r;// 左右下标
    for(l=0,r=0;r<numsSize;r++){
        if(nums[r]==0){
            zcount++;
        }
        while(zcount>k){
            if(nums[l]==0){
                zcount--;
            }
            l++;
        }
        maxLen=MAX(maxLen, r-l+1);
    }
    return maxLen;
}

int main(){
    int i, j;
    int out;
    int numsSize=11;
    int nums[11]={1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0};
    int k=2;
    out=longestOnes(nums, numsSize, k);
    printf("__out = %d__\n", out);
    return 0;
}