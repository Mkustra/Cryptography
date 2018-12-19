#include "sha1.h"


#define H0 0x67452301U
#define H1 0xEFCDAB89U
#define H2 0x98BADCFEU
#define H3 0x10325476U
#define H4 0xC3D2E1F0U

#define K1 0x5A827999U
#define K2 0x6ED9EBA1U
#define K3 0x8F1BBCDCU
#define K4 0xCA62C1D6U

#define MASK  0x0000000FU

#define rotl32(X,n) ( (X << n) | (X >> (32-n)) )

#define f1(B,C,D) ((B & C) | ((~B) & D))
#define f2(B,C,D) (B ^ C ^ D)
#define f3(B,C,D) ((B & C) | (B & D) | (C & D))
#define f4(B,C,D) (B ^ C ^ D)

#define s(t) (t & MASK)
#define block(t) (W[s(t)] = rotl32((W[(s(t) + 13) & MASK] ^ W[(s(t) + 8) & MASK] ^ W[(s(t) + 2) & MASK] ^ W[s(t)]), 1))

#define ROUND0(a,b,c,d,e,t) e += rotl32(a, 5) + f1(b,c,d) + W[s(t)]  + K1; b = rotl32(b,30);
#define ROUND1(a,b,c,d,e,t) e += rotl32(a, 5) + f1(b,c,d) + block(t) + K1; b = rotl32(b,30);
#define ROUND2(a,b,c,d,e,t) e += rotl32(a, 5) + f2(b,c,d) + block(t) + K2; b = rotl32(b,30);
#define ROUND3(a,b,c,d,e,t) e += rotl32(a, 5) + f3(b,c,d) + block(t) + K3; b = rotl32(b,30);
#define ROUND4(a,b,c,d,e,t) e += rotl32(a, 5) + f4(b,c,d) + block(t) + K4; b = rotl32(b,30);


/* Local functions*/
void sha1_transform(SHA1Context_t * sha1_struct); //transforms single block


void sha1_init(SHA1Context_t * sha1_struct)
{
  sha1_struct->len = 0;

  sha1_struct->hash[0] = H0;
  sha1_struct->hash[1] = H1;
  sha1_struct->hash[2] = H2;
  sha1_struct->hash[3] = H3;
  sha1_struct->hash[4] = H4;

  memset(sha1_struct->buf, 0, 64);
}

