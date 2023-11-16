#include <stdio.h>
#include <stdlib.h>

int cmp(const void *e1, const void *e2){
    return (*(int *)e1 - *(int *)e2);
    //从小到大排序
}
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** threeSum(int* nums, int numsSize, int* returnSize, 
               int** returnColumnSizes){
    int i, j;
    int left=0, right=numsSize-1;
    int ** ret=(int **)malloc(sizeof(int*)*100000);
    int * tmp;

    *returnSize=0;



    qsort(nums, numsSize, sizeof(nums[0]), cmp);
    for(i=0;i<numsSize-1;i++)
    {
        if(nums[i]>0){
            *returnColumnSizes=(int *)malloc(sizeof(int)*(*returnSize));
            for(i=0;i<*returnSize;i++){
                (*returnColumnSizes)[i]=3;
            }
            return ret;
        }
        if(i>0 && (nums[i]==nums[i-1])){
            continue;
        }
        left=i+1;
        right=numsSize-1;
        while(left<right){
            if(nums[i]+nums[left]+nums[right]>0){
                right--;
            }
            else if(nums[i]+nums[left]+nums[right]<0){
                left++;
            }
            else{
                ret[*returnSize]=(int *)malloc(sizeof(int)*3);
                ret[*returnSize][0]=nums[i];
                ret[*returnSize][1]=nums[left];
                ret[*returnSize][2]=nums[right];
                // returnColumnSizes[*returnSize]=(int *)malloc(sizeof(int*));
                // returnColumnSizes[*returnSize]
                (*returnSize)++;
                while(right>left&&nums[right]==nums[right-1]) right--;
                while(left<right&&nums[left]==nums[left+1]) left++;
                right--;
                left++;
            }
        }
    }
    //这里之后需要再看看，returnColumnSizes是一个数组指针，不要再当成一个二维数组了
    //补充：
    //returnColumnSizes指向一个一维数组，然后(*returnColumnSizes)是一维数组的首地址
    
    *returnColumnSizes=(int *)malloc(sizeof(int)*(*returnSize));
    for(i=0;i<*returnSize;i++){
        (*returnColumnSizes)[i]=3;
    }
    return ret;
}
int main(){
    int i, j;
    int nums[6]={-1, 0, 1, 2, -1, -4};
    //int nums[3]={0,1,1};
    
    int returnSize=0;
    int **returnColumnSizes;
    int **output;
    output=threeSum(nums, 6, &returnSize, returnColumnSizes);
    for(i=0;i<returnSize;i++){
        for(j=0;j<(*returnColumnSizes)[i];j++){
            printf("%d ", output[i][j]);
        }
        printf("\n");
    }
    getchar();
    return 0;
}