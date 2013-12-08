/* --------------------------
   Filename: piglatin.cpp
   Author: Robert Speller
   Date: 3rd Janurary 2013
   -------------------------- */

#include <cstring>
#include <iostream>

using namespace std;

#include "piglatin.h"

bool isVowel( const char ch, int position, int length ) {
  char vowels[13] = "AEIOUYaeiouy";
  if ( ! ( ( ch == 'y' || ch =='Y' ) && ( position == 0 || position == length - 1 ) )
       && strchr(vowels,ch) ) 
    return true;
  return false;
}
  

int findFirstVowel( const char *word ) {
  int position = 0;
  int length = strlen(word);
  while (*word) {
    if (isVowel(*word,position,length))
      return position;
    ++position;
    ++word; //iterate along word
  }
  return -1;
}

void translateWord( const char *english, char *piglatin ) {
  if ( !isalnum(*english) ) { //unexpected input
    strcpy(piglatin,"Bad English Input"); 
    return;
  }
  
  if ( isdigit(*english) ) {
    strcpy( piglatin, english ); //if a word starts with a digit, its piglatin is the same
    return;
  }
  
  bool initial_capital = isupper(*english); //flag for starts with a capital letter
  int first_vowel_position = findFirstVowel(english);

  if ( first_vowel_position == 0 )  {
    strcpy( piglatin, english );
    strcat( piglatin, "way" ); //add 'way' if the first character is a vowel
  }
  else if ( first_vowel_position == -1 ) {
    strcpy( piglatin, english );
    strcat( piglatin, "ay" ); //add 'ay' if there is no vowel
  }
  else { // contains vowel after first letter
    strcpy( piglatin, english + first_vowel_position ); //copy ending to output
    strncat( piglatin, english, first_vowel_position ); //concatenate the beginning
    strcat( piglatin, "ay" ); //concatenate add 'ay'
  }
 
  if ( initial_capital ) { //convert first character to upper-case if the original word had a capital
    piglatin[0] = toupper(piglatin[0]);
    char *iterator = piglatin + 1;
    while (*iterator) { //ensure all other letters are lower case
      if (isupper(*iterator))
	*iterator = tolower(*iterator);
      iterator++;
    }
  }
}

void getword( istream &inputStream, char *word )  {
  char ch;
  inputStream.get(ch);
  while ( isalnum(ch) || ch == '\'' ) {
    *word++ = ch;
    inputStream.get(ch);
  }
  *word = '\0'; //add null character to 'word'
  inputStream.putback(ch); //put back the character that was read that wasn't part of 'word'
}
  
void translateStream( istream &inputStream, ostream &outputStream ) {

  char word[65];
  char translatedWord[68];
  char ch;
 
  inputStream.get(ch);
  if (inputStream.eof()) //stop recursion when the inputStream end-of-file is read.
    return;

  if ( isalnum(ch) ) { //get a word if an alphanumeric character is encountered
    inputStream.putback(ch);
    getword(inputStream, word);
    translateWord( word, translatedWord );
    outputStream << translatedWord;
  }
  else 
    outputStream << ch; //output any non alphanumeric characters directly.
  

  translateStream( inputStream, outputStream ); //recurse to the next character
}

      
