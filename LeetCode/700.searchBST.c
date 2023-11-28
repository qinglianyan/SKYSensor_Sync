#include <stdio.h>
#include <stdlib.h>
struct TreeNode{
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
struct TreeNode* searchBST(struct TreeNode* root, int val) {
    struct TreeNode *result;
    if(root==NULL||root->val==val){
        return root;
    }
    if(root->val>val){
        result=searchBST(root->left, val);
    }
    if(root->val<val){
        result=searchBST(root->right, val);
    }
    return result;
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
    int val=2;
    struct TreeNode *out;
    struct TreeNode *root, *node1, *node2, *node3, *node4, *node5;
    node1=(struct TreeNode *)malloc(sizeof(struct TreeNode));
    node2=(struct TreeNode *)malloc(sizeof(struct TreeNode));
    node3=(struct TreeNode *)malloc(sizeof(struct TreeNode));
    node4=(struct TreeNode *)malloc(sizeof(struct TreeNode));
    node5=(struct TreeNode *)malloc(sizeof(struct TreeNode));
    
    node1->val=4;node1->left=node2;node1->right=node3;
    node2->val=2;node2->left=node4;node2->right=node5;
    node3->val=7;node3->left=NULL;node3->right=NULL;
    node4->val=1;node4->left=NULL;node4->right=NULL;
    node5->val=3;node5->left=NULL;node5->right=NULL;
    root=node1;

    out=searchBST(root, val);
    DFS(out);
    return 0;
}