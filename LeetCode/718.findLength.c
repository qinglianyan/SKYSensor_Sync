#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int findLength(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int i, j;
    int dp[nums1Size+1][nums2Size];
    int result=0;
    memset(dp, 0, sizeof(dp));

    for(i=1;i<nums1Size;i++){
        for(j=1;j<nums2Size;j++){
            if(nums1[i]==nums2[j]){
                dp[i][j]=dp[i-1][j-1]+1;
            }
            if(dp[i][j]>result){
                result=dp[i][j];
            }
        }
    }
    for(i=0;i<nums1Size;i++){
        for(j=0;j<nums2Size;j++){
            printf("%d ", dp[i][j]);
        }
        printf("\n");
    }
    return result;
}

int main(){
    int i, j;
    int out;
    int nums1Size=5;
    int nums2Size=5;
    int nums1[5]={1, 2, 3, 2, 1};
    int nums2[5]={3, 2, 1, 4, 7};// out=3

    // int nums1Size=5;
    // int nums2Size=5;
    // int nums1[5]={0, 0, 0, 0, 0};
    // int nums2[5]={0, 0, 0, 0, 0};// out=5

    out=findLength(nums1, nums1Size, nums2, nums2Size);
    printf("__out = %d__\n", out);
    return 0;
}