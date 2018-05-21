/*------------
Author: Nikhil Ragde
Student #12
Due Date: May 1, 2018
file: nqueens.cpp
*/

/*----------------------------------------------------------------
All includes here
-----------------------------------------------------------------*/
#include "dealornodeal.h"
//#define DEBUG0 1
//#define DEBUGTEST 1
//#define DEBUG_PRINT_STATES 1
//#define DEBUG_1 1
#define DEBUG_PRINTS 1

//Set value of show and interactive
//dealornodeal::_show = false;
//dealornodeal::_interactive = false;

const int NUM_CASES = 26;

//Suitcase Class
//Constructor
suitcase::suitcase(double val):
    _opened(false), _value(val){
#ifdef DEBUG_PRINTS
    cout << "In suitcase constructor, for value = $" << _value << endl;
#endif
}
//Note: no way to "close" a case once it's opened
void suitcase::open_case(){
    _opened = true;
}

double suitcase::get_value(){
    return _value;
}


//LIST OF SUITCASES Class
//Crude linked list
list_of_suitcases::list_of_suitcases(int num):
    _case_list(nullptr), _size(0), _maxsize(num){
#ifdef DEBUG_PRINTS
    cout << "In list_of_suitcases constructor" << endl;
#endif
    _case_list = new suitcase*[_maxsize];
}
list_of_suitcases::~list_of_suitcases(){
    _release();
}
//int get_num_cases(){return _num_cases;}
double list_of_suitcases::get_banker_deal(){
    return double(0);
}
void list_of_suitcases::_release(){
//Free each suitcase
    
//Then free the list
    
}
void list_of_suitcases::_copy(){
}

//double default_case_vals[] = {0.01, 1.0, 5.0, 10.0, 25.0, 50.0, 75.0, 100.0, 200.0, 300.0, 400.0, 500.0 750.0, 1000.0, 5000.0, 10000.0, 25000.0, 50000.0, 75000.0, 100000.0, 200000.0, 300000.0, 400000.0, 500000.0, 750000.0, 1000000.0};

dealornodeal::dealornodeal(const unsigned int num_cases, double* money_vals, int rounds):
 _num_cases(num_cases), _case_values(money_vals), _rounds(rounds), _game_cases(num_cases){
    if(show()){
        cout << "In dealornodeal constructor! " << endl;
    }
    assert(_num_cases > 0);
    
}
dealornodeal::~dealornodeal(){
    if(show()){
        cout << "In dealornodeal destructor! " << endl;
    }
    
}
ostream& dealornodeal::operator<<(ostream& o, const dealornodeal& game){
    return o;

}
void dealornodeal::play(){
    //# suitcases, money in cases, and rounds have been inputted in the constructor
    

}
#if 0

//Two constructors, one for ints and one for string
//Constructor for the ints input case
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

//Constructor for the string input case
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

//Copy constructor: just copys the values from the passed in matrix reference
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

bool intmatrix2::isEmpty() const{
return _is_empty;
}

bool intmatrix2::isEqual(const intmatrix2 that) const{
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
    //If dimensions don't match, they necessarily cannot be equal
    return false;
}
//If we've made it this far, the checks have passed and we are equal
return true;
}

intmatrix2 intmatrix2::add(const intmatrix2 that) const{
//What happens if it's just a single number?
//Dimensions have to be the same
if ((this->_rows == that._rows) && (this->_cols == that._cols)){
    intmatrix2 sum_arr(this->_rows, this->_cols);
    for(int r = 0; r < this->_rows; r++){
        for(int c = 0; c < this->_cols; c++){
            int sum_val = this->_arr[this->_rcind(r,c)] + that._arr[that._rcind(r,c)];
            //sum_arr.set_arr_val(r,c, sum_val);
            sum_arr._arr[sum_arr._rcind(r,c)] = sum_val;
        }
    }
    return sum_arr;
}
//If the dimensions do NOT match, we need to return an empty matrix
intmatrix2 sum_arr;    
return sum_arr;
}

intmatrix2 intmatrix2::mult(const intmatrix2 that) const{
//Scalars are an edge case
//this matrix is a single, scalar value
if(this->_rows == 1 && this->_cols ==1){
    //Copy the inputted matrix, and apply the scalar to that
    intmatrix2 prod_arr(that);
    int scalar = this->_arr[0];
    for(int r = 0; r < prod_arr._rows; r++){
        for(int c = 0; c < prod_arr._cols; c++){
            prod_arr._arr[prod_arr._rcind(r,c)] *= scalar;
#ifdef DEBUG_1
            cout << prod_arr << endl;
#endif 
        }
    }
    return prod_arr;
}
//the inputted matrix is a single, scalar value
else if(that._rows == 1 && that._cols ==1){
    //Copy the current matrix, and apply the scalar to that
    intmatrix2 prod_arr(*this);
    int scalar = that._arr[0];
    for(int r = 0; r < prod_arr._rows; r++){
        for(int c = 0; c < prod_arr._cols; c++){
            prod_arr._arr[prod_arr._rcind(r,c)] *= scalar;
#ifdef DEBUG_1
            cout << prod_arr << endl;
#endif 
        }
    }
    return prod_arr;
}

//Do the dimension check
if(this->_cols == that._rows){
    //The dimensions match! Now do the math...
    //The _rows and _cols are set by the _rows of this and the _cols of that
    //Initialize to 0 to start with a clean matrix
    intmatrix2 prod_arr(this->_rows, that._cols, 0);
    //Multiply the corresponding row of THIS by the col of THAT
    //The first row of prod_arr requires the first row of THIS, and so on
    for(int r = 0; r < this->_rows; r++){
        //Get the row of THIS
        int this_row[this->_cols];
        for(int tc = 0; tc < _cols; tc++){
            this_row[tc] = this->_arr[this->_rcind(r,tc)];
        }
        //Now do the math for each col of THAT, by going down rows
        for(int cc = 0; cc < that._cols; cc++){
            int that_col[that._rows];
            for(int rr = 0; rr < that._rows; rr++){
                that_col[rr] = that._arr[that._rcind(rr,cc)];
            }
            //At this point, I have the current row and the current col
            int cur_num = 0;
            for(int ind = 0; ind < that._rows; ind++){
                int this_val = this_row[ind];
                int that_val = that_col[ind];
                int prod = this_val * that_val;
                cur_num += prod;
            }
            prod_arr._arr[prod_arr._rcind(r,cc)] = cur_num;
        }
    }
    return prod_arr;
}
//The dimensions do NOT allow for valid multiplication, so empty arr
intmatrix2 prod_arr;
return prod_arr;
}

