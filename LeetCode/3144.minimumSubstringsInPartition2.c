#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/**
 * 优化判断平衡字符串
 * 
 * 给你一个字符串 s ，你需要将它分割成一个或者更多的 平衡 子字符串。
 * 比方说，s == "ababcc" 那么 
 * ("abab", "c", "c") ，("ab", "abc", "c") 和 ("ababcc") 都是合法分割，
 * 但是 ("a", "bab", "cc") ，("aba", "bc", "c") 和 ("ab", "abcc") 不是，
 * 不平衡的子字符串用粗体表示。
 * 
 * 请你返回 s 最少 能分割成多少个平衡子字符串。
 * 注意：一个 平衡 字符串指的是字符串中所有字符出现的次数都相同。
 * 
 * 示例 1：
 * 输入：s = "fabccddg"
 * 输出：3
 * 解释：我们可以将 s 分割成 3 个子字符串：
 * ("fab, "ccdd", "g") 或者 ("fabc", "cd", "dg") 。
 * 
 * 示例 2：
 * 输入：s = "abababaccddb"
 * 输出：2
 * 解释：我们可以将 s 分割成 2 个子字符串：("abab", "abaccddb") 。
 * 
 * 提示：
 * 1 <= s.length <= 1000
 * s 只包含小写英文字母。
*/
#define MIN(a,b) a<b?a:b
bool isBalancestr(char *s, int left, int right){
    int i, j;
    int len=strlen(s);
    int nowtime=0;
    
    if(right<left){
        printf("error:right < left.\n");
        return false;
    }
    if(left>len-1){
        printf("error:left > len.(len = %d, left = %d)\n", len, left);
        return false;
    }
    if(left==right){
        return true;
    }

    int hash[26]={0};
    for(i=left;i<=right;i++){
        hash[s[i]-'a']++;
    }
    for(i=0;i<26;i++){
        if(hash[i]>0){
            if(nowtime==0){
                nowtime=hash[i];
            }
            else{
                if(nowtime!=hash[i]){
                    return false;
                }
            }
        }
    }
    return true;
}
int minimumSubstringsInPartition(char* s) {
    int i, j;
    int len=strlen(s);
    int dp[len+1];
    /**
     * dp[i]表示0-i的字符串最少可以分解成几个子字符串
     * 对于 0 < j < i，判断[j,i]是不是平衡字符串
     * 如果是平衡字符串，那么dp[i]=MIN(dp[j]+1, dp[i]);
     * 如果不是,空；
     * 依赖前文；dp[0]=1;初始化大值;
     * 
    */
    if(len==1){
        return 1;
    }
    // memset(dp, 0x3f, sizeof(dp));
    dp[0]=1;
    for(i=1;i<len;i++){
        if(i==8){
            i=8;
        }
        dp[i]=i+1;
        for(j=i;j>=0;j--){
            
            if(isBalancestr(s, j, i)){
                if(j==0){
                    dp[i]=1;
                }
                else{
                    dp[i]=MIN(dp[j-1]+1, dp[i]);
                }
            }
        }
    }
    // printf("dp : ");
    // for(i=0;i<len;i++){
    //     printf("%d ", dp[i]);
    // }
    // printf("\n");
    return dp[len-1];

}

int main(){
    int i, j;
    int out;
    char s[20]="abababaccddb";
    out = minimumSubstringsInPartition(s);
    printf("__out = %d__\n", out);
    return 0;
}