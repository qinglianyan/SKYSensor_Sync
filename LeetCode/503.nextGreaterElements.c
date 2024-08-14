#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
/**
 * 时间很慢，空间很大，这个栈可以考虑大小手动申请
 * 另外这个ans初始化为-1可能占了比较长的时间
*/
#define valueMax 100001
#define lenMax 10000000
int stack[lenMax*2];
int top=-1;
int ans[lenMax*2];
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
int* nextGreaterElements(int* nums, int numsSize, int* returnSize) {
    int i, j;
//    int out[numsSize];

    top=-1;
    *returnSize=numsSize;
//    memset(out, 0xff, sizeof(out));
    memset(ans, 0xff, sizeof(ans));
    for(i=0;i<numsSize;i++){
        push(nums, i);
    }
    for(i=0;i<numsSize;i++){
        push(nums, i);
    }

    return ans;
}

int main(){
    int i, j;
    int *nums, *out;
    int numsSize;
    int *returnSize=(int *)malloc(sizeof(int));
    *returnSize=0;

    // numsSize=3;
    // nums=(int *)malloc(sizeof(int)*numsSize);
    // nums[0]=1, nums[1]=2, nums[2]=1;

    numsSize=1;
    nums=(int *)malloc(sizeof(int)*numsSize);
    nums[0]=1;

    out=nextGreaterElements(nums, numsSize, returnSize);
    for(i=0;i<(*returnSize);i++){
        printf("%d ", out[i]);
    }printf("\n");
    return 0;
}