//Helper function to convert an (r,c) pair to it's linearized value
//NOTE: must be called for the specific object when used in a function, or else
// "this"'s _rows and _cols will be used, resulting in potentially bad stuff
int intmatrix2::_rcind(int r, int c) const{
return r*_cols + c;
}

//Helper function to convert a numeric char '0'-'9' to it's int value of 0-9
int intmatrix2::_char_to_int(const char* int_str){
return int(*int_str - '0');
}

//A ridiculous function that both parses a matrix string to determine if it's
//valid and also sets up the array if it is for the current object
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
Matrix a
Empty matrix

Matrix b
    0    0    0    0
    0    0    0    0
    0    0    0    0

Matrix c
Empty matrix

Matrix d
Empty matrix

Matrix e
    7    7    7    7    7    7    7    7    7    7
    7    7    7    7    7    7    7    7    7    7
    7    7    7    7    7    7    7    7    7    7

Matrix f
    1    2
    3    4
    5    6

Matrix g
    1    2
    3    4
    5    6

Matrix h
Empty matrix

Matrix g
    1    2
    3    4
    5    6

Matrix h
    1    2
    3    4
    5    6

Matrix e
    1    2
    3    4
    5    6

Matrix a
    7    9   11
   13   15   17

Matrix b
    6    8   10
   12   14   16

Matrix s
   13   17   21
   25   29   33

Matrix expected ans
   13   17   21
   25   29   33

Matrix a
    1    2    3
    4    5    6

Matrix b
    1    2

Matrix s
Empty matrix

Matrix expected ans
Empty matrix

Matrix a
    1    2    3

Matrix b
    2    1    3
    3    3    2
    4    1    2

Matrix s
   20   10   13

matrix expected ans
   20   10   13

----------------------------------
Matrix a
    3    4    2

Matrix b
   13    9    7   15
    8    7    4    6
    6    4    0    3

Matrix s
   83   63   37   75

matrix expected ans
   83   63   37   75

----------------------------------
Matrix a
    3

Matrix b
    5    2   11
    9    4   14

Matrix s
   15    6   33
   27   12   42

matrix expected ans
   15    6   33
   27   12   42

----------------------------------
Matrix a
    5    2   11
    9    4   14

Matrix b
    3

Matrix s
   15    6   33
   27   12   42

matrix expected ans
   15    6   33
   27   12   42

----------------------------------
Matrix a
    3    9    0    2    2    9    5    2
    0    2    2    1    9    6    6    8
    7    5    6    1    4    9    8    9
    3    3    2    9    2    1    7    4
    1    9    0    1    2    9    5    2
    4    2    0    3    7    3    9    1
    5    9    0    6    6    7    8    2
    9    3    4    6    8    4    9    1

Matrix b
    6    1    6    0    8    3    0    0
    6    8    9    0    6    6    7    2
    4    8    2    0    5    4    6    7
    2    4    4    2    2    6    9    8
    4    8    2    2    4    6    4    1
    1    5    5    6    4    7    5    5
    7    4    6    5    0    6    5    3
    2    3    7    0    1    3    8    5

Matrix s
  132  170  200   87  128  186  175  106
  122  186  166   86   92  182  195  123
  197  235  267  104  179  243  253  178
  128  140  164   63   86  162  194  140
  118  164  184   85  110  174  166   98
  138  142  144   83   91  162  137   82
  187  222  244  106  160  244  232  141
  201  212  210   97  171  230  204  142

matrix expected ans
  132  170  200   87  128  186  175  106
  122  186  166   86   92  182  195  123
  197  235  267  104  179  243  253  178
  128  140  164   63   86  162  194  140
  118  164  184   85  110  174  166   98
  138  142  144   83   91  162  137   82
  187  222  244  106  160  244  232  141
  201  212  210   97  171  230  204  142

----------------------------------
Matrix a
    7    3
    2    5
    6    8
    9    0

Matrix b
    8   14    0    3    1
    7   11    5   91    3
    8    4   19    5   57

Matrix s
Empty matrix

matrix expected ans
Empty matrix

----------------------------------

#endif
