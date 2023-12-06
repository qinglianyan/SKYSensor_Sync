#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void GetNext(int * next, const char * s)
{
	int i, j;
    j=-1;
    next[0]=j;
    for(i=1;s[i]<strlen(s);i++){
        while(j>=0&&s[i]!=s[j]){
            j=next[j];
        }
        if(s[i]==s[j+1]){
            j++;
        }
        next[i]=j;
    }
}

int strStr(char* haystack, char* needle) {
    int i, j;
    int hayLen=strlen(haystack), needleLen=strlen(needle);
    int out=-1;
    bool flag=false;
    for(i=0;i<hayLen-needleLen+1;i++){
        flag=true;
        for(j=0;j<needleLen;j++){
            if(haystack[i+j]!=needle[j]){
                flag=false;
                break;
            }
        }
        if(flag) return i;
    }
    return out;
}

int main(){
    char txtstr[10]="aabaabaaf";
    char modelstr[10]="aabaaf";
    int next[10];
    int i, j;
    printf("len of modelstr = %d\n", strlen(modelstr));
    // GetNext(next, modelstr);
    printf("txtstr  =||%s||\n", txtstr);
    printf("modelstr=||%s||\n", modelstr);
    printf("strstr = %d\n", strStr(txtstr, modelstr));
    //printf("next=||%s||\n", next);
    return 0;
}