#include <stdio.h>
#include "sha1.h"

int main()
{

  Sha1Struct_t Sha1Struct;

  sha1_init(&Sha1Struct);

  for(int i=0; i<64; i++)
    printf("%u", Sha1Struct.buf[i]);

   return 0;
}
