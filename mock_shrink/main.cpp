#include <iostream>

using namespace std;

#include "shrink.h"

int main() {

  const char* dictionary[] = { "iguana", "aardvark", "swimming",
			       "Zambezi", "river", "rescue", "" };

  int word;
  word = lookup("iguana", dictionary);
  cout << "iguana: " << word << endl;
  word = lookup("aardvark", dictionary);
  cout << "aardvark: " << word << endl;
  word = lookup("Zambezi", dictionary);
  cout << "Zambezi: " << word << endl;
  word = lookup("resq", dictionary);
  cout << "resq: " << word << endl;

  char compressed[100];
  encode("Zambezi", compressed, dictionary);
  cout << "Zambezi compressed: " << compressed << endl;
  encode("elephant", compressed, dictionary);
  cout << "elephant compressed: " << compressed << endl;
  encode("05", compressed, dictionary);
  cout << "05 compressed: " << compressed << endl;
  encode("!hallo", compressed, dictionary);
  cout << "!hallo compressed: " << compressed << endl;


  return 0;
}