void sha1_transform(SHA1Context_t * sha1_struct)
{
  uint32_t W[16];
  uint32_t A, B, C, D, E;

  A = sha1_struct->hash[0];
  B = sha1_struct->hash[1];
  C = sha1_struct->hash[2];
  D = sha1_struct->hash[3];
  E = sha1_struct->hash[4];

  for(uint8_t t = 0; t < 16; t++)
  {
    W[t]  = sha1_struct->buf[t*4+0] << 24 & 0xFF000000;
    W[t] |= sha1_struct->buf[t*4+1] << 16 & 0x00FF0000;
    W[t] |= sha1_struct->buf[t*4+2] << 8  & 0x0000FF00;
    W[t] |= sha1_struct->buf[t*4+3] << 0  & 0x000000FF;
  }

  /*TEST*/
  printf("\nMACIERZ:\n");
  for (int i=0; i<16; i++)
    printf("%x", W[i]);
  printf("\n");
  /*TEST*/
  /* SHA-1 rounds*/
  {
    ROUND0(A, B, C, D, E,  0)
    ROUND0(E, A, B, C, D,  1)
    ROUND0(D, E, A, B, C,  2)
    ROUND0(C, D, E, A, B,  3)
    ROUND0(B, C, D, E, A,  4)
    ROUND0(A, B, C, D, E,  5)
    ROUND0(E, A, B, C, D,  6)
    ROUND0(D, E, A, B, C,  7)
    ROUND0(C, D, E, A, B,  8)
    ROUND0(B, C, D, E, A,  9)
    ROUND0(A, B, C, D, E, 10)
    ROUND0(E, A, B, C, D, 11)
    ROUND0(D, E, A, B, C, 12)
    ROUND0(C, D, E, A, B, 13)
    ROUND0(B, C, D, E, A, 14)
    ROUND0(A, B, C, D, E, 15)
    ROUND1(E, A, B, C, D, 16)
    ROUND1(D, E, A, B, C, 17)
    ROUND1(C, D, E, A, B, 18)
    ROUND1(B, C, D, E, A, 19)
    ROUND2(A, B, C, D, E, 20)
    ROUND2(E, A, B, C, D, 21)
    ROUND2(D, E, A, B, C, 22)
    ROUND2(C, D, E, A, B, 23)
    ROUND2(B, C, D, E, A, 24)
    ROUND2(A, B, C, D, E, 25)
    ROUND2(E, A, B, C, D, 26)
    ROUND2(D, E, A, B, C, 27)
    ROUND2(C, D, E, A, B, 28)
    ROUND2(B, C, D, E, A, 29)
    ROUND2(A, B, C, D, E, 30)
    ROUND2(E, A, B, C, D, 31)
    ROUND2(D, E, A, B, C, 32)
    ROUND2(C, D, E, A, B, 33)
    ROUND2(B, C, D, E, A, 34)
    ROUND2(A, B, C, D, E, 35)
    ROUND2(E, A, B, C, D, 36)
    ROUND2(D, E, A, B, C, 37)
    ROUND2(C, D, E, A, B, 38)
    ROUND2(B, C, D, E, A, 39)
    ROUND3(A, B, C, D, E, 40)
    ROUND3(E, A, B, C, D, 41)
    ROUND3(D, E, A, B, C, 42)
    ROUND3(C, D, E, A, B, 43)
    ROUND3(B, C, D, E, A, 44)
    ROUND3(A, B, C, D, E, 45)
    ROUND3(E, A, B, C, D, 46)
    ROUND3(D, E, A, B, C, 47)
    ROUND3(C, D, E, A, B, 48)
    ROUND3(B, C, D, E, A, 49)
    ROUND3(A, B, C, D, E, 50)
    ROUND3(E, A, B, C, D, 51)
    ROUND3(D, E, A, B, C, 52)
    ROUND3(C, D, E, A, B, 53)
    ROUND3(B, C, D, E, A, 54)
    ROUND3(A, B, C, D, E, 55)
    ROUND3(E, A, B, C, D, 56)
    ROUND3(D, E, A, B, C, 57)
    ROUND3(C, D, E, A, B, 58)
    ROUND3(B, C, D, E, A, 59)
    ROUND4(A, B, C, D, E, 60)
    ROUND4(E, A, B, C, D, 61)
    ROUND4(D, E, A, B, C, 62)
    ROUND4(C, D, E, A, B, 63)
    ROUND4(B, C, D, E, A, 64)
    ROUND4(A, B, C, D, E, 65)
    ROUND4(E, A, B, C, D, 66)
    ROUND4(D, E, A, B, C, 67)
    ROUND4(C, D, E, A, B, 68)
    ROUND4(B, C, D, E, A, 69)
    ROUND4(A, B, C, D, E, 70)
    ROUND4(E, A, B, C, D, 71)
    ROUND4(D, E, A, B, C, 72)
    ROUND4(C, D, E, A, B, 73)
    ROUND4(B, C, D, E, A, 74)
    ROUND4(A, B, C, D, E, 75)
    ROUND4(E, A, B, C, D, 76)
    ROUND4(D, E, A, B, C, 77)
    ROUND4(C, D, E, A, B, 78)
    ROUND4(B, C, D, E, A, 79)
  }

  sha1_struct->hash[0] += A;
  sha1_struct->hash[1] += B;
  sha1_struct->hash[2] += C;
  sha1_struct->hash[3] += D;
  sha1_struct->hash[4] += E;
}

bool sha1_update(SHA1Context_t * sha1_struct, uint8_t * buf, uint64_t size)
{
  uint64_t cnt = 0;

  if(size == 0)
    return true;

  while(cnt != size)
  {
    sha1_struct->buf[sha1_struct->len % 64] = buf[cnt++];
    sha1_struct->len++;

    if(sha1_struct->len % 64 == 0)
    {
      printf("CHUJ");
      sha1_transform(sha1_struct);
    }
  }

  return true;

}

void sha1_final(SHA1Context_t * sha1_struct)
{
  int index = sha1_struct->len % 64;

  if(index > 48)
  {
    for(int i = index; i < 64; i++)
    {
      sha1_struct->buf[i] = 0;
    }
    sha1_transform(sha1_struct);
  }

  sha1_struct->buf[index] = 0x80;

  for(int i = index + 1; i < 56; i++)
    sha1_struct->buf[i] = 0;



  /* Counter low */
  sha1_struct->buf[63] = (uint8_t)((sha1_struct->len & 0x00000000000000FF) >>  0);
  sha1_struct->buf[62] = (uint8_t)((sha1_struct->len & 0x000000000000FF00) >>  8);
  sha1_struct->buf[61] = (uint8_t)((sha1_struct->len & 0x0000000000FF0000) >> 16);
  sha1_struct->buf[60] = (uint8_t)((sha1_struct->len & 0x00000000FF000000) >> 24);

  /* Counter high */
  sha1_struct->buf[59] = (uint8_t)((sha1_struct->len & 0x000000FF00000000) >> 32);
  sha1_struct->buf[58] = (uint8_t)((sha1_struct->len & 0x0000FF0000000000) >> 40);
  sha1_struct->buf[57] = (uint8_t)((sha1_struct->len & 0x00FF000000000000) >> 48);
  sha1_struct->buf[56] = (uint8_t)((sha1_struct->len & 0xFF00000000000000) >> 56);

  sha1_transform(sha1_struct);
}
