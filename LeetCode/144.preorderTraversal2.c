#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
void sPush(struct TreeNode ** stack, int * top, struct TreeNode * in){
    if((*top)>=2000){
        printf("push error!\n");
        return ;
    }
    stack[(*top)++]=in;
    return;
}
struct TreeNode * sPop(struct TreeNode ** stack, int * top){
    if((*top)<=0){
        printf("pop error!\n");
        // return ;
    }
    return stack[--(*top)];
}
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* preorderTraversal(struct TreeNode* root, int* returnSize) {
    int * out=(int *)malloc(sizeof(int)*2000);
    int i, j;
    struct TreeNode * stack[2000];
    int stackTop=0;
    struct TreeNode * tmp;
    *returnSize=0;

    if(root==NULL){
        return out;
    }
    sPush(stack, &stackTop, root);
    while(stackTop>0){
        tmp=stack[stackTop-1];
        sPop(stack, &stackTop);
        out[(*returnSize)++]=tmp->val;
        if(tmp->right){
            sPush(stack, &stackTop, tmp->right);
        }
        if(tmp->left){
            sPush(stack, &stackTop, tmp->left);
        }
    }
    
    return out;
}
int main(){
    int i,j;
    int * out;
    int * returnSize=(int *)malloc(sizeof(int));
    struct TreeNode * root;
    struct TreeNode * node1=(struct TreeNode *)malloc(sizeof(struct TreeNode));
    struct TreeNode * node2=(struct TreeNode *)malloc(sizeof(struct TreeNode));
    struct TreeNode * node3=(struct TreeNode *)malloc(sizeof(struct TreeNode));
    node1->val=1, node1->left=NULL, node1->right=node2;
    node2->val=2, node2->left=node3, node2->right=NULL;
    node3->val=3, node3->left=NULL, node3->right=NULL;
    root=node1;
    out=preorderTraversal(root, returnSize);
    for(i=0;i<(*returnSize);i++){
        printf("%d ", out[i]);
    }
    return 0;
}