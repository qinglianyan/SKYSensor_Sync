#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

/**
 * 给定一个整数数组 temperatures ，表示每天的温度，返回一个数组 answer ，
 * 其中 answer[i] 是指对于第 i 天，下一个更高温度出现在几天后。
 * 如果气温在这之后都不会升高，请在该位置用 0 来代替。
 * 
 * 示例 1:
 * 输入: temperatures = [73,74,75,71,69,72,76,73]
 * 输出: [1,1,4,2,1,1,0,0]
 * 
 * 示例 2:
 * 输入: temperatures = [30,40,50,60]
 * 输出: [1,1,1,0]
 * 
 * 示例 3:
 * 输入: temperatures = [30,60,90]
 * 输出: [1,1,0]
 * 
 * 提示：
 * 1 <= temperatures.length <= 10^5
 * 30 <= temperatures[i] <= 100
*/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
/**
 * 之前那个版本是从前往后单调栈，结果最后一个测试用例超时了
 * 这个版本是从后往前读,维持一个递减的栈
*/ 
#define MAX_Stack 100001
int stack[MAX_Stack];
int top=-1;
int answer[MAX_Stack];
bool stackEmpty(){
    if(top==-1){
        return true;
    }
    else if(top>=0){
        return false;
    }
    else{
        printf("Error:stackEmpty error!\n");
        return false;
    }
}
int pop(){
    if(top<0){
        printf("Error:pop Error. stack empty.\n");
        return 0;
    }
    return stack[top--];
}
void push(int *temperatures, int index){
    int tmp, now;
    int i, j;
    if(top>=MAX_Stack){
        printf("Error:push Error. stack full.\n");
        return ;
    }
    else if(top<-1){
        printf("Error:push Error.invalid top.\n");
        return ;
    }
    else if(top==-1){
        stack[++top]=index;
    }
    else{
        now=top;
        while(now>=0&&temperatures[stack[now]]<temperatures[index]){
            stack[now+1]=stack[now];
            now--;
        }
        stack[now+1]=index;
        if(now==-1){
            answer[index]=0;
        }
        else{
            answer[index]=stack[now]-index;
        }
    }
}


int* dailyTemperatures( int* temperatures, int temperaturesSize, 
                        int* returnSize) {
    int i, j;
    
    memset(answer, 0, sizeof(answer));
    memset(stack, 0, sizeof(stack));
    *returnSize=temperaturesSize;
    for(i=temperaturesSize-1;i>=0;i--){
        push(temperatures, i);
    }
    return answer;
}

int main(){
    int i, j;
    int *out;
    int *returnSize=(int *)malloc(sizeof(int));
    *returnSize=0;

    int temperaturesSize=8;
    int *temperatures=(int *)malloc(sizeof(int)*8);
    temperatures[0]= 73;
    temperatures[1]= 74;
    temperatures[2]= 75;
    temperatures[3]= 71;
    temperatures[4]= 69;
    temperatures[5]= 72;
    temperatures[6]= 76;
    temperatures[7]= 73;
    // int temperaturesSize=4;
    // int *temperatures=(int *)malloc(sizeof(int)*4);
    // temperatures[0]= 30;
    // temperatures[1]= 40;
    // temperatures[2]= 50;
    // temperatures[3]= 60;


    out=dailyTemperatures(temperatures, temperaturesSize, returnSize);
    for(i=0;i<(*returnSize);i++){
        printf("%d ", out[i]);
    }printf("\n");
    return 0;
}