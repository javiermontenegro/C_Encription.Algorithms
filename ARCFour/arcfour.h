/*********************************************************************
* Filename:   arcfour.h
* Author:     Javier Montenegro (https://javiermontenegro.github.io/)
* Copyright:
* Details:    Defines the API for the corresponding ARCFOUR implementation.
*********************************************************************/

#ifndef ARCFOUR_H
#define ARCFOUR_H

#include <stddef.h>

typedef unsigned char BYTE;             // 8-bit byte

// Input: state - the state used to generate the keystream
//        key - Key to use to initialize the state
//        len - length of key in bytes (valid lenth is 1 to 256)
void arcfour_key_setup(BYTE state[], const BYTE key[], int len);

// Pseudo-Random Generator Algorithm
// Input: state - the state used to generate the keystream
//        out - Must be allocated to be of at least "len" length
//        len - number of bytes to generate
void arcfour_generate_stream(BYTE state[], BYTE out[], size_t len);

#endif   // ARCFOUR_H
