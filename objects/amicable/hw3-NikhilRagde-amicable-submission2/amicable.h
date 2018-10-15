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
  //YOU can have any number of private variables
    unsigned _max; //unsigned is "unsigned int"
    unsigned int* _arr;
    unsigned int _arr_len;
  //YOU can have any number of private functions
    void _release();
    void _alloc();
    void _zero_fill_arr(unsigned int*& arr, unsigned int len, unsigned int fill_val = 0);
    
    void _find_amicable_pairs();
    unsigned int _find_factor_sum(unsigned int cur_val);
    bool _is_amicable(unsigned int cur_sum, unsigned int sums_sum, unsigned int cur_val);
    unsigned int _factor_sum_loop_to_n(unsigned int cur_val);
    unsigned int _factor_sum_halfn(unsigned int cur_val);
    unsigned int _factor_sum_sqrtn(unsigned int cur_val);
    unsigned int _factor_sum_primefactorization(unsigned int cur_val);
    
    void _find_pairs_classsolution();
    void _fill_factor_sums();
    unsigned int _verify_amicable_pair(unsigned int N);
    
    void _fill_prime_num(unsigned int cur_prime_num);
    unsigned int _find_prime_factorization(unsigned int cur_val);
    void _print_arr(unsigned int*& arr, unsigned int len);
    unsigned int _prime_factorize(unsigned& cur_val, unsigned prime_num);
     
};

#endif
//EOF

