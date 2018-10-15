/*----------------------------------------------------------------
Copyright (c) 2018 Author: Jagadeesh Vasudevamurthy
file: amicable.cpp
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
This file has amicable class definition
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
All includes here
-----------------------------------------------------------------*/
#include "amicable.h"

/*----------------------------------------------------------------
WRITE YOUR CODE HERE
-----------------------------------------------------------------*/
//#define _DEBUG1     0
//#define _DEBUG2     2
//#define _DEBUG3     3
//#define _DEBUG4     4
//#define _DEBUG5     5
//#define _PRINTPRIMES    6
#define _USEARR     7

//Constructor
amicable::amicable(unsigned max):
    _max(max), _arr(nullptr), _arr_len(0){
    //Allocate heap space, zero it out, and fill if necessary
#ifdef _USEARR
    _alloc();
#endif
        
//    _find_amicable_pairs();
        _find_pairs_classsolution();
}

amicable::~amicable(){
    //Empty since there's no dynamically allocated memory to release
#ifdef _USEARR
    _release();
#endif
}

//Helper functions
void amicable::_release(){
    delete [] _arr;
}

void amicable::_alloc(){
    //LOOK_HERE: This is probably too much allocation...
    _arr = new unsigned int[_max+1];
    unsigned int fill_val = 1;
    _zero_fill_arr(_arr, _max+1, fill_val);
    _arr[0] = 0;
    /*
    _zero_fill_arr(_arr, _max);
    _arr[0] = 2;
    ++_arr_len;
    _arr[1] = 3;
    ++_arr_len;
     */
    
//    _print_arr(_arr, _arr_len);
}
//Create and zero out the elements
void amicable::_zero_fill_arr(unsigned int*& _arr, unsigned int len, unsigned int fill_val){
    for(int i = 0; i < len; ++i){
        _arr[i] = fill_val;
    }
}

/* SOLUTION FROM THE CLASS (FOR A B+!)*/

void amicable::_find_pairs_classsolution(){
    //First, fill with factors
    _fill_factor_sums();
    int num_pairs = 0;
    //Then, loop through the array and see if each element has an amicable pair
    for(int i = 0; i <= _max; ++i){
        //Get the amicable pair, if it exists
        unsigned int j = _verify_amicable_pair(i);
        //We want to make sure that both are within the "max" limits
        if(j > i && j < _max){
            //Print out both (if wanted)
            cout << num_pairs << ": " << i << " & " << j << endl;
            ++num_pairs;
        }
    }
    cout << "TOTAL NUMBER: " << num_pairs << endl;
}

void amicable::_fill_factor_sums(){
    //The array should be filled with 1s, except for _arr[0] == 0
    //This means 0 & 1 are filled properly
    for(unsigned int i = 2; (i*i) <= _max; ++i){
        //Multiply i by all of the next integers
        unsigned int k = i;
        while(1){
            unsigned int product = i*k;
            //If the product is outside of our array, we're done
            if(product > _max){
                break;
            }
            //If the numbers are the same, do not double add
            if(i == k){
                _arr[product] += i;
            }
            //Otherwise, add both divisor and quotient
            else{
                _arr[product] += i + k;
            }
            //Don't forget to increment!
            ++k;
        }
    }
    
}

unsigned int amicable::_verify_amicable_pair(unsigned int N){
    //Get the factor sum
    unsigned int sum1 = _arr[N];
    //If the sum is outside the bounds, skip it since it's outside the bounds
    if(sum1 <= _max){
        //Get the factor sum of the factor sum
        unsigned int sum2 = _arr[sum1];
        //If this is the same as the initial number, we've found a pair!
        if(sum2 == N){
            return sum1;
        }
    }
    return 0;
}




/* SOLUTION FROM THE CLASS (FOR A B+!)*/



void amicable::_find_amicable_pairs(){
    int total_num = 0;
    //We've filled in 2 & 3 as the first two primes, and we know 4 is neither a prime number nor an amicable pair
    unsigned int cur_val = 5;
    for(; cur_val <= _max; ++cur_val){
#ifdef _DEBUG1
        cout << "CURRENT NUMBER: " << cur_val << endl;
#endif
        //Find sum of factors
        unsigned int cur_sum = _find_factor_sum(cur_val);
        //If cur_sum is 1, it's a prime number, so skip to the next number
#ifdef _DEBUG5
        cout << "CUR_VAL: " << cur_val << " , CUR_SUM: " << cur_sum << endl;
#endif
        if(cur_sum != 1){
            //Find sum of factors of sum of factors (from previous step)
    #ifdef _DEBUG3
            cout << "cur_sum: " << cur_sum << endl;
    #endif
            unsigned int sums_sum = _find_factor_sum(cur_sum);
    #ifdef _DEBUG3
            cout << "sums_sum: " << sums_sum << endl;
    #endif
            
            //Are they a pair
            bool is_pair = _is_amicable(cur_sum, sums_sum, cur_val);
            if(is_pair){
                cout << total_num << ": " << cur_val << " and " << cur_sum << endl;
                total_num++;            
            }
        }
#ifdef _USEARR
            else{
#ifdef _DEBUG5
                cout << "THIS NUMBER IS PRIME! " << cur_val << endl;
#endif
                _fill_prime_num(cur_val);
            }
#endif
        
    }
#ifdef _PRINTPRIMES
    cout << "PRIMES!!!!!!!!!!!" <<endl;
    _print_arr(_arr, _arr_len);
#endif
    cout << "TOTAL NUMBER: " << total_num << endl;
}

