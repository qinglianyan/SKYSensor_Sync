#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_N 30
int fib(int n){
    int i, j, out;
    int nums[MAX_N+1];
    out=0;

    nums[0]=0, nums[1]=1;
    if(n<=1) return nums[n];
    else{
        for(i=2;i<=n;i++){
            nums[i]=nums[i-1]+nums[i-2];
        }
        return nums[n];
    }
}

int main(){
    int n, out, i, j;
    printf("n = ");
    scanf("%d", &n);
    printf("input n = %d\n", n);
    out=fib(n);
    printf("out = %d\n", out);
    return 0;
}