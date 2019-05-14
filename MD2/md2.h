/*********************************************************************
* Filename:   md2.h
* Author:     Javier Montenegro (www.javiermontenegro.com)
* Copyright:
* Details:    Defines the API for the corresponding MD2 implementation.
*********************************************************************/

#ifndef MD2_H
#define MD2_H


#include <stddef.h>

#define MD2_BLOCK_SIZE 16

typedef unsigned char BYTE;             // 8-bit byte

typedef struct {
   BYTE data[16];
   BYTE state[48];
   BYTE checksum[16];
   int len;
} MD2_CTX;

void md2_init(MD2_CTX *ctx);
void md2_update(MD2_CTX *ctx, const BYTE data[], size_t len);
void md2_final(MD2_CTX *ctx, BYTE hash[]);   // size of hash must be MD2_BLOCK_SIZE

#endif   // MD2_H
