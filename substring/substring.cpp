#include <iostream>
#include <cstring>

using namespace std;

#include "substring.h"

bool is_prefix( const char *str1, const char *str2) {
  if ( *str1 == '\0' )
    return true;
  else if ( *str1 != *str2 )
    return false;
  else
    return is_prefix( ++str1, ++str2 );
}
    
int substring_position( const char *str1, const char *str2 ) {
  int n = 0;
  do {
    if ( is_prefix( str1, str2 ) )
      return n;
    ++n; }
  while ( *str2++ != '\0' ); 
  return -1;
}

int substring_position2( const char *a, const char *b ) {
  return(a=strstr(b,a))?a-b:-1;
}

