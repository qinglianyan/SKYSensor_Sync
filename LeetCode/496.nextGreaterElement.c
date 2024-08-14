#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define valueMax 10001
#define lenMax 1001
int stack[lenMax];
int top=-1;
int ans[lenMax];
bool stackEmpty(){
    if(top==-1){
        return true;
    }
    else if(top>=0){
        return false;
    }
    else{
        printf("Error:stackEmpty error!\n");
        return false;
    }
}
int pop(){
    if(top<0){
        printf("Error:pop Error. stack empty.\n");
        return 0;
    }
    return stack[top--];
}
void push(int *nums2, int index){
    int tmp, now;
    int i, j;
    if(top>=lenMax){
        printf("Error:push Error. stack full.\n");
        return ;
    }
    else if(top<-1){
        printf("Error:push Error.invalid top.\n");
        return ;
    }
    else if(top==-1){
        stack[++top]=index;
    }
    else{
        while(top>=0 && nums2[stack[top]]<nums2[index]){
            ans[stack[top]]=nums2[index];
            top--;
        }
        stack[++top]=index;
    }
    return ;
}
int* nextGreaterElement(int* nums1, int nums1Size, 
                        int* nums2, int nums2Size, int* returnSize) {
    int i, j;
    int hash[valueMax];

    top=-1;
    *returnSize=nums1Size;
    memset(ans, 0xff, sizeof(ans));
    memset(hash, -1, sizeof(hash));
    for(i=0;i<nums2Size;i++){
        hash[nums2[i]]=i;
    }
    for(i=0;i<nums2Size;i++){
        push(nums2, i);
    }
    // for(i=0;i<nums2Size;i++){
    //     printf("%d ", ans[i]);
    // }printf("\n");
    for(i=0;i<nums1Size;i++){
        nums1[i]=ans[hash[nums1[i]]];
    }

    return nums1;
}


int main(){
    int i, j;
    int *nums1, *nums2, *out;
    int nums1Size, nums2Size;
    int *returnSize=(int *)malloc(sizeof(int));
    *returnSize=0;

    // nums1Size=3;
    // nums2Size=4;
    // nums1=(int *)malloc(sizeof(int)*nums1Size);
    // nums2=(int *)malloc(sizeof(int)*nums2Size);
    // nums1[0]=4, nums1[1]=1, nums1[2]=2;
    // nums2[0]=1, nums2[1]=3, nums2[2]=4, nums2[3]=2;

    nums1Size=3;
    nums2Size=3;
    nums1=(int *)malloc(sizeof(int)*nums1Size);
    nums2=(int *)malloc(sizeof(int)*nums2Size);
    nums1[0]=2, nums1[1]=1, nums1[2]=3;
    nums2[0]=2, nums2[1]=3, nums2[2]=1;

    out=nextGreaterElement(nums1, nums1Size, nums2, nums2Size, returnSize);
    for(i=0;i<(*returnSize);i++){
        printf("%d ", out[i]);
    }printf("\n");


    return 0;
}

/**
 * nums1 中数字 x 的 下一个更大元素 是指 x 在 nums2 中对应位置 右侧 的 第一个 比 x 大的元素。

给你两个 没有重复元素 的数组 nums1 和 nums2 ，下标从 0 开始计数，其中nums1 是 nums2 的子集。

对于每个 0 <= i < nums1.length ，找出满足 nums1[i] == nums2[j] 的下标 j ，并且在 nums2 确定 nums2[j] 的 下一个更大元素 。如果不存在下一个更大元素，那么本次查询的答案是 -1 。

返回一个长度为 nums1.length 的数组 ans 作为答案，满足 ans[i] 是如上所述的 下一个更大元素 。

 

示例 1：

输入：nums1 = [4,1,2], nums2 = [1,3,4,2].
输出：[-1,3,-1]
解释：nums1 中每个值的下一个更大元素如下所述：
- 4 ，用加粗斜体标识，nums2 = [1,3,4,2]。不存在下一个更大元素，所以答案是 -1 。
- 1 ，用加粗斜体标识，nums2 = [1,3,4,2]。下一个更大元素是 3 。
- 2 ，用加粗斜体标识，nums2 = [1,3,4,2]。不存在下一个更大元素，所以答案是 -1 。
示例 2：

输入：nums1 = [2,4], nums2 = [1,2,3,4].
输出：[3,-1]
解释：nums1 中每个值的下一个更大元素如下所述：
- 2 ，用加粗斜体标识，nums2 = [1,2,3,4]。下一个更大元素是 3 。
- 4 ，用加粗斜体标识，nums2 = [1,2,3,4]。不存在下一个更大元素，所以答案是 -1 。


提示：

1 <= nums1.length <= nums2.length <= 1000
0 <= nums1[i], nums2[i] <= 104
nums1和nums2中所有整数 互不相同
nums1 中的所有整数同样出现在 nums2 中
*/