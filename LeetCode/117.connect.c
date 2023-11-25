#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
struct Node {
    int val;
    struct Node *left;
    struct Node *right;
    struct Node *next;
};
/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     struct Node *left;
 *     struct Node *right;
 *     struct Node *next;
 * };
 */
/**
 * 跟116一模一样
*/
#define QUE_MAX 6000

bool queEmpty(struct Node **queue, int *queTop, int *queEnd){
    if((*queTop)>=(*queEnd)){
        return true;
    }
    return false;
}
void quePush(struct Node **queue, int *queTop, int *queEnd, struct Node *in){
    if((*queEnd)>=QUE_MAX){
        printf("push Error!\n");
        return ;
    }
    queue[(*queEnd)++]=in;
    return;
}
struct Node *quePop(struct Node **queue, int *queTop, int * queEnd){
    struct Node *ret;
    if(queEmpty(queue, queTop, queEnd)){
        printf("pop Error!\n");
        return ret;
    }
    return queue[(*queTop)++];
}

struct Node* connect(struct Node* root) {
    struct Node **queue=(struct Node **)malloc(sizeof(struct Node *)*QUE_MAX);
    int queTop=0, queEnd=0;
    int i, j;
    int nowSize=0;
    struct Node *tmp;

    if(root!=NULL){
        quePush(queue, &queTop, &queEnd, root);
    }
    while(!queEmpty(queue, &queTop, &queEnd)){
        nowSize=queEnd-queTop;
        for(i=0;i<nowSize;i++){
            tmp=quePop(queue, &queTop, &queEnd);
            if(i==(nowSize-1)){
                tmp->next=NULL;
            }
            else{
                tmp->next=queue[queTop];
            }

            if(tmp->left){
                quePush(queue, &queTop, &queEnd, tmp->left);
            }
            if(tmp->right){
                quePush(queue, &queTop, &queEnd, tmp->right);
            }
        }
    }

    return root;
}

void printNext(struct Node * in){
    printf("node%d.next = ", in->val);
    if(in->next==NULL){
        printf("NULL\n");
    }
    else{
        printf("%d\n", in->next->val);
    }
    return ;
}
int main(){
    int i, j;
    struct Node *root,  *out,
                *node1, *node2, *node3, *node4, *node5, *node6, *node7;
    node1=(struct Node *)malloc(sizeof(struct Node));
    node2=(struct Node *)malloc(sizeof(struct Node));
    node3=(struct Node *)malloc(sizeof(struct Node));
    node4=(struct Node *)malloc(sizeof(struct Node));
    node5=(struct Node *)malloc(sizeof(struct Node));
    node6=(struct Node *)malloc(sizeof(struct Node));
    node7=(struct Node *)malloc(sizeof(struct Node));

    node1->val=1;node1->left=node2;node1->right=node3;node1->next=NULL;
    node2->val=2;node2->left=node4;node2->right=node5;node2->next=NULL;
    node3->val=3;node3->left=node6;node3->right=node7;node3->next=NULL;
    node4->val=4;node4->left=NULL;node4->right=NULL;node4->next=NULL;
    node5->val=5;node5->left=NULL;node5->right=NULL;node5->next=NULL;
    node6->val=6;node6->left=NULL;node6->right=NULL;node6->next=NULL;
    node7->val=7;node7->left=NULL;node7->right=NULL;node7->next=NULL;
    root=node1;

    printNext(node1);
    printNext(node2);
    printNext(node3);
    printNext(node4);
    printNext(node5);
    printNext(node6);
    printNext(node7);
    printf("before------------\n");

    root=NULL;
    out=connect(root);
    
    return 0;
}