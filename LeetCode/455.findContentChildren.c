#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int compare(const void *p1, const void *p2){
    return *(int *)p1-*(int *)p2;
}
int findContentChildren(int* g, int gSize, int* s, int sSize) {
    int count=0;
    int sIndex=0, gIndex=0;
    int i, j;
    qsort(g, gSize, sizeof(int), compare);
    qsort(s,sSize, sizeof(int), compare);
    // printf("g:");
    // for(gIndex=0;gIndex<gSize;gIndex++){
    //     printf("%d ", g[gIndex]);
    // }printf("\n");
    // printf("s:");
    // for(sIndex=0;sIndex<sSize;sIndex++){
    //     printf("%d ", s[sIndex]);
    // }printf("\n");
    for(sIndex=sSize-1;sIndex>=0;sIndex--){
        for(gIndex=gSize-1;gIndex>=0;gIndex--){
            //找到最大的符合人
            //把饼干和人都提出来
            if(s[sIndex]>=g[gIndex]){
                count++;
                sSize--;
                for(i=gIndex;i<gSize-1;i++){
                    g[i]=g[i+1];
                }
                gSize--;
                break;
            }
        }
        if(gIndex==-1){
            return count;
        }
        
    }
    return count;
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