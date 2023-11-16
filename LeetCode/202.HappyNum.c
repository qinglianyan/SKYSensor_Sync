#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

int get_sum(int n) {
    int sum = 0;
    div_t n_div = { .quot = n };
    while (n_div.quot != 0) {
        n_div = div(n_div.quot, 10);
        sum += n_div.rem * n_div.rem;
    }
    return sum;
}

int getsum(int n)
{
    int i, j;
    int sum = 0;
    
    while (n)
    {

        sum += (n % 10) * (n % 10);
        n /= 10;
    }

    return sum;
}

bool isHappy(int n)
{
    int sum;

    while(1){
        sum=getsum(n);
        if(sum==1){
            return true;
        }
        //如果已经出现过了就循环了，返回false
        //如果没有就进记录
        
    }
    return true;
}

int main()
{
    return 0;
}
