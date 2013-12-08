#ifndef SHRINK_H
#define SHRINK_H

int lookup( const char *word, const char *dictionary[] );

void intToStr(const int code, char *strcode);

void encode( const char *word, char *compressed, const char *dictionary[] );

#endif //SHRINK_H
