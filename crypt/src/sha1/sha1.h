#include <stdio.h>
#include <stdint.h>


typedef struct
{
   uint32_t hash[5];
   uint64_t len;
   uint8_t buf[64];
} Sha1Struct_t;


extern void sha1_init(Sha1Struct_t * sha1_struct);
extern void sha1_update(Sha1Struct_t * sha1_struct, uint8_t * buf, size_t len);
extern void sha1_final(Sha1Struct_t * sha1_struct);
