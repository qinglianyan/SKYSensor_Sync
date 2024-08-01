#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

/**
 * 给你两个单词 word1 和 word2，
 * 请你计算出将 word1 转换成 word2 所使用的最少操作数 。
 * 你可以对一个单词进行如下三种操作：
 * 插入一个字符
 * 删除一个字符
 * 替换一个字符
 * 
 * 示例 1：
 * 输入：word1 = "horse", word2 = "ros"
 * 输出：3
 * 解释： horse -> rorse (将 'h' 替换为 'r') rorse -> rose (删除 'r') rose -> ros (删除 'e')
 * 
 * 示例 2：
 * 输入：word1 = "intention", word2 = "execution"
 * 输出：5
 * 解释： intention -> inention (删除 't') inention -> enention (将 'i' 替换为 'e') enention -> exention (将 'n' 替换为 'x') exention -> exection (将 'n' 替换为 'c') exection -> execution (插入 'u')
 * 
 * 提示：
 * 0 <= word1.length, word2.length <= 500
 * word1 和 word2 由小写英文字母组成
*/
#define MIN(a, b, c) 
int minDistance(char* word1, char* word2) {
    int i, j;
    int count=0;
    int len1=strlen(word1), len2=strlen(word2);
    int dp[len1+1][len2+1];
    /**
     * dp[i][j]表示从word1[0 - i-1]转化为word2[0 - j-1]
     * 需要的步数
     * if word1[i-1]==word2[j-1]
     *      dp[i][j]=dp[i-1][j-1]
     * else
     *      
    */

    return 0;
}

int main(){
    int i, j;
    int *word1, *word2;
    int out=0;
    word1=(char *)malloc(sizeof(char)*6);
    word2=(char *)malloc(sizeof(char)*4);
    strcpy(word1, "horse");
    strcpy(word2, "ros");
    out=minDistance(word1, word2);
    printf("__out = %d__\n");
    return 0;
}