#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* swapPairs(struct ListNode* head){
    struct ListNode * virtualHead=(struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode * p, *q, *cur, *tmp;
    int flag=0;
    virtualHead->val=0; virtualHead->next=head;
    head=virtualHead;

    cur=head;
    while(cur->next!=NULL&&cur->next->next!=NULL){
        p=cur->next, q=cur->next->next;

        p->next=q->next;
        cur->next=q;
        q->next=p;

        cur=cur->next->next;
    }
    return head->next;
}

int main(){
    int i, j;
    struct ListNode *head, *p, *q, *cur, *output;
    head=(struct ListNode*)malloc(sizeof(struct ListNode));
    head->val=0;
    head->next=NULL;
    
    cur=head;
    for(i=1;i<=4;i++){
        p=(struct ListNode *)malloc(sizeof(struct ListNode));
        p->val=i;
        p->next=NULL;
        cur->next=p;
        cur=p;
    }
    for(p=head->next;p!=NULL;p=p->next){
        printf("%d ", p->val);
    }printf("\n");
    output = swapPairs(head->next);

    for(p=output;p!=NULL;p=p->next){
        printf("%d ", p->val);
    }
    return 0;
}