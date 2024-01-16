#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
int cmp(const void *p1, const void *p2){
    int **pp1=(int **)p1, **pp2=(int **)p2;
    if((*pp1)[0]==(*pp2)[0]){
        return (*pp1)[1]-(*pp2)[1];
    }
    return (*pp1)[0]-(*pp2)[0];
}

int findMinArrowShots(int** points, int pointsSize,
                    int* pointsColSize){
    int out=0;
    int i, j;
    qsort(points, pointsSize, sizeof(points[0]), cmp);
    printf("\n---------------\n");
    for(i=0;i<pointsSize;i++){
        printf("points[%d] = [", i);
        for(j=0;j<pointsColSize[i];j++){
            printf("%d ", points[i][j]);
        }
        printf("]\n");
    }
    return out;
}

int main(){
    int i, j;
    int out;
    int **points=(int **)malloc(sizeof(int *)*4);
    int pointsSize=4;
    int *pointsColSize=(int *)malloc(sizeof(int)*pointsSize);

    for(i=0;i<pointsSize;i++){
        points[i]=(int *)malloc(sizeof(int)*2);
        pointsColSize[i]=2;
    }
    points[0][0]=10;    points[0][1]=16;
    points[1][0]=2;     points[1][1]=8;
    points[2][0]=1;     points[2][1]=6;
    points[3][0]=7;     points[3][1]=12;

    for(i=0;i<pointsSize;i++){
        printf("points[%d] = [", i);
        for(j=0;j<pointsColSize[i];j++){
            printf("%d ", points[i][j]);
        }
        printf("]\n");
    }
    out=findMinArrowShots(points, pointsSize, pointsColSize);
    printf("out = %d\n", out);
    return 0;
}