#include<stdio.h>
int main()
{
    // 向文件中输入数据
    FILE* pf = fopen("text.txt", "w");
    if (pf == NULL)
    {
        perror("fopen :w");
        return 1;
    }
    else
    {
        char ch = 0;
        for (ch = 'a'; ch <= 'z'; ch++)
        {
            fputc(ch, pf);
        }
    }
    fclose(pf);
    pf = NULL;
    // 向文件中读取数据
    FILE* pf2 = fopen("text.txt", "r");
    if (pf2 == NULL)
    {
        perror("fopen: r");
        return 1;
    }
    else
    {
        int ch = 0; // ch 为int类型，以便接收fgetc的返回值
        while ((ch = fgetc(pf2)) != EOF)
        {
            putchar(ch); // 直接输出字符
        }
    }
    fclose(pf2);
    pf2 = NULL;
    return 0;
}