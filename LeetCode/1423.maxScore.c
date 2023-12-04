#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int maxScore(int* cardPoints, int cardPointsSize, int k) {
    int preCount[cardPointsSize];
    int lastCount[cardPointsSize];
    int preCounts=0, lastCounts=0;
    int max, tmp;
    int i, j;
    int left, right;

    memset(preCount, cardPointsSize, sizeof(int)*cardPointsSize);
    memset(lastCount, cardPointsSize, sizeof(int)*cardPointsSize);
    for(i=0;i<cardPointsSize;i++){
        preCounts+=cardPoints[i];
        lastCounts+=cardPoints[cardPointsSize-1-i];
        preCount[i]=preCounts;
        lastCount[cardPointsSize-1-i]=lastCounts;
    }

    printf("preCount:\n");
    for(i=0;i<cardPointsSize;i++){
        printf("%d ", preCount[i]);
    }printf("\n");
    printf("lastCount:\n");
    for(i=0;i<cardPointsSize;i++){
        printf("%d ", lastCount[i]);
    }printf("\n");

    max=lastCount[cardPointsSize-k];
    tmp=0;
    for(i=0;i<=k;i++){
        //左边有i个，右边有k-i个
        if(i==0){//全在右边
            if(lastCount[cardPointsSize-k]>max){
                max=lastCount[cardPointsSize-k];
            }
        }
        else if(i==k){//全在左边
            if(preCount[k-1]>max){
                max=preCount[k-1];
            }
        }
        else{
            tmp=preCount[i-1]+lastCount[cardPointsSize-k+i];
            if(tmp>max){
                max=tmp;
            }
        }
        
    }
    return max;
}
int main(){
    int cardPoints[7]={1, 2, 3, 4, 5, 6, 1};
    int cardPointsSize=7;
    int k=3;
    int out=0;

    out=maxScore(cardPoints, cardPointsSize, k);
    printf("out = %d\n", out);
    return 0;
}