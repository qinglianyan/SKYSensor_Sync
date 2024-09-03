#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

long long maxStrength(int* nums, int numsSize){
    int i, j;
    long long ret=1;
    int minabs=-10;
    int nzcount=0;
    if(numsSize==1){ // 只有一个元素
        return nums[0];
    }
    for(i=0;i<numsSize;i++){
        if(nums[i]!=0){
            nzcount++;
            if(nums[i]<0){
                if(minabs<nums[i]){
                    minabs=nums[i];
                }
            }
            ret*=nums[i];
        }
    }
    if(nzcount==0){ // 全是0
        return 0;
    }
    else if(nzcount==1){
        return (ret>0?ret:0);
    }
    if(ret<0){
        ret/=minabs;
    }
    return ret;
}

int main(){
    int i, j;
    int numsSize=6;
    int nums[6]={3, -1, -5, 2, 5, -9};
    long long out;

    out=maxStrength(nums, numsSize);
    printf("__out = %lld__\n", out);
    return 0;
}