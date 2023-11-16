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
    
}

int main(){
    char txtstr[10]="aabaabaaf";
    char modelstr[10]="aabaaf";
    int next[10];
    int i, j;
    printf("len of modelstr = %d\n", strlen(modelstr));
    GetNext(next, modelstr);
    printf("txtstr=||%s||\n", modelstr);
    for(i=0;i<6;i++){
        printf("%d", next[i]);
    }
    //printf("next=||%s||\n", next);
    return 0;
}