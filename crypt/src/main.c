#include <stdio.h>
#include "sha1/sha1.h"


int main()
{
  uint8_t buf[1024];

  SHA1Context_t SHA1Context;


  buf[0]='a';
  buf[1]='a';
  /* TEST*/

  sha1_init(&SHA1Context);
  sha1_update(&SHA1Context, buf, 1);
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
