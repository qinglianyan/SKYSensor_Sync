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
    char RUname[50];
    char CHname[50];
    char Outname[50];
    // FILE *pInFileCH=fopen("export_units-ch.txt", "r");
    /**
     * export_ancillaries   读取一行最大字符 1538, Name最大 
     * export_buildings     读取一行最大字符 5928, Name最大 
     * export_units         读取一行最大字符 2269, Name最大 
     * export_vnvs          读取一行最大字符 1763, Name最大 
    */
    
    char readLineCH[6000];
    char readLineRU[6000];
    char divNameCH[200];
    char divNameRU[200];
    
    printf("1.原理  :  先从俄文找到被大括号 {} 包括的,要检索的字符串,在中文txt中检索.\n");
    printf("  如果没有检索到,输出原本的俄文;如果中文txt中翻译为了英文,输出原本的俄文;\n");
    printf("  只有检索到了,而且被翻译为了中文,才会输出中文.\n");
    printf("2.编码  :  注意两种语言的文件都需要是UTF-8编码;\n");
    printf("3.文件名:  注意区分大小写,注意要带后缀;注意要放在与这个exe的同级目录下面,我是用相对路径打开的;如果不在同一个位置可以文件名写绝对路径;\n\n");
    getchar();
    printf("请输入俄语文件名称,如 export_ancillaries-RU.txt\n");
    scanf("%s", RUname);
    printf("请输入汉语文件名称,如 export_ancillaries-CH.txt\n");
    scanf("%s", CHname);
    printf("请输入生成文件名称,如 export_ancillaries-out.txt\n");
    scanf("%s", Outname);

// FILE *pInFileRU=fopen("export_vnvs-ru.txt", "r");
// FILE *pInFileCH=fopen("export_vnvs-ch.txt", "r");
// FILE *pOutput=fopen("output.txt", "w");

    FILE *pInFileRU=fopen(RUname, "r");
    FILE *pInFileCH=fopen(CHname, "r");
    FILE *pOutput=fopen(Outname, "w");

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
            fseek(pInFileCH, 0, 0);
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