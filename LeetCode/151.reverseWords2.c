#include <stdio.h>
#include <stdlib.h>
// 有问题，deleteSpace函数有越界访问

void reversexy(char * s, int left, int right){
    int temp;
    while(left<=right){
        temp=s[left];
        s[left]=s[right];
        s[right]=temp;
        left++;
        right--;
    }
    return ;
}
void deleteSpace(char* s){
    int i, j;
    int slow=0;
    for(i=0;s[i]!='\0';i++){
        if(s[i]!=' '){
            if(slow!=0){
                s[slow++]=' ';
            }
            while(s[i]!='\0'&&s[i]!=' '){
                s[slow++]=s[i++];
            }
        }
    }
    s[slow]='\0';
    printf("delete =%s\n", s);
}
char* reverseWords(char* s){
    int i, j;
    int len, start;
    deleteSpace(s);
    len=0;
    while(s[len]!='\0'){
        len++;
    }
    printf("||%s||\n", s);
    printf("len=%d\n", len);

    reversexy(s, 0, len-1);
    start=0;
    for(i=0;i<=len;i++){
        if(i==len||s[i]==' '){
            reversexy(s, start, i-1);
            start=i+1;
        }
    }
return s;
}
int main(){
    int i, j;
    // char input[100]="the   sky   is blue    ";
    char input[100]="  hello  world   ";
    // char input[100]="a good    example";
    int ilen=0, index;
    char * output;

    
    printf("input=||%s||\n", input);
    output=reverseWords(input);
    printf("output==||%s||\n", output);
    getchar();
    return 0;
}