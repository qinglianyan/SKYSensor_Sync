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
#define NODE_MAX 301
struct NextNode{
    int nVal;
    struct NextNode *next;
};
struct Node{
    int val;
    struct NextNode *pnode;
    // int next[300];
    // int nextTop;
};
int path[301];
int pathTop=0;
int hash[HASH_MAX][HASH_MAX];
struct Node NodeStore[NODE_MAX];
int storeTop=0;
bool find=false;

bool pnodeEmpty(struct NextNode *pnode){
    return pnode==NULL;
}
void pnodePush(struct NextNode *pnode, struct NextNode *in){
    struct NextNode *tmp;
    if(pnodeEmpty(pnode)==true){
        pnode=in;
        return ;
    }
    else{
        tmp=pnode;
        if(tmp->nVal>in->nVal){
            in->next=tmp->next;
            tmp=in;
            return ;
        }
        while(tmp->next!=NULL){
            if(tmp->next->nVal>pnode->nVal){
                pnode->next=tmp->next;
                tmp->next=pnode;
                return ;
            }
        }
    }
}

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
    // ret[2]=(in%HASH_PLINE)-1+'A';
    if((in%HASH_PLINE)==0){
        ret[2]='Z';
        in/=HASH_PLINE;
        in--;
    }
    else{
        ret[2]=(in%HASH_PLINE)-1+'A';
        in/=HASH_PLINE;
    }
    if((in%HASH_PLINE)==0){
        ret[1]='Z';
        in/=HASH_PLINE;
        in--;
    }
    else{
        ret[1]=(in%HASH_PLINE)-1+'A';
        in/=HASH_PLINE;
    }
    ret[0]=(in%HASH_PLINE)==0?'Z':(in%HASH_PLINE)-1+'A';
    return ret;
}
void backstacking(char ***tickets, int ticketsSize, 
                int *ticketsColSize, char **out, int now, int *returnSize){
    int i, j;
    if(find==true){
        return;
    }
    if(pathTop==ticketsSize+1){
        // for(i=0;i<pathTop;i++){
        //     printf("%s ", NumToStr(path[i]));
        // }
        // printf("\n");
        (*returnSize)=pathTop;
        
        for(i=0;i<pathTop;i++){
            out[i]=(char *)malloc(sizeof(char )*5);
            strcpy(out[i], NumToStr(path[i]));
        }
        find=true;
        return ;
    }
    for(i=0;i<HASH_MAX;i++){
        if(find==true){
            break;
        }
        if(hash[now][i]>=1){
            path[pathTop++]=i;
            hash[now][i]-=1;
            backstacking(tickets, ticketsSize, ticketsColSize, out, i, returnSize);
            hash[now][i]+=1;
            pathTop--;
        }
    }
    return ;
}

char** findItinerary(char*** tickets, int ticketsSize, 
                    int* ticketsColSize, int* returnSize) {
    int i, j;
    char **out;
    int numTmp1, numTmp2, numTmp;
    // init
    (*returnSize)=0;
    pathTop=0;
    find=false;
    memset(hash, 0, HASH_MAX*HASH_MAX);

    if(ticketsSize<=0){
        printf("ticketsSize Error!\n");
        return NULL;
    }
    
    out=(char **)malloc(sizeof(char *)*(ticketsSize+1));
    for(i=0;i<NODE_MAX;i++){
        NodeStore[i].val=0;
        NodeStore[i].pnode=NULL;
    }
    for(i=0;i<ticketsSize;i++){
        numTmp1=StrToNum(tickets[i][0]);
        numTmp2=StrToNum(tickets[i][1]);
        hash[numTmp1][numTmp2]+=1;
        for(j=0;j<storeTop;j++){
            if(numTmp1==NodeStore[j].val){

            }
        }
        if(j==storeTop){
            
        }
        NodeStore[storeTop].val=numTmp1;
        
        storeTop++;

        // 这里还能优化吗
    }
    numTmp=StrToNum("JFK");
    path[pathTop++]=numTmp;
    backstacking(tickets, ticketsSize, ticketsColSize, out, numTmp, returnSize);
    for(i=0;i<ticketsSize;i++){
        numTmp1=StrToNum(tickets[i][0]);
        numTmp2=StrToNum(tickets[i][1]);
        hash[numTmp1][numTmp2]=0;
        // 这里还能优化吗
    }
    return out;
}

