#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#define PEOPLE_MAX 2001
int cmp(const void *p1, const void *p2){
    if((*(int **)p2)[0]==(*(int **)p1)[0]){
        return (*(int **)p1)[1]-(*(int **)p2)[1];
    }
    return (*(int **)p2)[0]-(*(int **)p1)[0];
}
void push(int *in, int **out, int *returnSize){
    int i, j;
    if(in[1]>(*returnSize)){
        printf("push Error!\n");
        return ;
    }
    for(i=(*returnSize);i>in[1];i--){
        out[i]=out[i-1];
    }
    out[in[1]]=in;
    (*returnSize)++;
    return ;
}

int** reconstructQueue(int** people, 
    int peopleSize, int* peopleColSize, 
    int* returnSize, 
    int** returnColumnSizes){
    int i, j;
    int **out;
    int mNumber=0;
    qsort(people, peopleSize, sizeof(people[0]), cmp);
    // for(i=0;i<peopleSize;i++){
    //     printf("[");
    //     for(j=0;j<2;j++){
    //         printf("%d ", people[i][j]);
    //     }printf("]\n");
    // }
    out=(int **)malloc(sizeof(int *)*peopleSize);
    (*returnColumnSizes)=(int *)malloc(sizeof(int )*peopleSize);
    *returnSize=0;
    for(i=0;i<peopleSize;i++){
        out[i]=(int *)malloc(sizeof(int)*2);
        (*returnColumnSizes)[i]=2;
    }

    for(i=0;i<peopleSize;i++){
        push(people[i], out, returnSize);
    }
    return out;
}

int main(){
    int i, j;
    int **out;
    int **people=(int **)malloc(sizeof(int *)*6);
    int peopleSize=6;
    int *peopleColSize=(int *)malloc(sizeof(int)*peopleSize);
    int *returnSize=(int *)malloc(sizeof(int));
    int **returnColumnSizes=(int **)malloc(sizeof(int *));

    people[0]=(int *)malloc(sizeof(int)*2);
    people[1]=(int *)malloc(sizeof(int)*2);
    people[2]=(int *)malloc(sizeof(int)*2);
    people[3]=(int *)malloc(sizeof(int)*2);
    people[4]=(int *)malloc(sizeof(int)*2);
    people[5]=(int *)malloc(sizeof(int)*2);
    people[0][0]=6, people[0][1]=0; peopleColSize[0]=2;
    people[1][0]=5, people[1][1]=0; peopleColSize[1]=2;
    people[2][0]=4, people[2][1]=0; peopleColSize[2]=2;
    people[3][0]=3, people[3][1]=2; peopleColSize[3]=2;
    people[4][0]=2, people[4][1]=2; peopleColSize[4]=2;
    people[5][0]=1, people[5][1]=4; peopleColSize[5]=2;
    (*returnSize)=0;
    // [5, 0][7, 0][5, 2][6, 1][4, 4][7, 1]

    out=reconstructQueue(people, peopleSize, peopleColSize, returnSize, returnColumnSizes);
    for(i=0;i<(*returnSize);i++){
        printf("[");
        for(j=0;j<(*returnColumnSizes)[i];j++){
            printf("%d ", out[i][j]);
        }printf("]\n");
    }


    return 0;
}