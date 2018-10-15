/*----------------------------------------------------------------
Copyright (c) 2018 Author: Jagadeesh Vasudevamurthy
file: squareroot.h
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
This file has squareroot class declaration
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
All includes here
-----------------------------------------------------------------*/
#ifndef squareroot_H
#define squareroot_H

/*----------------------------------------------------------------
all includes here
-----------------------------------------------------------------*/
#include "../util/util.h"

/*----------------------------------------------------------------
Declaration of squareroot class
NOTHING CAN BE CHANGED IN THIS FILE
-----------------------------------------------------------------*/
class squareroot {
public:
  squareroot(const unsigned int n, bool d = true) :_n(n), _steps(0), _ans(0), _show(d) { _sqrt_without_using_sqrt(); }
  ~squareroot() {}
  squareroot(const squareroot& from) = delete;
  squareroot& operator=(const squareroot& from) = delete;
  unsigned int ans() const { return _ans; }
  unsigned int steps() const { return _steps; }
private:
  const unsigned int _n;
  bool _show;
  unsigned int _steps;
  unsigned int _ans;
  void _sqrt_without_using_sqrt();
};


#endif

//EOF
