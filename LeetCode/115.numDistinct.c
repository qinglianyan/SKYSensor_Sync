#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

/**
 * 给你两个字符串 s 和 t ，统计并返回在 s 的 子序列 中 t 出现的个数，
 * 结果需要对 10^9 + 7 取模。
 * 
 * 示例 1：
 * 
 * 输入：s = "rabbbit", t = "rabbit"
 * 输出：3
 * 解释：
 * 如下所示, 有 3 种可以从 s 中得到 "rabbit" 的方案。
 * rabbbit
 * rabbbit
 * rabbbit
 * 
 * 示例 2：
 * 
 * 输入：s = "babgbag", t = "bag"
 * 输出：5
 * 解释：
 * 如下所示, 有 5 种可以从 s 中得到 "bag" 的方案。 
 * babgbag
 * babgbag
 * babgbag
 * babgbag
 * babgbag
 * 
 * 提示：
 * 
 * 1 <= s.length, t.length <= 1000
 * s 和 t 由英文字母组成
 **/

int numDistinct(char* s, char* t) {
    int i, j;
    int count;
    int lens=strlen(s), lent=strlen(t);
    printf("strlens = %d\n", lens);
    printf("strlent = %d\n", lent);
    int dp[lens+1][lent+1];
    /**
     * dp[i][j]表示截至s[i-1]和t[j-1]，s序列中有几个t
     * if s[i-1]==t[j-1]
     *      
     * else
     *      
    */

    return 0;
}

int main(){
    int i, j;
    int out=0;
    char *s, *t;
    s=(char *)malloc(sizeof(char )*8);
    t=(char *)malloc(sizeof(char )*4);
    strcpy(s, "babgbag");
    strcpy(t, "bag");
    out=numDistinct(s, t);
    return 0;
}