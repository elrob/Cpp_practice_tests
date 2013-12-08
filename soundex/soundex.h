#ifndef SOUNDEX_H
#define SOUNDEX_H

const int SOUNDEX_SIZE = 4; //4 characters in soundex

void encode( const char *surname, char soundex_code[SOUNDEX_SIZE] );

char get_code( const char ch );

bool compare( const char *str1, const char *str2 );

int count( const char *surname, const char *sentence );

//void get_word( const char* sentence, char* word );

#endif //SOUNDEX_H
