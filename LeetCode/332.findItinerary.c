#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define HASH_MAX 17578  //26*26*26=17576
// #define LIST_MAX 680    //26*26=676
#define HASH_PLINE 26

struct Node{
    int val;
    struct Node *next;
};
int path[300][5];
int pathTop=0;
int hash[HASH_PLINE][HASH_PLINE];
int StrToNum(char *s){
    int slen=strlen(s);
    if(slen!=3){
        printf("Str LEN != 3, Error!\n");
        return -1;
    }
    return (s[0]-'A'+1)*HASH_PLINE*HASH_PLINE+(s[1]-'A'+1)*HASH_PLINE+(s[2]-'A'+1);
}
char *NumToStr(int in){
    char *ret=(char *)malloc(sizeof(char )*4);
    ret[3]='\0';
    ret[2]=(in%HASH_PLINE)-1+'A';
    in/=HASH_PLINE;
    ret[1]=(in%HASH_PLINE)-1+'A';
    in/=HASH_PLINE;
    ret[0]=(in%HASH_PLINE)-1+'A';
    return ret;
}
void backstacking(){
    int i, j;
    
}

char** findItinerary(char*** tickets, int ticketsSize, 
                    int* ticketsColSize, int* returnSize) {
    int i, j;
    char **out;
    int numTmp1, numTmp2;
    (*returnSize)=0;
    pathTop=0;
    if(ticketsSize<=0){
        printf("ticketsSize Error!\n");
        return NULL;
    }
    for(i=0;i<ticketsSize;i++){
        numTmp1=StrToNum(tickets[i][0]);
        numTmp2=StrToNum(tickets[i][1]);
        hash[numTmp1][numTmp2]=1;
        // 这里还能优化吗
    }
    

    return out;
}

int main(){
    int i, j, k;
    char tickets[5][2][5]={{"JFK", "SFO"}, {"JFK", "ATL"}, 
            {"SFO", "ATL"}, {"ATL", "JFK"}, {"ATL", "SFO"}};
    int ticketsSize=5;
    int ticketColSize[5]={2, 2, 2, 2, 2};
    int *returnSize=(int *)malloc(sizeof(int ));
    char **out;
    // For Test
        int num=0;
    // End
    *returnSize=0;

    // printf("%s , %s ", tickets[0][0], tickets[1][0]);
    
    // Test
        num=StrToNum(tickets[0][0]);
        printf("num = %d\n", num);
        printf("back = %s\n", NumToStr(num));
    // End 

    out=findItinerary(tickets, ticketsSize, ticketColSize, returnSize);
    for(i=0;i<(*returnSize);i++){
        printf("%s ", out[i]);
    }
    return 0;
}