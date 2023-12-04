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
int count=0;
void lastOrder(struct TreeNode * node){
    if(node==NULL){
        return ;
    }
    if(node->right) lastOrder(node->right);
    count+=node->val;
    node->val=count;
    if(node->left) lastOrder(node->left);
    return ;
}
struct TreeNode* bstToGst(struct TreeNode* root) {
    count=0;
    lastOrder(root);
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
    struct TreeNode *out,   *root,  *node1, *node2,
                    *node3, *node4, *node5, *node6,
                    *node7, *node8, *node9;
    node1=(struct TreeNode *)malloc(sizeof(struct TreeNode));
    node2=(struct TreeNode *)malloc(sizeof(struct TreeNode));
    node3=(struct TreeNode *)malloc(sizeof(struct TreeNode));
    node4=(struct TreeNode *)malloc(sizeof(struct TreeNode));
    node5=(struct TreeNode *)malloc(sizeof(struct TreeNode));
    node6=(struct TreeNode *)malloc(sizeof(struct TreeNode));
    node7=(struct TreeNode *)malloc(sizeof(struct TreeNode));
    node8=(struct TreeNode *)malloc(sizeof(struct TreeNode));
    node9=(struct TreeNode *)malloc(sizeof(struct TreeNode));
    
    node1->val=4;node1->left=node2;node1->right=node3;
    node2->val=1;node2->left=node4;node2->right=node5;
    node3->val=6;node3->left=node6;node3->right=node7;
    node4->val=0;node4->left=NULL;node4->right=NULL;
    node5->val=2;node5->left=NULL;node5->right=node8;
    node6->val=5;node6->left=NULL;node6->right=NULL;
    node7->val=7;node7->left=NULL;node7->right=node9;
    node8->val=3;node8->left=NULL;node8->right=NULL;
    node9->val=8;node9->left=NULL;node9->right=NULL;
    root=node1;
    DFS(root);
    printf("\n");
    out=bstToGst(root);
    printf("out = \n");
    DFS(out);
    return 0;
}