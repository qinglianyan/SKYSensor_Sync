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
//广度优先遍历
#define QUE_MAX 10000
bool queEmpty(struct TreeNode **queue, int *queTop, int *queEnd){
    if((*queTop)>=(*queEnd)){
        return true;
    }
    return false;
}
void quePush(struct TreeNode **queue, int *queTop, int *queEnd, struct TreeNode *in){
    if((*queEnd)>=QUE_MAX){
        printf("push Error!\n");
        return ;
    }
    queue[(*queEnd)++]=in;
    return;
}
struct TreeNode *quePop(struct TreeNode **queue, int *queTop, int *queEnd){
    struct TreeNode * ret;
    if(queEmpty(queue, queTop, queEnd)){
        printf("pop Error!\n");
        return ret;
    }
    return queue[(*queTop)++];
}
int findBottomLeftValue(struct TreeNode* root) {
    int out=0;
    struct TreeNode **queue=(struct TreeNode **)malloc(sizeof(struct TreeNode)*QUE_MAX);
    struct TreeNode *tmp;
    int queTop=0, queEnd=0;
    int i, j;
    int nowSize;

    if(root==NULL){
        return out;
    }
    else{
        quePush(queue, &queTop, &queEnd, root);
    }
    while(!queEmpty(queue, &queTop, &queEnd)){
        nowSize=queEnd-queTop;
        for(i=0;i<nowSize;i++){
            tmp=quePop(queue, &queTop, &queEnd);
            if(i==0){
                out=tmp->val;
            }
            if(tmp->left){
                quePush(queue, &queTop, &queEnd, tmp->left);
            }
            if(tmp->right){
                quePush(queue, &queTop, &queEnd, tmp->right);
            }
        }
    }
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