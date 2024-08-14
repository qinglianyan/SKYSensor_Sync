#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

/**
 * 记录每个柱子两侧第一个小于其高度的坐标
 * 如果没有比它小的，那么左右两边就写-1
 * 
 * 单调栈
 *      维持递增单调栈
*/
#define MAX(a,b) (a>b?a:b)
bool stackEmpty(int *stack, int *top){
    if(*top==-1){
        return true;
    }
    else if(*top>=0){
        return false;
    }
    else{
        printf("Empty Error, top<-1\n");
        return false;
    }
}
int popStack(int *stack, int *top){
    if(stackEmpty(stack, top)){
        printf("Pop Error:stack empty\n");
        return 0;
    }
    return stack[(*top)--];
}
void pushStack(int *heights, int index, int *stack, int *top, int *LeftLine){
    int i, j;
    if(*top==-1){
        stack[++(*top)]=index;
        return ;
    }
    else if(*top<-1){
        printf("Push Error: top<-1\n");
        return ;
    }
    else{
        // 每个柱体找右侧第一个小于它的index
        while((*top)>=0 && heights[stack[*top]] > heights[index]){
            LeftLine[stack[*top]]=index;
            (*top)--;
        }
        stack[++(*top)]=index;
    }
    return ;
}
int largestRectangleArea(int* heights, int heightsSize) {
    int i, j;
    int res, out;
    int lefttemp, righttemp;
    // 记录当前柱体左右两侧第一个小于他高度的柱体下标
    int LeftLine[heightsSize], RightLine[heightsSize];
    
    int stack[heightsSize];
    int top;

    memset(LeftLine, 0xff, sizeof(LeftLine));
    memset(RightLine, 0xff, sizeof(RightLine));

    top=-1;
    for(i=0;i<heightsSize;i++){
        pushStack(heights, i, stack, &top, RightLine);
    }
    // printf("rightline = ");
    // for(i=0;i<heightsSize;i++){
    //     printf("%d ", RightLine[i]);
    // }printf("\n");

    top=-1;
    for(i=heightsSize-1;i>=0;i--){
        pushStack(heights, i, stack, &top, LeftLine);
    }
    // printf("leftline = ");
    // for(i=0;i<heightsSize;i++){
    //     printf("%d ", LeftLine[i]);
    // }printf("\n");
    out=0;
    for(i=0;i<heightsSize;i++){
        lefttemp=LeftLine[i];
        righttemp=(RightLine[i]==-1?heightsSize:RightLine[i]);
        out=MAX(out, heights[i]*(righttemp-lefttemp-1));
    }
    return out;
}

int main(){
    int i, j;
    int out;
    int *heights;
    int heightsSize;

    // heightsSize=6;
    // heights=(int *)malloc(sizeof(int)*heightsSize);
    // heights[0]=2, heights[1]=1, heights[2]=5;
    // heights[3]=6, heights[4]=2, heights[5]=3;
    
    heightsSize=2;
    heights=(int *)malloc(sizeof(int)*heightsSize);
    heights[0]=2, heights[1]=4;

    out=largestRectangleArea(heights, heightsSize);
    printf("__out = %d__\n", out);
    return 0;
}
/**
 * 给定 n 个非负整数，用来表示柱状图中各个柱子的高度。
 * 每个柱子彼此相邻，且宽度为 1 。
 * 求在该柱状图中，能够勾勒出来的矩形的最大面积。
 * 
示例 1:
输入：heights = [2,1,5,6,2,3]
输出：10
解释：最大的矩形为图中红色区域，面积为 10

示例 2：
输入： heights = [2,4]
输出： 4
 
提示：
1 <= heights.length <=105
0 <= heights[i] <= 104
*/