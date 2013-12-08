/* --------------------------
   Filename: braille.h
   Author: Robert Speller
   Date: 3rd Janurary 2013
   -------------------------- */

#ifndef BRAILLE_H
#define BRAILLE_H

#include <iostream>

const int BRAILLE_SIZE = 13; //braille for one character can be upto 12 characters and '\0'

/* returns the braille for character 'ch' in the 6-char 'string'. e.g. "0....." for 'a'.
 */
void get_braille( const char ch, char *string );

/* returns the braille for the alphabet character 'ch' which can be upper or lower case.
 * 'braille' may therefore be 6-chars or 12-chars long depending on the case of 'ch'.
 */
void alpha_braille( const char ch, char *braille );

/* returns the braille for the numeric digit 'ch'. 'braille' will be 12-chars long as it
 * includes the 'number sign' and 6-chars for the particular number.
 */
void digit_braille( const char ch, char *braille );

/* returns the braille for the punctuation character 'ch'. 'braille' will be 6-chars long.
 */
void punct_braille( const char ch, char *braille );

/* returns the 'braille' for character 'ch' and the length of the 'braille' string (6 or 12 chars).
 */
int encode_character( const char ch, char *braille );

/* recursively converts 'plaintext' to the 'braille' string. 
 */
void encode( const char *plaintext, char *braille );

/* output full braille cells of 'plaintext' with space between each cell and the plaintext
 * equivalent underneath the corresponding cell.
 */
void print_braille( const char *plaintext, ostream &output );

#endif //BRAILLE_H
