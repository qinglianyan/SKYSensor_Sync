#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @@@@@ 这个还没过
 * 给你一个整数 k 和一个整数 x 。整数 num 的价值是它的二进制表示中
 * 在 x，2x，3x 等位置处设置位的数目（从最低有效位开始）。
 * 下面的表格包含了如何计算价值的例子。
x	num	Binary Representation	Price
1	13	000001101	3
2	13	000001101	1
2	233	011101001	3
3	13	000001101	1
3	362	101101010	2
num 的 累加价值 是从 1 到 num 的数字的 总 价值。
如果 num 的累加价值小于或等于 k 则被认为是 廉价 的。
请你返回 最大 的廉价数字。
 * 1 <= k <= 1015
 * 1 <= x <= 8
*/
int calculateValue(int x, long long in){
    long long tmp;
    int value;
    int i, j;
    int firsttime=1;

    tmp=in;
    value=0;
    while(tmp){
        if(firsttime){
            tmp=tmp>>(x-1);
            firsttime=0;
        }
        else{
            tmp=tmp>>x;
        }
        value+=tmp%2;
    }
    return value;
}
long long findMaximumNumber(long long k, int x) {
    int i, j;
    int nowNum=1;
    int tmp;
    long long nowSum=0;
    while(nowSum<=k){
        tmp=calculateValue(x, nowNum++);
        nowSum+=tmp;
    }
    return nowNum-2;

}

int main(){
    int i, j;
    long long k;
    int x;
    long long out;

    k=7;
    x=2;
    out=findMaximumNumber(k, x);
    printf("__out = %lld__\n", out);
    return 0;
}