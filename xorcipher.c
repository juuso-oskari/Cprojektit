#include <stdio.h>
#include <stdint.h>
#include "xorcipher.h"



/*
 * Encrypts / decrypts the void* buffer named <data>
 * Encrypted data will be saved to the same <data> -buffer.
 * Encryption is based on XOR operation using a 32-bit <key>
 */
void confidentiality_xor(uint32_t key, void* data, int len)
{

    uint32_t* buffer=data;
    int i=0;


    while(i<len){

        buffer[i]=buffer[i]^key;
        i++;
    }

    data=buffer;


}

/*
 * Encrypts / decrypts the void* buffer named <data>
 * Encrypted data will be saved to the same <data> -buffer.
 * Encryption is based on XOR operation using a 32-bit <key>
 * After encrypting one 32-bit block of original data, the key shifts one bit left
 */
void confidentiality_xor_shift(uint32_t key, void* data, int len)
{
    uint32_t* buffer=data;
    int i=0;
    uint32_t verrokki;



    while(i<len){

        buffer[i]=buffer[i]^key;
        verrokki=0x1<<31;

        if(key&verrokki){
            key=(key<<1)|(verrokki>>31);
        } else{
            key=key<<1;
        }
        i++;
    }

    data=buffer;
}

void print_uint32_hex(void* data, int len)
{
    for(int i = 0; i < len; i++) printf("0x%08x ", ((uint32_t*)data)[i]);
    printf("\n");
}
