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
/**
 * 遍历找到从root到目标节点的路径
 * 然后比较两个路径
 * 时间：32ms       14.58%
 * 内存：21.14MB    5.17%
*/
#define NODE_MAX 200000
bool pathEmpty(struct TreeNode **path, int *pathTop){
    if((*pathTop)<=0){
        return true;
    }
    return false;
}
void pathPush(struct TreeNode **path, int *pathTop, struct TreeNode *in){
    if((*pathTop)>=NODE_MAX){
        printf("push Error!\n");
        return ;
    }
    path[(*pathTop)++]=in;
    return ;
}
struct TreeNode *pathPop(struct TreeNode **path, int *pathTop){
    struct TreeNode *ret;
    if(pathEmpty(path, pathTop)){
        printf("pop Error!\n");
        return ret;
    }
    return path[--(*pathTop)];
}
void getNodePath(   struct TreeNode **path, int *pathTop, 
                    struct TreeNode *node,  struct TreeNode *target,
                    bool *finish){
    if(node==NULL){
        return ;
    }
    if(node==target){
        pathPush(path, pathTop, node);
        (*finish)=true;
        return ;
    }
    if(!(*finish)){
        pathPush(path, pathTop, node);
        getNodePath(path, pathTop, node->left, target, finish);
        getNodePath(path, pathTop, node->right, target, finish);
        if(!(*finish)){
            pathPop(path, pathTop);
        }
    }
    
}
struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    struct TreeNode *out;
    struct TreeNode **path=(struct TreeNode **)malloc(sizeof(struct TreeNode *)*NODE_MAX);
    int pathTop=0;
    int i, j;
    bool findFinish=false;
    //another
    struct TreeNode **path2=(struct TreeNode **)malloc(sizeof(struct TreeNode *)*NODE_MAX);
    int pathTop2=0;
    int minPath=0;

    getNodePath(path, &pathTop, root, p, &findFinish);
    for(i=0;i<pathTop;i++){
        printf("%d ", path[i]->val);
    }printf("\n");

    //another
    findFinish=false;
    getNodePath(path2, &pathTop2, root, q, &findFinish);
    for(i=0;i<pathTop2;i++){
        printf("%d ", path2[i]->val);
    }printf("\n");

    minPath=pathTop<pathTop2?pathTop:pathTop2;
    for(i=0;i<minPath;i++){
        if(path[i]!=path2[i]){
            out=path[i-1];
            return out;
        }
    }
    out=path[i-1];
    return out;
}
int main(){
    int i, j;
    struct TreeNode *out, *root, *node1, *node2, *node3, *node4,
                    *node5, *node6, *node7, *node8, *node9;
    node1=(struct TreeNode *)malloc(sizeof(struct TreeNode));
    node2=(struct TreeNode *)malloc(sizeof(struct TreeNode));
    node3=(struct TreeNode *)malloc(sizeof(struct TreeNode));
    node4=(struct TreeNode *)malloc(sizeof(struct TreeNode));
    node5=(struct TreeNode *)malloc(sizeof(struct TreeNode));
    node6=(struct TreeNode *)malloc(sizeof(struct TreeNode));
    node7=(struct TreeNode *)malloc(sizeof(struct TreeNode));
    node8=(struct TreeNode *)malloc(sizeof(struct TreeNode));
    node9=(struct TreeNode *)malloc(sizeof(struct TreeNode));
    
    node1->val=3;node1->left=node2;node1->right=node3;
    node2->val=5;node2->left=node4;node2->right=node5;
    node3->val=1;node3->left=node6;node3->right=node7;
    node4->val=6;node4->left=NULL;node4->right=NULL;
    node5->val=2;node5->left=node8;node5->right=node9;
    node6->val=0;node6->left=NULL;node6->right=NULL;
    node7->val=8;node7->left=NULL;node7->right=NULL;
    node8->val=7;node8->left=NULL;node8->right=NULL;
    node9->val=4;node9->left=NULL;node9->right=NULL;
    root=node1;

    out=lowestCommonAncestor(root, node2, node9);
    printf("p = %d, q = %d\n", node4->val, node9->val);
    if(out!=NULL){
        printf("out = %d\n", out->val);
    }
    return 0;
}