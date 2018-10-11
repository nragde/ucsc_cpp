/*----------------------------------------------------------------
Copyright (c) 2018 Author: Jagadeesh Vasudevamurthy
file: duplicateNTest.cpp

Tests duplicateN object
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
To compile:  ../util/util.cpp duplicateN.cpp duplicateNTest.cpp
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
all includes here
-----------------------------------------------------------------*/
//#include "../util/util.h"
#include "duplicateN.h"

/*----------------------------------------------------------------
               NOTHING CAN BE CHANGED IN THIS FILE
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
test
-----------------------------------------------------------------*/
static void test(const int* a1, int size, bool show) {
  if (show) {
    cout << "-------------------------------------\n";
  }
  util u;
  int* a = u.duplicate_array(a1, size); //Working array
  int d0 = 0;
  int d1 = 0;
  int d2 = 0;
  {
    clock_t start = clock();
    duplicateN obj(a, size, show);
    d0 = obj.nsquare_time_constant_space();
    clock_t end = clock();
    double d = double(end - start) / CLOCKS_PER_SEC;
    cout << "O(n^2)Time O(1)Space n = " << size << " CPU " << d << " secs" << endl;
    bool e = u.is_array_equal(a1, a, size);
    assert(e);
    if (show) {
      u.print_array_indices_and_contents(a, size, 4);
    }
  }
  {
    clock_t start = clock();
    duplicateN obj(a, size, show);
    d1 = obj.ntime_n_space();
    clock_t end = clock();
    double d = double(end - start) / CLOCKS_PER_SEC;
    cout << "O(n)Time O(n)Space  n = " << size << " CPU " << d << " secs" << endl;
    bool e = u.is_array_equal(a1, a, size);
    assert(e);
    if (show) {
      u.print_array_indices_and_contents(a, size, 4);
    }
  }
  {
    clock_t start = clock();
    duplicateN obj(a, size, show);
    d2 = obj.ntime_constant_space();
    clock_t end = clock();
    double d = double(end - start) / CLOCKS_PER_SEC;
    cout << "O(n)Time O(1)Space n = " << size << " CPU " << d << " secs" << endl;
    bool e = u.is_array_equal(a1, a, size);
    assert(e);
    if (show) {
      u.print_array_indices_and_contents(a, size, 4);
    }
  }
//  cout << "D0: " << d0 << endl;
//  cout << "D1: " << d1 << endl;
  assert(d0 == d1);
  assert(d1 == d2);
  if (show) {
    cout << "-------------------------------------\n";
  }
  delete[] a;
}

/*----------------------------------------------------------------
test
-----------------------------------------------------------------*/
static void test() {
  {
    const int a[] = { 1,1,1 };
    int s = sizeof(a) / sizeof(int);
    test(a, s, true);
  }
  {
    const int a[] = { 1,0,0,0 };
    int s = sizeof(a) / sizeof(int);
    test(a, s, true);
  }
  {
    const int a[] = { 1,2,3,1,3,6,6 };
    int s = sizeof(a) / sizeof(int);
    test(a, s, true);
  }
  {
    const int a[] = { 1,2,3,1,3,0,0 };
    int s = sizeof(a) / sizeof(int);
    test(a, s, true);
  }
  {
    const int a[] = { 0,0,1 };
    int s = sizeof(a) / sizeof(int);
    test(a, s, true);
  }
  {
    const int a[] = { 3,2,0,1 };
    int s = sizeof(a) / sizeof(int);
    test(a, s, true);
  }
  {
    const int N = 500000;
    for (int i = 10000; i < N; i = i + 10000) {
      int* a = new int[i];
      util u;
      u.generate_random_numbers(i, a, 0, i - 1);
      test(a, i, false);
      delete[] a;
    }
    cout << N << " Random test cases passed\n";
  }
  cout << "All test cases passed. You will get full grade now\n";
  cout << "Include only duplicateN.h duplicateN.cpp and the output of this program for FULL grade\n";
}

/*----------------------------------------------------------------
main
-----------------------------------------------------------------*/
int main() {
#ifdef _WIN32
  _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif
  test();
  return 0;
}
