/*------------
Author: Nikhil Ragde
Student #12
Due Date: May 1, 2018
file: nqueens.cpp
*/

/*----------------------------------------------------------------
All includes here
-----------------------------------------------------------------*/
#include "intmatrix1.h"
//#define DEBUG0 1
//#define DEBUGTEST 1

//void intmatrix1::init(int row = 0, int col = 0, int val = 0);
void intmatrix1::init(int row, int col, int val){
    //Empty Matrix:
    //If there are no inputs, row & col will be (defaulted to) 0
    //If there's an invalid number for row or col (0 or negative)
    //if(row == 0 || col == 0){
    if(row < 1 || col < 1){    
        //We're creating an empty matrix
        _is_empty = true;
        //Keep track of the rows and cols, internally
        _rows = 0;
        _cols = 0;
        //Initialize the empty array
        _arr = new int[0];
    }
    else{
        //We've got a proper number of rows and cols, so we can fill it!
        _is_empty = false;
        //Keep track of the rows and cols, internally
        _rows = row;
        _cols = col;
        //Fill a matrix with the proper dimensions with the proper "val"
        int num_elements = row * col;
        _arr = new int[num_elements];
        for(int i = 0; i < num_elements; i++){
            _arr[i] = val;
        }
    }
}

void intmatrix1::init(const char* arr_str){
    //This helper function will return false if the string is invalid
    //If it is valid, the function ALSO takes care of creating the array
    //and settings rows and cols, so only _is_empty needs to be handled
    bool is_valid = _insert_str_vals(arr_str);
    if(is_valid){
    //Create the array using the values
        //We've got a proper number of rows and cols, so we can fill it!
        _is_empty = false;
    }
    else{
        //We're creating an empty matrix
        _is_empty = true;
        //Keep track of the rows and cols, internally
        _rows = 0;
        _cols = 0;
        //Initialize the empty array
        _arr = new int[0];   
    }
}

void intmatrix1::fini(){
    delete [] _arr;
}

int intmatrix1::get_rows(){
    return _rows;
}

int intmatrix1::get_cols(){
    return _cols;
}

int intmatrix1::get_arr_val(int row, int col)
{
    assert(row>=0);
    assert(col>=0);
    if(!_is_empty){
        return _arr[row*_cols + col];
    }
    return -1;
}

void intmatrix1::set_arr_val(int row, int col, int val){
    _arr[row*_cols + col] = val;
}

void intmatrix1::raw_set_arr_val(int ind, int val){
    _arr[ind] = val;
}


bool intmatrix1::isEmpty(){
    return _is_empty;
}


bool intmatrix1::isEqual(intmatrix1 that){
    bool is_equal = true;
    //Dimensions have to be the same
    if ((this->_rows == that.get_rows()) && (this->_cols == that.get_cols())){
        //Now check element by element. The values should be same for the same
        //(row,col) pairs. If even one is off, return false.
        for(int r = 0; r < this->_rows; r++){
            for(int c = 0; c < this->_cols; c++){
                if(this->get_arr_val(r,c) != that.get_arr_val(r,c)){
                    return false;
                }
            }
        }
    }
    else{
        return false;
    }
    return is_equal;
}

intmatrix1 intmatrix1::add(intmatrix1 that){
    intmatrix1 sum_arr;
    //What happens if it's just a single number?
    //Dimensions have to be the same
    if ((this->_rows == that.get_rows()) && (this->_cols == that.get_cols())){
        sum_arr.init(this->_rows, this->_cols);
        for(int r = 0; r < this->_rows; r++){
            for(int c = 0; c < this->_cols; c++){
                int sum_val = this->get_arr_val(r,c) + that.get_arr_val(r,c);
                sum_arr.set_arr_val(r,c, sum_val);
            }
        }
    }
    else{
        sum_arr.init();
    }
    
    return sum_arr;
}

