#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
#define MAX(a, b) a>b?a:b
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int rob(struct TreeNode* root) {
    int i, j;


    return 0;
}

int main(){
    int i, j;
    int out;
    struct TreeNode *node1, *node2, *node3, *node4, *node5, *root;
    node1=(struct TreeNode *)malloc(sizeof(struct TreeNode));
    node2=(struct TreeNode *)malloc(sizeof(struct TreeNode));
    node3=(struct TreeNode *)malloc(sizeof(struct TreeNode));
    node4=(struct TreeNode *)malloc(sizeof(struct TreeNode));
    node5=(struct TreeNode *)malloc(sizeof(struct TreeNode));
    node1->val=3;node1->left=node2;node1->right=node3;
    node2->val=2;node2->left=NULL;node2->right=node4;
    node3->val=3;node3->left=NULL;node3->right=node5;
    node4->val=3;node4->left=NULL;node4->right=NULL;
    node5->val=1;node5->left=NULL;node5->right=NULL;
    root=node1;
    out=rob(root);
    printf("__out = %d__\n", out);
    return 0;
}