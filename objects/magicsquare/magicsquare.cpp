/*------------
Author: Nikhil Ragde
Student #12
Due Date: April 24, 2018
file: tommatsumoto.cpp
*/

/*----------------------------------------------------------------
All includes here
-----------------------------------------------------------------*/
#include "magicsquare.h"

void magicsquare::generate_square(int N){
    //Check that we can make a square this large
    assert(N<COLS);
    //Dynamically allocate a proper one
    int (*magic)[COLS] = new int[N][COLS];
    //Place the first number
    int row = 0;
    int col = N/2;
    magic[row][col] = 1;
    for(int i = 2; i <= N*N; i++){
        _move_diagonally(magic, row, col, N);
        magic[row][col] = i;
    }
    int sum = 0;
    bool is_valid = _validate_square(magic, N, sum);
    if(is_valid){
        _print_array(magic, N);
    }
}

void magicsquare::_move_up(int& r, int n){
    r -= 1;
    if(r < 0){
        r += n;
    }    
}

void magicsquare::_move_left(int& c, int n){
    c -= 1;
    if(c < 0){
        c += n;
    } 
}

void magicsquare::_move_down(int originalr, int originalc, int& r, int& c){
    r = originalr+1;
    c = originalc;
}

void magicsquare::_move_diagonally(int arr[][COLS], int& r, int& c, int n){
    //Get the coordinates of up and to the left, one square
    int cur_r = r;
    int cur_c = c;
    _move_up(r,n);
    _move_left(c,n);
    
    //Check if it's filled, and if it is, move straight down instead
    if(!arr[r][c]){
        _move_down(cur_r, cur_c, r, c);
    }
    //At this point, the new r,c pair should be set
}
bool magicsquare::_validate_square(const int arr[][COLS], int N, int& sum){
    cout << "TEMPT" << endl;
    return true;
}

void magicsquare::_print_array(const int arr[][COLS], int N){
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