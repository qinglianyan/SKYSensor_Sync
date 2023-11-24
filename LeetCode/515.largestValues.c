#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
bool queEmpty(struct TreeNode **queue, int *queTop, int *queEnd){
    if((*queTop)>=(*queEnd)){
        return true;
    }
    return false;
}
void quePush(struct TreeNode **queue, int *queTop, int *queEnd, struct TreeNode *in){
    if((*queEnd)>=10000){
        printf("push Error!\n");
        return;
    }
    queue[(*queEnd)++]=in;
    return;
}
struct TreeNode *quePop(struct TreeNode **queue, int *queTop, int *queEnd){
    struct TreeNode *ret;
    if(queEmpty(queue, queTop, queEnd)){
        return ret;
    }
    return queue[(*queTop)++];
}
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* largestValues(struct TreeNode* root, int* returnSize) {
    int *out=(int *)malloc(sizeof(int)*10000);
    struct TreeNode ** queue=(struct TreeNode **)malloc(sizeof(struct TreeNode *)*10000);
    struct TreeNode *tmp;
    int nowSize=0;
    int i, j;
    int maxOfLine=-1;//只是用来标记一下，-1不够小
    int queTop=0, queEnd=0;

    *returnSize=0;
    if(root==NULL){
        return out;
    }
    if(root!=NULL){
        quePush(queue, &queTop, &queEnd, root);
    }
    while(!queEmpty(queue, &queTop, &queEnd)){
        nowSize=queEnd-queTop;
        maxOfLine=queue[queTop]->val;
        for(i=0;i<nowSize;i++){
            tmp=quePop(queue, &queTop, &queEnd);
            if((tmp->val)>maxOfLine){
                maxOfLine=tmp->val;
            }

            if(tmp->left) quePush(queue, &queTop, &queEnd, tmp->left);
            if(tmp->right)  quePush(queue, &queTop, &queEnd, tmp->right);
        }
        out[(*returnSize)++]=maxOfLine;
    }
    return out;
}

int main(){
    int i, j;
    int *out;
    int *returnSize=(int *)malloc(sizeof(int));
    struct TreeNode *root, *node1, *node2, *node3, *node4, *node5, *node6;
    node1=(struct TreeNode *)malloc(sizeof(struct TreeNode));
    node2=(struct TreeNode *)malloc(sizeof(struct TreeNode));
    node3=(struct TreeNode *)malloc(sizeof(struct TreeNode));
    node4=(struct TreeNode *)malloc(sizeof(struct TreeNode));
    node5=(struct TreeNode *)malloc(sizeof(struct TreeNode));
    node6=(struct TreeNode *)malloc(sizeof(struct TreeNode));

    node1->val=1;   node1->left=node2;  node1->right=node3;
    node2->val=3;   node2->left=node4;  node2->right=node5;
    node3->val=2;   node3->left=NULL;   node3->right=node6;
    node4->val=5;   node4->left=NULL;   node4->right=NULL;
    node5->val=3;   node5->left=NULL;   node5->right=NULL;
    node6->val=9;   node6->left=NULL;   node6->right=NULL;

    *returnSize=0;
    root=node1;

    out=largestValues(root, returnSize);
    for(i=0;i<(*returnSize);i++){
        printf("%d ", out[i]);
    }printf("\n");
    
    return 0;
}