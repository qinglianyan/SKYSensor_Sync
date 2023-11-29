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
void preOrderDFS(struct TreeNode *node, int * nums, int *numTop){
    if(node==NULL){
        return ;
    }
    preOrderDFS(node->left, nums, numTop);
    nums[(*numTop)++]=node->val;
    preOrderDFS(node->right, nums, numTop);
    return ;
}
int getMinimumDifference(struct TreeNode* root) {
    int nums[10000];
    int numTop=0;
    int i, j;
    int minCha, tmp;
    preOrderDFS(root, nums, &numTop);
    minCha=abs(nums[0]-nums[1]);
    for(i=0;i<numTop-1;i++){
        tmp=abs(nums[i]-nums[i+1]);
        if(tmp<minCha){
            minCha=tmp;
        }
    }
    return minCha;
}
int main(){
    int i, j;
    int out;
    struct TreeNode *root, *node1, *node2, *node3, *node4, *node5;
    node1=(struct TreeNode *)malloc(sizeof(struct TreeNode));
    node2=(struct TreeNode *)malloc(sizeof(struct TreeNode));
    node3=(struct TreeNode *)malloc(sizeof(struct TreeNode));
    node4=(struct TreeNode *)malloc(sizeof(struct TreeNode));
    node5=(struct TreeNode *)malloc(sizeof(struct TreeNode));
    
    node1->val=1;node1->left=node2;node1->right=node3;
    node2->val=0;node2->left=NULL;node2->right=NULL;
    node3->val=48;node3->left=node4;node3->right=node5;
    node4->val=12;node4->left=NULL;node4->right=NULL;
    node5->val=49;node5->left=NULL;node5->right=NULL;
    root=node1;
    out=getMinimumDifference(root);
    printf("out = %d\n", out);
    return 0;
}