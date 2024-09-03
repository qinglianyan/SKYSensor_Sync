#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool checkRecord(char* s) {
    int i, j;
    int Acount=0;
    int Lcount=0;
    int len=strlen(s);
    
    for(i=0;i<len;i++){
        if(s[i]!='L'){
            Lcount=0;
        }
        else if(s[i]=='L'){
            Lcount++;
        }
        if(s[i]=='A'){
            Acount++;
        }
        if(Acount>=2 || Lcount>=3){
            return false;
        }
    }
    return true;
}

int main(){
    int i, j;
    bool out;
    char s[50]="PPALLP";
    // char s[50]="PPALLL";
    out=checkRecord(s);
    if(out){
        printf("__out = TRUE__\n");
    }
    else{
        printf("__out = FALSE__\n");
    }
    return 0;
}