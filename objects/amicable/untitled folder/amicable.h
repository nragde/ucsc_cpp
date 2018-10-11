/*----------------------------------------------------------------
Copyright (c) 2018 Author: Jagadeesh Vasudevamurthy
file: amicable.h
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
This file has amicable class declaration
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
All includes here
-----------------------------------------------------------------*/
#ifndef amicable_H
#define amicable_H

#include "../util/util.h"

/*----------------------------------------------------------------
Declaration of amicable class
-----------------------------------------------------------------*/
class amicable {
public:
  //Nothing can be added in public
  amicable(unsigned max = 2000);
  ~amicable();
  amicable(const amicable& from) = delete;
  amicable& operator=(const amicable& from) = delete;
private:
  //WRITE CODE
  //  duplicateN(int* a, int s, bool show = false) :_a(a), _size(s), _show(show), _kount(0) {}
  //YOU can have any number of private variables
    unsigned _max; //unsigned is "unsigned int"
    unsigned int* _arr_sums;
  //YOU can have any number of private functions
    void _release();
    void _alloc(const int x[], int len);
    void _init_arr(const int x[], int len);
    void _zero_fill_arr();
    
    
    void _find_amicable_pairs();
    unsigned int _find_factor_sum(unsigned int cur_val);
    bool _is_amicable(unsigned int cur_sum, unsigned int sums_sum, unsigned int cur_val);
    unsigned int _factor_sum_loop_to_n(unsigned int cur_val);
    unsigned int _factor_sum_halfn(unsigned int cur_val);
    unsigned int _factor_sum_sqrtn(unsigned int cur_val);
    unsigned int _factor_sum_lut(unsigned int cur_val);
    
    void _fill_arr_sums(unsigned int val, unsigned int val_factor_sum);
};

#endif
//EOF

