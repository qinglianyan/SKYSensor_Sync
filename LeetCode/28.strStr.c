#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    for(i=0;i<hayLen-needleLen;i++){
        for(j=0;j<needleLen;j++){
            if(haystack[i+j]==needle[j]){
                if(j==needleLen-1){
                    out=i+j;
                    break;
                }
            }
        }
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
    printf("txtstr=||%s||\n", modelstr);
    printf("strstr = %d\n", strStr(txtstr, modelstr));
    //printf("next=||%s||\n", next);
    return 0;
}