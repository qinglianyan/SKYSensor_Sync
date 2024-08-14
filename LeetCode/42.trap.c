#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
/**
 * 对于每一个，获取左右的最大边界，取最小的一个求差值
*/
// void isEmpty(int *stack, int *top){
//     if((*top)==-1){
//         return true;
//     }
//     else if((*top)>=0){
//         return false;
//     }
//     else{
//         printf("Error:stackEmpty error!\n");
//         return false;
//     }
// }
// int pop(int *stack, int *top){
//     if(*top<0){
//         printf("Error:pop Error. stack empty.\n");
//         return 0;
//     }
//     return stack[(*top)--];
// }
// void pushStackR(int *height, int index, int* stack, int *top, int *RightLine){
//     int i, j;

// }
#define MIN(a,b) (a<b?a:b)
int trap(int* height, int heightSize) {
    int i, j;
    int res, max;
    int LeftLine[heightSize], RightLine[heightSize];
    // int stack[heightSize];
    // int *top=(int *)malloc(sizeof(int));
    // *top=-1;
    // 下面这个memset没有必要
    //memset(LeftLine, 0, sizeof(LeftLine));
    //(RightLine, 0, sizeof(RightLine));
    max=0;
    LeftLine[0]=0;
    for(i=0;i<heightSize-1;i++){
        if(height[i]>max){
            max=height[i];
        }
        LeftLine[i+1]=max;
    }

    max=0;
    RightLine[heightSize-1]=0;
    for(i=heightSize-1;i>0;i--){
        if(height[i]>max){
            max=height[i];
        }
        RightLine[i-1]=max;
    }
    // for(i=0;i<heightSize;i++){
    //     printf("%d ", LeftLine[i]);
    // }printf("\n");
    // for(i=0;i<heightSize;i++){
    //     printf("%d ", RightLine[i]);
    // }printf("\n");
    res=0;
    for(i=0;i<heightSize;i++){
        if(MIN(LeftLine[i], RightLine[i])>height[i]){
            res+=(MIN(LeftLine[i], RightLine[i])-height[i]);
        }
    }


    return res;
}

int main(){
    int i, j, out;
    int *height;
    int heightSize;

    heightSize=12;
    height=(int *)malloc(sizeof(int)*heightSize);
    height[0]=0; height[1]=1; height[2]=0; height[3]=2;
    height[4]=1; height[5]=0; height[6]=1; height[7]=3;
    height[8]=2; height[9]=1; height[10]=2; height[11]=1;
    
    // for(i=0;i<heightSize;i++){
    //     printf("%d ", height[i]);
    // }printf("\n");
    out=trap(height, heightSize);
    printf("__out = %d__\n", out);
    return 0;
}
/**
 * 给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，
 * 计算按此排列的柱子，下雨之后能接多少雨水。

示例 1：
输入：height = [0,1,0,2,1,0,1,3,2,1,2,1]
输出：6
解释：上面是由数组 [0,1,0,2,1,0,1,3,2,1,2,1]
      表示的高度图，在这种情况下，可以接 6 个单位的雨水（蓝色部分表示雨水）。 

示例 2：
输入：height = [4,2,0,3,2,5]
输出：9

提示：
n == height.length
1 <= n <= 2 * 10^4
0 <= height[i] <= 10^5
*/