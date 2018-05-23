/*------------
Author: Nikhil Ragde
Student #12
Due Date: May 1, 2018
file: nqueens.cpp
*/

/*----------------------------------------------------------------
All includes here
-----------------------------------------------------------------*/
#include "iset64.h"
//#define DEBUG_PRINTS 1
//#define DEBUG_INTERACTIVE
//#define DEBUG_AUTOMATED 1
//#define DEBUG_ROUNDS
/*--------------------------------------------------------
 * SUITCASE
----------------------------------------------------------*/
int NUM_ELEMENTS = 64;
bool iset64::_show = false;

/*--------------------------------------------------------
 * SUITCASE
----------------------------------------------------------*/
iset64::iset64(const int x[], int length):
    _arr(nullptr), _len(length){
    if(show()){
        cout << "In iset64 constructor!" << endl;
    }
    //Allocate heap space, zero it out, and fill if necessary
    _alloc(x, length);
}

iset64::~iset64(){
    _release();
    _arr = nullptr;
    _len = 0;
}

iset64::iset64(const iset64& set){
    if(show()){
        cout << "In the iset64 copy constructor!" << endl;
    }
    _copy(set);
}


iset64& iset64::operator=(const iset64& set){
    if(show()){
        cout << "In the iset64 equal operator!" << endl;
    }
    //Guard against equalling yourself!
    if(this != &set){
        //Release the currently allocated heap stuff
        _release();
        //Now, just a deep copy is needed
        _copy(set);
    }
    //"this" is a pointer. To return an object (ref), need to de-reference 
    // the pointer (aka the "this" object)
    return *this;
}

ostream& operator<<(ostream& o, const iset64& set){
    if(iset64::show()){
        cout << "In the iset64 print operator!" << endl;
    }
    o << "{";
    bool is_first = true;
    for(int i = 0; i < NUM_ELEMENTS; ++i){
        if(set._arr[i]){
            if(!is_first){
                o << ", ";
            }
            o << i;
            is_first = false;
        }
    }
    o << "}" << endl;
    return o;
}

//Helper functions
void iset64::_release(){
    delete [] _arr;
}

void iset64::_copy(const iset64& set){
    if(show()){
    cout << "In _copy!" << endl;
    }
    _len = set._len;
    _arr = new int[NUM_ELEMENTS];
    for(int i = 0; i < NUM_ELEMENTS; ++i){
        _arr[i] = set._arr[i];
    }
}
void iset64::_alloc(const int x[], int len){
    _arr = new int[NUM_ELEMENTS];
    _zero_fill_arr();
    if(len > 0){
        _init_arr(x, len);
    }
}  
//Create and zero out the elements
void iset64::_zero_fill_arr(){
    for(int i = 0; i < NUM_ELEMENTS; ++i){
        _arr[i] = 0;
    }
}

void iset64::_init_arr(const int x[], int len){
    for(int i = 0; i < len; ++i){
        int ind = x[i];
        //Make sure it's within 0-63
        if(ind >= 0 && ind < NUM_ELEMENTS){
            // A set is unique numbers only, so can't have repeats
            if(!_arr[ind]){
                _arr[ind] = 1;
            }
        }
    }
}

iset64::operator bool() const{
    bool at_least_one_nonzero = false;
    for(int i = 0; i < NUM_ELEMENTS; ++i){
        if(_arr[i]){
            at_least_one_nonzero = true;
            break;
        }
    }
    return at_least_one_nonzero;
}

bool operator!(const iset64& set){
    bool at_least_one_nonzero = false;
    for(int i = 0; i < NUM_ELEMENTS; ++i){
        if(set._arr[i]){
            at_least_one_nonzero = true;
            break;
        }
    }
    return !at_least_one_nonzero;
}

//EQUALS
iset64& operator +=(iset64& a, const iset64& b){
    for(int i = 0; i < NUM_ELEMENTS; ++i){
        //If there is something in "b" and not in "a", add it to "a"
        if(b._arr[i] && !a._arr[i]){
            a._arr[i] = 1;
        }
    }
    return a;
}

iset64& operator +=(iset64& a, int b){
    if(b >= 0 && b < NUM_ELEMENTS){
        if(!a._arr[b]){
            a._arr[b] = 1;
        }
    }
    return a;
}

iset64& operator -=(iset64& a, const iset64& b){
    for(int i = 0; i < NUM_ELEMENTS; ++i){
        //If there is something in "b" and also in "a", take it out from "a"
        if(b._arr[i] && a._arr[i]){
            a._arr[i] = 0;
        }
    }
    return a;
    
}

iset64& operator -=(iset64& a, int b){
    if(b >= 0 && b < NUM_ELEMENTS){
        if(a._arr[b]){
            a._arr[b] = 0;
        }
    }
    return a;
}

iset64& operator *=(iset64& a, const iset64& b){
    for(int i = 0; i < NUM_ELEMENTS; ++i){
        if(a._arr[i] && b._arr[i]){
            a._arr[i] = 1;
        }
        else{
            a._arr[i] = 0;
        }
    }
    return a;    
}

iset64& operator *=(iset64& a, int b){
    if(b >= 0 && b <= NUM_ELEMENTS){
        if(a._arr[b]){
            a._zero_fill_arr();
            a._arr[b] = 1;
        }
        else{
            a._zero_fill_arr();
        }
    }
    else{
        a._zero_fill_arr();
    }
    return a;
}

