#ifndef WORDS_H
#define WORDS_H

const int LETTERS_IN_ALPHABET = 26;

/* return a copy of str1 with the characters reversed as str2. 
 * str2 memory should have already been allocated and be 
 * sufficient to hold the output string and sentinel character.
 */
void reverse( const char *str1, char *str2 );

/* return true (1) if strings one and two are equivalent
 * comparing only their letters and not comparing letter case.
 */
bool compare( const char *one, const char *two );

/* return true (1) if sentence is a palindrome - it is the same
 * forwards as it is backwards, discounting all punctuation and
 * letter case.
 */
bool palindrome( const char *sentence );

/* recursive function to return the integer letters_array filled
 * with the number of each letter found in string. each letter is
 * mapped to its index in the alphabet. i.e. letters_array[0] holds
 * the number of a's found in string. letters_array must be at least
 * 26 integers in size.
 */
void get_letters( const char *string, int *letters_array );

/* return true (1) if array1 and array2 of size 'size' are equal.
 */
bool equal_int_arrays( const int *array1, const int *array2, const int size );

/* return true (1) if str2 is an anagram of str2 discounting all
 * punctuation and letter case.
 */
bool anagram( const char *str1, const char *str2 );

#endif  // WORDS_H
