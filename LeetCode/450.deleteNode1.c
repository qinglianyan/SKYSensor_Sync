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


struct TreeNode* deleteNode(struct TreeNode* root, int key){
    struct TreeNode *ret, *tmp, *cur;

    if(root==NULL){
        return root;
    }
    if(root->val==key){
        if(root->left==NULL&&root->right==NULL){
            free(root);
            return NULL;
        }
        else if(root->left==NULL){
            ret=root->right;
            free(root);
            return ret;
        }
        else if(root->right==NULL){
            ret=root->left;
            free(root);
            return ret;
        }
        else{
            cur=root->right;
            while(cur->left!=NULL){
                cur=cur->left;
            }
            cur->left=root->left;

            tmp=root;
            root=root->right;
            free(tmp);
            return root;
        }
    }
    if(root->val>key) root->left=deleteNode(root->left, key);
    if(root->val<key) root->right=deleteNode(root->right, key);

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
    struct TreeNode *out, *root, *node1, *node2,
                    *node3, *node4, *node5, *node6;
    node1=(struct TreeNode *)malloc(sizeof(struct TreeNode));
    node2=(struct TreeNode *)malloc(sizeof(struct TreeNode));
    node3=(struct TreeNode *)malloc(sizeof(struct TreeNode));
    node4=(struct TreeNode *)malloc(sizeof(struct TreeNode));
    node5=(struct TreeNode *)malloc(sizeof(struct TreeNode));
    node6=(struct TreeNode *)malloc(sizeof(struct TreeNode));
    
    node1->val=5;node1->left=node2;node1->right=node3;
    node2->val=3;node2->left=node4;node2->right=node5;
    node3->val=6;node3->left=NULL;node3->right=node6;
    node4->val=2;node4->left=NULL;node4->right=NULL;
    node5->val=4;node5->left=NULL;node5->right=NULL;
    node6->val=7;node6->left=NULL;node6->right=NULL;
    root=node1;
    DFS(root);
    out=deleteNode(root, 3);
    printf("\n");
    DFS(out);
    return 0;
}