intmatrix1 intmatrix1::mult(intmatrix1 that){
    intmatrix1 prod_arr;
//    //Check if either is a "scalar" i.e. just a single value?
//    if(this->_rows == 1 && this->_cols == 1){
//        int scalar = this->get_arr_val(0,0);
//        prod_arr.init(that.get_rows(), that.get_cols(), 0);
//        for(int r = 0; r < that.get_rows(); r++){
//            for(int c = 0; c < that.get_cols(); c++){
//                int val = that.get_arr_val(r,c);
//                prod_arr.set_arr_val(r, c, val*scalar);
//            }
//        }
//        return prod_arr;
//    }
//    if(that.get_rows() == 1 && that.get_cols() == 1){
//        int scalar = that.get_arr_val(0,0);
//        prod_arr.init(this->_rows, this->_cols, 0);
//        for(int r = 0; r < this->_rows; r++){
//            for(int c = 0; c < this->_cols; c++){
//                int val = this->get_arr_val(r,c);
//                prod_arr.set_arr_val(r, c, val*scalar);
//            }
//        }
//        return prod_arr;
//    }
    //Do the dimension check
    if(this->_cols == that.get_rows()){
        //The dimensions match! Now do the math...
        //The _rows and _cols are set by the _rows of this and the _cols of that
        //Initialize to 0 to start with a clean matrix
        prod_arr.init(this->_rows, that.get_cols(), 0);
        //Multiply the corresponding row of THIS by the col of THAT
        //The first row of prod_arr requires the first row of THIS, and so on
        for(int r = 0; r < this->_rows; r++){
            //Get the row of THIS
            int this_row[this->_cols];
            for(int tc = 0; tc < _cols; tc++){
                this_row[tc] = this->get_arr_val(r, tc);
            }
            //Now do the math for each col of THAT, by going down rows
            for(int cc = 0; cc < that.get_cols(); cc++){
                int that_col[that.get_rows()];
                for(int rr = 0; rr < that.get_rows(); rr++){
                    that_col[rr] = that.get_arr_val(rr,cc);
                }
                //At this point, I have the current row and the current col
                int cur_num = 0;
                for(int ind = 0; ind < that.get_rows(); ind++){
                    int this_val = this_row[ind];
                    int that_val = that_col[ind];
                    int prod = this_val * that_val;
                    cur_num += prod;
                }
                prod_arr.set_arr_val(r, cc, cur_num);
            }
        }
    }
    else{
        //The dimensions do NOT allow for valid multiplication, so empty arr
        prod_arr.init();
    }
    return prod_arr;
}

void intmatrix1::print(const char* str){
    cout << "-------- " << str << " -----------" << endl;
    if(_is_empty){
        //print out empty matrix
        cout << "Empty matrix" << endl;
    }
    else{
        for(int r = 0; r < _rows; r++){
            for(int c = 0; c < _cols; c++){
                //Print out the 1D array as a 2D array
                cout << setw(5) << _arr[r*_cols + c];
            }
            cout << endl;
        }
    }
    
}


int intmatrix1::_char_to_int(const char* int_str){
    return int(*int_str - '0');
}

bool intmatrix1::_insert_str_vals(const char* arr_str){
    const char* init_arr_str = arr_str; //shallow copy of beginning of char* arr
    int num_rows = 0;
    bool first_row = true;
    int num_cols = 0;
    int cur_col_num = 0;
    bool within_number = false;
    
    while(*arr_str){

        //Check what the current character is
        //Is it a space
        if(*arr_str == ' '){
            if(within_number){
                within_number = false;
                cur_col_num++;
                //cur_col_num = 0;
            }
        }
        //Is it a |
        else if (*arr_str == '|'){
            //The first row defines how many numbers are for "cols"
            if(within_number){
                within_number = false;
                cur_col_num++;
            }
            if(first_row){
                first_row = false;
                num_cols = cur_col_num;
            }
            //Every row must have the same number of columns
            if(!(num_cols == cur_col_num)){
                return false;
            }
            cur_col_num = 0;
            num_rows++;
        }
        //Is it a number?
        else if (*arr_str >= '0' && *arr_str <= '9'){
            within_number = true;
            
        }
        //If it's anything else, not valid
        else{
            return false;
        }
        arr_str++;
    }
    //Tweak the column count if the last character is a number
    if(within_number){
        within_number = false;
        cur_col_num++;
    }
    //If it's a single row of numbers, make sure we mark that
    if(num_rows == 0 && cur_col_num != 0){
        //num_rows++;
        num_cols = cur_col_num;
    }
    //Need to verify that the last row is also valid
    if(!(num_cols == cur_col_num)){
            return false;
    }
    else{
        num_rows++;
    }
    //--------------------------------------------------
    //At this point, we know the number of cols and rows
    //If it's an empty string, the above may pass through without failing
    if(num_rows == 0 || num_cols == 0){
        return false;
    }
    //We will now loop through the string, again, and add values as appropriate
    int cur_num = 0;
    _arr = new int[num_rows*num_cols];
    _rows = num_rows;
    _cols = num_cols;
    int arr_ind = 0;
    arr_str = init_arr_str;
    while(*arr_str){
        //Check what the current character is
        //Is it a space
        if(*arr_str == ' '){
            //Space between numbers, so enter the current number into the next spot
            if(within_number){
                within_number = false;
                _arr[arr_ind++] = cur_num;
                cur_num = 0;
            }
        }
        //Is it a |
        else if (*arr_str == '|'){
            //The first row defines how many numbers are for "cols"
            if(within_number){
                within_number = false;
                _arr[arr_ind++] = cur_num;
                cur_num = 0;
            }
        }
        //Is it a number?
        else if (*arr_str >= '0' && *arr_str <= '9'){
            //Double digit number, so shift the current number left by one
            if(within_number){
                cur_num *= 10;
            }
            within_number = true;
            cur_num += _char_to_int(arr_str);
            
        }
        //If it's anything else, not valid
        else{
            return false;
        }
        arr_str++;
    }
    //Tweak the column count if the last character is a number
    if(within_number){
        within_number = false;
        _arr[arr_ind++] = cur_num;
        cur_num = 0;
    }
    
    return true;
}