unsigned int amicable::_find_factor_sum(unsigned int cur_val){
//    unsigned int factor_sum = _factor_sum_loop_to_n(cur_val);
//    unsigned int factor_sum = _factor_sum_halfn(cur_val);
//    unsigned int factor_sum = _factor_sum_sqrtn(cur_val);
    unsigned int factor_sum = _factor_sum_primefactorization(cur_val);
    return factor_sum;
}

bool amicable::_is_amicable(unsigned int cur_sum, unsigned int sums_sum, unsigned int cur_val){
    bool is_pair = false;
    //If the sum of the sums and the current val are the same, 
    //we're potentially an amicable pair
    if(sums_sum == cur_val){
#ifdef _DEBUG2
        cout << "\n\nCURRENT NUMBER: " << cur_val << endl;
        cout << sums_sum << " (sums_sum) == (cur_val) " << cur_val << endl;
#endif
        //But we need to check that it's not the same value 
        //(e.g: cur_val = 6 would give 6 which gives 6)
        if(cur_sum != cur_val){
#ifdef _DEBUG2
            cout << cur_sum << " (cur_sum) != (cur_val) " << cur_val << endl;
#endif
            //For printing purposes, we only want to print out the sum if we've found it for the first time
            if(cur_val < cur_sum){
#ifdef _DEBUG2
                cout << cur_val << " (cur_val) < (cur_sum) " << cur_sum << endl;
#endif
                is_pair = true;
            }
        }        
    }
    return is_pair;
}



unsigned int amicable::_factor_sum_primefactorization(unsigned int cur_val){
    //Factors are from 1 until the number (non-inclusive)
    // EX: 10 --> 1, 2, 5 == 7
    //      Note: 10 is NOT included as a factor
    // PRIME FACTORIZATION:
    //Non-prime numbers can be expressed as a product of prime numbers 
    //raised to some value:
    //  N = p1^m * p2^n
    //Factors are then p1^(0...m)*p2^(0...n)
    //To get the sum of the factors, you need to do:
    //  p1^0*p2^0 + p1^1+p2^0 + ... + p1^m*p2^0 + p1^1+p2^1 +.... + p1^m*p2^n 
    //          - p1^m*p2^n (since we don't want to include N itself in the sum)
    //  This simplifies to (1 + p1^1 + p1^2 + .... + p1^m)*(1+p2^1 + p2^2 + ... p2^n)
    //  
    unsigned int init_val = cur_val;
    unsigned int factor_sum = 1;
#ifdef _DEBUG4
        cout << "factors of " << cur_val << ": ";
#endif
    
    unsigned int loop_limit = sqrt(min(cur_val,_max));
    //Loop through known prime numbers up to (inclusive) the sqrt(cur_val)
    for(int i = 0; _arr[i] <= loop_limit; ++i){
        unsigned int prime_num = _arr[i];
        if(prime_num == 0){
            break;
        }
        factor_sum *= _prime_factorize(cur_val, prime_num);
        if(cur_val == 1){
            break;
        }
    }
    
    //What about the case of 15?
    //  15 = 3^1*5^1
    //But floor(sqrt(15)) ~= 3
    //  So factor_sum would be 4 (3^0+3^1), but cur_val would be 5 (15/3)
    //  This means we need to correct for these cases where the remaining prime factor is Px^1:
    //  In the example:
    //      The sum would be 1 + 3 + 5 + 15 = 24
    //      (3^0+3^1) * X = 24 ==> X = 6
    //      The 6 comes from: 5^0 + 5^1
    // So, if cur_val is not 1 (completely factored) at the end, add the prime value cur_val is at and 1
    if(cur_val != 1){
        factor_sum *= cur_val + 1;
    }
    //At this point, if factor_sum is 1, it's a prime number
    //But if it's NOT a prime number, then we've included N = p1^m*p2^n in factor_sum
    // We need to subtract that out to meet how an amicable pair is defined
    if(factor_sum > 1){
        factor_sum -= init_val;
    }
    //1 will always be a factor, which is why the loop starts at 2
    return factor_sum;
}

void amicable::_fill_prime_num(unsigned int cur_prime_num){
    //We don't care about saving prime numbers greater than the sqrt of the _max value
    if(cur_prime_num <= sqrt(_max)){
        //Check that the current value at "_prime_num_len" holds a 0, if not
        // increment so that the next empty value is picked
        if(_arr[_arr_len] != 0){
            ++_arr_len;
        }
        //Verify that the current number is greater than the previous number
        if(_arr_len != 0 && _arr[_arr_len-1] < cur_prime_num){
        //Put in the current prime number and then increment the length var
            _arr[_arr_len] = cur_prime_num;
            ++_arr_len;
        }
        else if(_arr_len == 0){
            //Put in the current prime number and then increment the length var
            _arr[_arr_len] = cur_prime_num;
            ++_arr_len;
        }
    }
}

