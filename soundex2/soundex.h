#ifndef SOUNDEX_H
#define SOUNDEX_H

const int SOUNDEX_SIZE = 4; //characters in a soundex encoding (not including '\0').

void encode( const char *surname, char *soundex );

char get_soundex_code( const char ch );

bool compare( const char *one, const char *two );

bool get_word(const char *&sentence, char * word);

int count( const char *surname, const char *sentence );

#endif //SOUNDEX_H
