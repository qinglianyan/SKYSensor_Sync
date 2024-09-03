#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/**
 * 这个提交超时了，需要优化
*/
#define nMAX 50001
#define MAX(a,b) (a>b?a:b)
#define MIN(a,b) (a<b?a:b)
int maxConsecutiveAnswers(char* answerKey, int k) {
    int i, j;
    int len=strlen(answerKey);
    int left, right;
    int ttmp, ftmp;
    int ret=0;
    /**
     * 思路：前缀和
     * 记录[0,i]共有多少个True和False
    */
    int tcount[nMAX]={0};
    int fcount[nMAX]={0};
    int nowTnum=0;
    int nowFnum=0;

    tcount[0]=fcount[0]=0;
    for(i=1;i<=len;i++){
        if(answerKey[i-1]=='T'){
            nowTnum++;
        }
        else{
            nowFnum++;
        }
        tcount[i]=nowTnum;
        fcount[i]=nowFnum;
    }
// debug
printf("True count: ");
for(i=0;i<=len;i++){
    printf("%d ", tcount[i]);
}printf("\n");
printf("False count: ");
for(i=0;i<=len;i++){
    printf("%d ", fcount[i]);
}printf("\n");

    for(right=0;right<len;right++){
        for(left=0;left<=right;left++){
            ttmp=tcount[right+1]-tcount[left];
            ftmp=fcount[right+1]-fcount[left];
            if(MIN(ttmp,ftmp)<=k){
                ret=MAX(ret, right-left+1);
                break;
            }
        }
    }
    return ret;
}

int main(){
    int i, j;
    int out;
    char answerKey[20]="TFFT";
    int k=1;
    out=maxConsecutiveAnswers(answerKey, k);
    printf("__out = %d__\n", out);

    return 0;
}