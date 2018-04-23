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
	const char* filename = "C:\\Users\\Nikhil\\Documents\\ucsc_cpp\\objects\\tommatsumoto\\sys_words.txt";
	const char* f2 = "C:\\Users\\Nikhil\\Documents\\ucsc_cpp\\objects\\tommatsumoto\\online_wordlist.txt";
	//http://app.aspell.net/create?defaults=en_US-large
	const char* f3 = "C:\\Users\\Nikhil\\Documents\\ucsc_cpp\\objects\\tommatsumoto\\scowl_1.txt";
	//https://github.com/dwyl/english-words/
	const char* f4 = "C:\\Users\\Nikhil\\Documents\\ucsc_cpp\\objects\\tommatsumoto\\alpha_words.txt";
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

//EOF
