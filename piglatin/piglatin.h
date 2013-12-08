/* --------------------------
   Filename: piglatin.h
   Author: Robert Speller
   Date: 3rd Janurary 2013
   -------------------------- */

#ifndef PIGLATIN_H
#define PIGLATIN_H

#include <fstream>

using namespace std;

/* returns true if 'ch' at 'position' in a word of 'length' is a vowel according to piglatin rules.
 * this function is not case-sensitive - 'e' and 'E' both return true.
 */
bool isVowel( const char ch, int position, int length );

/* returns the index of the first vowel in string 'word' or -1
 */
int findFirstVowel( const char *word );

/* translates an 'english' word to its 'piglatin' equivalent. 
 */
void translateWord( const char *english, char *piglatin );

/* returns a word from inputStream. A string of alphanumeric characters and apostrophes ' 
 * inputStream is left so it will read the character directly after the word.
 */
void getword( istream &inputStream, char *word );

/* recursively translates inputStream into piglatin and outputs it to outputStream. 
 * Words from inputStream must only be upto 64 chars long.
 */
void translateStream( istream &inputStream, ostream &outputStream );

#endif //PIGLATIN_H
