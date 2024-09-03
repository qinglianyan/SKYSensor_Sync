#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int busyStudent(int* startTime, int startTimeSize, 
                int* endTime, int endTimeSize, int queryTime) {
    int i, j;
    int count=0;
    for(i=0;i<startTimeSize;i++){
        if(startTime[i]<=queryTime && endTime[i]>=queryTime){
            count++;
        }
    }
    return count;
}

int main(){
    int i, j;
    int out=0;
    int startTimeSize=9;
    int endTimeSize=9;
    int startTime[9]={9,8,7,6,5,4,3,2,1};
    int endTime[9]={10,10,10,10,10,10,10,10,10};
    int queryTime=5;
    
    out=busyStudent(startTime, startTimeSize, endTime, endTimeSize, queryTime);
    printf("__out = %d__\n", out);

    return 0;
}