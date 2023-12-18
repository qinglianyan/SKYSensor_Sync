#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
int cmp(const int *p1, const int *p2){
    return *(int *)p1-*(int *)p2;
}
int largestSumAfterKNegations(int* nums, int numsSize, int k) {
    int out=0;
    int i, j;
    qsort(nums, numsSize, sizeof(int), cmp);
    // for(i=0;i<numsSize;i++){
    //     printf("nums[%d] = %d\n", i, nums[i]);
    // }
    
    return out;
}

int main(){
    int i ,j;
    int out=0;

    int nums[3]={4, 2, 3};
    int numsSize=3;
    
    out=largestSumAfterKNegations(nums, numsSize, 1);
    printf("out = %d\n", out);
    return 0;
}