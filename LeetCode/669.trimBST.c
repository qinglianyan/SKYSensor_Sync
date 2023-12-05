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
struct TreeNode* trimBST(struct TreeNode* root, int low, int high) {
    struct TreeNode *ret;
    if(root==NULL) return root;
    if(root->val<low) return trimBST(root->right, low, high);
    if(root->val>high) return trimBST(root->left, low, high);
    root->left=trimBST(root->left, low, high);
    root->right=trimBST(root->right, low, high);
    return root;
}
void DFS(struct TreeNode *node){
    if(node==NULL){
        return ;
    }
    // if(node->right) DFS(node->right);
    if(node->left) DFS(node->left);
    printf("%d ", node->val);
    // if(node->left) DFS(node->left);
    if(node->right) DFS(node->right);
    return;
}
int main(){
    int i, j;
    int low=1, high=3;
    struct TreeNode *out, *root, *node1, *node2,
                    *node3, *node4, *node5;
    node1=(struct TreeNode *)malloc(sizeof(struct TreeNode));
    node2=(struct TreeNode *)malloc(sizeof(struct TreeNode));
    node3=(struct TreeNode *)malloc(sizeof(struct TreeNode));
    node4=(struct TreeNode *)malloc(sizeof(struct TreeNode));
    node5=(struct TreeNode *)malloc(sizeof(struct TreeNode));

    node1->val=3;node1->left=node2;node1->right=node3;
    node2->val=0;node2->left=NULL;node2->right=node4;
    node3->val=4;node3->left=NULL;node3->right=NULL;
    node4->val=2;node4->left=node5;node4->right=NULL;
    node5->val=1;node5->left=NULL;node5->right=NULL;
    root=node1;
DFS(root);
    out=trimBST(root, low, high);
printf("\n");
DFS(out);
    return 0;
}