#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void GetNext(int * next, const char * s)
{
    /**
     * 这个是以0开头的next表
     * ||a b a b c a a b c||
     * ||0 0 1 2 0 1 1 2 0||
    */
	int i, j;
    j=0;
    next[0]=j;
    for(i=1;i<strlen(s);i++){
        while(j>0&&s[i]!=s[j]){//前后缀不同
            j=next[j-1];//向前回退
        }
        if(s[i]==s[j]){//相同的前后缀
            j++;
        }
        next[i]=j;
    }
}

int strStr(char* haystack, char* needle) {
    int i, j;
    int hayLen=strlen(haystack), needleLen=strlen(needle);
    int out=-1;
    if(needleLen==0){
        return 0;
    }
    int next[needleLen];
    GetNext(next, needle);
    j=0;
    for(i=0;i<hayLen;i++){
        while(j>0&&haystack[i]!=needle[j]){
            j=next[j-1];
        }
        if(haystack[i]==needle[j]){
            j++;
        }
        if(j==needleLen){
            return i-needleLen+1;
        }
    }
    return out;
}

int main(){
    char txtstr[20]="aabaabaaf";
    char modelstr[20]="aabaaf";
    // char txtstr[20]="leetcode";
    // char modelstr[20]="leeto";
    int next[20]={0};
    int i, j;
    printf("len of modelstr = %d\n", strlen(modelstr));
    printf("txtstr  =||%s||\n", txtstr);
    printf("modelstr=||%s||\n", modelstr);
    GetNext(next, modelstr);
    printf("next=||");
    for(i=0;i<strlen(modelstr);i++){
        printf("%d ", next[i]);
    }printf("||\n");
    printf("strstr = %d\n", strStr(txtstr, modelstr));
    return 0;
}