#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool wordBreak(char* s, char** wordDict, int wordDictSize) {
    int i, j;
    int m, n;
    /**
     * dp[j]表示字符串到下标j是否可以被字典表示出来
     * 如果dp[j]=true,说明dp[j]可以用字典表示出来
     * 如果dp[j]=true,且(j, i]也可以用字典表示出来，那么说明dp[i]可以用字典表示出来
    */

    bool dp[strlen(s)+1];
    memset(dp, 0, sizeof(dp));
    dp[0]=true;
    printf("dp:\n");
    for(i=0;i<=strlen(s);i++){
        printf("%d ", dp[i]);
    }printf("\n");

    // for(i=0;i<wordDictSize;i++){
    //     for(j=0;j<=strlen(s);j++){
    //         if(j>=strlen(wordDict[i]) && dp[j-strlen(wordDict[i])]==true){
    //             dp[j]=dp[j] | dp[j-strlen(wordDict[i])];
    //         }
    //     }
    // }
return 0;

}

int main(){
    int i,j;

    char s[9]="leetcode";
    char **wordDict;
    int wordDictSize;
    bool out;
    wordDict=(char **)malloc(sizeof(char *)*2);
    wordDict[0]=(char *)malloc(sizeof(char)*5);
    wordDict[1]=(char *)malloc(sizeof(char)*5);
    strcpy(wordDict[0], "leet");
    strcpy(wordDict[1], "code");
    // for(i=0;i<2;i++){
    //     printf("%s\n", wordDict[i]);
    // }
    out=wordBreak(s, wordDict, wordDictSize);
    if(out){
        printf("out = true!\n");
    }
    else{
        printf("out = false!\n");
    }
    return 0;
}