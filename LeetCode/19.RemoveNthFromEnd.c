#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    int i, j;
    int length=0;
    struct ListNode *p, *q, *forward, *virtualHead;
    for(p=head;p!=NULL;p=p->next){
        length++;
    }
    // printf("length = %d\n", length);
    if(length<n){
        printf("error : n is too large!\n");
        return head;
    }
    virtualHead=(struct ListNode *)malloc(sizeof(struct ListNode));
    virtualHead->val=0;
    virtualHead->next=head;
    head=virtualHead;

    q=head;
    p=q;
    for(i=0;i<n;i++){
        p=p->next;
    }
    while(p->next!=NULL){
        p=p->next;
        q=q->next;
    }
    q->next=q->next->next;
    
    return head->next;
}

int main(){
    int i, j;
    struct ListNode *head, *p, *q, *cur, *output;
    head=(struct ListNode*)malloc(sizeof(struct ListNode));
    head->val=0;
    head->next=NULL;
    
    cur=head;
    for(i=1;i<=5;i++){
        p=(struct ListNode *)malloc(sizeof(struct ListNode));
        p->val=i;
        p->next=NULL;
        cur->next=p;
        cur=p;
    }
    for(p=head->next;p!=NULL;p=p->next){
        printf("%d ", p->val);
    }printf("\n");
    output = removeNthFromEnd(head->next, 2);

    for(p=output;p!=NULL;p=p->next){
        printf("%d ", p->val);
    }
    return 0;
}