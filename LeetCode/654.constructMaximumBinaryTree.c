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
struct TreeNode* constructMaximumBinaryTree(int* nums, int numsSize) {
    
}

void DFS(struct TreeNode *root){
    if(root==NULL) return;
    printf("node = %d\n", root->val);
    if(root->left){
        DFS(root->left);
    }
    if(root->right){
        DFS(root->right);
    }
}
int main(){
    struct TreeNode *out;
    int i, j;
    int nums[6]={3, 2, 1, 6, 0, 5};
    int numsSize=6;
    out=constructMaximumBinaryTree(nums, numsSize);
    
    DFS(out);
    return 0;
}
