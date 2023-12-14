#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int wiggleMaxLength(int* nums, int numsSize){
    int out=0;
    int i, j;
    // true is +, false is -
    int preSig, nowSig;
    if(numsSize==1){
        return 1;
    }
    if(numsSize==2){
        if(nums[0]==nums[1]){
            return 1;
        }
        return 2;
    }
    // 确定起始值
    preSig=(nums[1]-nums[0])>0?1:(nums[1]==nums[0]?0:-1);
    if(preSig==0){
        out=1;
    }
    else{
        out=2;
    }

    for(i=2;i<numsSize;i++){
        nowSig=(nums[i]-nums[i-1])>0?1:(nums[i]==nums[i-1]?0:-1);
        if(nowSig!=0){
            if(preSig==0){
                preSig=nowSig;
                out++;
            }
            else{
                if(nowSig!=preSig){
                    preSig=nowSig;
                    out++;
                }
            }
        }
    }
    return out;
}

int main(){
    int nums[10]={1, 17, 5, 10, 13, 15, 10, 5, 16, 8};
    int numsSize=10;
    int out=0;

    out=wiggleMaxLength(nums, numsSize);
    printf("out = %d\n", out);
    return 0;
}