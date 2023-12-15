#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// int jump(int* nums, int numsSize) {
//     int *minJump=(int *)malloc(sizeof(int)*numsSize);
//     int i, j;
//     // int out=0;
//     memset(minJump, 9, sizeof(int)*numsSize);
//     minJump[0]=0;
//     for(i=0;i<numsSize-1;i++){
//         if(nums[i]==0){
//             continue;
//         }
//         for(j=1;j<=nums[i];j++){
//             if(i+j>=numsSize){
//                 break;
//             }
//             if(minJump[i]+1 < minJump[i+j]){
//                 minJump[i+j]=minJump[i]+1;
//             }
//         }
//     }
//     return minJump[numsSize-1];
// }
int jump(int* nums, int numsSize) {
    int end = 1;
    int start = 0;
    int ans = 0;
    while (end < numsSize) {
        int max_pos = 0;
        for (int i = start; i < end; i++){
            if (i + nums[i] > max_pos) {
                max_pos = i + nums[i]; 
            }
        }
        start = end;
        end = max_pos + 1;
        ans++;
    }
    return ans;
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