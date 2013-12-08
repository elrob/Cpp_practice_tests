#include <cctype>
#include <cstring>

using namespace std;

#include "words.h"

void reverse(const char *str1, char *str2) {
  char const * const str1_start = str1;
  
  while( *str1 != '\0') //str1 points to null character
    ++str1; 
  --str1; //str1 points to character before null

  while (str1 >= str1_start)
    *str2++ = *str1--;

  *str2 = '\0';
}


bool compare(const char *str1, const char *str2) {
  if (  *str1 != '\0' && !isalpha(*str1) )
    return compare(++str1,str2);
  else if (  *str2 != '\0' && !isalpha(*str2) )
    return compare(str1,++str2);
  else if ( *str1 == '\0' && *str2 == '\0' )
    return true;
  else if ( toupper(*str1) == toupper(*str2) )
    return compare(++str1,++str2);
  else
    return false;
}
  

bool palindrome(const char *string) {
  char reversed_string[512];
  reverse(string,reversed_string);
  return compare(string,reversed_string);
}


int find_min_index(char *sorted) {
  int min_index = 0;
  int index = 0;
  while (sorted[index] != '\0') {
    if (tolower(sorted[index]) < tolower(sorted[min_index]))
      min_index = index;
    ++index;
  }
  return min_index;
}  


void recursive_sort(char *sorted) {
  if (*sorted != '\0') {
    int min_index = find_min_index(sorted);

    char temp = *sorted;
    *sorted = sorted[min_index];
    sorted[min_index] = temp;

    return recursive_sort(++sorted);
  }
}
 
void string_sort(const char *string, char *sorted) {
  strcpy(sorted,string);
  recursive_sort(sorted);
}

bool anagram(const char *str1, const char *str2) {

  char str1sorted[512];
  char str2sorted[512];

  string_sort(str1,str1sorted);
  string_sort(str2,str2sorted);

  return compare(str1sorted,str2sorted);
}

  

