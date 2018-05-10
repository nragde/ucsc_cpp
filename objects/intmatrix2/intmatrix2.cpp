/*------------
Author: Nikhil Ragde
Student #12
Due Date: May 1, 2018
file: nqueens.cpp
*/

/*----------------------------------------------------------------
All includes here
-----------------------------------------------------------------*/
#include "intmatrix2.h"
//#define DEBUG0 1
//#define DEBUGTEST 1
#define DEBUG_PRINT_STATES 1

//Two constructors, one for ints and one for string
intmatrix2::intmatrix2(int row, int col, int val):
    _rows(row), _cols(col), _arr(nullptr), _is_empty(true){
#ifdef DEBUG_PRINT_STATES
    cout << "In the (int) constructor!" << endl;
#endif
    //By default, we're initialized into an empty matrix
    //Now determine if we a legitimate matrix definition
    //Reasons for an Empty Matrix:
    //If there are no inputs, row & col will be (defaulted to) 0
    //If there's an invalid number for row or col (0 or negative)
                                                                                    //LOOK_HERE: Use ! or "not"?
    if(not (row < 1 || col < 1)){
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
intmatrix2::intmatrix2(const char* arr_str):
    _rows(0), _cols(0), _arr(nullptr), _is_empty(true){
#ifdef DEBUG_PRINT_STATES
    cout << "In the (char*) constructor!" << endl;
#endif
    bool is_valid = _insert_str_vals(arr_str);
    if(is_valid){
        _is_empty = false;
    }
}
//Destructor
intmatrix2::~intmatrix2(){
#ifdef DEBUG_PRINT_STATES
    cout << "In the destructor!" << endl;
#endif
    //Run the helper function that'll free allocated heap memory
    _release();    
}
//Copy constructor
intmatrix2::intmatrix2(const intmatrix2& mat){
    #ifdef DEBUG_PRINT_STATES
    cout << "In the copy constructor!" << endl;
#endif
    _copy(mat);
}
//Equal operator
intmatrix2& intmatrix2::operator=(const intmatrix2& mat){
#ifdef DEBUG_PRINT_STATES
    cout << "In the equal operator!" << endl;
#endif
    //Guard against equalling yourself!
    if(this != &mat){
        //Release the currently allocated heap stuff
        _release();
        //Now, just a deep copy is needed
        _copy(mat);
    }
    //"this" is a pointer. To return an object (ref), need to de-reference 
    // the pointer (aka the "this" object)
    return *this;
}
//Print operator (<<)
ostream& operator<<(ostream& o, const intmatrix2& mat){
#ifdef DEBUG_PRINT_STATES
    cout << "In the print (<<) operator!" << endl;
#endif
    //cout << "-------- " << str << " -----------" << endl;
    if(mat._is_empty){
        //print out empty matrix
        o << "Empty matrix" << endl;
    }
    else{
        for(int r = 0; r < mat._rows; r++){
            for(int c = 0; c < mat._cols; c++){
                //Print out the 1D array as a 2D array
                o << setw(5) << mat._arr[r*mat._cols + c];
            }
            o << endl;
        }
    }
    //"o" is the referenced object, so we can directly return it (unlike "this")!
    return o;
}

void intmatrix2::_release(){
    //The only heap allocated data is our array of values
    delete [] _arr;
}

void intmatrix2::_copy(const intmatrix2& orig_mat){
#ifdef DEBUG_PRINT_STATES
    cout << "In _copy!" << endl;
#endif
    _rows = orig_mat._rows;
    _cols = orig_mat._cols;
    _is_empty = orig_mat._is_empty;
    //Copy the existing arr into a new one
    _arr = new int[_rows*_cols];
    for(int i = 0; i < _rows*_cols; i++){
        _arr[i] = orig_mat._arr[i];
    }
}

int intmatrix2::get_rows(){
    return _rows;
}

int intmatrix2::get_cols(){
    return _cols;
}

int intmatrix2::get_arr_val(int row, int col)
{
    assert(row>=0);
    assert(col>=0);
    if(!_is_empty){
        return _arr[row*_cols + col];
    }
    return -1;
}

void intmatrix2::set_arr_val(int row, int col, int val){
    _arr[row*_cols + col] = val;
}

void intmatrix2::raw_set_arr_val(int ind, int val){
    _arr[ind] = val;
}


bool intmatrix2::isEmpty() const{
    return _is_empty;
}

bool intmatrix2::isEqual(const intmatrix2 that) const{
    bool is_equal = true;
    //Dimensions have to be the same
    if ((this->_rows == that._rows) && (this->_cols == that._cols)){
        //Now check element by element. The values should be same for the same
        //(row,col) pairs. If even one is off, return false.
        for(int r = 0; r < this->_rows; r++){
            for(int c = 0; c < this->_cols; c++){
                if(this->_arr[r*(this->_cols)+c] != that._arr[r*that._cols+c]){
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

intmatrix2 intmatrix2::add(const intmatrix2 mat) const{
    intmatrix2 sum_mat;
    return sum_mat;
}

intmatrix2 intmatrix2::mult(const intmatrix2 mat) const{
    intmatrix2 prod_mat;
    return prod_mat;
}

int intmatrix2::_char_to_int(const char* int_str){
    return int(*int_str - '0');
}

bool intmatrix2::_insert_str_vals(const char* arr_str){
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
//void intmatrix2::init(int row = 0, int col = 0, int val = 0);
void intmatrix2::init(int row, int col, int val){
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

void intmatrix2::init(const char* arr_str){
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

void intmatrix2::fini(){
    delete [] _arr;
}

int intmatrix2::get_rows(){
    return _rows;
}

int intmatrix2::get_cols(){
    return _cols;
}

int intmatrix2::get_arr_val(int row, int col)
{
    assert(row>=0);
    assert(col>=0);
    if(!_is_empty){
        return _arr[row*_cols + col];
    }
    return -1;
}

void intmatrix2::set_arr_val(int row, int col, int val){
    _arr[row*_cols + col] = val;
}

void intmatrix2::raw_set_arr_val(int ind, int val){
    _arr[ind] = val;
}


bool intmatrix2::isEmpty(){
    return _is_empty;
}


bool intmatrix2::isEqual(intmatrix2 that){
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

intmatrix2 intmatrix2::add(intmatrix2 that){
    intmatrix2 sum_arr;
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

intmatrix2 intmatrix2::mult(intmatrix2 that){
    intmatrix2 prod_arr;
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

void intmatrix2::print(const char* str){
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


int intmatrix2::_char_to_int(const char* int_str){
    return int(*int_str - '0');
}

bool intmatrix2::_insert_str_vals(const char* arr_str){
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

#endif

#if 0
//OUTPUT GOES HERE:

#endif
