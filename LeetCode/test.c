#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){
   char name[100];
   printf("What is your name?\n");
   scanf("%s",name);
   printf("Hello,%s,nice to meet you!\n",name);
}