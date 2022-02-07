/*
 * @Date: 2021-10-08 14:08:48
 * @LastEditors: hongchang.han
 * @LastEditTime: 2022-02-07 16:03:05
 * @FilePath: \HelloWorld\helloword.cpp
 */
#include <stdio.h>
#include<sys/types.h>

#include<sys/stat.h>

#include<fcntl.h>
#include <unistd.h>

//整数 大端转小端
int intb2l(int);

// short int 大端转小端
short short2Little(short);

int main() {
    printf("Hello World!\n");

    FILE * file = fopen("./HelloJava.class", "r");
    if (file == NULL) {
        printf("file not find\n");
        _exit(1);
    }

    // magic number
    unsigned int magic;
    fread(&magic, sizeof(magic), 1, file);
    magic = intb2l(magic);
    printf("magic number: %#x\n", magic);


    // 副版本号
    unsigned short minorVersion;
    fread(&minorVersion, sizeof(minorVersion), 1, file);
    minorVersion = short2Little(minorVersion);
    printf("minorVersion: %#d\n", minorVersion);

    // 主版本号
    unsigned short majorVersion;
    fread(&majorVersion, sizeof(majorVersion), 1, file);
    majorVersion = short2Little(majorVersion);
    printf("majorVersion: %#d\n", majorVersion);

    // constant pool count
    unsigned short constantPoolCount;
    fread(&constantPoolCount, sizeof(constantPoolCount), 1, file);
    constantPoolCount = short2Little(constantPoolCount);
    printf("constant pool count: %#d\n", constantPoolCount);


    fclose(file);

    return 0;
}

// unsinged int 大端转小端
int intb2l(int b)
{
    return (b << 24 & 0xff000000) | (b << 8 & 0x00ff0000) | (b >> 24 & 0x000000ff) | (b >> 8 & 0x0000ff00);
}

// unsinged short 大端转小端
short short2Little(short b) {
     return (b << 8 & 0xff00) | (b >> 8 & 0x00ff);
}