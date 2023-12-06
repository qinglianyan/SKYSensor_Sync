#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void GetNext(int * next, const char * s)
{
    /**
     * 这个是以-1开头的next表
     * || a  b  a  b  c  a  a  b  c||
     * ||-1 -1  0  1 -1  0  0  1 -1||
    */
	int i, j;
    j=-1;
    next[0]=j;
    for(i=1;i<strlen(s);i++){
        while(j>=0&&s[i]!=s[j+1]){//前后缀不同
            j=next[j];//向前回退
        }
        if(s[i]==s[j+1]){//相同的前后缀
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
    j=-1;
    for(i=0;i<hayLen;i++){
        while(j>=0&&haystack[i]!=needle[j+1]){
            j=next[j];
        }
        if(haystack[i]==needle[j+1]){
            j++;
        }
        if(j==needleLen-1){
            return i-needleLen+1;
        }
    }
    return out;
}

int main(){
    // char txtstr[10]="aabaabaaf";
    // char modelstr[10]="aabaaf";
    char txtstr[20]="ababcaababcaabc";
    char modelstr[20]="ababcaabc";
    int next[20]={0};
    int i, j;
    printf("len of modelstr = %d\n", strlen(modelstr));
    GetNext(next, modelstr);
    printf("txtstr  =||%s||\n", txtstr);
    printf("modelstr=||%s||\n", modelstr);
    printf("strstr = %d\n", strStr(txtstr, modelstr));
    printf("next=||");
    for(i=0;i<strlen(modelstr);i++){
        printf("%d ", next[i]);
    }printf("||\n");
    return 0;
}