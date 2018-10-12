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
#define _PRINTPRIMES    6

//Constructor
amicable::amicable(unsigned max):
    _max(max), _prime_nums(nullptr), _prime_nums_len(0){
    //Allocate heap space, zero it out, and fill if necessary
    _alloc();
    _find_amicable_pairs();
}

amicable::~amicable(){
    //Empty since there's no dynamically allocated memory to release
    _release();
}

//Helper functions
void amicable::_release(){
    delete [] _prime_nums;
}

//void iset64::_copy(const iset64& set){
//    if(show()){
//    cout << "In _copy!" << endl;
//    }
//    _len = set._len;
//    _arr = new int[NUM_ELEMENTS];
//    for(int i = 0; i < NUM_ELEMENTS; ++i){
//        _arr[i] = set._arr[i];
//    }
//}
void amicable::_alloc(){
    //LOOK_HERE: This is probably too much allocation...
    _prime_nums = new unsigned int[_max];
    _zero_fill_arr(_prime_nums, _max);
    _prime_nums[0] = 2;
    ++_prime_nums_len;
    _prime_nums[1] = 3;
    ++_prime_nums_len;
}  
//Create and zero out the elements
void amicable::_zero_fill_arr(unsigned int*& _arr, unsigned int len){
    for(int i = 0; i < len; ++i){
        _arr[i] = 0;
    }
}

void amicable::_find_amicable_pairs(){
    int total_num = 0;
    //We've filled in 2 & 3 as the first two primes, and we know 4 is neither a prime number nor an amicable pair
    unsigned int cur_val = 5;
//    int i = 220; //The first valid amicable pair
    for(cur_val; cur_val <= _max; ++cur_val){
#ifdef _DEBUG1
        cout << "CURRENT NUMBER: " << cur_val << endl;
#endif
        //Find sum of factors
        unsigned int cur_sum = _find_factor_sum(cur_val);
        //If cur_sum is 1, it's a prime number, so skip to the next number
        if(cur_sum != 1){
            //Find sum of factors of sum of factors (from previous step)
    #ifdef _DEBUG3
            cout << "cur_sum: " << cur_sum << endl;
    #endif
            unsigned int sums_sum = _find_factor_sum(cur_sum);
    #ifdef _DEBUG3
            cout << "sums_sum: " << sums_sum << endl;
    #endif

            
//            cout << endl << endl;
            
            
            //Are they a pair
            bool is_pair = _is_amicable(cur_sum, sums_sum, cur_val);
            if(is_pair){
                cout << total_num << ": " << cur_val << " and " << cur_sum << endl;
                total_num++;            
            }
        }
        else{
#ifdef _DEBUG5
            cout << "THIS NUMBER IS PRIME! " << cur_val << endl;
#endif
            _fill_prime_num(cur_val);
        }
    }
#ifdef _PRINTPRIMES
    cout << "PRIMES!!!!!!!!!!!" <<endl;
    _print_arr(_prime_nums, _prime_nums_len);
#endif
    cout << "TOTAL NUMBER: " << total_num << endl;
}

