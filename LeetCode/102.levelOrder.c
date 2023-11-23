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
bool queueEmpty(struct TreeNode ** queue, int *top, int *end){
    return (*top)==(*end);
}
/**
 * |a|b|c| <- |d|
*/
void pushQueue(struct TreeNode ** queue, int *queTop, int *queEnd, struct TreeNode * in){
    if((*queEnd)>=2000){
        printf("push Error!\n");
    }
    queue[(*queEnd)++]=in;
    return;
}
/**
 * |a| <- |b|c|d|
*/
struct TreeNode * popQueue(struct TreeNode ** queue, int *queTop, int *queEnd){
    struct TreeNode * ret;
    if(queueEmpty(queue, queTop, queEnd)){
        printf("pop Error!\n");
        return ret;
    }
    return queue[(*queTop)++];

}
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
    int ** out=(int **)malloc(sizeof(int *)*2000);
    int i, j;
    struct TreeNode * tmp;
    struct TreeNode ** queue=(struct TreeNode **)malloc(sizeof(struct TreeNode *)*2000);
    *returnColumnSizes=(int *)malloc(sizeof(int )*2000);
    /**
     * |a|b|c|d|e|
     *  ↑         ↑
     * queTop   queEnd
    */
    int queTop=0, queEnd=0;
    int nowSize=0;

    *returnSize=0;
    // *returnColumnSizes;
    if(root==NULL) return out;
    if(root!=NULL){
        pushQueue(queue, &queTop, &queEnd, root);
    }
    while(!queueEmpty(queue, &queTop, &queEnd)){
        nowSize=queEnd-queTop;
        // printf("nowSize = %d, queTop = %d, queEnd = %d\n", nowSize, queue[queTop]->val, queue[queEnd-1]->val);
        (*returnColumnSizes)[*returnSize]=nowSize;
        out[(*returnSize)]=(int *)malloc(sizeof(int)*nowSize);
        for(i=0;i<nowSize;i++){
            tmp=popQueue(queue, &queTop, &queEnd);
            out[(*returnSize)][i]=tmp->val;
            if(tmp->left){
                pushQueue(queue, &queTop, &queEnd, tmp->left);
            }
            if(tmp->right){
                pushQueue(queue, &queTop, &queEnd, tmp->right);
            }
        }
        (*returnSize)++;
    }
    return out;
}

int main(){
    int i, j;
    int ** out;
    int *returnSize = (int *)malloc(sizeof(int));
    // int ** returnColumnSizes=(int **)malloc(sizeof(int *));
    int **returnColumnSizes=(int **)malloc(sizeof(int *));

    *returnSize = 0;
    struct TreeNode * root;
    struct TreeNode * node1=(struct TreeNode*)malloc(sizeof(struct TreeNode));
    struct TreeNode * node2=(struct TreeNode*)malloc(sizeof(struct TreeNode));
    struct TreeNode * node3=(struct TreeNode*)malloc(sizeof(struct TreeNode));
    struct TreeNode * node4=(struct TreeNode*)malloc(sizeof(struct TreeNode));
    struct TreeNode * node5=(struct TreeNode*)malloc(sizeof(struct TreeNode));
    node1->val=3;   node1->left=node2;  node1->right=node3;
    node2->val=9;   node2->left=NULL;   node2->right=NULL;
    node3->val=20;  node3->left=node4;  node3->right=node5;
    node4->val=15;  node4->left=NULL;   node4->right=NULL;
    node5->val=7;   node5->left=NULL;   node5->right=NULL;
    root=node1;
    // node1->val=1;   node1->left=NULL;   node1->right=NULL;
    // root=NULL;
    out=levelOrder(root, returnSize, returnColumnSizes);
    for(i=0;i<(*returnSize);i++){
        for(j=0;j<(*returnColumnSizes)[i];j++){
        // for(j=0;j<2;j++){
            printf("%d ", out[i][j]);
        }printf("\n");
    }
    return 0;
}