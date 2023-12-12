#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define TICKETS_MAX 301

char path[TICKETS_MAX][4];
int pathTop=0;
int used[TICKETS_MAX];
bool find=false;

int cmp(const void *str1, const void *str2)
{
    /**
     * 作者：lsm
     * 链接：https://leetcode.cn/problems/reconstruct-itinerary/solutions/2463279/332-by-lsm-63-4z5b/
     * 来源：力扣（LeetCode）
     * 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
    */
    const char **tmp1 = *(char**)str1;
    const char **tmp2 = *(char**)str2;
    int ret = strcmp(tmp1[0], tmp2[0]);
    if (ret == 0) {
        return strcmp(tmp1[1], tmp2[1]);
    }

    return ret;
}

void backstacking(char ***tickets, int ticketsSize, 
                int *ticketsColSize, char **out, char *now, int *returnSize){
    int i, j;
    if(pathTop==ticketsSize+1){
        // for(i=0;i<pathTop;i++){
        //     printf("%s ", (path[i]));
        // }
        // printf("\n");
        (*returnSize)=pathTop;
        
        for(i=0;i<pathTop;i++){
            out[i]=(char *)malloc(sizeof(char )*4);
            strcpy(out[i], (path[i]));
        }
        find=true;
        return ;
    }
    // 单步循环
    for(i=0;i<ticketsSize;i++){
        if(find==true){
            break;
        }
        if(used[i]==1){
            continue;
        }
        // 下面这个if是过80 81的关键
        if(i>0 && strcmp(tickets[i][0], tickets[i-1][0])==0 && 
                  strcmp(tickets[i][1], tickets[i-1][1])==0 && used[i]==0){
            continue;
        }
        if(strcmp(now, tickets[i][0])==0){
            strcpy(path[pathTop++], tickets[i][1]);
            used[i]=1;
            backstacking(tickets, ticketsSize, ticketsColSize, out, tickets[i][1], returnSize);
            used[i]=0;
            pathTop--;
        }
        else{
            continue;
        }
    }

    return ;
}

char** findItinerary(char*** tickets, int ticketsSize, 
                    int* ticketsColSize, int* returnSize) {
    int i, j;
    char **out;
    // init
    (*returnSize)=0;
    pathTop=0;
    find=false;
    memset(used, 0, sizeof(used));

    if(ticketsSize<=0){
        printf("ticketsSize Error!\n");
        return NULL;
    }
    qsort(tickets, ticketsSize, sizeof(tickets[0]), cmp);
    out=(char **)malloc(sizeof(char *)*(ticketsSize+1));
    
    strcpy(path[pathTop++], "JFK");
    // printf("%s\n", path[pathTop-1]);
    backstacking(tickets, ticketsSize, ticketsColSize, out, path[pathTop-1], returnSize);
    return out;
}

int main(){
    int i, j, k;
    int *returnSize=(int *)malloc(sizeof(int ));
    char **out;
    int num;
    // 测试 用例1
    char ***tickets=(char ***)malloc(sizeof(char **)*5);
    // char tickets[5][2][5]={{"JFK", "SFO"}, {"JFK", "ATL"}, 
    //         {"SFO", "ATL"}, {"ATL", "JFK"}, {"ATL", "SFO"}};
    int ticketsSize=5;
    int ticketColSize[5]={2, 2, 2, 2, 2};
    
    for(i=0;i<ticketsSize;i++){
        tickets[i]=(char **)malloc(sizeof(char *)*2);
        tickets[i][0]=(char *)malloc(sizeof(char )*5);
        tickets[i][1]=(char *)malloc(sizeof(char )*5);
    }
    strcpy(tickets[0][0],"JFK");strcpy(tickets[0][1],"SFO");
    strcpy(tickets[1][0],"JFK");strcpy(tickets[1][1],"ATL");
    strcpy(tickets[2][0],"SFO");strcpy(tickets[2][1],"ATL");
    strcpy(tickets[3][0],"ATL");strcpy(tickets[3][1],"JFK");
    strcpy(tickets[4][0],"ATL");strcpy(tickets[4][1],"SFO");
    // 测试 用例1 end

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

    // // 测试 用例3
    // char ***tickets=(char ***)malloc(sizeof(char **)*10);
    // // char tickets[][][]={{"MUC", "LHR"}, {"JFK", "MUC"}, 
    // //         {"SFO", "SJC"}, {"LHR", "SFO"}};
    // int ticketsSize=10;
    // int ticketColSize[10]={2, 2, 2, 2, 2, 2, 2, 2, 2, 2};
    
    // for(i=0;i<ticketsSize;i++){
    //     tickets[i]=(char **)malloc(sizeof(char *)*2);
    //     tickets[i][0]=(char *)malloc(sizeof(char )*5);
    //     tickets[i][1]=(char *)malloc(sizeof(char )*5);
    // }
    // strcpy(tickets[0][0],"EZE");strcpy(tickets[0][1],"AXA");
    // strcpy(tickets[1][0],"TIA");strcpy(tickets[1][1],"ANU");
    // strcpy(tickets[2][0],"ANU");strcpy(tickets[2][1],"JFK");
    // strcpy(tickets[3][0],"JFK");strcpy(tickets[3][1],"ANU");
    // strcpy(tickets[4][0],"ANU");strcpy(tickets[4][1],"EZE");
    // strcpy(tickets[5][0],"TIA");strcpy(tickets[5][1],"ANU");
    // strcpy(tickets[6][0],"AXA");strcpy(tickets[6][1],"TIA");
    // strcpy(tickets[7][0],"TIA");strcpy(tickets[7][1],"JFK");
    // strcpy(tickets[8][0],"ANU");strcpy(tickets[8][1],"TIA");
    // strcpy(tickets[9][0],"JFK");strcpy(tickets[9][1],"TIA");
    // // 测试 用例3 end
    *returnSize=0;
    // for(i=0;i<ticketsSize;i++){
    //     for(j=0;j<ticketColSize[i];j++){
    //         printf("%s ", tickets[i][j]);
    //     }printf("\n");
    // }

    out=findItinerary(tickets, ticketsSize, ticketColSize, returnSize);
    
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
