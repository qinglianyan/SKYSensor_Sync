#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int jump(int* nums, int numsSize) {
    int i, j;
    int max=0;
    int start=0, end=1;
    int maxEnd=0;
    int out=0;

    if(numsSize==1){
        return 0;
    }
    while(end < numsSize-1){
        maxEnd=0;
        for(i=start;i<end;i++){
            if(nums[i]+i>maxEnd){
                maxEnd=nums[i]+i;
            }
        }
        start=end;
        end=maxEnd;
        out++;
    }
    return out;
}

int main(){
    // int nums[5]={2, 3, 1, 1, 4};
    // int numsSize=5;
    int i, j;
    int out;
    int nums[2]={2, 1};
    int numsSize=2;

    out=jump(nums, numsSize);
    printf("out = %d\n", out);
    return 0;
}