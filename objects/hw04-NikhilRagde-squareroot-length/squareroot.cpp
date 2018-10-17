/*----------------------------------------------------------------
Copyright (c) 2018 Author: Jagadeesh Vasudevamurthy
file: squareroot.cpp
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
all includes here
-----------------------------------------------------------------*/
#include "../util/util.h"
#include "squareroot.h"

/*----------------------------------------------------------------
Time complexity : O(log(N))
Space Complexity : Theta(1)
-----------------------------------------------------------------*/
void squareroot::_sqrt_without_using_sqrt() {
    //WRITE CODE HERE
    // We want to, effectively, do a binary search for the square root
    // Do not need to worry about negative numbers (since it's unsigned)
    
    // This is the "highest" value we've checked that's below n
    unsigned int max_below = 1;
    // This is the "lowest" value we've checked that's above n
    unsigned int min_above = _n;
    // Do a binary search for the sqrt, between the bounds of what we've checked
    unsigned int s = (max_below + min_above)/2;
    ++_steps; //Steps are defined by how many values we try out
    // When we reach max_below again, we've found it. Until then, keep doing the binary search
    while(s > max_below){
        unsigned this_square = s*s;
        // If this_square is equal to n, we've found the sqrt
        if (this_square == _n){
            _ans = s;
            return;
            //If we do not return out here and simple break, we'll overwrite _ans
            //Alternatively, we could break and set "max_below" to s,
            // but the "return" is a bit easier to follow/understand than this:
            //max_below = s;
            //break;
        }
        // If this_square is bigger than n, we need to go lower
        else if(this_square > _n){
            min_above = s;
        }
        else if(this_square < _n){
            max_below = s;
        }
        // Calculate the next s, which should be in the middle of our new bounds
        s = (max_below + min_above)/2;
        //If we reach our terminating condition, we shouldn't count this "s" as a step...
        if(s > max_below){
            ++_steps;
        }
        // When we reach max_below again, we've found it. Until then, keep doing the binary search
//        if(not (s > max_below)){
//            _ans = max_below;
//            break;
//        }
    }
    _ans = max_below;
    
    if(_n == 0){
        _ans = 0;
    }
    
}
