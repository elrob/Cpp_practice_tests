/* --------------------------------
   Filename: correct.h
   Author: Robert Speller
   Date: 4th January 2013
   -------------------------------- */

#ifndef CORRECT_H
#define CORRECT_H

#include <cstring>

//supplied helper functions
void ascii_to_binary(char letter, char *output);
char binary_to_ascii(char *binary);


/* recursive funcion to convert all characters in string 'str' to binary versions
 * of their ASCII codes and concatenate them all to a stream of bits 'binary'
 */
void text_to_binary( const char *str, char *binary );

/* recursive function to convert a 'binary' stream of bits to a string of characters 'str',
 * converting each byte (8 bits) of 'binary' to its ASCII character equivalent.
 */
void binary_to_text( char *binary, char *str );


/* convert chars a, b, and c to integers and return char '0' if they sum to
 * an even number or '1' if they sum to an odd number.
 */
char parity( const char a, const char b, const char c );

/* overload the above function for four characters with the same return values
 */
char parity( const char a, const char b, const char c, const char d);

/* convert a set of just 4 'data' bits to its error-corrected 7-bit version and return it as 
 * 'corrected'
 */ 
void insert_bits( const char *data, char *corrected );

/* recurse through every four 'bits' in the 'data' string and append the error-corrected
 * version to 'corrected' 
 */
void add_error_correction( const char *data, char *corrected );


/* calculate which bit in 'bits_received' needs to be flipped based on the values of p1, p2, and p3
 * and flip it
 */
void correct_error( const char p1, const char p2, const char p3, char *bits_received );

/* decode 7 bits in 'received', calling 'correct_error' function above if necessary.
 * Return the decoded bits in 'decoded' and return the integer number of errors 0 or 1.
 */
int decode_part( const char *received, char *decoded );

/* recurse through every seven 'bits' in the 'received' string and append the decoded
 * version to 'decoded'. Recursively sum the errors detected and return the value as an integer. 
 */
int decode( const char *received, char *decoded );

#endif
