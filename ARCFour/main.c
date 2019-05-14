/*********************************************************************
* Filename:   main.c
* Author:     Javier Montenegro (www.javiermontenegro.com)
* Copyright:
* Details:     ARCFOUR tests.
*********************************************************************/

#include <stdio.h>
#include <memory.h>
#include <time.h>
#include "arcfour.h"

int rc4_test(void);

int rc4_test(void)
{
	BYTE state[256];
	BYTE key[3][10] = {{"Key"}, {"Wiki"}, {"Secret"}};
	BYTE stream[3][10] = {{0xEB,0x9F,0x77,0x81,0xB7,0x34,0xCA,0x72,0xA7,0x19},
	                      {0x60,0x44,0xdb,0x6d,0x41,0xb7},
	                      {0x04,0xd4,0x6b,0x05,0x3c,0xa8,0x7b,0x59}};
	int stream_len[3] = {10,6,8};
	BYTE buf[1024];
	int idx;
	int pass = 1;

	// Only test the output stream. Note that the state can be reused.
	for (idx = 0; idx < 3; idx++) 
	 {
		arcfour_key_setup(state, key[idx], strlen(key[idx]));
		arcfour_generate_stream(state, buf, stream_len[idx]);
		pass = pass && !memcmp(stream[idx], buf, stream_len[idx]);
	 }//End for

	return(pass);
}//End rc4_test

int main(int argc, char *argv[])
{
	clock_t start = clock();
	printf("ARCFOUR tests: %s\n", rc4_test() ? "SUCCEEDED" : "FAILED");

    clock_t end = clock();
    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;

	printf("Time spent testing: %f\n", time_spent);
	return(0);
}