#if 0
//OUTPUT GOES HERE:
-------- Matrix a -----------
Empty matrix
-------- Matrix b -----------
    0    0    0    0
    0    0    0    0
    0    0    0    0
-------- Matrix c -----------
Empty matrix
-------- Matrix d -----------
Empty matrix
-------- Matrix e -----------
    7    7    7    7    7    7    7    7    7    7
    7    7    7    7    7    7    7    7    7    7
    7    7    7    7    7    7    7    7    7    7
-------- Matrix e -----------
    1    2
    3    4
    5    6
-------- Matrix g -----------
    1    2
    3    4
    5    6
-------- Matrix h -----------
Empty matrix
-------- Matrix a -----------
    7    9   11
   13   15   17
-------- Matrix b -----------
    6    8   10
   12   14   16
-------- matrix s -----------
   13   17   21
   25   29   33
-------- matrix expected ans -----------
   13   17   21
   25   29   33
-------- Matrix a -----------
    1    2    3
    4    5    6
-------- Matrix b -----------
    1    2
-------- matrix s -----------
Empty matrix
-------- matrix expected ans -----------
Empty matrix
-------- Matrix a -----------
    1    2    3
-------- Matrix b -----------
    2    1    3
    3    3    2
    4    1    2
-------- matrix s -----------
   20   10   13
-------- matrix expected ans -----------
   20   10   13
----------------------------------
-------- Matrix a -----------
    3    4    2
-------- Matrix b -----------
   13    9    7   15
    8    7    4    6
    6    4    0    3
-------- matrix s -----------
   83   63   37   75
-------- matrix expected ans -----------
   83   63   37   75
----------------------------------
-------- Matrix a -----------
    3
-------- Matrix b -----------
    5    2   11
    9    4   14
-------- matrix s -----------
Empty matrix
-------- matrix expected ans -----------
Empty matrix
----------------------------------
-------- Matrix a -----------
    3    9    0    2    2    9    5    2
    0    2    2    1    9    6    6    8
    7    5    6    1    4    9    8    9
    3    3    2    9    2    1    7    4
    1    9    0    1    2    9    5    2
    4    2    0    3    7    3    9    1
    5    9    0    6    6    7    8    2
    9    3    4    6    8    4    9    1
-------- Matrix b -----------
    6    1    6    0    8    3    0    0
    6    8    9    0    6    6    7    2
    4    8    2    0    5    4    6    7
    2    4    4    2    2    6    9    8
    4    8    2    2    4    6    4    1
    1    5    5    6    4    7    5    5
    7    4    6    5    0    6    5    3
    2    3    7    0    1    3    8    5
-------- matrix s -----------
  132  170  200   87  128  186  175  106
  122  186  166   86   92  182  195  123
  197  235  267  104  179  243  253  178
  128  140  164   63   86  162  194  140
  118  164  184   85  110  174  166   98
  138  142  144   83   91  162  137   82
  187  222  244  106  160  244  232  141
  201  212  210   97  171  230  204  142
-------- matrix expected ans -----------
  132  170  200   87  128  186  175  106
  122  186  166   86   92  182  195  123
  197  235  267  104  179  243  253  178
  128  140  164   63   86  162  194  140
  118  164  184   85  110  174  166   98
  138  142  144   83   91  162  137   82
  187  222  244  106  160  244  232  141
  201  212  210   97  171  230  204  142
----------------------------------
-------- Matrix a -----------
    7    3
    2    5
    6    8
    9    0
-------- Matrix b -----------
    8   14    0    3    1
    7   11    5   91    3
    8    4   19    5   57
-------- matrix s -----------
Empty matrix
-------- matrix expected ans -----------
Empty matrix
----------------------------------
        
#endif