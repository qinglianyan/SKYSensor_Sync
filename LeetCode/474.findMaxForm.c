#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int findMaxForm(char** strs, int strsSize, int m, int n) {
    return 0;
}

int main(){
    int i, j;
    char strs[5][8]={"10", "0001", "111001", "1", "0"};
    int strsSize=5;
    int m=5, n=3;
    int out=-1;
    out=findMaxForm(strs, strsSize, m, n);
    for(i=0;i<strsSize;i++){
        printf("%s\n", strs[i]);
    }

    return 0;
}