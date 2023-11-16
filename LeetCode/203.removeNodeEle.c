#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct ListNode{
    int val;
    struct ListNode * next;
};
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeElements(struct ListNode* head, int val){
    struct ListNode *p, *q, *tmp;
    //删除开头的val
    while(head!=NULL&&head->val==val){
        p=head;
        head=head->next;
        free(p);
    }
    if(head==NULL){
        return head;
    }
    //删除第一个以后的val
    q=head;p=head->next;
    while(p!=NULL){
        if(p->val==val){
            tmp=p;
            p=p->next;
            q->next=p;
            free(tmp);
        }
        else{
            q=p;
            p=p->next;
        }
    }
    return head;
}

int main(){
    struct ListNode * head, * last, * p;
    int input[]={7, 7, 7, 7};
    int i, j;
    int num=4;
    int val=7;
    for(i=0;i<num;i++){
        p=(struct ListNode *)malloc(sizeof(struct ListNode));
        p->val=input[i];
        p->next=NULL;
        if(i==0){
            head=p;
            last=head;
        }
        else{
            last->next=p;
            last=p;
        }
    }
    head=removeElements(head, val);
    //just for test
    for(p=head;p!=NULL;p=p->next){
        printf("%d ", p->val);
    }

    return 0;
}
