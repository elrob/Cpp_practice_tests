#include <cctype>

using namespace std;

#include "words.h"

void reverse( const char *str1, char *str2 ) {
  const char *str1_end = str1;  //a second pointer pointing to str1
  
  while (*str1_end != '\0' )    //point to the sentinel character
    ++str1_end;
  --str1_end;                   //point to the previous character

  while ( str1_end >= str1 )    //copy characters to str2 going backwards
    *str2++ = *str1_end--;      //through str1 until reaching the start.
  *str2 = '\0';                 //add the sentinel character to str2
}


bool compare( const char *one, const char *two ) {
  while ( !( isalpha(*one) || *one == '\0') ) //skip to next letter or sentinel
    ++one;
  while ( !( isalpha(*two) || *two == '\0') ) //skip to next letter or sentinel
    ++two;

  if ( *one == '\0' && *two == '\0' )         //both reached sentinel
    return true;

  else if ( *one == '\0' || *two == '\0' ||   //only one reached sentinel
	    toupper(*one) != toupper(*two) )  //or characters not equivalent
    return false;

  else                                        //equivalent characters
    return compare(++one, ++two);
}


bool palindrome( const char *sentence ) {
  char reversed[512];
  reverse( sentence, reversed );
  return compare(sentence,reversed);
}

void get_letters( const char *string, int *letters_array ) {
  //increment the array element for the particular letter
  if (isalpha(*string))
    ++letters_array[ toupper(*string) - 'A' ]; 
    
  // recurse through string character by character
  if ( *string != '\0' )
    get_letters( ++string, letters_array );
}

bool equal_int_arrays( const int *array1, const int *array2, const int size ) {
  for ( int n = 0; n < size; n++ )
    if ( array1[n] != array2[n] )
      return false;
  return true;
}

bool anagram( const char *str1, const char *str2 ) {
  //integer arrays to hold the totals of each letter for both strings
  int str1_letters[LETTERS_IN_ALPHABET] = {0}; //initialise to 0's
  int str2_letters[LETTERS_IN_ALPHABET] = {0};
  get_letters( str1, str1_letters );
  get_letters( str2, str2_letters );
  return equal_int_arrays(str1_letters, str2_letters, LETTERS_IN_ALPHABET);
}
