/*----------------------------------------------------------------
Copyright (c) 2018 Author: Jagadeesh Vasudevamurthy
file: lengthtest.cpp

Tests length object
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
To compile:  ../util/util.cpp length.cpp lengthtest.cpp
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
all includes here
-----------------------------------------------------------------*/
#include "../util/util.h"
#include "length.h"

/*----------------------------------------------------------------
NOTHING CAN BE CHANGED IN THIS FILE
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
test 1
-----------------------------------------------------------------*/
static void test1(const  int* o, int s, int p, bool show) {
  util u;
  int* a = u.duplicate_array(o, s);
  length l1(a);
  int x = l1.length_easy(p);
  if (show) {
    cout << "length_easy y = " << x << endl;
  }

  int* b = u.duplicate_array(o, s);
  length l2(b);
  int y = l2.length_tough(p);
  if (show) {
    cout << "length_tough y = " << y << endl;
  }
  assert(y == x);

  /* make sure contents are same */
  assert(u.is_array_equal(a, b, s));
  if (show) {
    cout << "Assert passed" << endl;
  }
}

/*----------------------------------------------------------------
test
-----------------------------------------------------------------*/
static void test() {
  {
    const  int o[] = { 5,1,0,4,2,3 }; //Orig array
    int s = sizeof(o) / sizeof(int);
    test1(o, s, 3, true);
  }
  {
    const  int o[] = { 5,1,0,4,2,3 }; //Orig array
    int s = sizeof(o) / sizeof(int);
    for (int i = 0; i < s; ++i) {
      test1(o, s, i, true);
    }
  }
  {
    util u;
    const int N = 5000;
    int o[N];
    u.generate_numbers_in_ascending_order(N, o, 0, 1);
    u.shuffle_an_array(o, N);
    for (int i = 0; i < N; ++i) {
      test1(o, N, i, false);
    }
    cout << N << " Random tests passed\n";
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
  cout << "You are genius. Bring a box of candies for me\n";
  cout << "Attach only length.cpp and output of this program as a pdf file for A grade\n";
  return 0;
}

