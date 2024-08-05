#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
/**
 * 如果一个整数能够被其各个数位上的数字之和整除，则称之为 哈沙德数（Harshad number）。
 * 给你一个整数 x.如果x是 哈沙德数 ，则返回 x 各个数位上的数字之和，否则，返回 -1 。
示例 1：
输入： x = 18
输出： 9

解释：
x 各个数位上的数字之和为 9 。18 能被 9 整除。因此 18 是哈沙德数，答案是 9 。
*/
int sumOfTheDigitsOfHarshadNumber(int x) {
    int i,j;
    int sum=0;
    int num=x;

    while(num>0){
        sum+=num%10;
        num/=10;
    }
    printf("sum = %d\nx = %d\nx%%sum = %dd\n", sum, x, x%sum);
    
    if(x%sum==0){
        return sum;
    }
    else{
        return -1;
    }
}

int main(){
    int i, j;
    int x=18;
    int out=0;

    out=sumOfTheDigitsOfHarshadNumber(x);
    printf("__out = %d__\n");
    return 0;
}