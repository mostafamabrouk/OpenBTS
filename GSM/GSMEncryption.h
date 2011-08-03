/*
 *  A3A8.h
 *  
 *
 *  Created by Mostafa Mabrouk on 4/7/11.
 *  Copyright 2011 Home. All rights reserved.
 *
 */
#ifndef TEST

#include <stdio.h>
#include <string.h>
#include <cctype>
#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include <stdint.h>
#include <math.h>

#include <ControlCommon.h>
#include <GSMCommon.h>
#include <GSMConfig.h>

#define TEST 

typedef unsigned char Byte;

class A3A8Class {
private:

    Byte kc[8];

public:
    Byte simoutput[12];

    void A3A8(/* in */ Byte* rand, /* in */ Byte* ki) {

	
	static const Byte table_0[512] = {
        102,177,186,162,  2,156,112, 75, 55, 25,  8, 12,251,193,246,188,
        109,213,151, 53, 42, 79,191,115,233,242,164,223,209,148,108,161,
        252, 37,244, 47, 64,211,  6,237,185,160,139,113, 76,138, 59, 70,
         67, 26, 13,157, 63,179,221, 30,214, 36,166, 69,152,124,207,116,
        247,194, 41, 84, 71,  1, 49, 14, 95, 35,169, 21, 96, 78,215,225,
        182,243, 28, 92,201,118,  4, 74,248,128, 17, 11,146,132,245, 48,
        149, 90,120, 39, 87,230,106,232,175, 19,126,190,202,141,137,176,
        250, 27,101, 40,219,227, 58, 20, 51,178, 98,216,140, 22, 32,121,
         61,103,203, 72, 29,110, 85,212,180,204,150,183, 15, 66,172,196,
         56,197,158,  0,100, 45,153,  7,144,222,163,167, 60,135,210,231,
        174,165, 38,249,224, 34,220,229,217,208,241, 68,206,189,125,255,
        239, 54,168, 89,123,122, 73,145,117,234,143, 99,129,200,192, 82,
        104,170,136,235, 93, 81,205,173,236, 94,105, 52, 46,228,198,  5,
         57,254, 97,155,142,133,199,171,187, 50, 65,181,127,107,147,226,
        184,218,131, 33, 77, 86, 31, 44, 88, 62,238, 18, 24, 43,154, 23,
         80,159,134,111,  9,114,  3, 91, 16,130, 83, 10,195,240,253,119,
        177,102,162,186,156,  2, 75,112, 25, 55, 12,  8,193,251,188,246,
        213,109, 53,151, 79, 42,115,191,242,233,223,164,148,209,161,108,
         37,252, 47,244,211, 64,237,  6,160,185,113,139,138, 76, 70, 59,
         26, 67,157, 13,179, 63, 30,221, 36,214, 69,166,124,152,116,207,
        194,247, 84, 41,  1, 71, 14, 49, 35, 95, 21,169, 78, 96,225,215,
        243,182, 92, 28,118,201, 74,  4,128,248, 11, 17,132,146, 48,245,
         90,149, 39,120,230, 87,232,106, 19,175,190,126,141,202,176,137,
         27,250, 40,101,227,219, 20, 58,178, 51,216, 98, 22,140,121, 32,
        103, 61, 72,203,110, 29,212, 85,204,180,183,150, 66, 15,196,172,
        197, 56,  0,158, 45,100,  7,153,222,144,167,163,135, 60,231,210,
        165,174,249, 38, 34,224,229,220,208,217, 68,241,189,206,255,125,
         54,239, 89,168,122,123,145, 73,234,117, 99,143,200,129, 82,192,
        170,104,235,136, 81, 93,173,205, 94,236, 52,105,228, 46,  5,198,
        254, 57,155, 97,133,142,171,199, 50,187,181, 65,107,127,226,147,
        218,184, 33,131, 86, 77, 44, 31, 62, 88, 18,238, 43, 24, 23,154,
        159, 80,111,134,114,  9, 91,  3,130, 16, 10, 83,240,195,119,253
    }, table_1[256] = {
         19, 11, 80,114, 43,  1, 69, 94, 39, 18,127,117, 97,  3, 85, 43,
         27,124, 70, 83, 47, 71, 63, 10, 47, 89, 79,  4, 14, 59, 11,  5,
         35,107,103, 68, 21, 86, 36, 91, 85,126, 32, 50,109, 94,120,  6,
         53, 79, 28, 45, 99, 95, 41, 34, 88, 68, 93, 55,110,125,105, 20,
         90, 80, 76, 96, 23, 60, 89, 64,121, 56, 14, 74,101,  8, 19, 78,
         76, 66,104, 46,111, 50, 32,  3, 39,  0, 58, 25, 92, 22, 18, 51,
         57, 65,119,116, 22,109,  7, 86, 59, 93, 62,110, 78, 99, 77, 67,
         12,113, 87, 98,102,  5, 88, 33, 38, 56, 23,  8, 75, 45, 13, 75,
         95, 63, 28, 49,123,120, 20,112, 44, 30, 15, 98,106,  2,103, 29,
         82,107, 42,124, 24, 30, 41, 16,108,100,117, 40, 73, 40,  7,114,
         82,115, 36,112, 12,102,100, 84, 92, 48, 72, 97,  9, 54, 55, 74,
        113,123, 17, 26, 53, 58,  4,  9, 69,122, 21,118, 42, 60, 27, 73,
        118,125, 34, 15, 65,115, 84, 64, 62, 81, 70,  1, 24,111,121, 83,
        104, 81, 49,127, 48,105, 31, 10,  6, 91, 87, 37, 16, 54,116,126,
         31, 38, 13,  0, 72,106, 77, 61, 26, 67, 46, 29, 96, 37, 61, 52,
        101, 17, 44,108, 71, 52, 66, 57, 33, 51, 25, 90,  2,119,122, 35
    }, table_2[128] = {
         52, 50, 44,  6, 21, 49, 41, 59, 39, 51, 25, 32, 51, 47, 52, 43,
         37,  4, 40, 34, 61, 12, 28,  4, 58, 23,  8, 15, 12, 22,  9, 18,
         55, 10, 33, 35, 50,  1, 43,  3, 57, 13, 62, 14,  7, 42, 44, 59,
         62, 57, 27,  6,  8, 31, 26, 54, 41, 22, 45, 20, 39,  3, 16, 56,
         48,  2, 21, 28, 36, 42, 60, 33, 34, 18,  0, 11, 24, 10, 17, 61,
         29, 14, 45, 26, 55, 46, 11, 17, 54, 46,  9, 24, 30, 60, 32,  0,
         20, 38,  2, 30, 58, 35,  1, 16, 56, 40, 23, 48, 13, 19, 19, 27,
         31, 53, 47, 38, 63, 15, 49,  5, 37, 53, 25, 36, 63, 29,  5,  7
    }, table_3[64] = {
          1,  5, 29,  6, 25,  1, 18, 23, 17, 19,  0,  9, 24, 25,  6, 31,
         28, 20, 24, 30,  4, 27,  3, 13, 15, 16, 14, 18,  4,  3,  8,  9,
         20,  0, 12, 26, 21,  8, 28,  2, 29,  2, 15,  7, 11, 22, 14, 10,
         17, 21, 12, 30, 26, 27, 16, 31, 11,  7, 13, 23, 10,  5, 22, 19
    }, table_4[32] = {
         15, 12, 10,  4,  1, 14, 11,  7,  5,  0, 14,  7,  1,  2, 13,  8,
         10,  3,  4,  9,  6,  0,  3,  2,  5,  6,  8,  9, 11, 13, 15, 12
    }, *table[5] = { table_0, table_1, table_2, table_3, table_4 };

        Byte x[32], bit[128];
        int i, j, k, l, m, n, y, z, next_bit;

        /* ( Load RAND into last 16 bytes of input ) */
        for (i = 16; i < 32; i++)
            x[i] = rand[i - 16];

        /* ( Loop eight times ) */
        for (i = 1; i < 9; i++) {
            /* ( Load key into first 16 bytes of input ) */
            for (j = 0; j < 16; j++)
                x[j] = ki[j];
            /* ( Perform substitutions ) */
            for (j = 0; j < 5; j++)
                for (k = 0; k < (1 << j); k++)
                    for (l = 0; l < (1 << (4 - j)); l++) {
                        m = l + k * (1 << (5 - j));
                        n = m + (1 << (4 - j));
                        y = (x[m] + 2 * x[n]) % (1 << (9 - j));
                        z = (2 * x[m] + x[n]) % (1 << (9 - j));
                        x[m] = table[j][y];
                        x[n] = table[j][z];
                    }
            /* ( Form bits from bytes ) */
            for (j = 0; j < 32; j++)
                for (k = 0; k < 4; k++)
                    bit[4 * j + k] = (x[j] >> (3 - k)) & 1;
            /* ( Permutation but not on the last loop ) */
            if (i < 8)
                for (j = 0; j < 16; j++) {
                    x[j + 16] = 0;
                    for (k = 0; k < 8; k++) {
                        next_bit = ((8 * j + k)*17) % 128;
                        x[j + 16] |= bit[next_bit] << (7 - k);
                    }
                }
        }

        /*
         * ( At this stage the vector x[] consists of 32 nibbles.
         *   The first 8 of these are taken as the output SRES. )
         */

        /* The remainder of the code is not given explicitly in the
         * standard, but was derived by reverse-engineering.
         */

        for (i = 0; i < 4; i++)
            simoutput[i] = (x[2 * i] << 4) | x[2 * i + 1];
        for (i = 0; i < 6; i++)
            simoutput[4 + i] = (x[2 * i + 18] << 6) | (x[2 * i + 18 + 1] << 2)
            | (x[2 * i + 18 + 2] >> 2);
        simoutput[4 + 6] = (x[2 * 6 + 18] << 6) | (x[2 * 6 + 18 + 1] << 2);
        simoutput[4 + 7] = 0;

LOG(DEBUG) << "simoutput = " << simoutput;

    };

