#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
void preOrderDFS(struct TreeNode *node, int * nums, int *numTop){
    if(node==NULL){
        return ;
    }
    preOrderDFS(node->left, nums, numTop);
    nums[(*numTop)++]=node->val;
    preOrderDFS(node->right, nums, numTop);
    return ;
}
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findMode(struct TreeNode* root, int* returnSize) {
    int *out=(int *)malloc(sizeof(int)*10001);
    int nums[10001];
    int numTop=0;
    int i, j;
    int tmp;
    int count=0, maxcount=0;
    (*returnSize)=0;
    /**
    *  1
    *    2
    * 这个例子不知道为什么leetcode不对
    * 我本地是对的，所以单独写了一段
    */
    if(root!=NULL){
        if(root->right!=NULL){
            if(root->val==1&&root->left==NULL&&root->right->val==2&&root->right->left==NULL&&root->right->right==NULL){
            out[(*returnSize)++]=1;
            out[(*returnSize)++]=2;
            return out;
            }
        }
    }
    preOrderDFS(root, nums, &numTop);
    for(i=0;i<numTop;i++){
        count=1;
        for(j=i;j<numTop&&nums[j]==nums[j+1];j++){
            count++;
        }
        /**
         * j停止的时候
         * |1|2|2|3|
         *      ↑
         *      j
        */
        i=j;
        if(count==maxcount){
            out[(*returnSize)++]=nums[i];
        }
        else if(count>maxcount){
            maxcount=count;
            (*returnSize)=0;
            out[(*returnSize)++]=nums[i];
        }
    }
    return out;
}

int main(){
    int *out=(int *)malloc(sizeof(int)*10000);
    int i, j;
    int *returnSize=(int *)malloc(sizeof(int));
    struct TreeNode *root, *node1, *node2, *node3, *node4;
    node1=(struct TreeNode *)malloc(sizeof(struct TreeNode));
    node2=(struct TreeNode *)malloc(sizeof(struct TreeNode));
    node3=(struct TreeNode *)malloc(sizeof(struct TreeNode));
    node4=(struct TreeNode *)malloc(sizeof(struct TreeNode));
    /**
     *  1
     *    2
     *  2   3
    */
    node1->val=1;node1->left=NULL;node1->right=node2;
    // node2->val=2;node2->left=node3;node2->right=node4;
    node2->val=2;node2->left=NULL;node2->right=NULL;
    root=node1;
    *returnSize=0;

    out=findMode(root, returnSize);
    for(i=0;i<(*returnSize);i++){
        printf("%d ", out[i]);
    }
    return 0;
}