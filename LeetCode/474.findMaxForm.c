#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
/**
 * 给你一个二进制字符串数组 strs 和两个整数 m 和 n 。
请你找出并返回 strs 的最大子集的长度，该子集中 最多 有 m 个 0 和 n 个 1 。
如果 x 的所有元素也是 y 的元素，集合 x 是集合 y 的 子集 。

示例 1：
输入：strs = ["10", "0001", "111001", "1", "0"], m = 5, n = 3
输出：4
解释：最多有 5 个 0 和 3 个 1 的最大子集是 {"10","0001","1","0"} ，因此答案是 4 。
其他满足题意但较小的子集包括 {"0001","1"} 和 {"10","1","0"} 。
{"111001"} 不满足题意，因为它含 4 个 1 ，大于 n 的值 3 。

示例 2：
输入：strs = ["10", "0", "1"], m = 1, n = 1
输出：2
解释：最大的子集是 {"0", "1"} ，所以答案是 2 。

提示：
1 <= strs.length <= 600
1 <= strs[i].length <= 100
strs[i] 仅由 '0' 和 '1' 组成
1 <= m, n <= 100
*/
int findMaxForm(char** strs, int strsSize, int m, int n) {
    int i, j;
    int out;
    int zeroNum, oneNum;
    int strsIndex;
    /**
     * dp[i][j]表示最多有i个0，j个1的最大子集是多少
     * 01背包，对于当前str可以用前面的推出来
     * dp[i][j]=max(dp[i][j], dp[i-zeroNum][j-oneNum]+1)
    */
    int dp[m+1][n+1];
    memset(dp, 0, sizeof(dp));

    for(strsIndex=0;strsIndex<strsSize;strsIndex++){
        zeroNum=0, oneNum=0;
        for(j=0;strs[strsIndex][j]!='\0';j++){
            if(strs[strsIndex][j]=='0'){
                zeroNum++;
            }
            else if(strs[strsIndex][j]=='1'){
                oneNum++;
            }
            else{
                printf("Error!\n");
                return -1;
            }
        }
        for(i=m;i>=zeroNum;i--){
            for(j=n;j>=oneNum;j--){
                if(dp[i][j]>dp[i-zeroNum][j-oneNum]+1){
                    dp[i][j]=dp[i][j];
                }
                else{
                    dp[i][j]=dp[i-zeroNum][j-oneNum]+1;
                }
            }
        }
        // // log
        // printf("---------\n");
        // for(i=0;i<=m;i++){
        //     for(j=0;j<=n;j++){
        //         printf("%d ", dp[i][j]);
        //     }
        //     printf("\n");
        // }
    }
    
    return dp[m][n];
}

int main(){
    int i, j;
    // char strs[5][8]={"10", "0001", "111001", "1", "0"};
    int strsSize=5;
    int m=5, n=3;
    int out=-1;
    char **strs = (char **)malloc(sizeof(char *)*strsSize);
    strs[0]="10";
    strs[1]="0001";
    strs[2]="111001";
    strs[3]="1";
    strs[4]="0";
    
    out=findMaxForm(strs, strsSize, m, n);
    // for(i=0;i<strsSize;i++){
    //     for(j=0;strs[i][j]!='\0';j++){
    //         printf("%c", strs[i][j]);
    //     }
    //     printf("\n");
    // }
    printf("__out = %d__\n", out);

    return 0;
}