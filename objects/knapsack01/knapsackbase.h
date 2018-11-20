/*----------------------------------------------------------------
Copyright (c) 2018 Author: Jagadeesh Vasudevamurthy
file: knapsackbase.h
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
This file has knapsackbase class declaration
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
All includes here
-----------------------------------------------------------------*/
#ifndef knapsackbase_H
#define knapsackbase_H

#include "../util/util.h"

/*----------------------------------------------------------------
class knapsackbase abstract base class
NOTHING CAN BE CHANGED BELOW
-----------------------------------------------------------------*/
class knapsackbase {
public:
  knapsackbase() {}
  ~knapsackbase() {}
  knapsackbase(const knapsackbase& m) = delete;
  knapsackbase& operator = (const knapsackbase& m) = delete;

protected:
  void testbed();
  //I don't know how to write this rourine
  virtual void knapsack(const char* t, int bagsize, int numitem, const int* w, const int* v, int& ans) = 0;
};


#endif

//EOF
