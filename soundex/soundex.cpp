#include <iostream>
#include <cstdlib>
#include <cctype>
#include <cstring>

using namespace std;

#include "soundex.h"

void encode( const char *surname, char soundex_code[SOUNDEX_SIZE + 1] ) {
  if ( ! isalpha(*surname) ) {
    cout << "Error: Invalid surname entered!\n";
    exit(1);
  }
    
  soundex_code[SOUNDEX_SIZE] = '\0';
  soundex_code[0] = toupper(*surname++);

  int code_it = 1;
  char char_code, previous_char_code = '0';

  while ( code_it < SOUNDEX_SIZE ) {
    if ( *surname == '\0' )
      soundex_code[code_it++] = '0';
    else {
      char_code = get_code(*surname++);
      if ( char_code > '0' && char_code != previous_char_code )
	soundex_code[code_it++] = char_code;
      previous_char_code = char_code;
    }
  } 
}

// version below was more messy but did the same job

// void encode( const char *surname, char soundex_code[SOUNDEX_SIZE + 1] ) {
//   soundex_code[SOUNDEX_SIZE] = '\0';
//   soundex_code[0] = toupper(*surname++);
 
//   bool adjacent_flag = false;
//   int code_it = 1;
//   while ( code_it < SOUNDEX_SIZE ) {
//     if ( *surname == '\0' ) 
//       soundex_code[code_it++] = '0';
//     else {
//       char code = get_code(*surname++);
//       if ( code > '0' && 
// 	   ( adjacent_flag == false || 
// 	     !(soundex_code[code_it-1] == code) ) ) {
// 	soundex_code[code_it++] = code;
// 	adjacent_flag = true;
//       }
//       else if ( code == '0' )  
// 	adjacent_flag = false;
//     }
//   }
// }


char get_code( const char ch ) {
  switch (toupper(ch)) {
  case 'B': case 'F': case 'P': case 'V': 
    return '1';
  case 'C': case 'G': case 'J': case 'K': case 'Q': case 'S': case 'X': case 'Z':
    return '2';
  case 'D': case 'T':
    return '3';
  case 'L': 
    return '4';
  case 'M': case 'N':
    return '5';
  case 'R':
    return '6';
  default:
    return '0';
  }
}

// bool compare( const char *str1, const char *str2 ) {
//   return ( strcmp(str1,str2) == 0 ? 1 : 0 );
// }

// Version above uses strcmp, version below doesn't.

bool compare( const char *str1, const char *str2 ) {
  if ( *str1 == '\0' && *str2 == '\0' )
    return true;
  else if ( *str1 != *str2 )
    return false;
  else
    return compare(++str1,++str2);
}


int count( const char *surname, const char *sentence ) {
  char surname_soundex_code[SOUNDEX_SIZE + 1];
  encode( surname, surname_soundex_code );

  int count = 0;
  while ( *sentence != '\0' ) { //could use while ( *sentence )
    if ( isalpha(*sentence) ) {
      
      char word[512];
      int n = 0;
      while ( isalpha(*sentence) ) 
	word[n++] = *sentence++;
      word[n] = '\0';
      
      //get_word(sentence,word);
      //while ( isalpha(*++sentence) );
      
      char word_soundex_code[SOUNDEX_SIZE + 1];
      encode( word, word_soundex_code );
      
      if ( compare(surname_soundex_code,word_soundex_code ) )
	++count;
    }
    else
      ++sentence;
  }
  return count;
}

// void get_word( const char * sentence, char* word ) {
//   int n = 0;
//   while ( isalpha(*sentence) ) 
//     word[n++] = *sentence++;
//   word[n] = '\0';
// }
  
  
