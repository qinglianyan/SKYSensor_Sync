#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

/**
 * 给定字符串 s 和 t ，判断 s 是否为 t 的子序列。
 * 字符串的一个子序列是原始字符串删除一些（也可以不删除）字符而不改变剩余字符相对位置形成的新字符串。（例如，"ace"是"abcde"的一个子序列，而"aec"不是）。
示例 1：
输入：s = "abc", t = "ahbgdc"
输出：true

示例 2：
输入：s = "axc", t = "ahbgdc"
输出：false

提示：
0 <= s.length <= 100
0 <= t.length <= 10^4
两个字符串都只由小写字符组成
*/

bool isSubsequence(char* s, char* t) {
    int i, j;
    int soff=0, toff=0;
    while(s[soff]!='\0'){
        while(t[toff]!=s[soff]){
            if(t[toff]=='\0'){
                return false;
            }
            toff++;
        }
        toff++;
        soff++;
    }

    return true;
}


int main(){
    char *s, *t;
    s=(char *)malloc(sizeof(char)*4);
    strcpy(s, "abc");
    t=(char *)malloc(sizeof(char )*7);
    strcpy(t, "ahbgdc");
    printf("s = %s\n", s);
    printf("t = %s\n", t);
    if(isSubsequence(s, t)){
        printf("TRUE\n");
    }
    else{
        printf("FALSE\n");
    }
    return 0;
}