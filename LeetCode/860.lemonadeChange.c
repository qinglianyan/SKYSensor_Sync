#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool lemonadeChange(int* bills, int billsSize) {
    bool out=false;
    int i, j;
    int m5=0, m10=0;
    for(i=0;i<billsSize;i++){
        if(bills[i]==5){
            m5++;
        }
        else if(bills[i]==10){ // 找回5块
            m5--;
            m10++;
            if(m5<0) return false;
        }
        else if(bills[i]==20){ // 找回15块
        // 10+5
        // 5+5+5
            if(m10>=1&&m5>=1){
                m10--;
                m5--;
            }
            else if(m5>=3){
                m5-=3;
            }
            else{
                return false;
            }
        }
        else{
            printf("Error Number!\n");
            return false;
        }
    }

    return true;
}

int main(){
    int i, j;
    int bills[]={5, 5, 5, 10, 20};
    int billsSize=5;
    bool out=false;

    out=lemonadeChange(bills, billsSize);
    if(out) printf("True\n");
    else printf("False\n");
    return 0;
}