/* --------------------------------
   Filename: correct.cpp
   Author: Robert Speller
   Date: 4th January 2013
   -------------------------------- */

#include <iostream>

using namespace std;

#include "correct.h"

/* You are supplied with two helper functions */

/* converts a character into a binary string representation */
void ascii_to_binary(char ch, char *binary);

/* converts a binary string representation into a character */
char binary_to_ascii(char *binary);

void ascii_to_binary(char ch, char *binary) {
  for (int n = 128; n; n >>= 1) 
    *binary++ = (ch & n) ? '1' : '0';
  *binary = '\0';
}

char binary_to_ascii(char *binary) {
  int ch = 0;
  for (int n=0, slide=128; n<8; n++, slide >>= 1) {
    if (binary[n] == '1')
      ch = ch | slide;
  }
  return ch;
}

/* now add your own functions here */

void text_to_binary( const char *str, char *binary ) {
  if (*str) {
    char binary_char[9];
    ascii_to_binary(*str,binary_char);
    strcpy(binary,binary_char);
    
    //recurse using the next character in 'str' and shifting 'binary' 1 byte.
    ++str;
    binary += 8;
    text_to_binary(str,binary);
  }
  else
    *binary = '\0'; //safety feature for being supplied an empty string 'str'
}

void binary_to_text( char *binary, char *str ) {
  if (strlen(binary) >= 8) {
    char ascii_char = binary_to_ascii(binary);
    *str = ascii_char;

    //recurse using the next the next byte for the next char in 'str'
    binary += 8;
    ++str;
    binary_to_text(binary,str);
  }
  else
    *str = '\0'; //makes sure 'str' ends with the null character
}

char parity( const char a, const char b, const char c ) {
  int sum = a + b + c - 3*'0'; //convert the char sum to an int sum
  if ( sum % 2 )
    return '1';
  else 
    return '0';
}

char parity( const char a, const char b, const char c, const char d) {
  int sum = a + b + c + d - 4*'0'; //convert the char sum to an int sum
  if ( sum % 2 )
    return '1';
  else 
    return '0';
}

void insert_bits( const char *data, char *corrected ) {
  corrected[0] = parity( data[0], data[1], data[3] );
  corrected[1] = parity( data[0], data[2], data[3] );
  corrected[2] = data[0];
  corrected[3] = parity( data[1], data[2], data[3] );
  corrected[4] = data[1];
  corrected[5] = data[2];
  corrected[6] = data[3];
}

void add_error_correction( const char *data, char *corrected ) {
  if (strlen(data) >= 4) {
    insert_bits( data, corrected ); //correction for 4 data bits (7 corrected bits)
    
    //recurse for the next 4 data bits and append after the current 7 corrected bits
    data += 4;
    corrected += 7;
    add_error_correction( data, corrected );
  }
  else 
    *corrected = '\0'; //safety feature for being supplied an empty 'data'
}

void correct_error( const char p1, const char p2, const char p3, char *bits_received ) {
  //convert binary p1p2p3 to decimal int.
  int error_index = 4*(p1 - '0') + 2*(p2 - '0') + (p3 - '0');

  --error_index; // error index is one less than error bit

  (bits_received[error_index] == '0' ? ++bits_received[error_index] : --bits_received[error_index]);
}
    

int decode_part( const char *received, char *decoded ) {
  char bits_received[8];
  strncpy( bits_received, received, 7 );
  
  char p1 = parity(received[3],received[4],received[5],received[6]);
  char p2 = parity(received[1],received[2],received[5],received[6]);
  char p3 = parity(received[0],received[2],received[4],received[6]);

  int error = 0;
  if ( p1 + p2 + p3 - 3*'0' > 0 ) { //if there is an error
    correct_error( p1, p2, p3, bits_received ); //flip the correct bit in bits_received
    ++error;
  }
  
  decoded[0] = bits_received[2];
  decoded[1] = bits_received[4];
  decoded[2] = bits_received[5];
  decoded[3] = bits_received[6];

  return error;
}

int decode( const char *received, char *decoded ) {
  int errors = 0;
  if (strlen(received) >= 7) {
    errors = decode_part( received, decoded );//decode 7 'received' bits and append 4 bits to 'decoded'
    
    //recurse to the next 7 'received' bits and append the next 4 'decoded' bits
    received += 7;
    decoded += 4;
    errors += decode( received, decoded ); //recursively sum the errors
  }
  else 
    *decoded = '\0'; //ensure 'decoded' ends with the null character
  
  return errors;
}
