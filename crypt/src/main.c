#include <stdio.h>
#include "sha1/sha1.h"


int main()
{
  uint8_t buf[2000000];

  SHA1Context_t SHA1Context;

  for(int i=0; i<1000000; i++)
    buf[i]='a';
  /* TEST*/

  sha1_init(&SHA1Context);
  sha1_update(&SHA1Context, buf, 1000000);
  sha1_final(&SHA1Context);

  printf("\n");
  for (int i=0; i<64; i++)
    printf("%x", SHA1Context.buf[i]);

  printf("\n");

  for (int i=0; i<5; i++)
    printf("%x", SHA1Context.hash[i]);

  printf("\n");

   return 0;
}
