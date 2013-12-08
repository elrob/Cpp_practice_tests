#include <cctype>
#include <cstring>

using namespace std;

#include "soundex.h"

char get_soundex_code( const char ch ) {
  if (isalpha(ch)) {
    switch(tolower(ch)) {
    case 'b': case 'f': case 'p': case 'v': 
      return '1';
    case 'c': case 'g': case 'j': case 'k': case 'q': case 's': case 'x': case 'z': 
      return '2';
    case 'd': case 't':
      return '3';
    case 'l':
      return '4';
    case 'm': case 'n':
      return '5';
    case 'r':
      return '6';
    default:
      return '0'; //sentinel value
    }
  }
  return '0';
}

void encode( const char *surname, char *soundex ) {
  *soundex = toupper(*surname++);

  int soundex_index = 1;

  while (*surname && soundex_index < SOUNDEX_SIZE) {
    char soundex_code = get_soundex_code( *surname );
    if ( soundex_code != '0' && soundex_code != get_soundex_code( *(surname + 1) ) ) {
      soundex[soundex_index++] = soundex_code;
    }
    ++surname;
  }
	
  while (soundex_index < SOUNDEX_SIZE ) 
    soundex[soundex_index++] = '0';

  soundex[soundex_index] = '\0';
}


bool compare( const char *one, const char *two ) {
  if (!(*one) && !(*two)) 
    return true;
  else if ( *one != *two )
    return false;
  else
    return compare(++one,++two);
}


bool get_word(const char *&sentence, char *word) {
  while(*sentence && !isalpha(*sentence))
    ++sentence;
  if (!*sentence) 
    return false;
  else {
    while(isalpha(*sentence)) 
      *word++ = *sentence++;
    *word = '\0';
    return true;
  }
}

int count( const char *surname, const char *sentence ) {
  char surname_soundex[SOUNDEX_SIZE + 1]; //+1 for the null character
  encode(surname,surname_soundex);
  
  int count = 0;
 
  char word[512]; 
  while (get_word(sentence,word)) {
 
    char word_soundex[SOUNDEX_SIZE + 1];
    encode(word,word_soundex);

    if (strcmp(surname_soundex,word_soundex) == 0) 
      ++count;
  }
  
  return count;
}
  
