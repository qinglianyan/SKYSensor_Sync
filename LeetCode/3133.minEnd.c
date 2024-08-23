#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// 下面这两个函数用不到，只是用来debug的时候方便显示二进制
void pLBinaryNum(long num){
    int bitSize = sizeof(num) * 8;  // 获取整数的位数
    int leadingZero = 1;            // 用于跳过前导零

    for (int i = bitSize - 1; i >= 0; i--) {
        int bit = (num >> i) & 1;    // 获取当前位的值
        if (bit || !leadingZero) {  // 跳过前导零
            putchar(bit ? '1' : '0');
            leadingZero = 0;
        }
    }

    if (leadingZero) {  // 如果所有位都是零，打印一个零
        putchar('0');
    }

    putchar('\n');     // 打印换行符
}
void pBinaryNum(int num){
    int bitSize = sizeof(num) * 8;  // 获取整数的位数
    int leadingZero = 1;            // 用于跳过前导零

    for (int i = bitSize - 1; i >= 0; i--) {
        int bit = (num >> i) & 1;    // 获取当前位的值
        if (bit || !leadingZero) {  // 跳过前导零
            putchar(bit ? '1' : '0');
            leadingZero = 0;
        }
    }

    if (leadingZero) {  // 如果所有位都是零，打印一个零
        putchar('0');
    }

    putchar('\n');     // 打印换行符
}
/**
 * 给你两个整数 n 和 x 。你需要构造一个长度为 n 的 正整数 数组 nums
 * 对于所有 0 <= i < n - 1 ，满足 nums[i + 1] 大于 nums[i] ,
 * 并且数组 nums 中所有元素的按位 AND 运算结果为 x 。
 * 返回 nums[n - 1] 可能的 最小 值。
*/
// long long minEnd(int n, int x) {
//     int i, j;
//     int tmp;
//     int highest=0, conut1=0, count0=0;
//     /**
//      * 理解：
//      * 有n个正整数，从小到大排序，绝对递增
//      * 这n个正整数所有元素ADN运算为x
//      * 求最小的最后一个值
//     */
//     tmp=x;
//     while(tmp){
//         conut1+=tmp%2;
//         tmp/=2;
//         highest++;
//     }
// printf("highest = %d\n", highest);
// printf("count1  = %d\n", conut1);
//     count0=highest-conut1;
//     if(count0>=n-1){
        
//     }
//     return 0;
// }
long long minEnd(int n, int x) {
    int i, j;
    int tmp, tmpn;
    int sto[64];
    int add[64];
    int nowindex1, nowindex2;
    int top, top2;
    long long out=0;

    tmp=x;
    top=0;
    while(tmp){
        sto[top++]=tmp%2;
        tmp/=2;
    }

    tmpn=n-1;
    top2=0;
    while(tmpn){
        add[top2++]=tmpn%2;
        tmpn/=2;
    }
// // debug
// printf("before = \n");
// for(i=0;i<top;i++){
//     printf("%d", sto[i]);
// }
// printf("\n");
// for(i=0;i<top2;i++){
//     printf("%d", add[i]);
// }
// printf("\n");

    nowindex1=0;
    nowindex2=0;
    for(nowindex1=0;nowindex1<63;nowindex1++){
        if(sto[nowindex1]==0){
            sto[nowindex1]=add[nowindex2++];
        }
        if(nowindex1>=top){
            top=nowindex1+1;
        }
        if(nowindex2>=top2){
            break;
        }
    }

// // debug
// printf("after = \n");
// for(i=0;i<top;i++){
//     printf("%d", sto[i]);
// }
// printf("\n");
    for(i=top-1;i>=0;i--){
        out=out*2+sto[i];
    }
    return out;
}

int main(){
    int i, j;
    long long out;
    int n, x;
    n=2, x=7;
    out=minEnd(n, x);
    printf("__out = %lld__\n", out);
    // pLBinaryNum(4);
    // pLBinaryNum(3);
    return 0;
}