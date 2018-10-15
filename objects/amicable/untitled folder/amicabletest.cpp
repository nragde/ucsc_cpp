/*----------------------------------------------------------------
Copyright (c) 2014 Author: Jagadeesh Vasudevamurthy
file: amicabletest.cpp

On linux:
g++ amicable.cpp amicabletest.cpp
valgrind a.out

-----------------------------------------------------------------*/

/*----------------------------------------------------------------
This file test amicable object
             NOTHING CAN BE CHNANGED BELOW
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
All includes here
-----------------------------------------------------------------*/
#include "amicable.h"

/*----------------------------------------------------------------
DO Not use some weird formulas from internet
MUST solve from fundamentals.

Only knowledge required to solve this problem is to
compute factor and reuse computed factors.
-----------------------------------------------------------------*/
int main() {
  clock_t start = clock();
  unsigned int n = 100000000;
//  unsigned int n = 225;
//  unsigned int n = 319550;
  amicable a(n);
  clock_t end = clock();
  double d = double(end - start) / CLOCKS_PER_SEC;
  cout << "Run time for amicable for n = " << n << " is " << d << " secs" << endl;
  cout << "I will fail if you take more than 45 sec\n";
  cout << "Attach amicable.h amicable.cpp and output of the program for FULL grade " << endl;
  return 0;
}

//EOF

