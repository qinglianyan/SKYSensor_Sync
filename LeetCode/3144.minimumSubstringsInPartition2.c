#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/**
 * 优化判断平衡字符串
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
    int hash[26]={0};
    /**
     * dp[i]表示0-i的字符串最少可以分解成几个子字符串
     * 对于 0 < j < i，判断[j,i]是不是平衡字符串
     * 如果是平衡字符串，那么dp[i]=MIN(dp[j]+1, dp[i]);
     * ---------
     * 优化点在这里👆，这里求是不是平衡字符串过于重复了
     * ---------
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