#include <stdio.h>
#include <stdlib.h>
void deleteSpace(char* s, int index){
    int i, j;
    int gap=0;
    for(i=index+1;s[i]==' ';i++){
        gap++;
    }
    for(i=index+1;s[i+gap]!='\0';i++){
        s[i]=s[i+gap];
    }
    s[i]=s[i+gap];
}
void reversexy(char * s, int left, int right){
    int temp;
    while(left<=right){
        temp=s[left];
        s[left]=s[right];
        s[right]=temp;
        left++;
        right--;
    }
}
char* reverseWords(char* s) {
    int i, j, k;
    int slen=0;
    int index;
    int left, right;
    
    for(i=0;s[i]!='\0';i++){
        if(s[i]==' '){
            deleteSpace(s, i);
        }
        slen++;
    }
    if(s[slen-1]==' '){
        slen--;
        s[slen]='\0';
    }
    if(s[0]==' '){
        for(i=0;s[i+1]!='\0';i++){
            s[i]=s[i+1];
        }
        s[i]=s[i+1];
        slen--;
    }
    

    // printf("before=%s\n", s);
    // printf("slen = %d\n", slen);
    reversexy(s, 0, slen-1);
    // printf("after1=%s\n", s);

    for(i=0;i<slen;i++){
        if(s[i]!=' '){
            left=i;
            right=left;
            while(s[right]!='\0'){
                if(s[right]==' '){
                    break;
                }
                right++;
            }
            reversexy(s, left, right-1);
            i=right;
        }
    }
    // printf("%s\n", s);
    return s;
}
int main(){
    int i, j;
    char input[100]="the   sky   is blue    ";
    // char input[100]="  hello  world   ";
    int ilen=0, index;
    char * output;

    
    // while(input[ilen]!='\0'){
    //     ilen++;
    // }
    // printf("ilen = %d\n", ilen);
    // index=ilen-1;
    // while((index--)>0){
    //     if(input[index]==' '){
    //         for(i=index;input[i]!='\0';i++){
    //             input[i]=input[i+1];
    //         }
    //     }
    // }
    printf("%s\n", input);
    output=reverseWords(input);
    printf("%s\n", output);
    // getchar();
    return 0;
}