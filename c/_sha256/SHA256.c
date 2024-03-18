#include "SHA256.h"

int main(int argc, char *argv[]){

    const char *input_path = "in.txt";
    const char *output_path = "out.txt";
    calculateHash(input_path, output_path);
    
    return 0;
}

void calculateHash(const char *input_path, const char *output_path){   

    // The current message block
    union messageBlock msgBlock;

    // The number of bits read from the file
    __uint64_t numBits = 0;

    // The state of the program
    enum status state = READ;

    __uint32_t K[64] = {
        0x428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5,
        0x3956c25b, 0x59f111f1, 0x923f82a4, 0xab1c5ed5,
        0xd807aa98, 0x12835b01, 0x243185be, 0x550c7dc3,
        0x72be5d74, 0x80deb1fe, 0x9bdc06a7, 0xc19bf174,
        0xe49b69c1, 0xefbe4786, 0x0fc19dc6, 0x240ca1cc,
        0x2de92c6f, 0x4a7484aa, 0x5cb0a9dc, 0x76f988da,
        0x983e5152, 0xa831c66d, 0xb00327c8, 0xbf597fc7,
        0xc6e00bf3, 0xd5a79147, 0x06ca6351, 0x14292967,
        0x27b70a85, 0x2e1b2138, 0x4d2c6dfc, 0x53380d13,
        0x650a7354, 0x766a0abb, 0x81c2c92e, 0x92722c85,
        0xa2bfe8a1, 0xa81a664b, 0xc24b8b70, 0xc76c51a3,
        0xd192e819, 0xd6990624, 0xf40e3585, 0x106aa070,
        0x19a4c116, 0x1e376c08, 0x2748774c, 0x34b0bcb5,
        0x391c0cb3, 0x4ed8aa4a, 0x5b9cca4f, 0x682e6ff3,
        0x748f82ee, 0x78a5636f, 0x84c87814, 0x8cc70208,
        0x90befffa, 0xa4506ceb, 0xbef9a3f7, 0xc67178f2
    };

    // Message schedule
    __uint32_t W[64];

    // Working variables
    __uint32_t a, b, c, d, e, f, g, h;

    // Temp variables
    __uint32_t T1;
    __uint32_t T2;

    // Hash values
    __uint32_t H[8] = {
        0x6a09e667,
        0xbb67ae85,
        0x3c6ef372,
        0xa54ff53a,
        0x510e527f,
        0x9b05688c,
        0x1f83d9ab,
        0x5be0cd19
    };

    int j;
    int o;
    FILE *input = fopen(input_path, "r");
    
    // The current message block
    while(fillMessageBlock(input, &msgBlock, &state, &numBits)){
        // iterate through the message block 
        for(j=0; j<16; j++){   
            // Fist check for big or little endian
            if(!IS_LITTLE_ENDIAN){
                W[j] = msgBlock.t[j];
            }else{
                // Convert
                W[j] = byteSwap32(msgBlock.t[j]);
            }
        }
        for (j=16; j<64; j++){
            // Step 1
            W[j] = sig1(W[j-2]) + W[j-7] + sig0(W[j-15]) + W[j-16];
        }

        // Step 2
        a = H[0];
        b = H[1];
        c = H[2];
        d = H[3];
        e = H[4];
        f = H[5];
        g = H[6];
        h = H[7];

        // Step 3
        for(j = 0; j < 64; j++){
            T1 = h + SIG1(e) + Ch(e,f,g) + K[j] + W[j];
            T2 = SIG0(a) + Maj(a,b,c);
            h = g;
            g = f;
            f = e;
            e = d + T1;
            d = c;
            c = b;
            b = a;
            a = T1 + T2;
        }

        // Step 4
        H[0] = a + H[0];
        H[1] = b + H[1];
        H[2] = c + H[2];
        H[3] = d + H[3];
        H[4] = e + H[4];
        H[5] = f + H[5];
        H[6] = g + H[6];
        H[7] = h + H[7];
    
    }
    FILE *output = fopen(output_path, "w");
    fprintf(output, "%08llx", H[0]);
    fprintf(output, "%08llx", H[1]);
    fprintf(output, "%08llx", H[2]);
    fprintf(output, "%08llx", H[3]);
    fprintf(output, "%08llx", H[4]);
    fprintf(output, "%08llx", H[5]);
    fprintf(output, "%08llx", H[6]);
    fprintf(output, "%08llx\n", H[7]);
    
    fclose(output);
    fclose(input);
}

