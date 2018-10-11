/*----------------------------------------------------------------
Copyright (c) 2014 Author: Jagadeesh Vasudevamurthy
file: duplicateN.h
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
This file has duplicateN class declaration
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
All includes here
-----------------------------------------------------------------*/
#ifndef duplicateN_H
#define duplicateN_H

/*----------------------------------------------------------------
all includes here
-----------------------------------------------------------------*/
#include "../util/util.h"

/*----------------------------------------------------------------
Declaration of duplicateN class
-----------------------------------------------------------------*/
class duplicateN {
public:
  duplicateN(int* a, int s, bool show = false) :_a(a), _size(s), _show(show), _kount(0) {}
  ~duplicateN() {}
  duplicateN(const duplicateN& from) = delete;
  duplicateN& operator=(const duplicateN& from) = delete;
  int nsquare_time_constant_space();
  int ntime_n_space();
  int ntime_constant_space();
private:
  int* _a;
  int  _size;
  bool _show;
  int _kount;
  void _zero_arr(int*& arr, int size);
  bool _check_before(int i, int cur_val);
  bool _check_after(int i, int cur_val);
  void _print_dupe(int dupe_val, bool& first_dupe);
};


#endif

//EOF
