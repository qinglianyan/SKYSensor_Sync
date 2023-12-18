#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
int cmp(const void *p1, const void *p2){
    return abs(*(int *)p2)-abs(*(int *)p1);
}
int largestSumAfterKNegations(int* nums, int numsSize, int k) {
    int out=0;
    int i, j;
    qsort(nums, numsSize, sizeof(int), cmp);
    // for(i=0;i<numsSize;i++){
    //     printf("%d ", nums[i]);
    // }printf("\n");
    for(i=0;i<numsSize;i++){
        if(nums[i]<0&&k>0){
            nums[i]*=-1;
            k--;
        }
    }
    if(k%2==1) nums[numsSize-1]*=-1;
    for(i=0;i<numsSize;i++){
        out+=nums[i];
    }
    return out;
}

int main(){
    int i ,j;
    int out=0;

    // int nums[3]={4, 2, 3};
    // int numsSize=3;

    int nums[5]={2, -3, -1, 5, -4};
    int numsSize=5;
    
    out=largestSumAfterKNegations(nums, numsSize, 2);
    printf("out = %d\n", out);
    return 0;
}