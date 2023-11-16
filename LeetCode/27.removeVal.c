#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
//方法一：for循环遍历
// int removeElement(int* nums, int numsSize, int val){
//     int i, j;
//     for(i=0;i<numsSize;i++){
//         if(nums[i]==val){
//             for(j=i;j<numsSize-1;j++){
//                 nums[j]=nums[j+1];
//             }
//             i--;
//             numsSize--;
//         }
//     }
//     return numsSize;
// }

//方法二：快慢指针
int removeElement(int* nums, int numsSize, int val){
    int fast, slow;

    for(fast = slow = 0; fast < numsSize ; fast++){
        if(nums[fast] != val){
            nums[slow++]=nums[fast];
        }
    }
    return slow;
}

int main(){
    int nums[] = {0, 1, 2, 2, 3, 0, 4, 2};
    int numsSize = 8;
    int val = 2;
    int i, j;
    
    int len = removeElement(nums, numsSize, val);
    printf("%d\n", len);
    for(i=0;i<len;i++){
        printf("%d ", nums[i]);
    }
    return 0;
}