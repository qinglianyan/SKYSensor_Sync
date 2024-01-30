#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


#define MAX_BALLOON 100000
int *record[MAX_BALLOON];
int top=0;
int cmp(const void *p1, const void *p2){
    int **a=(int **)p1, **b=(int **)p2;
    if((*a)[0]==(*b)[0]){
        return (*a)[1]>(*b)[1];
    }
    return (*a)[0]>(*b)[0];
}

int findMinArrowShots(int** points, int pointsSize,
                    int* pointsColSize){
    int out=1;
    int i, j;
    qsort(points, pointsSize, sizeof(points[0]), cmp);
    // for(i=0;i<pointsSize;i++){
    //     printf("[");
    //     for(j=0;j<2;j++){
    //         printf("%d ", points[i][j]);
    //     }
    //     printf("]\n");
    // }
    for(i=1;i<pointsSize;i++){
        if(points[i][0]>points[i-1][1]){
            out++;
        }
        else{
            points[i][1]=(points[i-1][1]<points[i][1]?points[i-1][1]:points[i][1]);
        }
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

    // for(i=0;i<pointsSize;i++){
    //     printf("points[%d] = [", i);
    //     for(j=0;j<pointsColSize[i];j++){
    //         printf("%d ", points[i][j]);
    //     }
    //     printf("]\n");
    // }
    out=findMinArrowShots(points, pointsSize, pointsColSize);
    printf("out = %d\n", out);
    return 0;
}