#include <stdio.h>
#include <stdlib.h>
#define square(a) (a)*(a)

int main(){
    int x=6;
    printf("out = %d\n", square(x+1));
    return 0;
}