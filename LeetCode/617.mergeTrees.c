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
/**
 * 同步遍历
 * 将root2树合并到root1里面
*/
void DFS_SYNC(struct TreeNode **node1, struct TreeNode **node2){
    if(*node1==NULL&&*node2==NULL){
        return ;
    }
    if(*node1==NULL&&*node2!=NULL){
        *node1=*node2;
        //一开始没加return，怪不得错了
        return;
    }
    if(*node1!=NULL&&*node2==NULL){
        return ;
    }
    if(*node1!=NULL&&*node2!=NULL){
        (*node1)->val+=(*node2)->val;
    }


    DFS_SYNC(&((*node1)->left), &(*node2)->left);
    DFS_SYNC(&((*node1)->right), &(*node2)->right);
}

struct TreeNode* mergeTrees(struct TreeNode* root1, struct TreeNode* root2) {
    DFS_SYNC(&root1, &root2);
    return root1;
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
    struct TreeNode *out, *root1, *root2, *node11, *node12, *node13, *node14,
                    *node21, *node22, *node23, *node24, *node25;
    node11=(struct TreeNode *)malloc(sizeof(struct TreeNode));
    node12=(struct TreeNode *)malloc(sizeof(struct TreeNode));
    node13=(struct TreeNode *)malloc(sizeof(struct TreeNode));
    node14=(struct TreeNode *)malloc(sizeof(struct TreeNode));
    
    node21=(struct TreeNode *)malloc(sizeof(struct TreeNode));
    node22=(struct TreeNode *)malloc(sizeof(struct TreeNode));
    node23=(struct TreeNode *)malloc(sizeof(struct TreeNode));
    node24=(struct TreeNode *)malloc(sizeof(struct TreeNode));
    node25=(struct TreeNode *)malloc(sizeof(struct TreeNode));
    
    node11->val=1;node11->left=node12;node11->right=node13;
    node12->val=3;node12->left=node14;node12->right=NULL;
    node13->val=2;node13->left=NULL;node13->right=NULL;
    node14->val=5;node14->left=NULL;node14->right=NULL;

    node21->val=2;node21->left=node22;node21->right=node23;
    node22->val=1;node22->left=NULL;node22->right=node24;
    node23->val=3;node23->left=NULL;node23->right=node25;
    node24->val=4;node24->left=NULL;node24->right=NULL;
    node25->val=7;node25->left=NULL;node25->right=NULL;

    root1=node11;
    root2=node21;
    root1=NULL;
    // printf("root1--------------\n");
    // DFS(root1);
    out=mergeTrees(root1, root2);
    DFS(out);
    return 0;
}