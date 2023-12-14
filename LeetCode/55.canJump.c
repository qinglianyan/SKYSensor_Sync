#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_NUMS 100001
bool success=false;
int hash[MAX_NUMS];
void backtracking(int *nums, int numsSize, int now){
    int i, j;
    if(now>=numsSize-1){
        success=true;
        return ;
    }
    if(nums[now]==0) return ;
    if(hash[now]==1) return ;
    for(i=nums[now];i>0;i--){
        if(success) return ;
        now+=i;
        backtracking(nums, numsSize, now);
        hash[now]=1;
        now-=i;
    }
    return ;
}

bool canJump(int* nums, int numsSize) {
    int i, j;
    success=false;
    memset(hash, 0, sizeof(hash));
    backtracking(nums, numsSize, 0);
    return success;
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