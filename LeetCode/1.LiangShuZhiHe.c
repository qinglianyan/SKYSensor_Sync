#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//����һ���������� nums ��һ������Ŀ��ֵ target,
//�����ڸ��������ҳ� ��ΪĿ��ֵ target ��������������
//���������ǵ������±� 
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int i, j;
    *returnSize=2;
//    int returned[2];
	int* returned=(int *)malloc(sizeof(int)*2);

    for(i=0;i<numsSize-1;i++){
        for(j=i+1;j<numsSize;j++){
            if(nums[i]+nums[j]==target){
                returned[0]=i;
                returned[1]=j;
                return returned;
            }
        }
    }
    *returnSize=0;
    return NULL;
}

int main(){
	int nums[4]={2, 7, 11, 15};
	int i;
	int* ret;
	int* retSize=(int *)malloc(sizeof(int));
	*retSize=2;
//	for(i=0;i<4;i++){
//		printf("%d ", nums[i]);
//	}
	ret=twoSum(nums, 4, 9, retSize);
	for(i=0;i<2;i++){
		printf("%d ", ret[i]);
	}
	return 0;
}
