#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int threeSumClosest(int* nums, int numsSize, int target){
    if(numsSize<3){
        return 0;
    }
    return 0；
}

int main(){
    int input[4]={-1, 2, 1, -4};
    int i, j;
    int target=1;
    int output=0;
    output=threeSumClosest(input, 4, target);
    printf("%d \n", output);
    // for(i=0;i<4;i++){
    //     printf("%d ", input[i]);
    // }

    return 0;
}