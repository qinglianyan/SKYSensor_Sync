#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

/**
 * 给你一个字符串 s ，请你统计并返回这个字符串中 回文子串 的数目。
 * 回文字符串 是正着读和倒过来读一样的字符串。
 * 子字符串 是字符串中的由连续字符组成的一个序列。
 * 
 * 示例 1：
 * 输入：s = "abc"
 * 输出：3
 * 解释：三个回文子串: "a", "b", "c"
 * 
 * 示例 2：
 * 输入：s = "aaa"
 * 输出：6
 * 解释：6个回文子串: "a", "a", "a", "aa", "aa", "aaa"
 * 
 * 提示：
 * 1 <= s.length <= 1000
 * s 由小写英文字母组成
*/

int countSubstrings(char* s) {
    int i, j;
    int len=strlen(s);
    bool dp[len][len];
    int count=0;
    memset(dp, 0, sizeof(dp));
    /**
     * dp[i][j]表示下标i--j是否是回文串
     * if s[i] != s[j]
     *      dp[i][j]=false;
     * else这时候s[i]==s[j]
     *      if i==j dp[i][j]=true;
     *      else if j==i+1 dp[i][j]=true
     *      else if dp[i+1][j-1]==true dp[i][j]=true;
     *      else dp[i][j]=false;
    */

   /**
    * 由于dp[i][j]依赖于dp[i+1][j-1]
    * 因此遍历顺序从左到右，从下到上
   */
    for(i=len-1;i>=0;i--){
        for(j=i;j<len;j++){
            if(s[i]==s[j]){
                if(abs(i-j)<=1){
                    dp[i][j]=true;
                    count++;
                }
                else if(dp[i+1][j-1]==true){
                    dp[i][j]=true;
                    count++;
                }
            }

            
        }
    }
    for(i=0;i<len;i++){
        for(j=0;j<len;j++){
            printf("%d ", dp[i][j]);
        }
        printf("\n");
    }
//     for(i=0;i<len;i++){
//         for(j=0;j<len;j++){
//             if(i==j){
//                 dp[i][j]=true;
//             }
//             else if(s[i]!=s[j]){
//                 dp[i][j]=false;
//             }
//             else if(i==j+1 || i==j-1){
//                 dp[i][j]=true;
//             }
//             else if(dp[i+1][j-1]==true){
//                 dp[i][j]=true;
//             }
//             else{
//                 dp[i][j]=false;
//             }
//         }
//     }
    return count;
}


int main(){
    int i, j;
    int out=0;
    char *s=(char *)malloc(sizeof(char)*4);
    strcpy(s, "aaa");
    out=countSubstrings(s);
    printf("__out = %d__\n", out);

    return 0;
}