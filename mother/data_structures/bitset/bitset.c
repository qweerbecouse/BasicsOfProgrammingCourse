#include "bitset.h"

__attribute__((unused))void printBitsState(char a) {
    printf("%i: ", a);
    printf("%i", (a & 0x80) ? 1 : 0);
    printf("%i", (a & 0x40) ? 1 : 0);
    printf("%i", (a & 0x20) ? 1 : 0);
    printf("%i", (a & 0x10) ? 1 : 0);
    printf("%i", (a & 0x08) ? 1 : 0);
    printf("%i", (a & 0x04) ? 1 : 0);
    printf("%i", (a & 0x02) ? 1 : 0);
    printf("%i", (a & 0x01) ? 1 : 0);
}

__attribute__((unused))char isBitOdd(int value) {
    return (value & 0b00000001);
}

__attribute__((unused))int invertBit(int value, unsigned char index) {
    return (value ^ (1 << index));
}

__attribute__((unused))int bitSet(int value, unsigned char index) {
    return (value | (1 << index));
}

__attribute__((unused))int clearBit(int value, unsigned char index) {
    return (value & ~ (1 << index));
}

__attribute__((unused))int testBit(int value, unsigned char index) {
    return (value & (1 << index));
}