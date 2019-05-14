/*********************************************************************
* Filename:   main.c
* Author:     Javier Montenegro (www.javiermontenegro.com)
* Copyright:
* Details:    ROT13 tests.
*********************************************************************/


#include <stdio.h>
#include <string.h>
#include <time.h>
#include "rot13.h"

int rot13_test(void);

int rot13_test(void)
{
	char text[] = {"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"};
	char code[] = {"NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm"};
	char buf[1024];
	int pass = 1;

	// To encode, just apply ROT-13.
	strcpy(buf, text);
	rot13(buf);
	pass = pass && !strcmp(code, buf);

	// To decode, just re-apply ROT-13.
	rot13(buf);
	pass = pass && !strcmp(text, buf);

	return(pass);
}

int main(int argc, char *argv[])
{
	clock_t start = clock();
	printf("ROT-13 tests: %s\n", rot13_test() ? "SUCCEEDED" : "FAILED");

    clock_t end = clock();
    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;

	printf("Time spent testing: %f\n", time_spent);
	return(0);
}//End main
