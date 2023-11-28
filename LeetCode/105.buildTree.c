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
struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize) {
    if(preorderSize==0&&inorderSize==0){
        return NULL;
    }
    struct TreeNode *node=(struct TreeNode *)malloc(sizeof(struct TreeNode));
    int index=0;
    for(index=0;index<inorderSize;index++){
        if(inorder[index]==preorder[0]){
            break;
        }
    }

    node->val=preorder[0];
    node->left=buildTree(preorder+1, index, inorder, index);
    node->right=buildTree(preorder+index+1, preorderSize-1-index, inorder+1+index, inorderSize-1-index);
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
    int preorder[5]={3, 9, 20, 15, 7};
    int inorderSize=5, preorderSize=5;
    struct TreeNode *out;
    out=buildTree(preorder, preorderSize, inorder, inorderSize);
    DFS(out);
    return 0;
}