    uint64_t getKC() {
        Byte Kc[8];
        uint64_t KCuint_64=0;
	int k=0;
	int i;
        for (i = 0; i < 8; i++) {
            Kc[i] = simoutput[i + 4];
        }
        for (i = 7;i>=0 ; i--){
            for(int j=7; j>=0 ; j--){
                KCuint_64 = KCuint_64 + ( (Kc[i] >> (7-j) ) & 1)*pow(2,k);
		k++;
            }
        }
        return KCuint_64;
    };

	unsigned int getSRES(){
		Byte SRES[4];
        	unsigned int SRESint=0;
		int k=0;
		int i;
        	for (i = 0; i < 4; i++) {
        	    SRES[i] = simoutput[i];
        	}
        	for (i = 3;i>=0 ; i--){
        	    for(int j=7; j>=0 ; j--){
        	        SRESint = SRESint + ( (SRES[i] >> (7-j) ) & 1)*pow(2,k);
			k++;
        	    }
        	}
        return SRESint;
	}

    A3A8Class() {
    };
};

class A51 {
    static const uint32_t R1MASK = 0x07FFFF; /* 19 bits, numbered 0..18 */
    static const uint32_t R2MASK = 0x3FFFFF; /* 22 bits, numbered 0..21 */
    static const uint32_t R3MASK = 0x7FFFFF; /* 23 bits, numbered 0..22 */

