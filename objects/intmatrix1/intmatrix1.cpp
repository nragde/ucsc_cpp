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
#define DEBUG0 1
//#define DEBUGTEST 1



//void intmatrix1::init(){
//    
//}
//void intmatrix1::init(int row = 0, int col = 0, int val = 0){
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
//                    cur_num += this_row[ind] * that_col[ind];
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


bool intmatrix1::_valid_init_str(const char* arr_str){
    int num_rows = 0;
    bool first_row = true;
    int num_cols = 0;
    int cur_col_num = 0;
    int cur_row_cols = 0;
   // int first_row_cols = 0;
    bool within_number = false;
    
    while(*arr_str){
#ifdef DEBUG0
        cout << *arr_str;
#endif
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
    //Need to verify that the last row is also valid
    if(!(num_cols == cur_col_num)){
            return false;
    }
    else{
        num_rows++;
    }
    return true;
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
void nqueens::generate_boards(int N){
    //Make sure we're only going up to N=8 queens
    if(N>COLS){
        cout << "The board is too large!" << endl;
        return;
    }
    
    //Allocate memory for a fresh board
    int (*board)[COLS] = new int[N][COLS];
    //Zero fill the NxN board to start off at a good point
    _zero_fill(board, N);
#ifdef DEBUGTEST
    //Fill with known solution
     _temp_fill(board);    
    //Check that the validatation is proper
    bool is_valid = _validate_solution(board, N);
    //Check that the print is proper
    if(is_valid){
        _print_solution(board, N);
    }
    return;
#endif
    //Loop through row by row.
    int row = 0;
    int col = 0;
    bool can_place_here = false;
    bool row_placed = false;
    int total_solutions = 0;
    while(row < N){
        //Look for the first valid empty spot, by traversing columns
        while(col < N){
            //Check the current row,col pair
            can_place_here = _check_square(board, row, col, N);
            //If this is a valid spot to place a queen, do it
            if(can_place_here){
                board[row][col] = 1;
                row_placed = true;
                break;
            }
            //If not that spot, check the next column
            col++;
        }
        //A queen was placed in this row, so move to the next row
        if(row_placed){
            row++;
            col = 0;
            row_placed = false;
#ifdef DEBUG
            cout << "GOOD!" << endl;
#endif
        }
        else{
            //There's no valid position for the queen on this current board!
            //We need to back track to the previous column and try again
            row--;
            int last_queen_col = _find_queen(board, row, N);
            _zero_fill_row(board, row, N);
            col = last_queen_col + 1;
#ifdef DEBUG
            cout << "BAD!" << endl;
#endif
        }
        
#ifdef DEBUG
        _print_array(board, N);
#endif
        //If we've found a solution, row == N
        if(row == N){
            bool is_solution = _validate_solution(board, N);
            if(is_solution){
                total_solutions++;
                cout << "Solution #" << total_solutions << " for " << N << "x" << N << " Board:" << endl;
                _print_solution(board, N);
            }
            //Now, we need to backtrack to the appropriate point to continue looking for solutions
            //It's possible that the first P (where P is less than N-1) rows will be the same for mutiple solutions.
            //Since we can't know that, we'll move up one row (which is the N-1 row) and keep going to the right.
            //This should keep going until row 0, col N-1 has been tested. This is our "terminating condition".
            row--;
            int last_queen_col = _find_queen(board, row, N);
            _zero_fill_row(board, row, N);
            col = last_queen_col + 1;
        }
        //We've tried all possible combos! So break out of the outer for loop and wrap things up!
        if(row == 0 && col == N){
            break;
        }        
    }
   
    delete[] board;
    cout << "------------------------" << endl;
    cout << "Total Solutions for an " << N << "x" << N << " Board: " << total_solutions << endl;
}

//Return the position of a queen in a certain row
int nqueens::_find_queen(const int arr[][COLS], int row, int N){
    for(int c = 0; c < N; c++){
        if(arr[row][c]){
            return c;
        }
    }
    //We should never really get here, but return the invalid coordinate of N if
    //we accidentally check an empty row!
    return N;
    
}

//Zero out a row to "remove" a placed queen
void nqueens::_zero_fill_row(int arr[][COLS], int row, int N){
    for(int c = 0; c < N; c++){
        arr[row][c] = 0;
    }
}

//Clear out an entire NxN board (necessary after allocation). 
//The point is to ensure that we have a known starting point, 
//since the allocated space will likely include garbage values.
void nqueens::_zero_fill(int arr[][COLS], int N){
    //Zero out each row in the NxN square
    for (int r = 0; r < N; r++) {
        _zero_fill_row(arr, r, N);
    }
}

//Check a potential square (row,col) to see if it's, at least currently,
//a valid spot for a queen piece.
bool nqueens::_check_square(const int arr[][COLS], int r, int c, int N){
    //There's guaranteed to be just one non-zero element: the queen
    //Thus, if we encounter any non-zero values in any of the 8 directions, 
    //we can return false immediately because we know that's invalid.
    
    //Look upward
    for(int up_row = r-1; up_row >=0; up_row--){
        if(arr[up_row][c]){
            return false;
        }                    
    }
    //Look downward
    for(int down_row = r+1; down_row < N; down_row++){
        if(arr[down_row][c]){
            return false;
        }                    
    }
    //Look rightward
    for(int cc = c+1; cc < N; cc++){
        if(arr[r][cc]){
            return false;
        }                    
    }
    //Look leftward
    for(int cc = c-1; cc >=0; cc--){
        if(arr[r][cc]){
            return false;
        }                    
    }
    //Diagonals, upward
    //To the right
    int cr = c+1;
    //To the left
    int cl = c-1;
    for(int up_row = r-1; up_row >=0; up_row--){
        //Up and to the right, if possible
        if(cr < N){
            if(arr[up_row][cr]){
                return false;
            }
        }
        //Up and to the left, if possible
        if(cl >= 0){
            if(arr[up_row][cl]){
                return false;
            }  
        }
        //Right one column
        cr++;
        //Left one column
        cl--;
    }
    //Diagonals, downward
    cr = c+1;
    //To the left
    cl = c-1;
    for(int down_row = r+1; down_row < N; down_row++){
        //Down and to the right, if possible
        if(cr < N){
            if(arr[down_row][cr]){
                return false;
            }
        }
        //Down and to the left, if possible
        if(cl >= 0){
            if(arr[down_row][cl]){
                return false;
            }  
        }
        //Right one column
        cr++;
        //Left one column
        cl--;
    }
    return true;
}


bool nqueens::_validate_solution(const int arr[][COLS], int N){
    //Traverse row by row
    for(int r = 0; r < N; r++){
        //Look column by column
        for(int c = 0; c < N; c++){
            //There's guaranteed to be just one non-zero element in a row: the queen
            if(arr[r][c]){              
                //Check that the current queen is in a valid spot
                bool is_valid = _check_square(arr, r, c, N);
                
                //If the current queen is not valid, return false
                if(!is_valid){
                    return false;
                }
                //All the directions are clear, so we're done with this row!
                //This is true because in valid solutions, 
                //there can only be one queen per row.
                break;
            }
        }
    }
    //We've checked all of the squares and haven't returned false, 
    //so it's a valid solution!
    return true;
}

//Print out the board: "-" for an empty spot, and "1" for a queen.
void nqueens::_print_solution(const int arr[][COLS], int N){
    //Print row by row, across columns.
    //A queen should be printed as a "1". An empty square should be a "-".
    for(int r = 0; r < N; r++){
        for(int c = 0; c < N; c++){
            int val = arr[r][c];
            if(val){
                cout << "1";
            }
            else{
                cout << "-";
            }
        }
        //New line at the end of a row
        cout << endl;
    }
}

//For debugging, print out the "raw" array (0 or 1). To be used to more easily 
//see how the algorithm is working and how the queens are being placed in the 
//empty squares.
void nqueens::_print_array(const int arr[][COLS], int N){
    //Print out a square, NxN array
    for(int r = 0; r < N; r++){
        for(int c = 0; c < N; c++){
            //Put spaces between elements in a row. Don't worry about hanging space.
            cout << arr[r][c] << " ";
        }
        //Put in a new line after a row is complete
        cout << endl;
    }
}


//A debug function. It fills a passed in array with a known 4x4 solution.
void nqueens::_temp_fill(int arr[][COLS]){
    //This is one of two solutions for a 4x4 board.
    int good[4][4] = { {0,1,0,0}, 
                       {0,0,0,1},
                       {1,0,0,0},
                       {0,0,1,0}};
                        
    //Place the queens in the proper spots (and empty out the right ones too).
    for(int r = 0; r < 4; r++){
        for(int c = 0; c < 4; c++){
            arr[r][c] = good[r][c];
        }
    } 
}
#endif

#if 0
//OUTPUT GOES HERE:

#endif
