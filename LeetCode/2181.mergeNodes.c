#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

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


struct ListNode* mergeNodes(struct ListNode* head){
    int i, j;
    int sum=0;
    struct ListNode *nowNode=head;
    struct ListNode *tmp, *ret=NULL, *retp=NULL;
    while(nowNode!=NULL){
        if(nowNode->val==0){
            if(sum!=0){
                tmp=(struct ListNode *)malloc(sizeof(struct ListNode));
                tmp->val=sum;
                tmp->next=NULL;
                if(ret==NULL){
                    ret=tmp;
                    retp=tmp;
                }
                else{
                    retp->next=tmp;
                    retp=tmp;
                }
            }
            sum=0;
        }
        else{
            sum+=nowNode->val;
        }
        nowNode=nowNode->next;
    }
    return ret;
}

int main(){
    int i, j;
    struct ListNode *head, *out;
    int headS[8]={0, 3, 1, 0, 4, 5, 2, 0};
    struct ListNode nodelist[8];
    for(i=0;i<8;i++){
        nodelist[i].val=headS[i];
        if(i==7){
            nodelist[i].next=NULL;
        }
        else{
            nodelist[i].next=&nodelist[i+1];
        }
    }
    head=&nodelist[0];
    // while(head!=NULL){
    //     printf("%d ", head->val);
    //     head=head->next;
    // }
    out=mergeNodes(head);
    while(out!=NULL){
        printf("%d ", out->val);
        out=out->next;
    }
    return 0;
}