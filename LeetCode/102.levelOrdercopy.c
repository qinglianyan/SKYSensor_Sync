#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int **levelOrder(struct TreeNode *root, int *returnSize, int **returnColumnSizes)
{
    int **ans = (int **)malloc(sizeof(int *) * 2000);
    *returnSize = 0;
    if (root == NULL)
        return NULL;
    int columnSizes[2000];        // 记录每一行的列数（每层结点数），因为要给出* returnColumnSizes
    struct TreeNode *queue[2000]; // 模拟队列
    int rear = 0;
    int head = 0;         // 记录队列头尾
    queue[rear++] = root; // 录入根结点

    while (rear != head)
    { // 队列不为空
        ans[(*returnSize)] = (int *)malloc(sizeof(int) * (rear - head));
        columnSizes[(*returnSize)] = rear - head;
        int start = head; // 记录遍历开始位置，即为本层的头
        head = rear;      // 本层的尾部成为下次的头，因为所有的元素均弹出队列
        // 在这里下层的头head同时作为遍历结束的位置，因为在遍历中rear会不断改变，成为下层的尾
        for (int i = start; i < head; i++)
        { // 弹出start到未变化的rear（即为head）之间的所有元素
            ans[(*returnSize)][i - start] = queue[i]->val;
            if (queue[i]->left)
                queue[rear++] = queue[i]->left;
            if (queue[i]->right)
                queue[rear++] = queue[i]->right; // rear不断改变
        }
        (*returnSize)++; // 一层遍历完*returnSize加一；
    }
    *returnColumnSizes = (int *)malloc(sizeof(int) * (*returnSize)); // 给出*returnColumnSizes
    for (int i = 0; i < *returnSize; i++)
        (*returnColumnSizes)[i] = columnSizes[i];
    return ans;
}

int main()
{
    int i, j;
    int **out;
    int *returnSize = (int *)malloc(sizeof(int));
    // int ** returnColumnSizes=(int **)malloc(sizeof(int *));
    int **returnColumnSizes=(int **)malloc(sizeof(int *));

    *returnSize = 0;
    struct TreeNode *root;
    struct TreeNode *node1 = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    struct TreeNode *node2 = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    struct TreeNode *node3 = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    struct TreeNode *node4 = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    struct TreeNode *node5 = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    node1->val = 3;     node1->left = node2;    node1->right = node3;
    node2->val = 9;     node2->left = NULL;     node2->right = NULL;
    node3->val = 20;    node3->left = node4;    node3->right = node5;
    node4->val = 15;    node4->left = NULL;     node4->right = NULL;
    node5->val = 7;     node5->left = NULL;     node5->right = NULL;
    root = node1;
    // node1->val=1;   node1->left=NULL;   node1->right=NULL;
    // root=NULL;
    out = levelOrder(root, returnSize, returnColumnSizes);
    for (i = 0; i < (*returnSize); i++)
    {
        for(j=0;j<(*returnColumnSizes)[i];j++){
        // for (j = 0; j < 2; j++){
            printf("%d ", out[i][j]);
        }
        printf("\n");
    }
    return 0;
}