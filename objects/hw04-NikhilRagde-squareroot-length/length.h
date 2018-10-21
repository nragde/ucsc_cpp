/*----------------------------------------------------------------
Copyright (c) 2018 Author: Jagadeesh Vasudevamurthy
file: length.h
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
This file has length class declaration
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
All includes here
-----------------------------------------------------------------*/
#ifndef length_H
#define length_H

/*----------------------------------------------------------------
all includes here
-----------------------------------------------------------------*/
#include "../util/util.h"

/*----------------------------------------------------------------
Declaration of length class
NOTHING CAN BE CHANGED IN THIS FILE
-----------------------------------------------------------------*/
class length {
public:
  length(int* a) :_a(a){}
  ~length() {}
  length(const length& from) = delete;
  length& operator=(const length& from) = delete;
  int length_easy(int p);
  int length_tough(int p);
private:
  int* _a;
};


#endif

//EOF
