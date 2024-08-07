#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

/**
 * 给定两个字符串 text1 和 text2，返回这两个字符串的最长 公共子序列 的长度。
 * 如果不存在 公共子序列 ，返回 0 。
 * 一个字符串的 子序列 是指这样一个新的字符串：
 * 它是由原字符串在不改变字符的相对顺序的情况下删除某些字符
 * （也可以不删除任何字符）后组成的新字符串。
例如，"ace" 是 "abcde" 的子序列，但 "aec" 不是 "abcde" 的子序列。
两个字符串的 公共子序列 是这两个字符串所共同拥有的子序列。

示例 1：
输入：text1 = "abcde", text2 = "ace" 
输出：3  
解释：最长公共子序列是 "ace" ，它的长度为 3 。

示例 2：
输入：text1 = "abc", text2 = "abc"
输出：3
解释：最长公共子序列是 "abc" ，它的长度为 3 。

示例 3：
输入：text1 = "abc", text2 = "def"
输出：0
解释：两个字符串没有公共子序列，返回 0 。

提示：
1 <= text1.length, text2.length <= 1000
text1 和 text2 仅由小写英文字符组成。
*/
#define MAX(a, b) (a>b?a:b)
int longestCommonSubsequence(char* text1, char* text2) {
    int i, j;
    int len1=strlen(text1), len2=strlen(text2);
    int dp[len1+1][len2+1];
    memset(dp, 0, sizeof(dp));
    /**
     * dp[i][j]表示截至text1[i], text2[j]的最长公共子序列的长度
     * if text1[i]==text2[j]
     *      dp[i][j]=dp[i-1][j-1]+1;
     * else dp[i][j]=dp[i-1][j-1];
    */
    for(i=1;i<=len1;i++){
        for(j=1;j<=len2;j++){
            if(text1[i-1]==text2[j-1]){
                dp[i][j]=dp[i-1][j-1]+1;
            }
            else{
                dp[i][j]=MAX(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    // for(i=0;i<=len1;i++){
    //     for(j=0;j<=len2;j++){
    //         printf("%d ", dp[i][j]);
    //     }
    //     printf("\n");
    // }
    return dp[len1][len2];
}

int main(){
    int i, j;
    int out;
    // char *text1, *text2;
    // text1=(char *)malloc(sizeof(char));
    // text2=(char *)malloc(sizeof(char));
    char text1[6]="abcde";
    char text2[4]="ace";
    // char text1[4]="abc";
    // char text2[4]="abc";

    out=longestCommonSubsequence(text1, text2);
    printf("__out = %d__\n", out);

    return 0;
}