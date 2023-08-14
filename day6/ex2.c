#include <stdio.h>
#include <stdint.h>

#define TINT 1
#define TCHAR 2
#define TDOUBLE 3
#define TFLOAT 4
#define TUINT8 5
#define TUINT16 6
#define TUINT32 7
#define TUINT64 8

void printInt(const void* valuePtr) {
    printf("%d\n", *((int*)valuePtr));
}

void printChar(const void* valuePtr) {
    printf("%c\n", *((char*)valuePtr));
}

void printDouble(const void* valuePtr) {
    printf("%lf\n", *((double*)valuePtr));
}

void printFloat(const void* valuePtr) {
    printf("%f\n", *((float*)valuePtr));
}

void printUInt8(const void* valuePtr) {
    printf("%u\n", *((uint8_t*)valuePtr));
}

void printUInt16(const void* valuePtr) {
    printf("%u\n", *((uint16_t*)valuePtr));
}

void printUInt32(const void* valuePtr) {
    printf("%u\n", *((uint32_t*)valuePtr));
}

void printUInt64(const void* valuePtr) {
    printf("%lu\n", *((uint64_t*)valuePtr));
}

typedef void (*PrintFunction)(const void*);

int main() {
    PrintFunction printFunctions[] = {
        NULL,         
        printInt,
        printChar,
        printDouble,
        printFloat,
        printUInt8,
        printUInt16,
        printUInt32,
        printUInt64
    };

    int intValue = 42;
    char charValue = 'A';
    double doubleValue = 3.14159;
    float floatValue = 2.71828;
    uint8_t uint8Value = 255;
    uint16_t uint16Value = 65535;
    uint32_t uint32Value = 4294967295;
    uint64_t uint64Value = 18446744073709551615UL;

    uint8_t flag = TINT;
    printFunctions[flag](&intValue);

    flag = TCHAR;
    printFunctions[flag](&charValue);

    flag = TDOUBLE;
    printFunctions[flag](&doubleValue);

    flag = TFLOAT;
    printFunctions[flag](&floatValue);

    flag = TUINT8;
    printFunctions[flag](&uint8Value);

    flag = TUINT16;
    printFunctions[flag](&uint16Value);

    flag = TUINT32;
    printFunctions[flag](&uint32Value);

    flag = TUINT64;
    printFunctions[flag](&uint64Value);

    return 0;
}
