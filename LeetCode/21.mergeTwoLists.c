#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct ListNode {
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
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    int i, j;
    struct ListNode *pnow1, *pnow2, ret, *retnow;
    if(list1==NULL) return list2;
    if(list2==NULL) return list1;
    ret.next=NULL;
    pnow1=list1, pnow2=list2;
    while(pnow1!=NULL && pnow2!=NULL){
        if(pnow1->val<pnow2->val){
            if(ret.next==NULL){
                ret.next=pnow1;
                retnow=pnow1;
            }
            else{
                retnow->next=pnow1;
                retnow=pnow1;
            }
            pnow1=pnow1->next;
        }
        else{
            if(ret.next==NULL){
                ret.next=pnow2;
                retnow=pnow2;
            }
            else{
                retnow->next=pnow2;
                retnow=pnow2;
            }
            pnow2=pnow2->next;
        }
    }
    if(pnow1!=NULL){
        retnow->next=pnow1;
    }
    if(pnow2!=NULL){
        retnow->next=pnow2;
    }
    return ret.next;
}

int main(){
    int i, j;
    struct ListNode *list1, *list2, *out;
    int arr1[3]={1, 2, 4};
    int arr2[3]={1, 3, 4};
    struct ListNode l1[3], l2[3];
    for(i=0;i<3;i++){
        l1[i].val=arr1[i];
        l1[i].next=NULL;
        if(i>0){
            l1[i-1].next=&l1[i];
        }
    }
    for(i=0;i<3;i++){
        l2[i].val=arr2[i];
        l2[i].next=NULL;
        if(i>0){
            l2[i-1].next=&l2[i];
        }
    }
    list1=&l1[0];
    list2=&l2[0];
    out=mergeTwoLists(list1, list2);
    while(out!=NULL){
        printf("%d ", out->val);
        out=out->next;
    }
    return 0;
}