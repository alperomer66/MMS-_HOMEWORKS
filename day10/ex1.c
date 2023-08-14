#include <stdio.h>
#include <stdint.h>

void swapBytes(uint16_t* word) {
    *word = ((*word & 0xFF00) >> 8) | ((*word & 0x00FF) << 8);
}

void printDoubleBits(double num) {
    union {
        double f;
        uint64_t u;
    } converter;

    converter.f = num;
    uint64_t bits = converter.u;

    for (int i = 63; i >= 0; i--) {
        printf("%d", (bits >> i) & 1);
        if (i == 63) {
            printf(" "); 
        } else if (i >= 52 && i <= 62) {
            printf(" "); 
        }
    }
    printf("\n");
}

int main() {
    uint16_t word = 0xABCD;
    printf("Before swap: 0x%X\n", word);
    swapBytes(&word);
    printf("After swap: 0x%X\n", word);

    double num = 123.456;
    printDoubleBits(num);

    return 0;
}
