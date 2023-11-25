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
 * Definition for a binary tree TreeNode.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
#define TreeNode_MAX 10000
bool queEmpty(struct TreeNode **queue, int *queTop, int *queEnd){
    if((*queTop)>=(*queEnd)){
        return true;
    }
    return false;
}
void quePush(struct TreeNode **queue, int *queTop, int *queEnd, struct TreeNode *in){
    if((*queEnd)>=TreeNode_MAX){
        printf("push Error!\n");
        return ;
    }
    queue[(*queEnd)++]=in;
    return;
}
struct TreeNode *quePop(struct TreeNode **queue, int *queTop, int * queEnd){
    struct TreeNode *ret;
    if(queEmpty(queue, queTop, queEnd)){
        printf("pop Error!\n");
        return ret;
    }
    return queue[(*queTop)++];
}
int maxDepth(struct TreeNode* root) {
    struct TreeNode **queue=(struct TreeNode **)malloc(sizeof(struct TreeNode *)*TreeNode_MAX);
    int queTop=0, queEnd=0;
    int i, j;
    int nowSize=0;
    struct TreeNode *tmp;
    int out=0;

    if(root!=NULL){
        quePush(queue, &queTop, &queEnd, root);
    }
    while(!queEmpty(queue, &queTop, &queEnd)){
        nowSize=queEnd-queTop;
        out++;
        for(i=0;i<nowSize;i++){
            tmp=quePop(queue, &queTop, &queEnd);
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
    struct TreeNode * root, *TreeNode1, *TreeNode2, *TreeNode3, *TreeNode4, *TreeNode5;
    int out=0;
    TreeNode1=(struct TreeNode *)malloc(sizeof(struct TreeNode));
    TreeNode2=(struct TreeNode *)malloc(sizeof(struct TreeNode));
    TreeNode3=(struct TreeNode *)malloc(sizeof(struct TreeNode));
    TreeNode4=(struct TreeNode *)malloc(sizeof(struct TreeNode));
    TreeNode5=(struct TreeNode *)malloc(sizeof(struct TreeNode));
    
    TreeNode1->val=3;   TreeNode1->left=TreeNode2;  TreeNode1->right=TreeNode3;
    TreeNode2->val=9;   TreeNode2->left=NULL;   TreeNode2->right=NULL;
    TreeNode3->val=20;  TreeNode3->left=TreeNode4;  TreeNode3->right=TreeNode5;
    TreeNode4->val=15;  TreeNode4->left=NULL;   TreeNode4->right=NULL;
    TreeNode5->val=7;   TreeNode5->left=NULL;   TreeNode5->right=NULL;
    root=TreeNode1;

    out=maxDepth(root);
    printf("out = %d\n", out);
    return 0;
}