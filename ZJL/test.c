#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// char InFileName1[255]="D:\\SoftwareDoc\\VSCodeWorkplace\\Native\\sourceCode\\ZJL\\testText.txt";

bool contains_chinese(const char *str) {
    while (*str != '\0') {
        unsigned int ch = *str;
        // 对于非ASCII字符，使用UTF-8编码，中文字符至少占用3个字节
        if (ch >> 7) { // 判断最高位，如果是1则是非ASCII字符
            // 取出前三个字节的头部
            unsigned int head = (ch & 0xE0) >> 5;
            // 如果属于中文字符的UTF-8编码头部范围，则可能是中文字符
            if (head >= 0x05 && head <= 0x15) {
                return true;
            }
            // 对于可能的四字节UTF-8编码，取出后三个字节的头部
            if ((ch & 0xF0) == 0xF0 && (str[1] & 0x80) && (str[2] & 0x80) && (str[3] & 0x80)) {
                // 取出后三个字节的头部
                unsigned int head = ((str[1] & 0x3F) << 6) | (str[2] & 0x3F);
                // 如果属于中文字符的Unicode编码范围，则是中文字符
                if (head >= 0x3400 && head <= 0x9fff) {
                    return true;
                }
            }
            str += 3; // 跳过UTF-8编码的下一个字符
        } else {
            str++;
        }
    }
    return false;
}

int main(){
    int i, j;
    int maxLine=0, maxDivLength=0;
    int nowLength=0, nowDivLength=0;
    int nowLine=0, nowLineCH=0;
    // FILE *pInFileCH=fopen("export_units-ch.txt", "r");
    FILE *pInFileCH=fopen("export_vnvs-ch.txt", "r");
    FILE *pInFileRU=fopen("export_vnvs-ru.txt", "r");
    /**
     * export_ancillaries   读取一行最大字符 1538, Name最大 
     * export_buildings     读取一行最大字符 5928, Name最大 
     * export_units         读取一行最大字符 2269, Name最大 
     * export_vnvs          读取一行最大字符 1763, Name最大 
    */
    FILE *pOutput=fopen("output.txt", "w");
    char readLineCH[6000];
    char readLineRU[6000];
    char divNameCH[200];
    char divNameRU[200];
    

    if(pInFileCH==NULL){
        printf("Error : InFileCH open error!\n");
        return 0;
    }
    else if(pInFileRU==NULL){
        printf("Error : InFileRU open error!\n");
        return 0;
    }
    else if(pOutput==NULL){
        printf("Error : output open error!\n");
        return 0;
    }
    else{
        printf("Open success!\n\n");
    }
    
    while(fgets(readLineRU, sizeof(readLineRU), pInFileRU)!=NULL){
        nowLine++;
        printf("\rnowLength = %d", nowLine);

        if(readLineRU[0]=='{'){//如果RU这行是标准行，先分割出来name
            for(i=0;readLineRU[i]!='}'&&readLineRU[i]!='\0';i++){
                divNameRU[i]=readLineRU[i];
            }
            if(readLineRU[i]=='\0'){// 如果没有右括号},说明出错了，原封不动输出
                printf("error:wrong RU Line, nowLine = %d\n", nowLine);
                fprintf(pOutput, "%s", readLineRU);
                //printf("%s\n", readLineRU);
                continue;;
            }
            else{
                divNameRU[i]=readLineRU[i];
                i++;
                divNameRU[i]='\0';
            }
            // 到此如果是标准行，且拿到了divNameRU,要在CH中找了
            nowLineCH=0;
            while(fgets(readLineCH, sizeof(readLineCH), pInFileCH)!=NULL){
                nowLineCH++;
                if(readLineCH[0]=='{'){
                    for(j=0;readLineCH[j]!='}'&&readLineCH[j]!='\0';j++){
                        divNameCH[j]=readLineCH[j];
                    }
                    if(readLineCH[j]=='\0'){
                        divNameCH[j]=readLineCH[j];
                        continue;
                    }
                    else{
                        divNameCH[j]=readLineCH[j];
                        j++;
                        divNameCH[j]='\0';
                        // 到这里顺利拿到了divNameCH
                        if(strcmp(divNameCH, divNameRU)==0){ // 找到了
                            if(contains_chinese(readLineCH)){// 中文这段还翻译了
                                fprintf(pOutput, "%s", readLineCH);
                                //printf("%s\n", readLineCH);
                            }
                            else{// 中文这段是英文，就原样输出
                                fprintf(pOutput, "%s", readLineRU);
                                //printf("%s\n", readLineRU);
                            }
                            break;
                        }
                    }
                }
            }

        }
        else{// 如果RU这行不是标准行，就直接输出
            fprintf(pOutput, "%s", readLineRU);
            //printf("%s\n", readLineRU);
        }
    }

    // fputs("hello world!", pInFileCH);
    fclose(pOutput);
    fclose(pInFileCH);
    fclose(pInFileRU);
    return 0;
}