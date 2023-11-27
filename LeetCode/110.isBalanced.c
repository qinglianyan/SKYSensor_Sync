#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
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
int getHeight(struct TreeNode * node){
    if(node==NULL){
        return 0;
    }
    int leftHeight=getHeight(node->left);
    if(leftHeight==-1) return -1;
    int rightHeight=getHeight(node->right);
    if(rightHeight==-1) return -1;

    // printf("now = %d, leftHeight = %d, rightHeight = %d\n", node->val, leftHeight, rightHeight);

    if(abs(leftHeight-rightHeight)>1){
        return -1;
    }
    else{
        if(leftHeight>rightHeight){
            return leftHeight+1;
        }
        else{
            return rightHeight+1;
        }
    }

    // return abs(leftHeight - rightHeight) > 1 ? -1 : 1 + max(leftHeight, rightHeight);
    // return abs(leftHeight - rightHeight) > 1 ? -1 : (leftHeight>rightHeight?(leftHeight+1):(rightHeight+1));
}
bool isBalanced(struct TreeNode* root) {
    return getHeight(root)==-1?false:true;
}
int main(){
    int i, j;
    bool out;
    struct TreeNode *root, *node1, *node2, *node22, 
                    *node3, *node33, *node4, *node44;
    node1=(struct TreeNode *)malloc(sizeof(struct TreeNode ));
    node2=(struct TreeNode *)malloc(sizeof(struct TreeNode ));
    node22=(struct TreeNode *)malloc(sizeof(struct TreeNode ));
    node3=(struct TreeNode *)malloc(sizeof(struct TreeNode ));
    node33=(struct TreeNode *)malloc(sizeof(struct TreeNode ));
    node4=(struct TreeNode *)malloc(sizeof(struct TreeNode ));
    node44=(struct TreeNode *)malloc(sizeof(struct TreeNode ));
    

    node1->val=1;node1->left=node2;node1->right=node22;
    node2->val=2;node2->left=node3;node2->right=node33;
    node22->val=2;node22->left=NULL;node22->right=NULL;
    node3->val=3;node3->left=node4;node3->right=node44;
    node33->val=3;node33->left=NULL;node33->right=NULL;
    node4->val=4;node4->left=NULL;node4->right=NULL;
    node44->val=4;node44->left=NULL;node44->right=NULL;
    root=node1;
    out=isBalanced(root);
    printf("out = %d\n", out);
    return 0;
}