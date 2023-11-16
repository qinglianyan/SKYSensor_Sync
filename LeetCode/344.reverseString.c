#include <stdio.h>
#include <stdlib.h>

void reverseString(char* s, int sSize) {
    int i, j;
    int left=0, right=sSize-1;
    char temp;
    while(left<right){
        temp=s[right];
        s[right]=s[left];
        s[left]=temp;
        left++;
        right--;
    }
    return;
}
int main(){
    char ch[10]="hello";
    int len;
    int i, j;
    for(i=0;i<sizeof(ch);i++){
        if(ch[i]=='\0'){
            len=i;
            break;
        }
    }
    printf("ch : %s\n", ch);
    reverseString(ch, len);
    printf("ch : %s\n", ch);
    getchar();
    return 0;
}