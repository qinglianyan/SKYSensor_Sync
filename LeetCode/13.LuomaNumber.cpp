#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// 罗马数字包含以下七种字符:
//  I， V， X，  L，  C，   D     M。
//  1， 5， 10， 50， 100， 500， 1000、
// 例如， 罗马数字 2 写做 II ，即为两个并列的 1 。12 写做 XII ，即为 X + II 。 27 写做  XXVII, 即为 XX + V + II 。
// 通常情况下，罗马数字中小的数字在大的数字的右边。但也存在特例，例如 4 不写做 IIII，而是 IV。数字 1 在数字 5 的左边，所表示的数等于大数 5 减小数 1 得到的数值 4 。同样地，数字 9 表示为 IX。这个特殊的规则只适用于以下六种情况：
// I 可以放在 V (5) 和 X (10) 的左边，来表示 4 和 9。
// X 可以放在 L (50) 和 C (100) 的左边，来表示 40 和 90。 
// C 可以放在 D (500) 和 M (1000) 的左边，来表示 400 和 900。
// 给定一个罗马数字，将其转换成整数。

//如果碰到I，判断后一位是不是V X
//如果碰到X，判断后一位是不是L C
//如果碰到C，判断后一位是不是D M
int romanToInt_1(char * s){
   // puts(s);
   // return 0;
   int i, j;
   int sum=0;
   // for(i=0;s[i]!='\0';i++){
   //    printf("i=%d : %c %d\n", i, s[i], s[i]=='I');
   // }
   for(i=0,j=1;s[i]!='\0';i++,j++){
      if(s[i]=='M'){
         sum+=1000;
      }
      else if(s[i]=='D'){
         sum+=500;
      }
      else if(s[i]=='C'){
         // sum+=100;
         if(s[j]=='D'){
            sum+=400;
            i++;j++;
         }
         else if(s[j]=='M'){
            sum+=900;
            i++;j++;
         }
         else{
            sum+=100;
         }
      }
      else if(s[i]=='L'){
         sum+=50;
      }
      else if(s[i]=='X'){
         // sum+=10;
         if(s[j]=='L'){
            sum+=40;
            i++;j++;
         }
         else if(s[j]=='C'){
            sum+=90;
            i++;j++;
         }
         else{
            sum+=10;
         }
      }
      else if(s[i]=='V'){
         sum+=5;
      }
      else if(s[i]=='I'){
         // sum+=1;
         if(s[j]=='V'){
            sum+=4;
            i++;j++;
         }
         else if(s[j]=='X'){
            sum+=9;
            i++;j++;
         }
         else{
            sum+=1;
         }
      }
      else{
         return 0;
      }
   }
   printf("%d", sum);
   return sum;
}
//如果碰到I X C的话，如果后一位比他们大，那么就是直接变成负号
int romanToInt(char * s){
   // puts(s);
   // return 0;
   int i, j;
   int sum=0;
   // for(i=0;s[i]!='\0';i++){
   //    printf("i=%d : %c %d\n", i, s[i], s[i]=='I');
   // }
   for(i=0,j=1;s[i]!='\0';i++,j++){
      if(s[i]=='M'){
         sum+=1000;
      }
      else if(s[i]=='D'){
         sum+=500;
      }
      else if(s[i]=='C'){
         // sum+=100;
         if(s[j]=='D'||s[j]=='M'){
            sum-=100;
         }
         else{
            sum+=100;
         }
      }
      else if(s[i]=='L'){
         sum+=50;
      }
      else if(s[i]=='X'){
         // sum+=10;
         if(s[j]=='L'||s[j]=='C'){
            sum-=10;
         }
         else{
            sum+=10;
         }
      }
      else if(s[i]=='V'){
         sum+=5;
      }
      else if(s[i]=='I'){
         // sum+=1;
         if(s[j]=='V'||s[j]=='X'){
            sum-=1;
         }else{
            sum+=1;
         }
      }
      else{
         return 0;
      }
   }
   printf("%d", sum);
   return sum;
}
int main(){
   // char name[]="III";
   // char name[]="IV";
   char name[]="MCMXCIV";

   // int i;
   // puts(name);
   // printf("%s\n", name);
   // for(i=0;name[i]!='\0';i++){
   //    printf("i=%d : %c\n", i, name[i]);
   // }
   romanToInt(name);
   return 0;
}