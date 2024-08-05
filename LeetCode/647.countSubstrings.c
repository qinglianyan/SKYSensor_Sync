#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


int countSubstrings(char* s) {
    int i, j;
    int len=strlen(s);
    bool dp[len][len];
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
    // 初始化
    for(i=0;i<len;i++){
        for(j=0;j<len;j++){
            if(i==j){
                dp[i][j]=true;
            }
            else if(s[i]!=s[j]){
                dp[i][j]=false;
            }
            else if(i==j+1 || i==j-1){
                dp[i][j]=true;
            }
            else if(dp[i+1][j-1]==true){
                dp[i][j]=true;
            }
            else{
                dp[i][j]=false;
            }
        }
    }
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