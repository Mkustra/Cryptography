/** @file sha1.h
 *  @brief Function prototypes for the console driver.
 *
 *  This contains the prototypes for the console
 *  driver and eventually any macros, constants,
 *  or global variables you will need.
 *
 *  @author Miroslaw Kustra (mkustra)
 *  @bug No known bugs.
 */

#include <stdio.h>
#include <stdint.h>


typedef struct
{
   uint32_t hash[5];
   uint64_t len;
   uint8_t buf[64];
} Sha1Struct_t;

/**
 * @brief Initiate values in Sha1Struct_t type variable with start values of SHA-1
 *
 * @param[in] sha1_struct This is the first parameter.
 *
 * @return void
 */
extern void sha1_init(Sha1Struct_t * sha1_struct);

extern void sha1_update(Sha1Struct_t * sha1_struct, uint8_t * buf, size_t len);
extern void sha1_final(Sha1Struct_t * sha1_struct);
