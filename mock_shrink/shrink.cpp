#include <cctype>
#include <cstring>

using namespace std;

#include "shrink.h"

int lookup( const char *word, const char *dictionary[] ) {
  int encoding = 0;
  while (strcmp(*dictionary,"")) {
    if (strcmp(*dictionary,word) == 0)
      return encoding;
    ++dictionary;
    ++encoding;
  }
  return -1;
}

void intToStr(const int code, char *strcode) {
  int digit1, digit2;
  digit1 = code / 10;
  digit2 = code % 10;
  
  strcode[0] = '0' + digit1;
  strcode[1] = '0' + digit2;
  strcode[2] = '\0';
}

void encode( const char *word, char *compressed, const char *dictionary[] ) {
  if (isdigit(*word) || *word == '!') {
    strcpy(compressed,"!");
    strcat(compressed,word);
    return;
  }

  if (isalpha(*word)) {
    int code = lookup(word,dictionary);
    if (code != -1) {
      char strcode[3];
      intToStr(code,strcode);
      strcpy(compressed,strcode);
      return;
    }
  }
  strcpy(compressed,word);
}
