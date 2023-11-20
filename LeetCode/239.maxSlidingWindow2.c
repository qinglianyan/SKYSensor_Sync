#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


int queue[100000];
int qTop=-1, qEnd=-1;
/**
 *       最后一个
 *          ↓
 * |0|1|2|3|4|
 *  ↑         ↑
 * qTop      qEnd
*/
int tfront(){
    return queue[qTop];
}

bool isEmpty(){
    if(qTop==qEnd){
        return true;
    }
    return false;
}
int popFront(){
    if(isEmpty()){
        printf("error:popFront empty!\n");
        return -1;
    }
    return queue[qTop++];
}
int popBack(){
    if(isEmpty()){
        printf("error:popBack empty!\n");
        return -1;
    }
    return queue[--qEnd];
}
int popQueue(int value){
    if(!isEmpty() && value==tfront()){
        return popFront();
    }
    return -1;
}
void push(int value){
    while(!isEmpty()&&value>queue[qEnd-1]){
        popBack();
    }
    if(qEnd==qTop&&qEnd==-1){
        qTop=0;
        qEnd=1;
        queue[qTop]=value;
    }
    else{
        queue[qEnd++]=value;
    }
    return ;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize) {
    int i, j;
    int max;
    int *out=(int *)malloc(100000*(sizeof(int)));
    int outop=0;
    qTop=-1;
    qEnd=-1;
    // returnSize=(int *)malloc(sizeof(int));
    //下面这行不能删除，对leetcode里面用returnSize需要先进行初始化，否则不一定有值
    *returnSize=0;

    for(i=0;i<k;i++){
        push(nums[i]);
    }
    out[(*returnSize)++]=tfront();
    for(i=k;i<numsSize;i++){
        popQueue(nums[i-k]);
        push(nums[i]);
        out[(*returnSize)++]=tfront();
    }
return out;
}

int main(){
    int input[8]={1, 3, -1, -3, 5, 3, 6, 7};
    int k=3;
    int numsSize=8;

    // int input[1]={1};
    // int k=1;
    // int numsSize=1;

    int * output;
    int * returnSize=(int *)malloc(sizeof(int));
    int i, j;

    output=maxSlidingWindow(input, numsSize, k, returnSize);
    for(i=0;i<(*returnSize)-1;i++){
        printf("%d,", output[i]);
    }printf("%d", output[i]);
    printf("\n");
    return 0;
}