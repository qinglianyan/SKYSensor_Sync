#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *intersection(int *nums1, int nums1Size,
                  int *nums2, int nums2Size,
                  int *returnSize)
{

    int i, j;
    int minSize = nums1Size < nums2Size ? nums1Size : nums2Size;
    int *ret = (int *)malloc(sizeof(int) * minSize);
    int hash[1001]={0};
    *returnSize=0;
    int cur=0;//保存ret数组最上面的pos

    for(i=0;i<nums1Size;i++){
        hash[nums1[i]]=1;
    }

    for(i=0;i<nums2Size;i++){
        if(hash[nums2[i]] > 0){
            ret[cur++]=nums2[i];
            (*returnSize)++;
            hash[nums2[i]]=0;
        }
    }
    return ret;
}

int main()
{
    int nums1[]={1, 2, 2, 1};
    int nums2[]={2, 2};
    int nums1Size=4, nums2Size=2, returnSize;
    int *output, i, j;
    output=intersection(nums1, nums1Size, nums2, nums2Size, &returnSize);
    for(i=0;i<returnSize;i++){
        printf("%d ", output[i]);
    }
    getchar();
    return 0;
}