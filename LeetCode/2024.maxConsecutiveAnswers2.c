#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/**
 * 滑动窗口
*/
#define nMAX 50001
#define MAX(a,b) (a>b?a:b)
#define MIN(a,b) (a<b?a:b)
int maxConsecutiveAnswers(char* answerKey, int k) {
    int i, j;
    int len=strlen(answerKey);
    int Fcount=0, Tcount=0;
    int left, right;
    int maxLen=0;
    
    for(left=0, right=0;right<len;right++){
        if(answerKey[right]=='F'){
            Fcount++;
        }
        else if(answerKey[right]=='T'){
            Tcount++;
        }
        while(MIN(Fcount, Tcount)>k){
            if(answerKey[left]=='F'){
                Fcount--;
            }
            else if(answerKey[left]=='T'){
                Tcount--;
            }
            left++;
        }
        maxLen=MAX(maxLen, right-left+1);
    }

    return maxLen;
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