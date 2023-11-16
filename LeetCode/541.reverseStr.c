#include <stdio.h>
#include <stdlib.h>

void reverseString(char* s, int sSize) {
    int i, j;
    int left=0, right=sSize-1;
    char temp;
    while(left<right){
        temp=s[right];
        s[right]=s[left];
        s[left]=temp;
        left++;
        right--;
    }
    return;
}
char* reverseStr(char* s, int k) {
    int i, j;
    int len=0;
    while(s[len]!='\0'){
        len++;
    }
    for(i=0;i<len;i+=(2*k)){
        if(i+k<=len){
            reverseString(&s[i], k);
        }else{
            reverseString(&s[i], len-i);
        }
    }
    return s;
}

int main(){
    char s[10]="abcdefg";
    int k=2;
    char *out;

    out=reverseStr(s, k);
    printf("output = %s\n", out);
    return 0;
}