/*----------------------------------------------------------------
Copyright (c) 2018 Author: Jagadeesh Vasudevamurthy
file: duplicateN.cpp
The array of size N will have numbers from (0 to N-1)ONLY
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
all includes here
-----------------------------------------------------------------*/
//#include "../util/util.h"
#include "duplicateN.h"

/*----------------------------------------------------------------
Time complexity O(n^2)
Space Complexity O(1)
-----------------------------------------------------------------*/
int duplicateN::nsquare_time_constant_space() {
  int num = 0;
  bool first_dupe = true;
  //Loop through _a
  for(int i = 0; i < _size; i++){
      //Get the current value
      int cur_val = _a[i];
      //Check if the value has already been printed
      bool already_caught = _check_before(i, cur_val);
      //If it hasn't, check the rest of the values in the array
      if(not already_caught){
          bool is_dupe = _check_after(i, cur_val);
          //If there is a duplicate in the remaining values, print it
          if(is_dupe){
              num++;
              _print_dupe(cur_val, first_dupe);
          }
      }
  }
  if(_show){
    //Close the brackets if you've printed any number of duplicates
    if(num){
        cout << "}" << endl;
    }
  }
  return num;
}

/*----------------------------------------------------------------
Time complexity O(n)
Space Complexity O(n)
-----------------------------------------------------------------*/
int duplicateN::ntime_n_space() {
  int num = 0;
  //Create a new array of the same size
  int *dupes = new int[_size];
  //Zero fill the dupes array, where the index is the count of the corresponding
  //values in _a (ex, three 1's in _a, would mean dupes[1] == 3 by the end)
  _zero_arr(dupes, _size);
  bool first_dupe = true;
  
  //Loop through _a
  for(int i = 0; i < _size; i++){
      //Get the current value
      int cur_val = _a[i];
      //Add one to the index of our dupes array
      dupes[cur_val] += 1;
      //If dupes[i] is 2, then we have the first instance of a duplicate 
      if(dupes[cur_val] == 2){
          num++;
          _print_dupe(cur_val, first_dupe);
      }
      //Note: we don't print if it's >2 because we've already done it, and 1 is
      //not a duplicate. The 2 is NOT arbitrary.
  }  
  if(_show){
    //Close the brackets if you've printed any number of duplicates
    if(num){
        cout << "}" << endl;
    }
  }
  delete [] dupes;
  return num;
}

/*----------------------------------------------------------------
Time complexity O(n)
Space Complexity O(1)
-----------------------------------------------------------------*/
int duplicateN::ntime_constant_space() {
    //ORIGINAL SOLUTION
//  int num = 0 ;
//  bool first_dupe = true;
//  //Create a new array of a massive size 
//  //This isn't the most creative O(1) space solution, but it works...
//  int *dupes = new int[1<<20];
//  _zero_arr(dupes, _size);
//  
//  //Loop through _a
//  for(int i = 0; i < _size; i++){
//      //Get the current value
//      int cur_val = _a[i];
//      //Add one to the index of our dupes array
//      dupes[cur_val] += 1;
//      //If dupes[i] is 2, then we have a duplicate
//      if(dupes[cur_val] == 2){
//          num++;
//          _print_dupe(cur_val, first_dupe);
//      }
//  }  
//  if(_show){
//    //Close the brackets if you've printed any number of duplicates
//    if(num){
//        cout << "}" << endl;
//    }
//  }
//  delete [] dupes;
//  return num;
    //666666666666666666666666666666666666666666666666666666666666666
    //SOLUTION SHOWN IN CLASS!!!
    //Loop through the full thing
    int num = 0;
    bool first_dupe = true;
    for(int i = 0; i < _size; ++i){
        //Get the value
        int cur_val = _a[i] % _size;
        assert(cur_val >= 0 && cur_val < _size);
        //Add N (i.e. size) to the cur_value position
        _a[cur_val] += _size;
    }
    //Loop through again to find the duplicates
    for(int j = 0; j < _size; ++j){
        int cur_val = _a[j];
        //If the value is >= 2*N, the index had more than 1 dupe 
        // (since 0 + _size + size) will always be >= 2*N
        if(cur_val >= 2 * _size){
            num++;
            _print_dupe(cur_val%_size, first_dupe);
        }
        //Now, return the value to the orignal value
        //Note that ELEMENT % _size will always give the original value
        // X + N + N + N + ... + N = T (the value before mod)
        // X + CN = T
        // T % N = X
        // EX: 3 + 5 + 5 + 5 = 18
        //     3 + 3*5 = 18
        //    18 % 5 = 3 = X
        _a[j] %= _size;
    }
    if(num){
        cout << "}";
    }
    return num;
}

//-------- HELPERS
void duplicateN::_zero_arr(int*& arr, int size){
    for(int i = 0; i < size; i++){
        arr[i] = 0;
    }
}

bool duplicateN::_check_before(int i, int cur_val){
    bool already_found = false;
    //Make sure we're not at the first element, or an invalid one
    if(i > 0 && i < _size){
        //Loop through from 0 to j
        for(int j = 0; j < i; j++){
            //If a value before our current index (i) is the same as our current
            //value, then return true so we don't double count
            if(_a[j] == cur_val){
                already_found = true;
                break;
            }
        }
    }
    return already_found;
}

bool duplicateN::_check_after(int i, int cur_val){
    //Make sure we're not looking at the last element
    bool is_dupe = false;
    if(i < _size - 1){
        //Loop through from i+1 to the end of the array
        for(int k = i + 1; k < _size; k++){
            if(_a[k] == cur_val){
                is_dupe = true;
                break;
            }
        }
    }
    return is_dupe;
}

void duplicateN::_print_dupe(int dupe_val, bool& first_dupe){
    //Since it's possible for there to be too many values to print, use the
    //"global" var _show to help determine when to print dupe'd values
    if(_show){
        //Open brackets and skip comma for the first number
        if(first_dupe){
            cout << "DUPLICATES: {" << dupe_val;
            first_dupe = false;
        }
        //Simply print out the leading comma and the number thereafter
        else{
            cout << ", " << dupe_val;
        }
    }
}

//EOF

