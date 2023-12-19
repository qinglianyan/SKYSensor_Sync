#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
int before(int Size, int i){
    if(i<0){
        printf("Error : I\n");
        return -1;
    }
    else if(i>0){
        return i-1;
    }
    else{   // i==0
        return Size-1;
    }
}
int next(int Size, int i){
    if(i<0||i>=Size){
        printf("Error : I\n");
        return -1;
    }
    else if(i==Size-1){
        return 0;
    }
    else{   //[0, Size)
        return i+1;
    }
}
int canCompleteCircuit(int* gas, int gasSize, int* cost, int costSize) {
    int out=0;
    int left[gasSize];
    int i, j;
    int total=0;
    int begin, end;

    for(i=0;i<gasSize;i++){
        left[i]=gas[i]-cost[i];
        total+=left[i];
    }
    if(total<0){
        return -1;
    }

    begin=0, end=0;
    total=left[begin];
    if(total>=0){   // end++
        end=next(gasSize, end);
        total+=left[end];
    }
    else{   // total < 0; begin--
        begin=before(gasSize, begin);
        total+=left[begin];
    }
    while(begin!=end){
        if(total>=0){   // end++
            end=next(gasSize, end);
            total+=left[end];
        }
        else{   // total < 0; begin--
            begin=before(gasSize, begin);
            total+=left[begin];
        }
    }

    return begin;
}

int main(){
    int gas[]={1, 2, 3, 4, 5};
    int cost[]={3, 4, 5, 1, 2};
    int gasSize=5, costSize=5;
    int out=0;

    out=canCompleteCircuit(gas, gasSize, cost, costSize);
    printf("out = %d\n", out);
    return 0;
}