#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

/**
 * 给定两个单词 word1 和 word2,
 * 返回使得 word1 和  word2 相同所需的最小步数。
 * 每步 可以删除任意一个字符串中的一个字符。
 * 示例 1：
 * 
 * 输入: word1 = "sea", word2 = "eat"
 * 输出: 2
 * 解释: 第一步将 "sea" 变为 "ea" ，
 *       第二步将 "eat "变为 "ea"
 * 示例  2:
 * 
 * 输入：word1 = "leetcode", word2 = "etco"
 * 输出：4
 * 
 * 提示：
 * 
 * 1 <= word1.length, word2.length <= 500
 * word1 和 word2 只包含小写英文字母
*/
#define MAX(a, b) (a>b?a:b)
int minDistance(char* word1, char* word2) {
    // 其实就是求最长公共子序列
    int i, j;
    int len1=strlen(word1), len2=strlen(word2);
    int dp[len1+1][len2+1];
    /**
     * dp[i][j]表示截至word1[i-1],word2[j-1]最长公共子序列是多长
     * if word1[i-1]==word2[j-1]
     *      dp[i][j]=dp[i-1][j-1]+1
     * else
     *      dp[i][j]=max(dp[i-1][j], dp[i][j-1])
    */
    memset(dp, 0, sizeof(dp));
    for(i=1;i<=len1;i++){
        for(j=1;j<=len2;j++){
            if(word1[i-1]==word2[j-1]){
                dp[i][j]=dp[i-1][j-1]+1;
            }
            else{
                dp[i][j]=MAX(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    return len1+len2-2*dp[len1][len2];
}


int main(){
    char *word1, *word2;
    int i, j;
    int out=0;
    word1=(char *)malloc(sizeof(char )*9);
    word2=(char *)malloc(sizeof(char )*5);
    strcpy(word1, "leetcode");
    strcpy(word2, "etco");
    out=minDistance(word1, word2);
    printf("__out = %d__\n", out);
    return 0;
}