int fillMessageBlock(FILE *file, union messageBlock *msgBlock, enum status *state, __uint64_t *numBits){
    if (!file || !msgBlock || !state || !numBits) {
        // Check for NULL pointers
        return -1; // Error code for invalid input
    }

    __uint64_t numBytes = 0;
    int i;

    if (*state == FINISH) {
        return 0; // Already finished processing, nothing to do
    }

    if (*state == PAD0 || *state == PAD1) {
        for (i = 0; i < 56; i++) {
            msgBlock->e[i] = 0x00; // Set the first 56 bytes to zeros
        }

        msgBlock->s[7] = byteSwap64(*numBits); // Set the last 64 bits to the size of the message

        *state = FINISH; // Set the state to finish

        if (*state == PAD1) {
            msgBlock->e[0] = 0x80; // Set the first bit of msgBlock to 1 if state is PAD1
        }

        return 1; // Keep the loop in SHA256 going for one more iteration
    }

    numBytes = fread(msgBlock->e, 1, 64, file); // Read bytes from the file

    *numBits += (numBytes * 8); // Update the number of bits read

    if (numBytes < 56) {
        msgBlock->e[numBytes] = 0x80; // Add the one bit before padding with zeros

        while (numBytes < 56) {
            msgBlock->e[++numBytes] = 0x00; // Pad with zeros until the last 64 bits
        }

        msgBlock->s[7] = byteSwap64(*numBits); // Store the length of the file in bits

        *state = FINISH; // Change the state

    } else if (numBytes < 64) {
        *state = PAD0; // Set the state to PAD0

        msgBlock->e[numBytes] = 0x80; // Add the one bit into the current message block

        while (numBytes < 64) {
            msgBlock->e[++numBytes] = 0x00; // Pad the rest of the message block with zeros
        }

    } else if (feof(file)) {
        *state = PAD1; // Set the state to PAD1 if we're at the end of the file
    }

    return 1; // Successfully processed
}
    
// calcuates the size of a file
int calcFileSize(FILE *file){
    int prev=ftell(file);
    fseek(file, 0L, SEEK_END);
    int size=ftell(file);
    fseek(file,prev,SEEK_SET); 
    return size;
}


__uint32_t sig0(__uint32_t x){
	return (rotr(x, 7) ^ rotr(x, 18) ^ shr(x, 3));
};

__uint32_t sig1(__uint32_t x){
	return (rotr(x, 17) ^ rotr(x, 19) ^ shr(x, 10));
};

__uint32_t rotr(__uint32_t x, __uint16_t a){
	return (x >> a) | (x << (32 - a));
};

__uint32_t shr(__uint32_t x, __uint16_t b){
	return (x >> b);
};

__uint32_t SIG0(__uint32_t x){
	return (rotr(x, 2) ^ rotr(x, 13) ^ rotr(x, 22));
};

__uint32_t SIG1(__uint32_t x){
	return (rotr(x, 6) ^ rotr(x, 11) ^ rotr(x, 25));
};

// Choose
__uint32_t Ch(__uint32_t x,__uint32_t y,__uint32_t z){
	return ((x & y) ^ (~(x)&z));
};

// Majority decision
__uint32_t Maj(__uint32_t x,__uint32_t y,__uint32_t z){
	return ((x & y) ^ (x & z) ^ (y & z));
};
