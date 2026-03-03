#include <stdio.h>
#include "pin.h"
#include <string.h> 
#include "../crypto/aes.h"
#include "../crypto/pinblock.h"

int main() {

    PIN_State state;
    pin_init(&state);

    uint8_t input[4];
uint8_t pinblock[8] = {0};

const char *pan = "1234567890123456";

create_iso0_pinblock(input, 4, pan, pinblock);

uint8_t key[16] = {
    0x10,0x11,0x12,0x13,
    0x14,0x15,0x16,0x17,
    0x18,0x19,0x1A,0x1B,
    0x1C,0x1D,0x1E,0x1F
};

uint8_t encrypted[16] = {0};
uint8_t block[16] = {0};

/* ISO block is 8 bytes → pad to 16 */
memcpy(block, pinblock, 8);

aes_encrypt(block, key, encrypted);

printf("Encrypted ISO-0 PIN block: ");
for(int i=0;i<16;i++)
    printf("%02X", encrypted[i]);
printf("\n");
aes_encrypt(block, key, encrypted);

printf("Encrypted PIN block: ");
for(int i=0;i<16;i++)
    printf("%02X", encrypted[i]);
printf("\n");

        } else {
            printf("Access Denied\n");
        }
        {   
        printf("System permanently locked.\n");
    return 0;
}