#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct ListNode {
    int val;
    struct ListNode *next;
};
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    struct ListNode *p, *q;
    int lenA=0, lenB=0, dist=0;
    int i, j;

    p=headA;
    while(p!=NULL){
        lenA++;
        p=p->next;
    }
    q=headB;
    while(q!=NULL){
        lenB++;
        q=q->next;
    }
    p=headA, q=headB;
    if(lenA<lenB){
        dist=lenB-lenA;
        for(i=0;i<dist;i++){
            q=q->next;
        }
    }
    else{
        dist=lenA-lenB;
        for(i=0;i<dist;i++){
            p=p->next;
        }
    }
    while(p!=NULL&&q!=NULL){
        if(p==q){
            return p;
        }
        p=p->next;
        q=q->next;
    }
    return NULL;
}

int main(){

    return 0;
}