unsigned int amicable::_prime_factorize(unsigned int &N, unsigned int prime){
    //Non-prime numbers can be expressed as a product of prime numbers
    //  raised to some value:
    //  N = p1^m * p2^n
    //Factors are then p1^(0...m)*p2^(0...n)
    //To get the sum of the factors, you need to do:
    //  p1^0*p2^0 + p1^1+p2^0 + ... + p1^m*p2^0 + p1^1+p2^1 +.... + p1^m*p2^n 
    //          - p1^m*p2^n (since we don't want to include N itself in the sum)
    //  This simplifies to (1 + p1^1 + p1^2 + .... + p1^m)*(1+p2^1 + p2^2 + ... p2^n)
    //  
    
    //In this function, we figure out if a specific Pi (i=0...._arr_len)
    // is a prime factor of N
    //If it is, we keep going until we figure out whole sum of this 1+Pi^1+...+Pi^m
    unsigned int Pi_sum = 1;
    unsigned int prime_raised = prime;
//    unsigned int remainder = N%prime;
    while(N%prime == 0){
        //If it is a factor
        Pi_sum += prime_raised;
        prime_raised *= prime;
        N /= prime;
    }

    return Pi_sum;
}

void amicable::_print_arr(unsigned int*& arr, unsigned int len){
    for(int i = 0; i < len; ++i){
        cout << i << ": " << arr[i] << endl;
    }
}

/*******************************
 OTHER ATTEMPTED METHODS
 *******************************/

unsigned int amicable::_factor_sum_loop_to_n(unsigned int cur_val){
    int factor_sum = 0;
    //Factors are from 1 until the number (non-inclusive)
    // EX: 10 --> 1, 2, 5 == 7
    //      Note: 10 is NOT included as a factor
    #ifdef _DEBUG1
        cout << "factors of " << cur_val << ": ";
#endif
    for(int f = 1; f < cur_val; ++f){
        //If the remainder is 0, add to the sum!

        if(cur_val%f == 0){
#ifdef _DEBUG1
        cout << " " << f;
#endif
            factor_sum += f;
        }
    }
#ifdef _DEBUG1
        cout << "\nfactor sum: " << factor_sum << endl;
#endif
        
        return factor_sum;
    
}

unsigned int amicable::_factor_sum_halfn(unsigned int cur_val){
    int factor_sum = 0;
    //Factors are from 1 until the number (non-inclusive)
    // EX: 10 --> 1, 2, 5 == 7
    //      Note: 10 is NOT included as a factor
    #ifdef _DEBUG3
        cout << "factors of " << cur_val << ": ";
#endif
//        if(cur_val == 1){
//            return 1;
//        }
    unsigned int loop_limit = cur_val/2-1;
    for(int f = 2; f < loop_limit; ++f){ //LOOK HERE: WHAT ARE THE BOUNDS?
        //If the remainder is 0, add to the sum!
        if(cur_val%f == 0){
#ifdef _DEBUG3
        cout << " " << f;
#endif      
            factor_sum += f;
            unsigned int other_factor = cur_val/f;
            if(other_factor >= loop_limit && other_factor != cur_val && other_factor != f){
#ifdef _DEBUG3
        cout << " " << other_factor;
#endif     
                factor_sum += other_factor;    
            }
        }
    }
#ifdef _DEBUG3
        cout << "\nfactor sum: " << factor_sum << endl;
#endif
        return factor_sum + 1;
}

unsigned int amicable::_factor_sum_sqrtn(unsigned int cur_val){
    int factor_sum = 0;
    //Factors are from 1 until the number (non-inclusive)
    // EX: 10 --> 1, 2, 5 == 7
    //      Note: 10 is NOT included as a factor
#ifdef _DEBUG4
    cout << "factors of " << cur_val << ": ";
#endif
    //    if(cur_val == 1){
    //        return 1;
    //    }
    
    //POTENTIAL OPTIMIZATION:
    //  f*f < cur_val
    //  do 2 on its own, then do odd numbers
    unsigned int loop_limit = sqrt(cur_val);
    for(int f = 2; f <= loop_limit; ++f){ //LOOK HERE: WHAT ARE THE BOUNDS?
        //If the remainder is 0, add to the sum!
        if(cur_val%f == 0){
#ifdef _DEBUG3
            cout << " " << f;
#endif
            factor_sum += f;
            unsigned int other_factor = cur_val/f;
            if(other_factor >= loop_limit && other_factor != cur_val && other_factor != f){
#ifdef _DEBUG3
                cout << " " << other_factor;
#endif
                factor_sum += other_factor;
            }
        }
    }
#ifdef _DEBUG4
    cout << "\nfactor sum: " << factor_sum << endl;
#endif
    //1 will always be a factor, which is why the loop starts at 2
    return factor_sum + 1;
}

//EOF
