/*----------------------------------------------------------------
Copyright (c) 2018 Author: Jagadeesh Vasudevamurthy
file: squareroottest.cpp

Tests squareroot object
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
To compile:  ../util/util.cpp squareroot.cpp squareroottest.cpp
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
all includes here
-----------------------------------------------------------------*/
#include "../util/util.h"
#include "squareroot.h"

/*----------------------------------------------------------------
NOTHING CAN BE CHANGED IN THIS FILE
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
test1
-----------------------------------------------------------------*/
static void test1(int n, bool show) {
  if (show) {
    cout << "---------------sqrt(" << n << ")-------------------------\n";
  }
  squareroot s(n, show);
  if (show) {
    cout << "sqrt(" << n << " )= " << s.ans() << " Num steps = " << s.steps() << endl;
  }
//  unsigned int gold = unsigned int(sqrt(n));
    unsigned int gold = unsigned(sqrt(n));
  util u;
  assert(s.ans() == gold);
}

/*----------------------------------------------------------------
test
-----------------------------------------------------------------*/
static void test() {
  const unsigned int a[] = { 0,1,2,9,10,11,24,99,100,1986,89067,4444,1230000 };
  int s = sizeof(a) / sizeof(unsigned int);
  for (int i = 0; i < s; ++i) {
//    unsigned int j = unsigned int(a[i]);
      unsigned int j = unsigned(a[i]);
    test1(j, true);
  }
  {
    const int N = 100000;
    for (int i = 0; i < N; ++i) {
      unsigned j = unsigned(i);
      test1(j, false);
    }
    cout << N << " test passed \n";
  }
}
/*----------------------------------------------------------------
main
-----------------------------------------------------------------*/
int main() {
#ifdef _WIN32
  _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif
  test();
  cout << "Attach only squareroot.cpp and output of this program as a pdf file for A grade\n";
  return 0;
}
