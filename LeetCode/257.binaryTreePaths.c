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
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define NODE_MAX 100

char** binaryTreePaths(struct TreeNode* root, int* returnSize) {
    char ** output=(char **)malloc(sizeof(char *)*NODE_MAX);
    *returnSize=0;

    
}
int main(){
    int i, j;
    char **output;
    int *returnSize=(int *)malloc(sizeof(int));
    struct TreeNode *root, *node1, *node2, *node3, *node4;
    node1=(struct TreeNode *)malloc(sizeof(struct TreeNode));
    node2=(struct TreeNode *)malloc(sizeof(struct TreeNode));
    node3=(struct TreeNode *)malloc(sizeof(struct TreeNode));
    node4=(struct TreeNode *)malloc(sizeof(struct TreeNode));
    
    node1->val=1;node1->left=node2;node1->right=node3;
    node2->val=2;node2->left=NULL;node2->right=node4;
    node3->val=3;node3->left=NULL;node3->right=NULL;
    node4->val=5;node4->left=NULL;node4->right=NULL;
    root=node1;
    *returnSize=0;

    for(i=0;i<(*returnSize);i++){
        printf("%s\n", output[i]);
    }
    
    return 0;
}