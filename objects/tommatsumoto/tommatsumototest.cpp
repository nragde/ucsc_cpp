/*----------------------------------------------------------------
Copyright (c) 2018 Author: Nikhil Ragde
file: tommatsumototest.cpp

On linux:
g++ tommatsumoto.cpp tommatsumototest.cpp
valgrind a.out

-----------------------------------------------------------------*/

/*----------------------------------------------------------------
All includes here
-----------------------------------------------------------------*/
#include "tommatsumoto.h"

/*----------------------------------------------------------------
All includes here
-----------------------------------------------------------------*/
void testbed() {
#ifdef WIN32
    const char* filename = "C:\\Users\\Nikhil\\Documents\\ucsc_cpp\\objects\\tommatsumoto\\sys_words.txt";
    const char* f2 = "C:\\Users\\Nikhil\\Documents\\ucsc_cpp\\objects\\tommatsumoto\\online_wordlist.txt";
    //http://app.aspell.net/create?defaults=en_US-large
    const char* f3 = "C:\\Users\\Nikhil\\Documents\\ucsc_cpp\\objects\\tommatsumoto\\scowl_1.txt";
    //https://github.com/dwyl/english-words/
    const char* f4 = "C:\\Users\\Nikhil\\Documents\\ucsc_cpp\\objects\\tommatsumoto\\alpha_words.txt";
#else
    const char* filename = "../tommatsumoto/sys_words.txt";
    const char* f2 = "../tommatsumoto/online_wordlist.txt";
    //http://app.aspell.net/create?defaults=en_US-large
    const char* f3 = "../tommatsumoto/scowl_1.txt";
    //https://github.com/dwyl/english-words/
    const char* f4 = "../tommatsumoto/alpha_words.txt";
#endif
    tommatsumoto o;
    o.find_words(filename);
    cout << endl;
    o.find_words(f2);
    cout << endl;
    o.find_words(f3);
    cout << endl;
    o.find_words(f4);
}

/*----------------------------------------------------------------
main
-----------------------------------------------------------------*/
int main() {
  testbed() ;
  return 0 ;
}

#if 0
// OUTPUT GOES HERE:
1. electromotivity
2. gynandrosporous
3. ornithocoprolite
4. paleophytologist
5. pterygospinous
6. siphonostomous
7. unostentatious
Number of words that have a cost of $25 = 7
Number of words worked on = 235886

1. bacteriochlorophyll
2. unostentatious
Number of words that have a cost of $25 = 2
Number of words worked on = 67598

1. antiproductively
2. bacteriochlorophyll
3. cryptanalytically
4. electromotivity
5. gynandrosporous
6. microminiaturized
7. nonincriminatory
8. nonlustrously
9. oligomerizations
10. ornithocoprolite
11. paleophytologist
12. pseudoallegoristic
13. pterygospinous
14. quasistationary
15. siphonostomous
16. supersexuality
17. unostentatious
Number of words that have a cost of $25 = 17
Number of words worked on = 515802

1. antiproductively
2. bacteriochlorophyll
3. cryptanalytically
4. electromotivity
5. gynandrosporous
6. microminiaturized
7. nonincriminatory
8. nonlustrously
9. ornithocoprolite
10. paleophytologist
11. pseudoallegoristic
12. pterygospinous
13. quasistationary
14. siphonostomous
15. unostentatious
Number of words that have a cost of $25 = 15
Number of words worked on = 370099
        
#endif

//EOF
