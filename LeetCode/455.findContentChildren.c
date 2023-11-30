#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int findContentChildren(int* g, int gSize, int* s, int sSize) {
    
}

int main(){
    // int g[3]={1, 2, 3};
    // int s[2]={1, 1};
    // int gSize=3, sSize=2;

    int g[2]={1, 2};
    int s[3]={1, 2, 3};
    int gSize=2, sSize=3;

    int out=-1;
    out=findContentChildren(g, gSize, s, sSize);
    printf("out = %d\n", out);
    return 0;
}