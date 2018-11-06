#include <string.h>
#include "sha1.h"





void sha1_transform(Sha1Struct_t * sha1_struct);

void sha1_init(Sha1Struct_t * sha1_struct)
{
  sha1_struct->hash[0] = 0x67452301;
  sha1_struct->hash[1] = 0xefcdab89;
  sha1_struct->hash[2] = 0x98badcfe;
  sha1_struct->hash[3] = 0x10325476;
  sha1_struct->hash[4] = 0xc3d2e1f0;

  sha1_struct->len = 0;
  memset(sha1_struct->buf, 0, 64);
}

void sha1_transform(Sha1Struct_t * sha1_struct)
{

}