int main(){
    int i, j, k;
    int *returnSize=(int *)malloc(sizeof(int ));
    char **out;
    int num;
    // // 测试 用例1
    // char ***tickets=(char ***)malloc(sizeof(char **)*5);
    // // char tickets[5][2][5]={{"JFK", "SFO"}, {"JFK", "ATL"}, 
    // //         {"SFO", "ATL"}, {"ATL", "JFK"}, {"ATL", "SFO"}};
    // int ticketsSize=5;
    // int ticketColSize[5]={2, 2, 2, 2, 2};
    
    // for(i=0;i<ticketsSize;i++){
    //     tickets[i]=(char **)malloc(sizeof(char *)*2);
    //     tickets[i][0]=(char *)malloc(sizeof(char )*5);
    //     tickets[i][1]=(char *)malloc(sizeof(char )*5);
    // }
    // strcpy(tickets[0][0],"JFK");strcpy(tickets[0][1],"SFO");
    // strcpy(tickets[1][0],"JFK");strcpy(tickets[1][1],"ATL");
    // strcpy(tickets[2][0],"SFO");strcpy(tickets[2][1],"ATL");
    // strcpy(tickets[3][0],"ATL");strcpy(tickets[3][1],"JFK");
    // strcpy(tickets[4][0],"ATL");strcpy(tickets[4][1],"SFO");
    // // 测试 用例1 end

    // // 测试 用例2
    // char ***tickets=(char ***)malloc(sizeof(char **)*4);
    // // char tickets[][][]={{"MUC", "LHR"}, {"JFK", "MUC"}, 
    // //         {"SFO", "SJC"}, {"LHR", "SFO"}};
    // int ticketsSize=4;
    // int ticketColSize[4]={2, 2, 2, 2, 2};
    
    // for(i=0;i<ticketsSize;i++){
    //     tickets[i]=(char **)malloc(sizeof(char *)*2);
    //     tickets[i][0]=(char *)malloc(sizeof(char )*5);
    //     tickets[i][1]=(char *)malloc(sizeof(char )*5);
    // }
    // strcpy(tickets[0][0],"MUC");strcpy(tickets[0][1],"LHR");
    // strcpy(tickets[1][0],"JFK");strcpy(tickets[1][1],"MUC");
    // strcpy(tickets[2][0],"SFO");strcpy(tickets[2][1],"SJC");
    // strcpy(tickets[3][0],"LHR");strcpy(tickets[3][1],"SFO");
    // // 测试 用例2 end

    // 测试 用例3
    char ***tickets=(char ***)malloc(sizeof(char **)*10);
    // char tickets[][][]={{"MUC", "LHR"}, {"JFK", "MUC"}, 
    //         {"SFO", "SJC"}, {"LHR", "SFO"}};
    int ticketsSize=10;
    int ticketColSize[10]={2, 2, 2, 2, 2, 2, 2, 2, 2, 2};
    
    for(i=0;i<ticketsSize;i++){
        tickets[i]=(char **)malloc(sizeof(char *)*2);
        tickets[i][0]=(char *)malloc(sizeof(char )*5);
        tickets[i][1]=(char *)malloc(sizeof(char )*5);
    }
    strcpy(tickets[0][0],"EZE");strcpy(tickets[0][1],"AXA");
    strcpy(tickets[1][0],"TIA");strcpy(tickets[1][1],"ANU");
    strcpy(tickets[2][0],"ANU");strcpy(tickets[2][1],"JFK");
    strcpy(tickets[3][0],"JFK");strcpy(tickets[3][1],"ANU");
    strcpy(tickets[4][0],"ANU");strcpy(tickets[4][1],"EZE");
    strcpy(tickets[5][0],"TIA");strcpy(tickets[5][1],"ANU");
    strcpy(tickets[6][0],"AXA");strcpy(tickets[6][1],"TIA");
    strcpy(tickets[7][0],"TIA");strcpy(tickets[7][1],"JFK");
    strcpy(tickets[8][0],"ANU");strcpy(tickets[8][1],"TIA");
    strcpy(tickets[9][0],"JFK");strcpy(tickets[9][1],"TIA");
    // 测试 用例3 end
    *returnSize=0;
    // for(i=0;i<ticketsSize;i++){
    //     for(j=0;j<ticketColSize[i];j++){
    //         printf("%s ", tickets[i][j]);
    //     }printf("\n");
    // }
    // for(i=0;i<ticketsSize;i++){
    //     printf("%s = %d\n", tickets[i][0], StrToNum(tickets[i][0]));
    // }

    num=StrToNum("EZE");
    printf("\nEZE = %d\n", num);
    printf("back = %s\n", NumToStr(num));

    // out=findItinerary(tickets, ticketsSize, ticketColSize, returnSize);
    
    for(i=0;i<(*returnSize);i++){
        printf("%s ", out[i]);
    }

    return 0;
}


// bool nextEmpty(int *next, int nextTop){
//     return nextTop==0;
// }
// void nextPush(int *next, int nextTop, int in){
// // 要求从小到大排序
//     int i,j;
//     int mark=0;
//     if(nextEmpty(next, nextTop)==true){
//         next[nextTop++]=in;
//     }
//     else{
//         for(mark=0;mark<nextTop;mark++){
//             if(next[mark]>in){
//                 break;
//             }
//         }
//         if(mark==nextTop){
//             next[nextTop++]=in;
//         }
//         else{
//             for(i=mark+1;i<nextTop+1;i++){
//                 next[i]=next[i-1];
//             }
//             next[mark]=in;
//         }
//     }
//     return ;
// }