unsigned int amicable::_find_factor_sum(unsigned int cur_val){
//    unsigned int factor_sum = _factor_sum_loop_to_n(cur_val);
//    unsigned int factor_sum = _factor_sum_halfn(cur_val);
//    unsigned int factor_sum = _factor_sum_sqrtn(cur_val);
//    unsigned int factor_sum = _factor_sum_sqrtn_primes(cur_val);
//    unsigned int factor_sum = _factor_sum_lut(cur_val);
    unsigned int factor_sum = _factor_sum_primefactorization(cur_val);
//    unsigned int factor_sum = _factor_sum_stackoverflow(cur_val);
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

unsigned int amicable::_factor_sum_sqrtn_primes(unsigned int cur_val){
    int factor_sum = 0;
    //Factors are from 1 until the number (non-inclusive)
    // EX: 10 --> 1, 2, 5 == 7
    //      Note: 10 is NOT included as a factor
#ifdef _DEBUG4
        cout << "factors of " << cur_val << ": ";
#endif    
    //POTENTIAL OPTIMIZATION: 
    //  f*f < cur_val
    //  do 2 on its own, then do odd numbers
    unsigned int loop_limit = sqrt(cur_val);
    
    //FIRST: check if it's even
    if(cur_val%2 == 0){
        factor_sum += 2;
        unsigned int other_factor = cur_val/2;
        if(other_factor >= loop_limit && other_factor != cur_val && other_factor != 2){
            factor_sum += other_factor;    
        }
    }
    //ONLY THEN: check all odd numbers up until sqrt(N) 
    //  (floor'd, but that's what casting does anyway)
    for(int f = 3; f < loop_limit; f+=2){ //LOOK HERE: WHAT ARE THE BOUNDS?
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
//        if(factor_sum == 0){
//#ifdef _DEBUG5
//            cout << "THIS NUMBER IS PRIME! " << cur_val << endl;
//#endif
//            _fill_prime_num(cur_val);
//        }
        //1 will always be a factor, which is why the loop starts at 2
        return factor_sum + 1;
}

unsigned int amicable::_factor_sum_primefactorization(unsigned int cur_val){
    //Non-prime numbers can be expressed as a product of prime numbers 
    //raised to some value:
    //  N = p1^m * p2^n
    //Factors are then p1^(0...m)*p2^(0...n)
    //To get the sum of the factors, you need to do:
    //  p1^0*p2^0 + p1^1+p2^0 + ... + p1^m*p2^0 + p1^1+p2^1 +.... + p1^m*p2^n 
    //          - p1^m*p2^n (since we don't want to include N itself in the sum)
    //  This simplifies to (1 + p1^1 + p1^2 + .... + p1^m)*(1+p2^1 + p2^2 + ... p2^n)
    //  
    
    
    //Go through numbers
    //If it's a prime number, no prime numbers will divide by it; add to array
    //For each number, loop through known prime numbers from 2 through sqrt(NUM)
        //If NUM%(prime_num)==0, find how many times
        //Reduce the val we're looking at
    
    //If we've gone through prime numbers and 
    unsigned int init_val = cur_val;
    unsigned int factor_sum = 1;
    //Factors are from 1 until the number (non-inclusive)
    // EX: 10 --> 1, 2, 5 == 7
    //      Note: 10 is NOT included as a factor
#ifdef _DEBUG4
        cout << "factors of " << cur_val << ": ";
#endif
    
    unsigned int loop_limit = sqrt(cur_val);
    //Loop through known prime numbers up to (inclusive) the sqrt(cur_val)
    for(int i = 0; _prime_nums[i] <= loop_limit; ++i){
        unsigned int prime_num = _prime_nums[i];
        factor_sum *= _prime_factorize(cur_val, prime_num);
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
    //Check that the current value at "_prime_num_len" holds a 0, if not
    // increment so that the next empty value is picked
    if(_prime_nums[_prime_nums_len] != 0){
        ++_prime_nums_len;
    }
    //Verify that the current number is greater than the previous number
    if(_prime_nums_len != 0 && _prime_nums[_prime_nums_len-1] < cur_prime_num){
    //Put in the current prime number and then increment the length var
        _prime_nums[_prime_nums_len] = cur_prime_num;
        ++_prime_nums_len;    
    }
    else if(_prime_nums_len == 0){
        //Put in the current prime number and then increment the length var
        _prime_nums[_prime_nums_len] = cur_prime_num;
        ++_prime_nums_len;    
    }
}

unsigned int amicable::_find_prime_factorization(unsigned int cur_val){
    
    return 0;
}

unsigned int amicable::_prime_factorize(unsigned int& N, unsigned int prime){
//Non-prime numbers can be expressed as a product of prime numbers 
    //raised to some value:
    //  N = p1^m * p2^n
    //Factors are then p1^(0...m)*p2^(0...n)
    //To get the sum of the factors, you need to do:
    //  p1^0*p2^0 + p1^1+p2^0 + ... + p1^m*p2^0 + p1^1+p2^1 +.... + p1^m*p2^n 
    //          - p1^m*p2^n (since we don't want to include N itself in the sum)
    //  This simplifies to (1 + p1^1 + p1^2 + .... + p1^m)*(1+p2^1 + p2^2 + ... p2^n)
    //  
    
    //In this function, we figure out if a specific Pi (i=0...._prime_nums_len)
    // is a prime factor of N
    //If it is, we keep going until we figure out whole sum of this 1+Pi^1+...+Pi^m
    unsigned int Pi_sum = 1;
    unsigned int prime_raised = prime;
    while(N%prime == 0){
        //If it is a factor
        Pi_sum += prime_raised;
        prime_raised *= prime;
        N /= prime;
    }
    //If this is not a prime factor, return 0
    //  If it is, though, we want the Pi^0 included off the bat
    if(Pi_sum == 1){
        --Pi_sum;
    }
    return Pi_sum;
}

void amicable::_print_arr(unsigned int*& arr, unsigned int len){
    for(int i = 0; i < len; ++i){
        cout << i << ": " << arr[i] << endl;
    }
}

unsigned int amicable::_factor_sum_stackoverflow(unsigned int n)
{
    unsigned int orig_n = n;
//    cout << "NUM: " << n;
    unsigned int prod=1;
    for(unsigned int k=2;k*k<=n;++k){
        unsigned int p=1;
        cout << "n: " << n;
        cout << ", P: " << p;
        cout << ", k: " << k;
        cout << ", prod: " << prod << endl;
        while(n%k==0){
            p=p*k+1;
            cout << "Incremented P: " << p;
            n/=k;
            cout << ", Decremented n: " << n << endl;
        }
        prod*=p;
        cout << "Prod: " << prod << endl;
    }
    if(n>1)
        cout << "If n>1 (" << n << "), Prod: " << prod;
        prod*=1+n;
        cout << ", *=1+n: " << prod << endl;
    unsigned int prodo = prod-orig_n;
    cout << "prod - original value: " << prodo << endl << endl << endl;
    return prodo;
}























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

//EOF
