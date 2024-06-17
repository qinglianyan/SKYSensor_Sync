#include <stdio.h>
#include <stdbool.h>
 
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
 
int main() {
    const char *str1 = "Hello, 你好!";
    const char *str2 = "Hello, World!";
 
    printf("String %s contains Chinese characters: %s\n", str1, contains_chinese(str1) ? "Yes" : "No");
    printf("String %s contains Chinese characters: %s\n", str2, contains_chinese(str2) ? "Yes" : "No");
 
    return 0;
}