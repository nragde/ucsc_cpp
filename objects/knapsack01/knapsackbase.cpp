/*----------------------------------------------------------------
Copyright (c) 2018 Author: Jagadeesh Vasudevamurthy
file: knapsackbase.cpp
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
knapsackbase class
NOTHING CAN BE CHANGED BELOW
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
All includes here
-----------------------------------------------------------------*/
#include "knapsackbase.h"

/*----------------------------------------------------------------
testbed
-----------------------------------------------------------------*/
void knapsackbase::testbed() {
  {
    const int w[] = { 3,2,1 };
    const int v[] = { 5,3,4 };
    int numitem = sizeof(w) / sizeof(int);
    int bagsize = 5;
    int ans = 0;
    knapsack("knapsack2(k2)", bagsize, numitem, w, v, ans);
    assert(ans == 9);
  }
  {
    const int w[] = { 2,1,3,2 };
    const int v[] = { 12,10,20,15 };
    int numitem = sizeof(w) / sizeof(int);
    int bagsize = 5;
    int ans = 0;
    knapsack("knapsack1(animal)", bagsize, numitem, w, v, ans);
    assert(ans == 37);
  }
  {
    const int w[] = { 2,3,4,5 };
    const int v[] = { 3,4,5,6 };
    int numitem = sizeof(w) / sizeof(int);
    int bagsize = 5;
    int ans = 0;
    knapsack("knapsack3", bagsize, numitem, w, v, ans);
    assert(ans == 7);
  }
  {
    const int w[] = { 5,4,6,3 };
    const int v[] = { 10,40,30,50 };
    int numitem = sizeof(w) / sizeof(int);
    int bagsize = 10;
    int ans = 0;
    knapsack("knapsack4(k1)", bagsize, numitem, w, v, ans);
    assert(ans == 90);
  }
}


