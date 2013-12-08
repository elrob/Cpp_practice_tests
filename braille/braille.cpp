/* --------------------------
   Filename: braille.cpp
   Author: Robert Speller
   Date: 3rd Janurary 2013
   -------------------------- */

#include <cstring>
#include <cctype>

using namespace std;

#include "braille.h"

void get_braille( const char ch, char *string ) {
  switch (ch) {
  case 'a': strcpy(string,"0....."); break;
  case 'b': strcpy(string,"00...."); break;
  case 'c': strcpy(string,"0..0.."); break;
  case 'd': strcpy(string,"0..00."); break;
  case 'e': strcpy(string,"0...0."); break;
  case 'f': strcpy(string,"00.0.."); break;
  case 'g': strcpy(string,"00.00."); break;
  case 'h': strcpy(string,"00..0."); break;
  case 'i': strcpy(string,".0.0.."); break;
  case 'j': strcpy(string,".0.00."); break;
  case 'k': strcpy(string,"0.0..."); break;
  case 'l': strcpy(string,"000..."); break;
  case 'm': strcpy(string,"0.00.."); break;
  case 'n': strcpy(string,"0.000."); break;
  case 'o': strcpy(string,"0.0.0."); break;
  case 'p': strcpy(string,"0000.."); break;
  case 'q': strcpy(string,"00000."); break;
  case 'r': strcpy(string,"000.0."); break;
  case 's': strcpy(string,".000.."); break;
  case 't': strcpy(string,".0000."); break;
  case 'u': strcpy(string,"0.0..0"); break;
  case 'v': strcpy(string,"000..0"); break;
  case 'w': strcpy(string,".0.000"); break;
  case 'x': strcpy(string,"0.00.0"); break;
  case 'y': strcpy(string,"0.0000"); break;
  case 'z': strcpy(string,"0.0.00"); break;
  default: strcpy(string,"NotA2Z"); //error!
    }
}

void alpha_braille( const char ch, char *braille ) {
  char letter[BRAILLE_SIZE];
  get_braille(tolower(ch),letter);
    
  if (isupper(ch)) {
    strcpy(braille,".....0"); //'capital sign'
    strcat(braille,letter);
  }
  else
    strcpy( braille, letter );
}

void digit_braille( const char ch, char *braille ) {
  char letter[BRAILLE_SIZE];
  strcpy( braille, "..0000" ); //'number sign'
  
  if ( ch == '0' ) 
    get_braille( 'j', letter ); //char '0' has the same encoding as 'j'
  else 
    get_braille( 'a' + (ch - '1'), letter ); //chars '1' to '9' have the same encodings as 'a' to 'h'
  
  strcat( braille, letter);
}

void punct_braille( const char ch, char *braille ) {
  switch (ch) {
  case '.': strcpy(braille,".0..00"); break;
  case ',': strcpy(braille,".0...."); break;
  case ';': strcpy(braille,".00..."); break;
  case '-': strcpy(braille,"..0..0"); break;
  case '!': strcpy(braille,".00.0."); break;
  case '?': strcpy(braille,".00..0"); break;
  case '(': case')': strcpy(braille,".00.00"); break;
  default: strcpy( braille,"......" ); //any punctuation character not listed
  }
}

int encode_character( const char ch, char *braille ) {
  braille[0] = '\0'; //in case the character is 'ch' is '\0'

  if (isalpha(ch)) 
    alpha_braille( ch, braille );
  else if (isdigit(ch))
    digit_braille( ch, braille );
  else if (ispunct(ch))
    punct_braille( ch, braille );
  else 
    strcpy(braille,"......");
  
  return strlen(braille);
}

void encode( const char *plaintext, char *braille ) {
  if (*plaintext) {
    char letter[BRAILLE_SIZE];
    int size = encode_character( *plaintext, letter );
    strcpy( braille, letter );

    //recurse to the next char in plaintext and append its braille conversion to 'braille'
    braille += size;
    encode( ++plaintext, braille);
  }
}

void print_braille( const char *plaintext, ostream &output ) {
  char braille[512];
  encode( plaintext, braille );
  int braille_length = strlen(braille);
  
  //output 3 lines of braille dots to produce the full braille cells
  for ( int line = 1; line < 4; line++ ) {
    int n = line - 1;
    while (n < braille_length) {
      output << braille[n];
      n += 3;
      output << braille[n] << " ";
      n += 3;
    }
    output << endl;
  }
  
  //output the plaintext underneath the braille cells
  while (*plaintext) {
    char braille_char[BRAILLE_SIZE];
    int braille_chars = encode_character( *plaintext, braille_char ) / 6;
    for ( int n = 1; n < braille_chars; ++n )
      output << "   ";
    output << *plaintext << "  ";
    ++plaintext;
  }
  output << endl;
}
  
