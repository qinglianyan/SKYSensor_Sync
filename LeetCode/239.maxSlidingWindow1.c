#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 * 这个超出时间限制啦，时间太长了
 * **/
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize) {
    int i, j;
    int max=-10001;
    int left=0, right=0;
    int *out=(int *)malloc(100000*(sizeof(int)));

    *returnSize=0;
    right=left+k-1;
    for(i=left;i<=right;i++){
        if(nums[i]>max){
            max=nums[i];
        }
    }
    out[(*returnSize)++]=max;
    while(right<numsSize){
        left++;
        right++;
        if(right>=numsSize){
            break;
        }
        //in        nums<-nums[right]
        //out       nums[left-1]<-nums
        if(nums[left-1]==max){
            max=nums[left];
            for(i=left;i<=right;i++){
                if(nums[i]>max){
                    max=nums[i];
                }
            }
            out[(*returnSize)++]=max;
        }
        else{
            if(nums[right]>max){
                max=nums[right];
            }
            out[(*returnSize)++]=max;
        }
    }
return out;
}

int main(){
    int input[8]={1, 3, -1, -3, 5, 3, 6, 7};
    int k=3;
    int numsSize=8;
    int * output;
    int returnSize=0;
    int i, j;

    output=maxSlidingWindow(input, numsSize, k, &returnSize);
    for(i=0;i<returnSize-1;i++){
        printf("%d,", output[i]);
    }printf("%d", output[i]);
    printf("\n");
    return 0;
}