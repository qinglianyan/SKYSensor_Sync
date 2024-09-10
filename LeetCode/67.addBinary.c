#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
void swap(char *in){
    int i, j;
    char tmp;
    int len=strlen(in);
    int left=0, right=len-1;// 注意跳过最后的'\0'
    while(left<right){
        tmp=in[right];
        in[right]=in[left];
        in[left]=tmp;
        left++;
        right--;
    }
    return ;
}
char* addBinary(char* a, char* b) {
    int i, j;
    int len1=strlen(a), len2=strlen(b);
    int jinwei=0;
    swap(a);
    swap(b);
printf("a = %s\n", a);
printf("b = %s\n", b);
    
    return a;
}

int main(){
    int i, j;
    char a[20]="1010";
    char b[20]="1011";
    char *out;
    out=addBinary(a, b);
    printf("__out = %s__\n", out);

    return 0;
}