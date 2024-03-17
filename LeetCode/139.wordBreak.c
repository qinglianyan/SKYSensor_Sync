#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool wordBreak(char* s, char** wordDict, int wordDictSize) {
    int i, j;
    int m, n;
    bool dp[strlen(s)+1];
    memset(dp, 0, sizeof(dp));
    dp[0]=true;

    for(i=0;i<wordDictSize;i++){
        for(j=0;j<=strlen(s);j++){
            if(j>=strlen(wordDict[i]) && dp[j-strlen(wordDict[i])]==true){
                dp[j]=dp[j] | dp[j-strlen(wordDict[i])];
            }
        }
    }


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