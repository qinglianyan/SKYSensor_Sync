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
struct record{
    int selected;
    int notSelected;
};
void backshow(struct TreeNode *root){
    if(root==NULL){
        return ;
    }
    // 想要后序遍历
    backshow(root->left);
    backshow(root->right);
    printf("%d ", root->val);
    return ;
}
struct record robTree(struct TreeNode *root){
    int i, j;
    int val1, val2;
    struct record ret, left, right;
    if(root==NULL){
        ret.selected=0, ret.notSelected=0;
        return ret;
    }
    left=robTree(root->left);
    right=robTree(root->right);
    // 偷当前root
    val1=root->val+left.notSelected+right.notSelected;
    // 不偷root
    val2=MAX(left.selected, left.notSelected)+MAX(right.selected, right.notSelected);
    ret.selected=val1;
    ret.notSelected=val2;
    return ret;

}
int rob(struct TreeNode* root) {
    int i, j;
    struct record ret;
    ret=robTree(root);
    return MAX(ret.selected, ret.notSelected);
}

int main(){
    int i, j;
    int out;
    struct TreeNode *node1, *node2, *node3, *node4, *node5, *node6, *root;
    // // 示例 1
    // node1=(struct TreeNode *)malloc(sizeof(struct TreeNode));
    // node2=(struct TreeNode *)malloc(sizeof(struct TreeNode));
    // node3=(struct TreeNode *)malloc(sizeof(struct TreeNode));
    // node4=(struct TreeNode *)malloc(sizeof(struct TreeNode));
    // node5=(struct TreeNode *)malloc(sizeof(struct TreeNode));
    // node1->val=3;node1->left=node2;node1->right=node3;
    // node2->val=2;node2->left=NULL;node2->right=node4;
    // node3->val=3;node3->left=NULL;node3->right=node5;
    // node4->val=3;node4->left=NULL;node4->right=NULL;
    // node5->val=1;node5->left=NULL;node5->right=NULL;
    // root=node1;
    // 示例 2
    node1=(struct TreeNode *)malloc(sizeof(struct TreeNode));
    node2=(struct TreeNode *)malloc(sizeof(struct TreeNode));
    node3=(struct TreeNode *)malloc(sizeof(struct TreeNode));
    node4=(struct TreeNode *)malloc(sizeof(struct TreeNode));
    node5=(struct TreeNode *)malloc(sizeof(struct TreeNode));
    node6=(struct TreeNode *)malloc(sizeof(struct TreeNode));
    node1->val=3;node1->left=node2;node1->right=node3;
    node2->val=4;node2->left=node4;node2->right=node5;
    node3->val=5;node3->left=NULL;node3->right=node6;
    node4->val=1;node4->left=NULL;node4->right=NULL;
    node5->val=3;node5->left=NULL;node5->right=NULL;
    node6->val=1;node5->left=NULL;node5->right=NULL;
    root=node1;
    backshow(root);
    printf("\n");
    out=rob(root);
    printf("__out = %d__\n", out);
    return 0;
}