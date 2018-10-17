/*----------------------------------------------------------------
Copyright (c) 2018 Author: Jagadeesh Vasudevamurthy
file: length.cpp
The array of size N will have numbers from (0 to N-1)ONLY
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
all includes here
-----------------------------------------------------------------*/
#include "../util/util.h"
#include "length.h"

/*----------------------------------------------------------------
Time complexity O(n)
Space Complexity O(1)
CANNOT CHANGE BELOW
-----------------------------------------------------------------*/
int length::length_easy(int x) {
  int l = 0;
  int gx = x;
  while (true) {
    if (_a[x] == gx) {
      return l;
    }
    x = _a[x];
    ++l;
  }
  return l;
}

/*----------------------------------------------------------------
Time complexity: O(N)
Space Complexity: O(N)

YOU CANNOT USE ANY static variable in this function
YOU can use as many local variables inside the function
Cannot use any loop statements like  for, while, do, while, go to
Can use if. 
ONLY AFTER THE execution of this routine array s MUST have the same contents as you got it.
YOU cannot call any subroutine inside this function except length_tough itself (NOT length_easy)
-----------------------------------------------------------------*/
int length::length_tough(int x) {
    //WRITE CODE HERE
    //ANOTHER HINT: should not be more than 10 lines! (THIS ONE IS 7 or 8)
    
    //If we've wrapped around, we want to return this step as -1, because we need to remove the first check
    // which is not actually a "hop" that we're counting, just the one that tells us we can stop hopping
    // See the logic of the alternative solution below that's clearer but maybe over the "10 lines" rule
    int l = -1;
    //Save the original value
    int new_x = _a[x];
    //If we have not yet visited this value
    if(new_x != -1){
        //Set it to -1 to denote that we've visited it
        _a[x] = -1;
        //Now make the recursive call and add 1 to l to count this as a "hop"
        l = 1 + length_tough(new_x);
        //Once we're unstacking, make sure to return the array to it's original values
        //a single element at a time
        _a[x] = new_x;
    }
    //Finally, return the number of hops that we have counted from the "-1" to the start
    return l;
}

//OTHER WAYS OF WRITING THIS SAME CODE:
//    //WRITE CODE HERE
//    //ANOTHER HINT: should not be more than 10 lines! (THIS ONE IS 10 or 11)
//    int l = 0 ;
//    int new_x = _a[x];
//    if(new_x == -1){
//        //This counts as an extra step
//        return -1;
//    }
//    else{
//        _a[x] = -1;
//        l = 1 + length_tough(new_x);
//        _a[x] = new_x;
//    }
//    return l;

//EOF

