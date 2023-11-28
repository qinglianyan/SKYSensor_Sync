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
bool isValidBST(struct TreeNode* root) {
    
}

int main(){
    int i, j;
    bool out;
    struct TreeNode *root, *node1, *node2, *node3, *node4, *node5;
    node1=(struct TreeNode *)malloc(sizeof(struct TreeNode));
    node2=(struct TreeNode *)malloc(sizeof(struct TreeNode));
    node3=(struct TreeNode *)malloc(sizeof(struct TreeNode));
    node4=(struct TreeNode *)malloc(sizeof(struct TreeNode));
    node5=(struct TreeNode *)malloc(sizeof(struct TreeNode));
    
    node1->val=5;node1->left=node2;node1->right=node3;
    node2->val=1;node2->left=NULL;node2->right=NULL;
    node3->val=4;node3->left=node4;node3->right=node5;
    node4->val=3;node4->left=NULL;node4->right=NULL;
    node5->val=6;node5->left=NULL;node5->right=NULL;
    root=node1;

    out=isValidBST(root);
    printf("out = %d\n", out);
    return 0;
}