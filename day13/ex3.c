#include <stdio.h>


#define MAX(x, y, z) (((x) > (y)) ? (((x) > (z)) ? (x) : (z)) : (((y) > (z)) ? (y) : (z)))


#define MIN(x, y, z) (((x) < (y)) ? (((x) < (z)) ? (x) : (z)) : (((y) < (z)) ? (y) : (z)))


#define SETBIT(mask, bit) ((mask) |= (1 << (bit)))


#define CLEARBIT(mask, bit) ((mask) &= ~(1 << (bit)))


#define INVERSEBIT(mask, bit) ((mask) ^= (1 << (bit)))


#define CHECKBIT(mask, bit) (((mask) >> (bit)) & 1)


#define SWAP(a, b) do { (a) ^= (b); (b) ^= (a); (a) ^= (b); } while (0)

int main() {
    int x = 5, y = 10, z = 7;
    int mask = 0b1010;

    printf("MAX(%d, %d, %d) = %d\n", x, y, z, MAX(x, y, z));
    printf("MIN(%d, %d, %d) = %d\n", x, y, z, MIN(x, y, z));

    printf("Original mask: %04x\n", mask);
    SETBIT(mask, 1);
    printf("After SETBIT(mask, 1): %04x\n", mask);
    CLEARBIT(mask, 3);
    printf("After CLEARBIT(mask, 3): %04x\n", mask);
    INVERSEBIT(mask, 0);
    printf("After INVERSEBIT(mask, 0): %04x\n", mask);
    printf("CHECKBIT(mask, 2): %d\n", CHECKBIT(mask, 2));
    printf("CHECKBIT(mask, 3): %d\n", CHECKBIT(mask, 3));

    int a = 15, b = 25;
    printf("Before SWAP: a = %d, b = %d\n", a, b);
    SWAP(a, b);
    printf("After SWAP: a = %d, b = %d\n", a, b);

    return 0;
}
