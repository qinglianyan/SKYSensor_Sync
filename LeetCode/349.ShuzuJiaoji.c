#include <stdio.h>
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

int main(){
    int nums1[3]={4, 9, 5};
    int nums2[5]={9, 4, 9, 8, 4};
    int numlen1=3, numlen2=5;
    int numsize;
    int *out;
    int i, j;

    out=intersection(nums1, numlen1, nums2, numlen2, &numsize);
    for(i=0;i<numsize;i++){
        printf("out[%d] = %d\n", i, out[i]);
    }
    getchar();
    return 0;
}