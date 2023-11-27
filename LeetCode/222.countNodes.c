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
void inorder(struct TreeNode *root, int *count){
    if(root==NULL){
        return ;
    }
    inorder(root->left, count);
    (*count)++;
    inorder(root->right, count);
}
int countNodes(struct TreeNode* root) {
    int i, j;
    int count=0;
    inorder(root, &count);
    return count;
}

int main(){
    int i, j;
    int out;
    struct TreeNode *root, *node1, *node2, *node3,
                    *node4, *node5, *node6;
    node1=(struct TreeNode *)malloc(sizeof(struct TreeNode));
    node2=(struct TreeNode *)malloc(sizeof(struct TreeNode));
    node3=(struct TreeNode *)malloc(sizeof(struct TreeNode));
    node4=(struct TreeNode *)malloc(sizeof(struct TreeNode));
    node5=(struct TreeNode *)malloc(sizeof(struct TreeNode));
    node6=(struct TreeNode *)malloc(sizeof(struct TreeNode));
    
    node1->val=1;   node1->left=node2;  node1->right=node3;
    node2->val=2;   node2->left=node4;  node2->right=node5;
    node3->val=3;   node3->left=node6;  node3->right=NULL;
    node4->val=4;   node4->left=NULL;   node4->right=NULL;
    node5->val=5;   node5->left=NULL;   node5->right=NULL;
    node6->val=6;   node6->left=NULL;   node6->right=NULL;
    root=node1;
    out=countNodes(root);
    printf("out = %d\n", out);

    return 0;
}