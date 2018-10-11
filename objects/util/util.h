/*----------------------------------------------------------------
Copyright (c) 2018 Author: Jagadeesh Vasudevamurthy
file: util.h
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
include this file for all the programs
-----------------------------------------------------------------*/
#ifndef UTIL_H
#define UTIL_H

/*----------------------------------------------------------------
Basic include files
-----------------------------------------------------------------*/
#include <iostream>
#include <fstream>

#include <iomanip>      // std::setprecision
using namespace std;

#ifdef _WIN32
#include <cassert>
#include <ctime>
#else
#include <assert.h>
#include <time.h>
#include <math.h> //required for log2
#include <string.h> //for strlen,strcat and strcpy on linux
#endif

//'sprintf': This function or variable may be unsafe. Consider using sprintf_s instead.To disable deprecation, 
//use _CRT_SECURE_NO_WARNINGS
//To overcome above warning
#ifdef _MSC_VER
#pragma warning(disable: 4996) /* Disable deprecation */
#endif


/*----------------------------------------------------------------
STL
-----------------------------------------------------------------*/
#include <stdexcept> //Without this catch will NOT work on Linux
#include <vector>
#include <string>
#include <algorithm> //for std::reverse

/*--------------------------------------------------------
class random number generator
----------------------------------------------------------*/
class Random {
public:
  Random() { srand((unsigned)time(0)); }
  int get_random_number(int a = 0, int b = 10000) const {
    int upper_bound, lower_bound;
    if (a < b) { upper_bound = b - a; lower_bound = a; } else if (a >= b) { upper_bound = a - b; lower_bound = b; }

    return(lower_bound + rand() % upper_bound);
  }
  /* no body can copy random or equal random */
  Random(const Random& x) = delete;
  Random& operator=(const Random& x) = delete;
private:

};

/*--------------------------------------------------------
util class
----------------------------------------------------------*/
class util {
public:
  util() {}
  ~util() {}

  int log2n(int n) { return int(log2(n)); }
  int nlog2n(int n) { return n * log2n(n); }

  void swap(int* a, int i, int j);
  int* duplicate_array(const int* a, int size);
  bool is_array_equal(const int* a, const int* b, int as, int bs);
  bool is_array_equal(const int* a, const int* b, int as);
  bool is_array_sorted_in_ascending_order(const int* a, int s);
  bool is_array_sorted_in_strict_ascending_order(const int* a, int s);

  void sort_array_in_ascending_order(int* a, int s);
  void sort_array_in_descending_order(int* a, int s);

  void print_array_indices(int s, int ie, int width = 4) const;
  void print_array_contents(const int* a, int s, int ie, int width = 4) const;
  void print_array_indices_and_contents(const int* a, int s, int ie, int width) const;
  void print_array_indices_and_contents(const string& t, const int* a, int s, int ie, int width) const;
  void print_array_indices_and_contents(const int* a, int n, int width) const;
  void print_array_indices_and_contents(const string& t, const int* a, int n, int width = 4) const;
  void print_array_indices_and_contents(const string& t, const int* a, const int* b, int n, int width = 4) const;
  void generate_random_numbers(int n, int* a, int min, int max) const;
  void generate_numbers_in_ascending_order(int n, int* a, int start, int steps) const;
  void generate_numbers_in_descending_order(int n, int* a, int start, int steps) const;
  void shuffle_an_array(int* a, int max);

  //String routine
  void appendString(string& s, char c);
  void appendString(string& s, int n);

  int strcmp(const char* s1, const char* s2);
  void strcpy(char* s1, const char* s2);
  void print_integer(const int& x);
  void print_integer(const int*& x);
  void print_integer(int& x);
  void print_integer(int*& x);
  int int_ascending_order(const int& c1, const int& c2);
  int int_ascending_order(int* const& c1, int* const& c2);
  int int_descending_order(const int& c1, const int& c2);
  int int_descending_order(int* const& c1, int* const& c2);
  void delete_int(int*& c);
  void delete_charstar(char*& c);
  int charcompare(const char& c1, const char& c2);
  void print_char(char& c);
  void print_string(char*& c);
  void free_string(char*& c);
  int string_descending_order(char* const& c1, char* const& c2);
  int string_ascending_order(char* const& c1, char* const& c2);

  /* no body can copy random or equal random */
  util(const util& x) = delete;
  util& operator=(const util& x) = delete;
private:

};

#endif

//EOF

