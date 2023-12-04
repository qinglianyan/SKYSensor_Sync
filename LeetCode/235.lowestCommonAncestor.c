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
#define NODE_MAX 1000
bool queEmpty(struct TreeNode **queue, int *queTop, int *queEnd){
    if((*queTop)>=(*queEnd)){
        return true;
    }
    return false;
}
void quePush(struct TreeNode **queue, int *queTop, int *queEnd, struct TreeNode *in){
    if((*queEnd)>=NODE_MAX){
        printf("push Error!\n");
        return ;
    }
    queue[(*queEnd)++]=in;
    return ;
}
struct TreeNode *quePop(struct TreeNode **queue, int *queTop, int *queEnd){
    struct TreeNode *ret;
    if(queEmpty(queue, queTop, queEnd)){
        printf("pop Error!\n");
        return ret;
    }
    return queue[(*queTop)++];
}
struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    struct TreeNode *out=NULL;
    struct TreeNode *tmp;
    struct TreeNode **queue=(struct TreeNode **)malloc(sizeof(struct TreeNode *)*NODE_MAX);
    int queTop=0, queEnd=0, nowSize=0;
    int i, j;
    int big, small;

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
            // printf("%d ", tmp->val);
            big=q->val>p->val?q->val:p->val;
            small=q->val<p->val?q->val:p->val;
            if(tmp->val<=big&&tmp->val>=small){
                out=tmp;
                return out;
            }

            if(tmp->left) quePush(queue, &queTop, &queEnd, tmp->left);
            if(tmp->right) quePush(queue, &queTop, &queEnd, tmp->right);
        }
    }

    return out;
}
void DFS(struct TreeNode *node){
    if(node==NULL){
        return ;
    }
    
    if(node->left) DFS(node->left);
    printf("%d ", node->val);
    if(node->right) DFS(node->right);

    // if(node->right) DFS(node->right);
    // printf("%d ", node->val);
    // if(node->left) DFS(node->left);
    return;
}
int main(){
    int i, j;
    struct TreeNode *out, *root;
    struct TreeNode node[12];
    int input[11]={6, 2, 8, 0, 4, 7, 9, -1, -1, 3, 5};
    int lenInput=11;
    printf("input = ");
    for(i=0;i<lenInput;i++){
        printf("%d ", input[i]);
    }
    printf("\n");
    for(i=0;i<lenInput;i++){
        node[i].val=input[i];
        node[i].left=NULL;
        node[i].right=NULL;
    }
    node[0].left=&node[1];node[0].right=&node[2];
    node[1].left=&node[3];node[1].right=&node[4];
    node[2].left=&node[5];node[2].right=&node[6];
    node[4].left=&node[9];node[4].right=&node[10];
    root=&node[0];
    DFS(root);
    printf("\n");
    out=lowestCommonAncestor(root, &node[1], &node[2]);
    printf("out = %d\n", out->val);
    return 0;
}