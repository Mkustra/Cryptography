/** @file sha1.h
 *  @brief Implementation of SHA-1 function
 *
 *  @author Miroslaw Kustra (mkustra)
 *  @bug No known bugs.
 */

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

typedef struct
{
   uint32_t hash[5];
   uint64_t len;
   uint8_t buf[64];
} SHA1Context_t;

/**
 * @brief                   Initiate values in Sha1Struct_t type variable with start values of SHA-1
 *
 * @param[in] sha1_struct   Structure of SHA-1 function to initiate.
 *
 * @return    void
 */
extern void sha1_init(SHA1Context_t * sha1_struct);

/**
 * @brief                       Adding input data to SHA-1 algorithm. This function can be used multiple times for single input vector.
 *
 * @param[in,out] sha1_struct   Structure of SHA-1 computing to update with data
 * @param[in]     buf           Buffer with input data
 * @param[in]     size          Size of buf in bytes
 *
 * @return        bool          Returns true if updating was successful
 */
extern bool sha1_update(SHA1Context_t * sha1_struct, uint8_t * buf, uint64_t size);

/**
 * @brief                       Adds padding and calculate final result of algorithm.
 *
 * @param[in,out] sha1_struct   Structure of SHA-1 computing.
 *
 * @return        void
 */
extern void sha1_final(SHA1Context_t * sha1_struct);
