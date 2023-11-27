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
typedef struct TreeNode Node;

void DFS(Node *node, int targetSum, int *sum, bool *out){
    if(node==NULL){
        return ;
    }
    if((*out)==true){//如果已经找到了就不必再循环找了
        return ;
    }
    (*sum)+=node->val;
    if(node->left==NULL&&node->right==NULL){
        if((*sum)==targetSum){
            (*out)=true;
            return ;
        }
    }
    if(node->left){
        DFS(node->left, targetSum, sum, out);
    }
    if(node->right){
        DFS(node->right, targetSum, sum, out);
    }
    (*sum)-=node->val;
}

bool hasPathSum(struct TreeNode* root, int targetSum) {
    bool out=false;
    int sum=0;
    DFS(root, targetSum, &sum, &out);
    return out;
}

int main(){
    int i, j;
    bool out;
    int targetSum=0;
    Node * root, *node1, *node2, *node3, *node4, *node5,
                    *node6, *node7, *node8, *node9;
    node1=(Node *)malloc(sizeof(Node));
    node2=(Node *)malloc(sizeof(Node));
    node3=(Node *)malloc(sizeof(Node));
    node4=(Node *)malloc(sizeof(Node));
    node5=(Node *)malloc(sizeof(Node));
    node6=(Node *)malloc(sizeof(Node));
    node7=(Node *)malloc(sizeof(Node));
    node8=(Node *)malloc(sizeof(Node));
    node9=(Node *)malloc(sizeof(Node));
    
    node1->val=5;node1->left=node2;node1->right=node3;
    node2->val=4;node2->left=node4;node2->right=NULL;
    node3->val=8;node3->left=node5;node3->right=node6;
    node4->val=11;node4->left=node7;node4->right=node8;
    node5->val=13;node5->left=NULL;node5->right=NULL;
    node6->val=4;node6->left=NULL;node6->right=node9;
    node7->val=7;node7->left=NULL;node7->right=NULL;
    node8->val=2;node8->left=NULL;node8->right=NULL;
    node9->val=1;node9->left=NULL;node9->right=NULL;
    root=node1;
    targetSum=22;

    out=hasPathSum(root, targetSum);
    printf("out = %d\n", out);
    return 0;
}