#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
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
/**
 * leetcode不支持，只能自己写了
 * binary恒定是10进制
*/
void itoa_DIY(int in, char *itoaTmp, int binary){
    int strTop=0;
    int i, j;
    int tmp;
    bool neg=0;
    if(in<0){
        neg=true;
        in=-in;
    }

    while(in!=0){
        itoaTmp[strTop++]=(in%10+'0');
        in=in/10;
    }
    if(neg){
        itoaTmp[strTop++]='-';
    }
    itoaTmp[strTop]='\0';
    i=0, j=strTop-1;
    while(i<j){
        tmp=itoaTmp[j];
        itoaTmp[j]=itoaTmp[i];
        itoaTmp[i]=tmp;
        i++;
        j--;
    }
    return;
}
void strAdd(char *tmpStr, int *strTop, bool root, int in){
    char itoaTmp[10];
    if(root){
        // itoa(in, itoaTmp, 10);
        itoa_DIY(in, itoaTmp, 10);
        strcat(tmpStr, itoaTmp);
        (*strTop)=strlen(tmpStr);
    }
    else{
        tmpStr[(*strTop)++]='-';
        tmpStr[(*strTop)++]='>';
        tmpStr[(*strTop)]='\0';
        // itoa(in, itoaTmp, 10);
        itoa_DIY(in, itoaTmp, 10);
        strcat(tmpStr, itoaTmp);
        (*strTop)=strlen(tmpStr);
    }
    return;
}
void strDelete(char *tmpStr, int *strTop){
    int i;
    for(i=(*strTop);i>0;i--){
        if(tmpStr[i]=='-'&&tmpStr[i+1]=='>'){
            tmpStr[i]='\0';
            (*strTop)=strlen(tmpStr);
            return;
        }
    }
}
void DFS(struct TreeNode *node, int *returnSize, char **output, char *tmpStr, int *strTop){
    if(node==NULL){//如果是NULL，直接返回，说明到头了
        return;
    }
    if((*strTop==0)){//说明现在是根节点，直接放在tmpStr里面
        strAdd(tmpStr, strTop, true, node->val);
    }
    else{//是普通节点， 先放一个"->"，再放数字
        strAdd(tmpStr, strTop, false, node->val);
    }
    if(node->left==NULL&&node->right==NULL){//是叶子节点，拿出来整个tmpStr存起来
        output[(*returnSize)]=(char *)malloc(sizeof(char)*300);
        strcpy(output[(*returnSize)], tmpStr);
        (*returnSize)++;
    }
    if(node->left!=NULL){
        DFS(node->left, returnSize, output, tmpStr, strTop);
    }
    if(node->right!=NULL){
        DFS(node->right, returnSize, output, tmpStr, strTop);
    }
    //每次左右都处理完之后需要回溯,要把node的节点从tmpStr中删掉
    strDelete(tmpStr, strTop);

}
char** binaryTreePaths(struct TreeNode* root, int* returnSize) {
    char ** output=(char **)malloc(sizeof(char *)*NODE_MAX);
    char * tmpStr=(char *)malloc(sizeof(char)*400);
    int strTop=0;
    *returnSize=0;
    tmpStr[0]='\0';
    DFS(root, returnSize, output,tmpStr, &strTop);
    return output;
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

    output=binaryTreePaths(root, returnSize);
    for(i=0;i<(*returnSize);i++){
        printf("%s\n", output[i]);
    }
    
    return 0;
}