    // majority bit
    /* Middle bit of each of the three shift registers, for clock control */
    static const uint32_t R1MID = 8; /* bit 8 */
    static const uint32_t R2MID = 10; /* bit 10 */
    static const uint32_t R3MID = 10; /* bit 10 */

    /* Feedback taps, for clocking the shift registers. */
    static const uint32_t R1TAPS = 0x072000; /* bits 18,17,16,13 */
    static const uint32_t R2TAPS = 0x300000; /* bits 21,20 */
    static const uint32_t R3TAPS = 0x700080; /* bits 22,21,20,7 */

    /* Output taps, for output generation */
    static const uint32_t R1OUT = 18; /* bit 18 (the high bit) */
    static const uint32_t R2OUT = 21; /* bit 21 (the high bit) */
    static const uint32_t R3OUT = 22; /* bit 22 (the high bit) */
    // xor the taps and return the LSB as it contains the result of xoring

	

    static int parity32(uint32_t x) {
        x ^= x >> 16;
        x ^= x >> 8;
        x ^= x >> 4;
        x ^= x >> 2;
        x ^= x >> 1;
        return x & 1;
    };

    static int majority(uint32_t R1, uint32_t R2, uint32_t R3) {
        int sum;
        sum = (R1 >> R1MID & 1) + (R2 >> R2MID & 1) + (R3 >> R3MID & 1);
        if (sum >= 2)
            return 1;
        else
            return 0;
    };

