#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool find(char **wordDict, int wordDictSize, char *str){
    int i, j;
    for(i=0;i<wordDictSize;i++){
        if(strcmp(str, wordDict[i])==0){
            printf("end compare");
            return true;
        }
        printf("end compare");
    }
    return false;
}

bool wordBreak(char* s, char** wordDict, int wordDictSize) {
    int i, j;
    int m, n;
    char *tmp=(char *)malloc(sizeof(char )*strlen(s)+1);
    /**
     * 首先尝试使用二维数组算一算
     * dp[i][j]表示从[0, i]下标的字典中，表示字符串[0, j]是否可以拼出
     * 递推公式：
     *  if dp[i]=true & find(i, j)=true
     *      then dp[j]=true
     * 内外循环：排列数(外背包，内物品)、组合数(外物品，内背包)
    */

    bool dp[strlen(s)+1];
    memset(dp, 0, sizeof(dp));
    dp[0]=true;
    // printf("dp:\n");
    // for(i=0;i<=strlen(s);i++){
    //     printf("%d ", dp[i]);
    // }printf("\n");

    for(j=1;j<=strlen(s);j++){
        for(i=0;i<j;i++){
            printf("in loop\n");
            // memset(tmp, 0, sizeof(tmp));
            tmp[0]='\0';
            strncpy(tmp, s+i, j-i);
            tmp[j-i]='\0';// ⭐⭐strncpy不会自动补全后面的'\0'
            if(dp[i]&&find(wordDict, wordDictSize, tmp)){
                dp[j]=true;
            }
        }
        // // log
        for(m=0;m<=strlen(s);m++){
            printf("%d ", dp[m]);
        }printf("\n");
    }
    // for(i=0;i<wordDictSize;i++){
    //     for(j=0;j<=strlen(s);j++){
    //         if(j>=strlen(wordDict[i]) && dp[j-strlen(wordDict[i])]==true){
    //             dp[j]=dp[j] | dp[j-strlen(wordDict[i])];
    //         }
    //     }
    // }
return dp[strlen(s)];

}

int main(){
    int i,j;
    char **wordDict;
    bool out;
    // // useCase 1
    // char s[9]="leetcode";
    // int wordDictSize=2;
    // wordDict=(char **)malloc(sizeof(char *)*2);
    // wordDict[0]=(char *)malloc(sizeof(char)*5);
    // wordDict[1]=(char *)malloc(sizeof(char)*5);
    // strcpy(wordDict[0], "leet");
    // strcpy(wordDict[1], "code");

    // useCase 2
    char s[2]="a";
    int wordDictSize=1;
    wordDict=(char **)malloc(sizeof(char *)*wordDictSize);
    wordDict[0]=(char *)malloc(sizeof(char)*5);
    strcpy(wordDict[0], "a");
    // printf("%s\n", wordDict[0]);
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