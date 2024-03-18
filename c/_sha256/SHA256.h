
#ifndef       SHA256_H
  #define     SHA256_H 0x1
  #include    <stdio.h>
  #include    <stdlib.h>
  #include    <string.h>
  #include    <inttypes.h>
  #include    <stdbool.h>
  #include    <stddef.h>

  #define     IS_LITTLE_ENDIAN 0x1 // Change to 0 for big-endian
  #define     byteSwap32(x) (((x) >> 24) | (((x)&0x00FF0000) >> 8) | (((x)&0x0000FF00) << 8) | ((x) << 24))
  #define     byteSwap64(x)                                                    \
    ((((x) >> 56) & 0x00000000000000FF) | (((x) >> 40) & 0x000000000000FF00) | \
    (((x) >> 24)  & 0x0000000000FF0000) | (((x) >> 8)  & 0x00000000FF000000) | \
    (((x) << 8)   & 0x000000FF00000000) | (((x) << 24) & 0x0000FF0000000000) | \
    (((x) << 40)  & 0x00FF000000000000) | (((x) << 56) & 0xFF00000000000000))

  // Union represents a message block
  union messageBlock{
      __uint8_t e[64];
      __uint32_t t[16];
      __uint64_t s[8];
  };

  // ENUM to control state of the program
  enum status{
    READ, 
    PAD0,
    PAD1,
    FINISH
  };


  #define       MAXCHAR 100000

  // See Section 4.1.2
  // Rotate bits right
  __uint32_t    rotr(__uint32_t n, __uint16_t x);

  // Shift bits right
  __uint32_t    shr(__uint32_t n, __uint16_t x);


  __uint32_t    Ch(__uint32_t x,__uint32_t y,__uint32_t z);
  __uint32_t    Maj(__uint32_t x,__uint32_t y,__uint32_t z);

  __uint32_t    SIG0(__uint32_t x);
  __uint32_t    SIG1(__uint32_t x);

  __uint32_t    sig0(__uint32_t x);
  __uint32_t    sig1(__uint32_t x);

  int       rng();
  int       calcFileSize();
  int       fillMessageBlock();
  void      calculateHash(const char *input_path, const char *output_path);
  int       nextMessageBlock(FILE *file, union messageBlock *msgBlock, enum status *state, __uint64_t *numBits);

#endif