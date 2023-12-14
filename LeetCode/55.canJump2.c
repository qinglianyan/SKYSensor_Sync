#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool canJump(int* nums, int numsSize) {
    int i, j;
    int cover=0;
    for(i=0;i<=cover;i++){
        cover=(i+nums[i])>cover?(i+nums[i]):cover;
        if(cover>=numsSize-1) return true;
    }

    return false;
}

int main(){
    int nums[5]={3, 2, 1, 0, 4};
    int numsSize=5;
    bool out=false;

    out=canJump(nums, numsSize);
    if(out){
        printf("out = true\n");
        return 0;
    }
    printf("out = false\n");
    return 0;
}