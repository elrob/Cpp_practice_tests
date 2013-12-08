#include <iostream>
#include "words.h"

using namespace std;

int main() {

  /*** QUESTION 1 ***/
  char reversed[9];
  reverse("lairepmi", reversed);
  cout << "'lairepmi' reversed is '" << reversed << "'" << endl;
  reverse("desserts", reversed);
  cout << "'desserts' reversed is '" << reversed << "'" << endl;
  reverse("robert", reversed);
  cout << "'robert' reversed is '" << reversed << "'" << endl;
  reverse("speller", reversed);
  cout << "'speller' reversed is '" << reversed << "'" << endl;
  reverse("2", reversed);
  cout << "'2' reversed is '" << reversed << "'" << endl;
  reverse("s o s", reversed);
  cout << "'s o s' reversed is '" << reversed << "'" << endl;
  reverse("", reversed);
  cout << "'' reversed is '" << reversed << "'" << endl << endl;


  /*** QUESTION 2 ***/
  cout << "The strings 'this, and THAT......' and 'THIS and THAT!!!' are ";
  if (!compare("this, and THAT......", "THIS and THAT!!!"))
    cout << "NOT ";
  cout << "the same" << endl << "  (ignoring punctuation and case)" << endl;
  
  cout << "The strings 'this, and THAT' and 'THIS, but not that' are ";
  if (!compare("this, and THAT", "THIS, but not that")) 
    cout << "NOT ";
  cout << "the same" << endl << "  (ignoring punctuation and case)" << endl << endl;

  /*** QUESTION 3 ***/
 
  cout << "The string 'rotor' is ";
  if (!palindrome("rotor"))
    cout << "NOT ";
  cout << "a palindrome." << endl;

  cout << "The string 'Madam I'm adam' is ";
  if (!palindrome("Madam I'm adam"))
    cout << "NOT ";
  cout << "a palindrome." << endl;

  cout << "The string 'Madam I'm not adam' is ";
  if (!palindrome("Madam I'm not adam"))
    cout << "NOT ";
  cout << "a palindrome." << endl;

  cout << "The string 'Radar' is ";
  if (!palindrome("Radar"))
    cout << "NOT ";
  cout << "a palindrome." << endl;

  cout << "The string 'A man, a plan, a canal, Panama!' is ";
  if (!palindrome("A man, a plan, a canal, Panama!"))
    cout << "NOT ";
  cout << "a palindrome." << endl;

  cout << "The string 'Mr. Owl ate my metal worm.' is ";
  if (!palindrome("Mr. Owl ate my metal worm."))
    cout << "NOT ";
  cout << "a palindrome." << endl;

  cout << "The string 'a. ..' is ";
  if (!palindrome("a. .."))
    cout << "NOT ";
  cout << "a palindrome." << endl;


  cout << "The string '.. ..!' is ";
  if (!palindrome(".. ..!"))
    cout << "NOT ";
  cout << "a palindrome." << endl;


  cout << "The string 'Robert Speller' is ";
  if (!palindrome("Robert Speller"))
    cout << "NOT ";
  cout << "a palindrome." << endl << endl;


  /*** QUESTION 4 ***/

  cout << "The string 'I am a weakish speller!' is ";
  if (!anagram("I am a weakish speller!", "William Shakespeare"))
    cout << "NOT ";
  cout << "an anagram of 'William Shakespeare'" << endl;

  cout << "The string 'I am a good speller!' is ";
  if (!anagram("I am a good speller!", "William Shakespeare"))
    cout << "NOT ";
  cout << "an anagram of 'William Shakespeare'" << endl;

  cout << "The string 'stain' is ";
  if (!anagram("stain", "satin"))
    cout << "NOT ";
  cout << "an anagram of 'satin'" << endl;

  cout << "The string 'Here come dots...' is ";
  if (!anagram("Here come dots...", "The Morse Code"))
    cout << "NOT ";
  cout << "an anagram of 'The Morse Code'" << endl;

  cout << "The string 'Mother-in-law' is ";
  if (!anagram("Mother-in_law", "Woman Hitler"))
    cout << "NOT ";
  cout << "an anagram of 'Woman Hitler'" << endl;

  cout << "The string 'Robert Speller' is ";
  if (!anagram("Robert Speller", "Robert Spellor"))
    cout << "NOT ";
  cout << "an anagram of 'Robert Spellor'" << endl;

  cout << endl;
  return 0;
}
