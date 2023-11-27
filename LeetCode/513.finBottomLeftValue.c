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
void DFS(struct TreeNode *node, int *out, int level, int *maxLevel){
    if(node==NULL){
        return ;
    }
    // printf("val = %d, level = %d\n", node->val, level);
    if(level>(*maxLevel)){
        *maxLevel=level;
        if(node->left==NULL&&node->right==NULL){
            (*out)=node->val;
        }
    }
    if(node->left){
        DFS(node->left, out, level+1, maxLevel);
    }
    if(node->right){
        DFS(node->right, out, level+1, maxLevel);
    }

}
int findBottomLeftValue(struct TreeNode* root) {
    int out=0;
    int level=1;
    int maxLevel=0;
    DFS(root, &out, level, &maxLevel);
    return out;
}

int main(){
    int i, j, out;
    struct TreeNode *root, *node1, *node2, *node3, 
                    *node4, *node5, *node6, *node7;
    node1=(struct TreeNode *)malloc(sizeof(struct TreeNode));
    node2=(struct TreeNode *)malloc(sizeof(struct TreeNode));
    node3=(struct TreeNode *)malloc(sizeof(struct TreeNode));
    node4=(struct TreeNode *)malloc(sizeof(struct TreeNode));
    node5=(struct TreeNode *)malloc(sizeof(struct TreeNode));
    node6=(struct TreeNode *)malloc(sizeof(struct TreeNode));
    node7=(struct TreeNode *)malloc(sizeof(struct TreeNode));

    node1->val=1;node1->left=node2;node1->right=node3;
    node2->val=2;node2->left=node4;node2->right=NULL;
    node3->val=3;node3->left=node5;node3->right=node6;
    node4->val=4;node4->left=NULL;node4->right=NULL;
    node5->val=5;node5->left=node7;node5->right=NULL;
    node6->val=6;node6->left=NULL;node6->right=NULL;
    node7->val=7;node7->left=NULL;node7->right=NULL;
    root=node1;

    out=findBottomLeftValue(root);
    printf("out = %d\n", out);
    return 0;
}