    static int getbit(uint32_t R1, uint32_t R2, uint32_t R3) {
        return (R1 >> R1OUT ^ R2 >> R2OUT ^ R3 >> R3OUT) & 1;
    };

    static uint32_t clockone(uint32_t reg, uint32_t mask, uint32_t taps) {
        uint32_t t = reg & taps; // select tap bits only
        reg = (reg << 1) & mask;
        reg |= parity32(t);
        return reg;
    };

    uint32_t R1, R2, R3;

public:

    void keysetup(uint64_t kc,uint32_t frameno) {
	
	R1 = R2 = R3 = 0; //initialization
        for (int i = 0; i < 64; ++i) {
            R1 = clockone(R1, R1MASK, R1TAPS) ^ ((kc >> i) & 1); // return register after clocking
            R2 = clockone(R2, R2MASK, R2TAPS) ^ kc >> i & 1;
            R3 = clockone(R3, R3MASK, R3TAPS) ^ kc >> i & 1;
        }
        for (int i = 0; i < 22; ++i) {
            R1 = clockone(R1, R1MASK, R1TAPS) ^ frameno >> i & 1;
            R2 = clockone(R2, R2MASK, R2TAPS) ^ frameno >> i & 1;
            R3 = clockone(R3, R3MASK, R3TAPS) ^ frameno >> i & 1;
        }
        for (int i = 0; i < 100; ++i) {
            int maj = majority(R1, R2, R3);
            if ((R1 >> R1MID & 1) == maj)
                R1 = clockone(R1, R1MASK, R1TAPS);
            if ((R2 >> R2MID & 1) == maj)
                R2 = clockone(R2, R2MASK, R2TAPS);
            if ((R3 >> R3MID & 1) == maj)
                R3 = clockone(R3, R3MASK, R3TAPS);
        }
    };

	
	int generate_keystream_bit() {
	    int maj = majority(R1, R2, R3);

	    if ((R1 >> R1MID & 1) == maj)
	      R1 = clockone(R1, R1MASK, R1TAPS);

	    if ((R2 >> R2MID & 1) == maj)
	      R2 = clockone(R2, R2MASK, R2TAPS);

	    if ((R3 >> R3MID & 1) == maj)
	      R3 = clockone(R3, R3MASK, R3TAPS);

	    int res = getbit(R1, R2, R3);

	    return res;
	  }	
    int* generateKeystream() {
        int keyStream[228];
        int maj = majority(R1, R2, R3);
        int ks = 0;
        for (int i = 0; i < 114; i++) {
            if ((R1 >> R1MID & 1) == maj)
                R1 = clockone(R1, R1MASK, R1TAPS);

            if ((R2 >> R2MID & 1) == maj)
                R2 = clockone(R2, R2MASK, R2TAPS);

            if ((R3 >> R3MID & 1) == maj)
                R3 = clockone(R3, R3MASK, R3TAPS);
            ks = getbit(R1, R2, R3);
            keyStream[i] = ks;
        }
        return keyStream;
    };
};

#endif

