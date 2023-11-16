#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    int stackInTop, stackOutTop;
    int stackIn[100], stackOut[100];
} MyQueue;


MyQueue* myQueueCreate() {
    MyQueue* queue=(MyQueue*)malloc(sizeof(MyQueue));
    queue->stackInTop=0;
    queue->stackOutTop=0;
    return queue;
}

void myQueuePush(MyQueue* obj, int x) {
    obj->stackIn[(obj->stackInTop)++]=x;

}

int myQueuePop(MyQueue* obj) {
    int out;
    while(obj->stackInTop>0){
        obj->stackOut[(obj->stackOutTop)++]=obj->stackIn[--(obj->stackInTop)];
    }
    out=obj->stackOut[--(obj->stackOutTop)];
    while(obj->stackOutTop>0){
        obj->stackIn[(obj->stackInTop)++]=obj->stackOut[--(obj->stackOutTop)];
    }
    return out;
}

int myQueuePeek(MyQueue* obj) {
    return obj->stackIn[0];
}

bool myQueueEmpty(MyQueue* obj) {
    return obj->stackInTop == 0 && obj->stackOutTop == 0;
}

void myQueueFree(MyQueue* obj) {
    obj->stackInTop=0;
    obj->stackOutTop=0;
}

/**
 * Your MyQueue struct will be instantiated and called as such:
 * MyQueue* obj = myQueueCreate();
 * myQueuePush(obj, x);
 
 * int param_2 = myQueuePop(obj);
 
 * int param_3 = myQueuePeek(obj);
 
 * bool param_4 = myQueueEmpty(obj);
 
 * myQueueFree(obj);
*/

int main(){

    return 0;
}