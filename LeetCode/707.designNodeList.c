#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct MyLinkedList_ori{
    int val;
    struct MyLinkedList_ori * next;
} MyLinkedList;


MyLinkedList* myLinkedListCreate() {
    MyLinkedList * obj=(MyLinkedList *)malloc(sizeof(MyLinkedList));
    obj->val=0;
    obj->next=NULL;
    return obj;
}

int myLinkedListGet(MyLinkedList* obj, int index) {
    int i, j;
    MyLinkedList * ret;
    for(ret=obj->next,i=0;i<index;i++){
        if(index<=0){
            return -1;
        }
        if(ret==NULL){
            return -1;
        }
        ret=ret->next;
    }
    if(ret==NULL) return-1;
    return ret->val;
}

void myLinkedListAddAtHead(MyLinkedList* obj, int val) {
    MyLinkedList * tmp=(MyLinkedList *)malloc(sizeof(MyLinkedList));
    tmp->val=val;
    tmp->next=obj->next;
    obj->next=tmp;
    return;
}

void myLinkedListAddAtTail(MyLinkedList* obj, int val) {
    MyLinkedList *p=obj;
    MyLinkedList * tmp=(MyLinkedList * )malloc(sizeof(MyLinkedList));
    tmp->val=val;
    tmp->next=NULL;
    while(p->next!=NULL){
        p=p->next;
    }
    p->next=tmp;
    return;
}

void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) {
    MyLinkedList * tmp=(MyLinkedList *)malloc(sizeof(MyLinkedList));
    MyLinkedList * p;
    int i, j;
    tmp->val=val;
    tmp->next=NULL;
    for(p=obj, i=0;i<index;i++){
        if(p->next==NULL){
            return;
        }
        p=p->next;
    }
    tmp->next=p->next;
    p->next=tmp;
    return;
}

void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) {
    int i, j;
    MyLinkedList * p=obj, *q=p->next;
    for(i=0;i<index;i++){
        if(q==NULL) return;
        p=q;
        q=q->next;
    }
    if(q==NULL) return;
    p->next=q->next;
    free(q);
    q=p->next;
    return;
}

void myLinkedListFree(MyLinkedList* obj) {
    MyLinkedList * p, * q;
    int i, j;
    p=obj, q=obj->next;
    while(q!=NULL){
        p=q;
        q=q->next;
        free(p);
    }
    return;
}

/**
 * Your MyLinkedList struct will be instantiated and called as such:
 * MyLinkedList* obj = myLinkedListCreate();
 * int param_1 = myLinkedListGet(obj, index);
 * myLinkedListAddAtHead(obj, val);
 * myLinkedListAddAtTail(obj, val);
 * myLinkedListAddAtIndex(obj, index, val);
 * myLinkedListDeleteAtIndex(obj, index);
 * myLinkedListFree(obj);
*/

int main(){
    int i, j;
    int index, val;
    MyLinkedList *p;
    MyLinkedList* obj = myLinkedListCreate();
    // myLinkedListAddAtHead(obj, 1);
    // myLinkedListAddAtTail(obj, 3);
    // myLinkedListAddAtIndex(obj, 1, 2);
    // for(p=obj->next;p!=NULL;p=p->next){
    //     printf("%d ", p->val);
    // }
    // // printf("\n")
    // printf("\n%d\n", myLinkedListGet(obj, 1));
    // myLinkedListDeleteAtIndex(obj, 1);
    // for(p=obj->next;p!=NULL;p=p->next){
    //     printf("%d ", p->val);
    // }
    // printf("\n%d\n", myLinkedListGet(obj, 1));
    myLinkedListAddAtHead(obj, 1);
    myLinkedListAddAtTail(obj, 3);
    myLinkedListAddAtIndex(obj, 3, 2);
    for(p=obj->next;p!=NULL;p=p->next){
        printf("%d ", p->val);
    }
    return 0;
}