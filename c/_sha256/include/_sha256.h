#include "_primes.h"


/*** SHA-256 hash implementation ***/
/* msg: text to cipher
   H: initial hash values
   K: round constants
   If the preprocessed msg < 64 bytes (512 bits), it's parsed into 16 32-bit words W0 --> W15.
   Otherwise, for a message larger than 64 bytes, it's parsed into blocks of 512 bits W0 --> Wn.

   We define the following functions:
   Already available:
       &            (Bitwise AND)
       |            (Bitwise OR)
       ^            (Bitwise XOR)
       !            (Bitwise NOT)
       +            (Addition (modulo 2^32))
       >>           (Bitwise right shift)
       <<           (Bitwise left shift)
   Implemented here:
       rotr(x,n)    (Right rotate x by n bits)
       rotl(x,n)    (Left rotate x by n bits)
       ch(x,y,z)    ((x & y) ^ (!x & z)) - Choose function
       maj(x,y,z)   ((x & y) ^ (x & z) ^ (y & z)) - Majority function
       sigma0_big(x) (rotr(x,2) ^ rotr(x,13) ^ rotr(x,22))
       sigma1_big(x) (rotr(x,6) ^ rotr(x,11) ^ rotr(x,25))
       
       // Only used when preprocessed msg > 64 bytes
       sigma0_small(x) (rotr(x,7) ^ rotr(x,18) ^ (x>>3))
       sigma1_small(x) (rotr(x,17) ^ rotr(x,19) ^ (x>>10))
*/



#ifndef _SHA256_H
  #define _SHA256_H   0x1
  



#endif