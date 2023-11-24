#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
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
bool queEmpty(struct TreeNode ** queue, int * queTop, int * queEnd){
    if((*queTop)<(*queEnd)){
        return false;
    }
    return true;
}
void pushQue(struct TreeNode ** queue, int * queTop, int * queEnd, struct TreeNode * in){
    if((*queEnd)>=10000){
        printf("push Error!\n");
        return ;
    }
    queue[(*queEnd)++]=in;
    return ;
}
struct TreeNode * popQue(struct TreeNode **queue, int *queTop, int * queEnd){
    struct TreeNode * ret;
    if(queEmpty(queue, queTop, queEnd)){
        printf("pop Error!\n");
        return ret;
    }
    return queue[(*queTop)++];
}
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
double* averageOfLevels(struct TreeNode* root, int* returnSize) {
    struct TreeNode * queue[10000];
    struct TreeNode * tmp;
    int i, j;
    long sum=0;
    double avg=0;
    int queTop=0, queEnd=0;
    int nowSize=0;
    double * out=(double *)malloc(sizeof(double)*10000);

    *returnSize=0;
    if(root==NULL){
        return out;
    }
    if(root!=NULL){
        pushQue(queue, &queTop, &queEnd, root);
    }
    while(!queEmpty(queue, &queTop, &queEnd)){
        nowSize=queEnd-queTop;
        // printf("nowSize = %d, queTop = %d, queEnd = %d\n", nowSize, queue[queTop]->val, queue[queEnd-1]->val);
        sum=0;avg=0;
        for(i=0;i<nowSize;i++){
            tmp=popQue(queue, &queTop, &queEnd);
            sum+=tmp->val;
            if(tmp->left) pushQue(queue, &queTop, &queEnd, tmp->left);
            if(tmp->right) pushQue(queue, &queTop, &queEnd, tmp->right);
        }
        avg=(double)((double)sum/(double)nowSize);
        out[(*returnSize)++]=avg;
    }
    return out;
}
int main(){
    int i, j;
    double * out;
    int * returnSize=(int *)malloc(sizeof(int));
    struct TreeNode *node1, *node2, *node3, *node4, *node5, *root;
    
    *returnSize=0;
    node1=(struct TreeNode *)malloc(sizeof(struct TreeNode*));
    node2=(struct TreeNode *)malloc(sizeof(struct TreeNode*));
    node3=(struct TreeNode *)malloc(sizeof(struct TreeNode*));
    node4=(struct TreeNode *)malloc(sizeof(struct TreeNode*));
    node5=(struct TreeNode *)malloc(sizeof(struct TreeNode*));
    node1->val=3;   node1->left=node2;  node1->right=node3;
    node2->val=9;   node2->left=NULL;   node2->right=NULL;
    node3->val=20;  node3->left=node4;  node3->right=node5;
    node4->val=15;  node4->left=NULL;   node4->right=NULL;
    node5->val=7;   node5->left=NULL;   node5->right=NULL;
    root = node1;
    out=averageOfLevels(root, returnSize);
    for(i=0;i<(*returnSize);i++){
        printf("%lf ", out[i]);
    }printf("\n");
    return 0;
}