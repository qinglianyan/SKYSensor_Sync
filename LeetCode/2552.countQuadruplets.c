#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

long long countQuadruplets(int* nums, int numsSize) {
    int i, j, k, l;
    int total=0;
    for(i=0;i<numsSize-3;i++){
        for(j=i+1;j<numsSize-2;j++){
            if(nums[j]<=nums[i]){
                continue;
            }
            for(k=j+1;k<numsSize-1;k++){
                if(nums[k]>=nums[j] || nums[k]<=nums[i]){
                    continue;
                }
                for(l=k+1;l<numsSize;l++){
                    if(nums[i]<nums[k] && nums[k]<nums[j] && nums[j]<nums[l]){
                        total++;
                    }
                }
            }
        }
    }

    return total;
}

int main(){
    int i, j;
    int numsSize=5;
    int nums[5]={1, 3, 2, 4, 5};
    long long output=0;

    output=countQuadruplets(nums, numsSize);
    printf("__out = %lld__\n", output);

    return 0;
}