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
    unsigned int* _prime_nums;
    unsigned int _prime_nums_len;
  //YOU can have any number of private functions
    void _release();
    void _alloc();
    void _init_arr(const int x[], int len);
    void _zero_fill_arr(unsigned int*& arr, unsigned int len);
    
    
    void _find_amicable_pairs();
    unsigned int _find_factor_sum(unsigned int cur_val);
    bool _is_amicable(unsigned int cur_sum, unsigned int sums_sum, unsigned int cur_val);
    unsigned int _factor_sum_loop_to_n(unsigned int cur_val);
    unsigned int _factor_sum_halfn(unsigned int cur_val);
    unsigned int _factor_sum_sqrtn(unsigned int cur_val);
    unsigned int _factor_sum_sqrtn_primes(unsigned int cur_val);
//    unsigned int _factor_sum_lut(unsigned int cur_val);
    unsigned int _factor_sum_primefactorization(unsigned int cur_val);
    unsigned int _factor_sum_stackoverflow(unsigned int cur_val);
    unsigned int _factor_sum_stackoverflow2(unsigned int cur_val);
    unsigned int _factor_sum_stackoverflow3(unsigned int cur_val);
    
//    void _fill_arr_sums(unsigned int val, unsigned int val_factor_sum);
    void _fill_prime_num(unsigned int cur_prime_num);
    unsigned int _find_prime_factorization(unsigned int cur_val);
    void _print_arr(unsigned int*& arr, unsigned int len);
    unsigned int _prime_factorize(unsigned& cur_val, unsigned prime_num);
     
};

#endif
//EOF

