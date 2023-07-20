#include <stdio.h>
#include <stdint.h>

typedef union union_MEM32 {
    float fv;
    struct {
        uint16_t lsb; // LSB
        uint16_t hsb; // HSB
    } data;
} uMEM32;

/**
 *  example：-100.34 =>  HSB:0xC2C8 LSB：0xAE14
 */
int main() {
    uMEM32 value;

    // uint16 to float
    value.data.lsb = 0xAE14;
    value.data.hsb = 0xC2C8;
    printf("float: %0.2f\n", value.fv);

    // float to uint16
    value.fv = -100.34;
    printf("HSB 0x%x\n", value.data.hsb);
    printf("LSB 0x%x\n", value.data.lsb);
    return 0;
}
