#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
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
struct TreeNode* sortedArrayToBST(int* nums, int numsSize) {
    // struct TreeNode *ret;
    int i, j, index;
    if(numsSize==0) return NULL;

    struct TreeNode *node=(struct TreeNode *)malloc(sizeof(struct TreeNode));
    index=numsSize/2;
    node->val=nums[index];
    node->left=sortedArrayToBST(nums, index);
    node->right=sortedArrayToBST(nums+index+1, numsSize-index-1);
    return node;
}


void DFS(struct TreeNode *node){
    if(node==NULL){
        return ;
    }
    // if(node->right) DFS(node->right);
    if(node->left!=NULL) DFS(node->left);
    printf("%d ", node->val);
    // if(node->left) DFS(node->left);
    if(node->right!=NULL) DFS(node->right);
    return;
}
int main(){
    struct TreeNode *out;
    int nums[5]={-10, -3, 0, 5, 9};
    // int *nums=(int *)malloc(sizeof(int)*5);
    int numSize=5;
    out=sortedArrayToBST(nums, numSize);
    DFS(out);
    return 0;
}