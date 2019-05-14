/*********************************************************************
* Filename:   rot-13.h
* Author:     Javier Montenegro (www.javiermontenegro.com)
* Copyright:
* Details:    Defines the API for the corresponding ROT-13 implementation.
*********************************************************************/

#ifndef ROT13_H
#define ROT13_H


#include <stddef.h>


// Performs IN PLACE rotation of the input. Assumes input is NULL terminated.
// Preserves each charcter's case. Ignores non alphabetic characters.
void rot13(char str[]);

#endif   // ROT13_H
