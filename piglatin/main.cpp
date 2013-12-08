#include <iostream>
#include <cctype>
#include <fstream>
#include "piglatin.h"

using namespace std;

int main() {

  /* QUESTION 1 */

  cout << "====================== Question 1 ======================" << endl;

  int vowel;

  vowel = findFirstVowel("Passionfruit");
  cout << "The first vowel in 'Passionfruit' occurs at position " << vowel << endl;

  vowel = findFirstVowel("prune");
  cout << "The first vowel in 'prune' occurs at position " << vowel << endl;

  vowel = findFirstVowel("my");
  cout << "The first vowel in 'my' occurs at position " << vowel << endl;

  vowel = findFirstVowel("chrysanthemum");
  cout << "The first vowel in 'chrysanthemum' occurs at position " << vowel << endl;

  vowel = findFirstVowel("yl");
  cout << "The first vowel in 'yl' occurs at position " << vowel << endl;

  vowel = findFirstVowel("yy");
  cout << "The first vowel in 'yy' occurs at position " << vowel << endl;

  vowel = findFirstVowel("yo");
  cout << "The first vowel in 'yo' occurs at position " << vowel << endl;

  vowel = findFirstVowel("oy");
  cout << "The first vowel in 'oy' occurs at position " << vowel << endl;
  cout << endl;

  /* QUESTION 2 */

  cout << "====================== Question 2 ======================" << endl;

  char translated[100];

  translateWord("grape", translated);
  cout << "In Pig Latin 'grape' is '" << translated << "'." << endl;
  translateWord("orange", translated);
  cout << "In Pig Latin 'orange' is '" << translated << "'." << endl;
  translateWord("Banana", translated);
  cout << "In Pig Latin 'Banana' is '" << translated << "'." << endl;
  translateWord("Yellow", translated);
  cout << "In Pig Latin 'Yellow' is '" << translated << "'." << endl;
  translateWord("300", translated);
  cout << "In Pig Latin '300' is '" << translated << "'." << endl;
  translateWord("my", translated);
  cout << "In Pig Latin 'my' is '" << translated << "'." << endl;
  translateWord("Robert", translated);
  cout << "In Pig Latin 'Robert' is '" << translated << "'." << endl;
  translateWord("Speller", translated);
  cout << "In Pig Latin 'Speller' is '" << translated << "'." << endl;
  cout << endl;

  /* QUESTION 3 */
  
  cout << "====================== Question 3 ======================" << endl;

  cout << "The file 'fruit.txt' translated into Pig Latin is:" << endl << endl;
  ifstream input;
  input.open("fruit.txt");
  translateStream(input, cout);
  input.close();
  cout << endl;

  return 0;
}



