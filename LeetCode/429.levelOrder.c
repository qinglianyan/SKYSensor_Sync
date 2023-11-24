#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
struct Node {
    int val;
    int numChildren;
    struct Node ** children;
};
/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     int numChildren;
 *     struct Node** children;
 * };
 */
bool queEmpty(struct Node **queue, int *queTop, int *queEnd){
    if((*queTop)>=(*queEnd)){
        return true;
    }
    return false;
}
void quePush(struct Node **queue, int *queTop, int *queEnd, struct Node *in){
    if((*queEnd)>=10000){
        printf("push Error!\n");
        return ;
    }
    queue[(*queEnd)++]=in;
    return;
}
struct Node *quePop(struct Node **queue, int *queTop, int *queEnd){
    struct Node *ret;
    if(queEmpty(queue, queTop, queEnd)){
        printf("push Error!\n");
        return ret;
    }
    return queue[(*queTop)++];
}
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** levelOrder(struct Node* root, int* returnSize, int** returnColumnSizes) {
    int **out=(int **)malloc(sizeof(int *)*1000);
    int i,j;
    struct Node ** queue=(struct Node **)malloc(sizeof(struct Node *)*10000);
    struct Node * tmp;
    int queTop=0, queEnd=0;
    int nowSize=0;
    *returnSize=0;
    *returnColumnSizes=(int *)malloc(sizeof(int)*1000);

    if(root==NULL){
        return out;
    }
    if(root!=NULL){
        quePush(queue, &queTop, &queEnd, root);
    }
    while(!queEmpty(queue, &queTop, &queEnd)){
        nowSize=queEnd-queTop;
        printf("nowSize = %d, Top = %d, End = %d\n", nowSize, queue[queTop]->val, queue[queEnd-1]->val);
        out[(*returnSize)]=(int *)malloc(sizeof(int)*(nowSize));
        (*returnColumnSizes)[(*returnSize)]=nowSize;
        for(i=0;i<nowSize;i++){
            tmp=quePop(queue, &queTop, &queEnd);
            out[(*returnSize)][i]=tmp->val;
            if(tmp->numChildren!=0){
                for(j=0;j<tmp->numChildren;j++){
                    quePush(queue, &queTop, &queEnd, tmp->children[j]);
                }
            }
        }
        (*returnSize)++;
    }
    return out;
}

int main(){
    int i, j;
    int **out;
    int *returnSize=(int *)malloc(sizeof(int));
    int ** returnColumnSizes=(int **)malloc(sizeof(int *));
    struct Node * root, *node1,     *node2,     *node3,     *node4,     *node5,
                        *node6,     *node7,     *node8,     *node9,     *node10,
                        *node11,    *node12,    *node13,    *node14;
    node1=(struct Node *)malloc(sizeof(struct Node));
    node2=(struct Node *)malloc(sizeof(struct Node));
    node3=(struct Node *)malloc(sizeof(struct Node));
    node4=(struct Node *)malloc(sizeof(struct Node));
    node5=(struct Node *)malloc(sizeof(struct Node));
    node6=(struct Node *)malloc(sizeof(struct Node));
    node7=(struct Node *)malloc(sizeof(struct Node));
    node8=(struct Node *)malloc(sizeof(struct Node));
    node9=(struct Node *)malloc(sizeof(struct Node));
    node10=(struct Node *)malloc(sizeof(struct Node));
    node11=(struct Node *)malloc(sizeof(struct Node));
    node12=(struct Node *)malloc(sizeof(struct Node));
    node13=(struct Node *)malloc(sizeof(struct Node));
    node14=(struct Node *)malloc(sizeof(struct Node));
    
    
    
    node1->val=1;   node1->numChildren=4;   node1->children=(struct Node **)malloc(sizeof(struct Node *)*node1->numChildren);
    node1->children[0]=node2, node1->children[1]=node3, node1->children[2]=node4, node1->children[3]=node5;

    node2->val=2;   node2->numChildren=0;   node2->children=NULL;
    
    node3->val=3;   node3->numChildren=2;   node3->children=(struct Node **)malloc(sizeof(struct Node *)*node3->numChildren);
    node3->children[0]=node6, node3->children[1]=node7;

    node4->val=4;   node4->numChildren=1;   node4->children=(struct Node **)malloc(sizeof(struct Node *)*node4->numChildren);
    node4->children[0]=node8;

    node5->val=5;   node5->numChildren=2;   node5->children=(struct Node **)malloc(sizeof(struct Node *)*node5->numChildren);
    node5->children[0]=node9; node5->children[1]=node10;

    node6->val=6;   node6->numChildren=0;   node6->children=NULL;

    node7->val=7;   node7->numChildren=1;   node7->children=(struct Node **)malloc(sizeof(struct Node *)*node7->numChildren);
    node7->children[0]=node11;

    node8->val=8;   node8->numChildren=1;   node8->children=(struct Node **)malloc(sizeof(struct Node *)*node8->numChildren);
    node8->children[0]=node12;

    node9->val=9;   node9->numChildren=1;   node9->children=(struct Node **)malloc(sizeof(struct Node *)*node9->numChildren);
    node9->children[0]=node13;

    node10->val=10; node10->numChildren=0;  node10->children=NULL;
    node11->val=11; node11->numChildren=1;  node11->children=(struct Node **)malloc(sizeof(struct Node *)*node11->numChildren);
    node11->children[0]=node14;

    node12->val=12; node12->numChildren=0;  node12->children=NULL;
    node13->val=13; node13->numChildren=0;  node13->children=NULL;
    node14->val=14; node14->numChildren=0;  node14->children=NULL;
    root=node1;
    *returnSize=0;
    
    out=levelOrder(root, returnSize, returnColumnSizes);
    for(i=0;i<(*returnSize);i++){
        for(j=0;j<(*returnColumnSizes)[i];j++){
            printf("%d ", out[i][j]);
        }printf("\n");
    }
    
    return 0;
}