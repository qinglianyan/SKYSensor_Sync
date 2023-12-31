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
struct TreeNode* buildTree(int* inorder, int inorderSize, int* postorder, int postorderSize) {
    if(inorderSize==0&&postorderSize==0){
        return NULL;
    }
    struct TreeNode *node=(struct TreeNode *)malloc(sizeof(struct TreeNode));
    int index=0;
    for(index=0;index<inorderSize;index++){
        if(inorder[index]==postorder[postorderSize-1]){
            break;
        }
    }
    node->val=postorder[postorderSize-1];
    // printf("node.val = %d\n");
    node->left=buildTree(inorder, index, postorder, index);
    node->right=buildTree(inorder+index+1, inorderSize-1-index, postorder+index, postorderSize-1-index);

    return node;
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
    int i, j;
    int inorder[5]={9, 3, 15, 20, 7};
    int postorder[5]={9, 15, 7, 20, 3};
    int inorderSize=5, postorderSize=5;
    struct TreeNode *out;
    out=buildTree(inorder, inorderSize, postorder, postorderSize);
    DFS(out);
    return 0;
}