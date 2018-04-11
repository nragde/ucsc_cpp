/*----------------------------------------------------------------
Copyright (c) 2018 Author: Jagadeesh Vasudevamurthy
file: reversetest.cpp

On linux:
g++ reverse.cpp reversetest.cpp
valgrind a.out

-----------------------------------------------------------------*/

/*----------------------------------------------------------------
YOU CANNOT CHANGE ANYTHING IN THIS FILE 
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
This file test reverse object 
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
All includes here
-----------------------------------------------------------------*/
#include "reverse.h"

/*----------------------------------------------------------------
All includes here
-----------------------------------------------------------------*/
void testbed() {
  reverse1 o;
  const unsigned long a[] = {0,1,10,9,1000,0xFFFFFFFE,0xFFFFFFFF,0xFFFFFFFD,0xA7FFFF0,1234567,765432} ;
  const unsigned long e[] =   {0,1,1,9,1,0,0,3927694924,257061671,7654321,234567} ;
  int s = sizeof(a)/sizeof(unsigned long) ;
  for (int i = 0; i < s; ++i) {
    unsigned long n = a[i] ;
    unsigned long b = e[i] ;
    unsigned long a = o.r(n) ;
    cout << "n = " << setw(10) << n  << " = " << setw(10) << a << " Expected = " << setw(10)<< b <<endl ;
    assert(a == b) ;
  }
  unsigned long first = o.firstFail() ;
  cout << "The first long number for which reverse fails = " << first << endl ;
  unsigned long shouldnotfail = first - 1;
  unsigned long x = o.r(shouldnotfail) ;
  assert(x != 0) ;
  unsigned long shouldfail = first + 1;
  x = o.r(shouldfail) ;
  assert(x == 0) ;
}

/*----------------------------------------------------------------
main
-----------------------------------------------------------------*/
int main() {
  testbed() ;
  cout << "All reverse tests passed. You are amazing\n" ;
  return 0 ;
}

//EOF