// Binary operators
iset64 operator+(const iset64& a, const iset64& b){
    iset64 out(a);
    for(int i = 0; i < NUM_ELEMENTS; ++i){
        if(!out._arr[i] && b._arr[i]){
            out._arr[i] = 1;
        }
    }
    //out += b;
    return out;
}
iset64 operator+(const iset64& a, int b){
    iset64 out(a);
    if(b >= 0 && b <= NUM_ELEMENTS){
        if(!out._arr[b]){
            out._arr[b] = 1;
        }
        //out += b;
    }
    return out;
}
iset64 operator+(int b, const iset64& a){
    iset64 out(a);
    if(b >= 0 && b <= NUM_ELEMENTS){
        if(!out._arr[b]){
            out._arr[b] = 1;
        }
    }
    return out;
}
iset64 operator-(const iset64& a, const iset64& b){
    iset64 out(a);
    for(int i = 0; i < NUM_ELEMENTS; ++i){
        if(out._arr[i] && b._arr[i]){
            out._arr[i] = 0;
        }
    }
    //out -= b;
    return out;
}
iset64 operator-(const iset64& a, int b){
    iset64 out(a);
    if(b >= 0 && b <= NUM_ELEMENTS){
        if(out._arr[b]){
            out._arr[b] = 0;
        }
        //out -= b;
    }
    return out;
}
iset64 operator-(int b, const iset64& a){
    iset64 out(a);
    if(b >= 0 && b <= NUM_ELEMENTS){
        if(out._arr[b]){
            out._arr[b] = 0;
        }
    }
    return out;
}
iset64 operator*(const iset64& a, const iset64& b){
    iset64 out(a);
    for(int i = 0; i < NUM_ELEMENTS; ++i){
        if(out._arr[i] && b._arr[i]){
            out._arr[i] = 1;
        }
        else{
            out._arr[i] = 0;
        }
    }
    return out;
}
iset64 operator*(const iset64& a, int b){
    iset64 out(a);
    if(b >= 0 && b <= NUM_ELEMENTS){
        if(out._arr[b]){
            out._zero_fill_arr();
            out._arr[b] = 1;
        }
        else{
            out._zero_fill_arr();
        }
    }
    else{
        out._zero_fill_arr();
    }
    return out;
}
iset64 operator*(int b, const iset64& a){
    iset64 out(a);
    if(b >= 0 && b <= NUM_ELEMENTS){
        if(out._arr[b]){
            out._zero_fill_arr();
            out._arr[b] = 1;
        }
        else{
            out._zero_fill_arr();
        }
    }
    else{
        out._zero_fill_arr();
    }
    return out;
}

bool operator==(const iset64& a, const iset64& b){
    bool is_equal = true;
    for(int i = 0; i < NUM_ELEMENTS; ++i){
        if(a._arr[i] != b._arr[i]){
            is_equal = false;
        }
    }
    return is_equal;
}

//Pre-increment operator
iset64& operator++(iset64& set){
    //Add one to everything. Wrap a 63 to a 0;
    bool wraparound = false;
    for(int i = NUM_ELEMENTS-1; i >=0; --i){
        //If the current int is part of the set, add one
        if(set._arr[i]){
            //Remove the current number
            set._arr[i] = 0;
            if(i != NUM_ELEMENTS-1){
                //Add one to the number higher above
                set._arr[i+1] = 1;
            }
            else{
                //If we need to wrap around, do it at the end.
                wraparound = true;
            }
        }
    }
    if(wraparound){
        set._arr[0] = 1;
    }
    return set;
}

iset64 operator++(iset64& set, int post){
    iset64 unincremented_set(set);
//    ++set;
    //Add one to everything. Wrap a 63 to a 0;
    bool wraparound = false;
    for(int i = NUM_ELEMENTS-1; i >=0; --i){
        //If the current int is part of the set, add one
        if(set._arr[i]){
            //Remove the current number
            set._arr[i] = 0;
            if(i != NUM_ELEMENTS-1){
                //Add one to the number higher above
                set._arr[i+1] = 1;
            }
            else{
                //If we need to wrap around, do it at the end.
                wraparound = true;
            }
        }
    }
    if(wraparound){
        set._arr[0] = 1;
    }
    return unincremented_set;
}

iset64& operator--(iset64& set){
    //Subtract one from everything. Wrap a 0 to a 63;
    bool wraparound = false;
    for(int i = 0; i < NUM_ELEMENTS; ++i){
        //If the current int is part of the set, subtract one
        if(set._arr[i]){
            //Remove the current number
            set._arr[i] = 0;
            //Wrap the 0 around at the very end
            if(i){
                //Add one to the number higher above
                set._arr[i-1] = 1;
            }
            else{
                //If we need to wrap around, do it at the end.
                wraparound = true;
            }
        }
    }
    if(wraparound){
        set._arr[NUM_ELEMENTS-1] = 1;
    }
    return set;
}

iset64 operator--(iset64& set, int post){
    iset64 undecremented_set(set);
//    --set;
    //Subtract one from everything. Wrap a 0 to a 63;
    bool wraparound = false;
    for(int i = 0; i < NUM_ELEMENTS; ++i){
        //If the current int is part of the set, subtract one
        if(set._arr[i]){
            //Remove the current number
            set._arr[i] = 0;
            //Wrap the 0 around at the very end
            if(i){
                //Add one to the number higher above
                set._arr[i-1] = 1;
            }
            else{
                //If we need to wrap around, do it at the end.
                wraparound = true;
            }
        }
    }
    if(wraparound){
        set._arr[NUM_ELEMENTS-1] = 1;
    }
    return undecremented_set;
}

iset64 operator~(iset64& set){
    iset64 out(set);
    for(int i = 0; i < NUM_ELEMENTS; ++i){
        if(out._arr[i]){
            out._arr[i] = 0;
        }
        else{
            out._arr[i] = 1;
        }
    }
    return out;   
}



#if 0
//OUTPUT GOES HERE:

#endif
