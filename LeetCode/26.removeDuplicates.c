#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int removeDuplicates(int* nums, int numsSize) {
    int i,j;
    int nowIndex=0;
    for(i=1;i<numsSize;i++){
        if(nums[i]!=nums[i-1]){
            nums[++nowIndex]=nums[i];
        }
    }
// for(i=0;i<=nowIndex;i++){
//     printf("%d ", nums[i]);
// }
    return nowIndex+1;
}

int main(){
    int i, j;
    int out;
    int numsSize=10;
    int nums[10]={0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    
    out=removeDuplicates(nums, numsSize);
    printf("__out = %d__\n");
    return 0;
}