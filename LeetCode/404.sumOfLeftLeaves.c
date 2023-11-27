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
void DFS(struct TreeNode *node, int *out){
    if(node==NULL){
        return;
    }
    if(node->left!=NULL){
        if(node->left->left==NULL&&node->left->right==NULL){
            (*out)+=node->left->val;
        }
    }
    DFS(node->left, out);
    DFS(node->right, out);
    return ;
}

int sumOfLeftLeaves(struct TreeNode* root){
    int out=0;

    DFS(root, &out);
    return out;
}
int main(){
    int i, j, out;
    struct TreeNode *root, *node1, *node2, *node3, *node4, *node5;
    node1=(struct TreeNode *)malloc(sizeof(struct TreeNode));
    node2=(struct TreeNode *)malloc(sizeof(struct TreeNode));
    node3=(struct TreeNode *)malloc(sizeof(struct TreeNode));
    node4=(struct TreeNode *)malloc(sizeof(struct TreeNode));
    node5=(struct TreeNode *)malloc(sizeof(struct TreeNode));

    node1->val=3;node1->left=node2;node1->right=node3;
    node2->val=9;node2->left=NULL;node2->right=NULL;
    node3->val=20;node3->left=node4;node3->right=node5;
    node4->val=15;node4->left=NULL;node4->right=NULL;
    node5->val=7;node5->left=NULL;node5->right=NULL;
    root=node1;

    out=sumOfLeftLeaves(root);
    printf("out = %d\n", out);
    return 0;
}