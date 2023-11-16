#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct ListNode{
    int val;
    struct ListNode *next;
};
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head){
    struct ListNode *p, *q, *tmp;
    int i, j;

    p=head;
    if(p==NULL){
        return NULL;
    }
    if(p->next==NULL){
        return head;
    }
    p=NULL, q=head;
    while(q!=NULL){
        tmp=q->next;
        q->next=p;
        p=q;
        q=tmp;
    }
    return p;
}

int main(){
    struct ListNode * head, * p, * q;
    struct ListNode *node1=(struct ListNode *)malloc(sizeof(struct ListNode)),
                    *node2=(struct ListNode *)malloc(sizeof(struct ListNode)),
                    *node3=(struct ListNode *)malloc(sizeof(struct ListNode)),
                    *node4=(struct ListNode *)malloc(sizeof(struct ListNode)),
                    *node5=(struct ListNode *)malloc(sizeof(struct ListNode));
    node1->val=1, node1->next=node2;
    node2->val=2, node2->next=node3;
    node3->val=3, node3->next=node4;
    node4->val=4, node4->next=node5;
    node5->val=5, node5->next=NULL;
    head=node1;
    for(p=head;p!=NULL;p=p->next){
        printf("%d ", p->val);
    }printf("\n");
    head=reverseList(head);
    for(p=head;p!=NULL;p=p->next){
        printf("%d ", p->val);
    }
    return 0;
}