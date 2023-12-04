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
struct TreeNode* insertIntoBST(struct TreeNode* root, int val) {
    struct TreeNode *out, *tmp, *bback;
    struct TreeNode *in=(struct TreeNode *)malloc(sizeof(struct TreeNode));

    in->val=val;in->left=NULL;in->right=NULL;
    if(root==NULL){
        root=in;
        out=root;
        return out;
    }
    
    tmp=root;bback=root;
    while(1){
        if(tmp==NULL){
            break;
        }
        else if(val<tmp->val){
            bback=tmp;
            tmp=tmp->left;
        }
        else if(tmp->val<val){
            bback=tmp;
            tmp=tmp->right;
        }
    }
    if(val<bback->val){
        bback->left=in;
    }
    else if(bback->val<val){
        bback->right=in;
    }
    out=root;
    return out;
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
                    *node3, *node4, *node5;
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
    DFS(root);
    out=insertIntoBST(root, 5);
    printf("\n");
    DFS(out);
    return 0;
}