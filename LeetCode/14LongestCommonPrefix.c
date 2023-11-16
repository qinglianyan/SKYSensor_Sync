#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// 编写一个函数来查找字符串数组中的最长公共前缀。
// 如果不存在公共前缀，返回空字符串 ""。

char * longestCommonPrefix(char ** strs, int strsSize){
    int i, j;
    // char* res=(char*)malloc(sizeof(char)*220);
    // int flag=0;
    char temp;
    if(strsSize==0){
        return "";
    }
    for(i=0;strs[0][i]!='\0';i++){
        temp=strs[0][i];
        // res[i]='\0';//init
        for(j=0;j<strsSize;j++){
            if(strs[j][i]=='\0'){
                strs[0][i]='\0';
                return strs[0];
                // return res;
            }
            if(strs[j][i]!=temp){
                strs[0][i]='\0';
                return strs[0];
                // return res;
            }
        }
        // res[i]=temp;
    }
    strs[0][i]='\0';
    return strs[0];
    // return res;
}

int main(){
    int i, j;
    char * strs[]={"flower", "flower", "flower"};
    // char * strs[]={""};
    // for(i=0;i<3;i++){
    //     printf("%s\n", strs[i]);
    // }
    printf("%s\n",longestCommonPrefix(strs, 3));
    // printf("%s\n",longestCommonPrefix(strs, 0));
    return 0;
}