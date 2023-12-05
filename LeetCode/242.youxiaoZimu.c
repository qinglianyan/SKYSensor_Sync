#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

bool isAnagram(char* s, char* t) {
    int num[26]={0}; 
    if(strlen(s)!=strlen(t))
        return false;
    for(int i=0;s[i]!='\0';i++){
        num[s[i]-'a']++;
        num[t[i]-'a']--;
    }
    for(int i=0;i<26;i++)
        if(num[i]!=0)
            return false;
    return true;
}

int main(){
    int i, j;
    char s[]="anagram";
    char t[]="nagaram";
    bool out;

    out=isAnagram(s, t);
    printf("out = %d\n", out);
    return 0;
}