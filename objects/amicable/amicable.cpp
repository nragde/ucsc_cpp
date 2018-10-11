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
//#define _DEBUG1      0
//#define _DEBUG2     2
//#define _DEBUG3      3
//#define _DEBUG4     4

//Constructor
amicable::amicable(unsigned max):
    _max(max), _arr_sums(nullptr){
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
    delete [] _arr_sums;
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
    _arr_sums = new unsigned int[_max];
    _zero_fill_arr();
    _arr_sums[1] = 1;
//    if(len > 0){
//        _init_arr(x, len);
//    }
}  
//Create and zero out the elements
void amicable::_zero_fill_arr(){
    for(int i = 0; i < _max; ++i){
        _arr_sums[i] = 0;
    }
}

void amicable::_find_amicable_pairs(){
    int total_num = 0;
    unsigned int cur_val = 100;
//    int i = 220; //The first valid amicable pair
    for(cur_val; cur_val <= _max; ++cur_val){
#ifdef _DEBUG1
        cout << "CURRENT NUMBER: " << cur_val << endl;
#endif
        //Find sum of factors
        unsigned int cur_sum = _find_factor_sum(cur_val);
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
    cout << "TOTAL NUMBER: " << total_num << endl;
}

unsigned int amicable::_find_factor_sum(unsigned int cur_val){
    unsigned int factor_sum = _factor_sum_loop_to_n(cur_val);
//    unsigned int factor_sum = _factor_sum_halfn(cur_val);
//    unsigned int factor_sum = _factor_sum_sqrtn(cur_val);
//    unsigned int factor_sum = _factor_sum_lut(cur_val);
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
    cout << "LIMIT: " << loop_limit << endl;
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
    unsigned int loop_limit = sqrt(cur_val);
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
#ifdef _DEBUG4
        cout << "\nfactor sum: " << factor_sum << endl;
#endif
        //1 will always be a factor, which is why the loop starts at 2
        return factor_sum + 1;
}

//Use a Look Up Table (LUT) for 
unsigned int amicable::_factor_sum_lut(unsigned int cur_val){
        int factor_sum = 0;
    //Factors are from 1 until the number (non-inclusive)
    // EX: 10 --> 1, 2, 5 == 7
    //      Note: 10 is NOT included as a factor
#ifdef _DEBUG3
        cout << "factors of " << cur_val << ": ";
#endif
    if(_arr_sums[cur_val] != 0){
        return _arr_sums[cur_val];
    }
//    if(cur_val == 1){
//        return 1;
//    }
    unsigned int loop_limit = sqrt(cur_val);
    for(int f = 1; f < loop_limit; ++f){ //LOOK HERE: WHAT ARE THE BOUNDS?
        //If the remainder is 0, add to the sum!
        if(cur_val%f == 0){
#ifdef _DEBUG3
        cout << " " << f;
#endif      
            factor_sum += f;
            unsigned int other_factor = cur_val/f;
            if(other_factor >= loop_limit && other_factor != cur_val){
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

        _fill_arr_sums(cur_val, factor_sum);
        
        return factor_sum;
    
}

void amicable::_fill_arr_sums(unsigned int val, unsigned int val_factor_sum){
    //Cannot assert, because there are going to be some factor sums > _max
    if(val < _max){
        if(_arr_sums[val] == 0){
            _arr_sums[val] = val_factor_sum;
        }
    }    
}

//EOF
