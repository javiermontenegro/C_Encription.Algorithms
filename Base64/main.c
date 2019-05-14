/*********************************************************************
* Filename:   main.c
* Author:     Javier Montenegro (www.javiermontenegro.com)
* Copyright:
* Details:    Base64 tests.
*********************************************************************/

#include <stdio.h>
#include <memory.h>
#include <time.h>
#include "base64.h"

int base64_test(void);

int base64_test(void)
{
	BYTE text[3][1024] = {{"fo"},
	                      {"foobar"},
	                      {"Man is distinguished, not only by his reason, but by this singular passion from other animals, which is a lust of the mind, that by a perseverance of delight in the continued and indefatigable generation of knowledge, exceeds the short vehemence of any carnal pleasure."}};
	BYTE code[3][1024] = {{"Zm8="},
	                      {"Zm9vYmFy"},
	                      {"TWFuIGlzIGRpc3Rpbmd1aXNoZWQsIG5vdCBvbmx5IGJ5IGhpcyByZWFzb24sIGJ1dCBieSB0aGlz\nIHNpbmd1bGFyIHBhc3Npb24gZnJvbSBvdGhlciBhbmltYWxzLCB3aGljaCBpcyBhIGx1c3Qgb2Yg\ndGhlIG1pbmQsIHRoYXQgYnkgYSBwZXJzZXZlcmFuY2Ugb2YgZGVsaWdodCBpbiB0aGUgY29udGlu\ndWVkIGFuZCBpbmRlZmF0aWdhYmxlIGdlbmVyYXRpb24gb2Yga25vd2xlZGdlLCBleGNlZWRzIHRo\nZSBzaG9ydCB2ZWhlbWVuY2Ugb2YgYW55IGNhcm5hbCBwbGVhc3VyZS4="}};
	BYTE buf[1024];
	size_t buf_len;
	int pass = 1;
	int idx;

	for (idx = 0; idx < 3; idx++) {
		printf("\nPlaintext    : %s\n", text[idx]);
		
		buf_len = base64_encode(text[idx], buf, strlen(text[idx]), 1);
		pass = pass && ((buf_len == strlen(code[idx])) &&
		                 (buf_len == base64_encode(text[idx], NULL, strlen(text[idx]), 1)));
		pass = pass && !strcmp(code[idx], buf);
        printf("\n-encrypted to: %s\n", code[idx]);
		
		memset(buf, 0, sizeof(buf));
		buf_len = base64_decode(code[idx], buf, strlen(code[idx]));
		pass = pass && ((buf_len == strlen(text[idx])) &&
		                (buf_len == base64_decode(code[idx], NULL, strlen(code[idx]))));
		pass = pass && !strcmp(text[idx], buf);
		printf("\n-decrypted to: %s \n\n", buf);
	}//End for

	return(pass);
}

int main(int argc, char *argv[])
{
	clock_t start = clock();
	printf("Base64 tests: %s\n", base64_test() ? "PASSED" : "FAILED");

    clock_t end = clock();
    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;

	printf("Time spent testing: %f\n", time_spent);
	return(0);
}//End main
