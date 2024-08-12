#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

/**
 * 给你一个字符串 s ，找出其中最长的回文子序列，并返回该序列的长度。
 * 子序列定义为：不改变剩余字符顺序的情况下，
 *              删除某些字符或者不删除任何字符形成的一个序列。
 * 
 * 示例 1：
 * 输入：s = "bbbab"
 * 输出：4
 * 解释：一个可能的最长回文子序列为 "bbbb" 。
 * 
 * 示例 2：
 * 输入：s = "cbbd"
 * 输出：2
 * 解释：一个可能的最长回文子序列为 "bb" 。
 * 
 * 提示：
 * 1 <= s.length <= 1000
 * s 仅由小写英文字母组成
*/
/**
 * 功能函数
*/
#define MAX(a,b) (a>b?a:b)
int longestPalindromeSubseq(char* s) {
    int i, j;
    int count=0;
    int len=strlen(s);
    int dp[len+1][len+1];
    char *reverse=(char *)malloc(sizeof(char )*len+1);
    for(i=0;i<len;i++){
        reverse[i]=s[len-i-1];
    }
    reverse[i]='\0';
    printf("s       = %s\n", s);
    printf("reverse = %s\n", reverse);

    /**
     * 其实就是求s和它的反串reverse的最长公共子序列
     * 其中dp[i][j]表示截至s[i]和reverse[j]最长公共子序列长度
     * 递推公式：
     *  if s[i]==reverse[j]
     *      dp[i][j]=dp[i-1][j-1]+1
     *  else
     *      dp[i][j]=max( dp[i-1][j], dp[i][j-1] )
    */
    memset(dp, 0, sizeof(dp));
    for(i=1;i<=len;i++){
        for(j=1;j<=len;j++){
            if(s[i-1]==reverse[j-1]){
                dp[i][j]=dp[i-1][j-1]+1;
            }
            else{
                dp[i][j]=MAX(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    return dp[len][len];
}

int main(){
    int i, j;
    int out=0;
    char *s=(char *)malloc(sizeof(char)*6);
    strcpy(s, "bbbab");
    out=longestPalindromeSubseq(s);
    printf("__out = %d__\n", out);

    return 0;
}