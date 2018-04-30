/*------------
Author: Nikhil Ragde
Student #12
Due Date: April 24, 2018
file: tommatsumoto.cpp
*/

/*----------------------------------------------------------------
All includes here
-----------------------------------------------------------------*/
#include "nqueens.h"
//#define DEBUG 1


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
#ifdef DEBUG1
     _temp_fill(board);
    
    //Fill the board with all possible solutions
    
    
    //Board is done, so validate again just to make sure
    
    bool is_valid = _validate_solution(board, N);
    if(is_valid){
        _print_solution(board, N);
    }
#endif
    //DEBUG: Use _temp_fill() to fill a 4x4 board with a known solution
    //_temp_fill(board);
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
        //If we've found a solution, row = N-1 and row_placed == true
        if(row == N){
            //cout << "We've found a solution!" << endl;
            bool is_solution = _validate_solution(board, N);
            if(is_solution){
                total_solutions++;
                cout << "Solution #" << total_solutions << " for " << N << "x" << N << " Board:" << endl;
                _print_solution(board, N);
            }
            //Now, we need to backtrack to the appropriate point to continue looking for solutions
            //Attempt 2: It's possible that the first P (where P < N-1) rows will be the same for mutiple solutions.
            //Since we can't know that, we'll move up one row (which is the N-1 row) and keep going to the right.
            //This should keep going until row 0, col N-1 has been tested. This is our "terminating condition".
            row--;
            int last_queen_col = _find_queen(board, row, N);
            _zero_fill_row(board, row, N);
            col = last_queen_col + 1;
            
            
            
//            //ATTEMPT 1: Back to the row after the one in the last spot
//            for(int r = row--; r >= 0; r--){
//                row--;
//                int last_queen_col = _find_queen(board, row, N);
//                if(last_queen_col == N-1){
//                    row++;
//                    if(row == N){
//                       //this is the last row, not sure what to do now...
//                        break;
//                    }
//                    col = _find_queen(board,row,N) + 1;
//                }
//            }
        }
        //We've tried all possible combos!
        if(row == 0 && col == N){
            break;
        }
//        if(row < 0){
//            break;
//        }
        
    }
   
    delete[] board;
    cout << "------------------------" << endl;
    cout << "Total Solutions for an " << N << "x" << N << " Board: " << total_solutions << endl;
}

//Return the position of a queen in a certain row
int nqueens::_find_queen(int arr[][COLS], int row, int N){
    for(int c = 0; c < N; c++){
        if(arr[row][c]){
            return c;
        }
    }
    //We should never really get here, but return the invalid coordinate of N if
    //we accidentally check an empty row!
    return N;
    
}

//Clear out a row
void nqueens::_zero_fill_row(int arr[][COLS], int row, int N){
    for(int c = 0; c < N; c++){
        arr[row][c] = 0;
    }
}

void nqueens::_zero_fill(int arr[][COLS], int N){
    //Fill the NxN square with zeros, because it'll be garbage otherwise
    for (int r = 0; r < N; r++) {
        /*for (int c = 0; c < N; c++) {
            //Fill the NxN array with 0's.
            arr[r][c] = 0;
        }*/
        _zero_fill_row(arr, r, N);
    }
}

//Check a potential square (row,col) to see if it's, at least currently,
//a valid spot for a queen piece.
bool nqueens::_check_square(int arr[][COLS], int r, int c, int N){
    //There's guaranteed to be just one non-zero element: the queen
    //Look up
    for(int up_row = r-1; up_row >=0; up_row--){
        if(arr[up_row][c]){
            return false;
        }                    
    }
    //Look down
    for(int down_row = r+1; down_row < N; down_row++){
        if(arr[down_row][c]){
            return false;
        }                    
    }
    //Look right
    for(int cc = c+1; cc < N; cc++){
        if(arr[r][cc]){
            return false;
        }                    
    }
    //Look left
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
        //Up and to the right, if possible
        if(cr < N){
            if(arr[down_row][cr]){
                return false;
            }
        }
        //Up and to the left, if possible
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
    //Look at a row
    for(int r = 0; r < N; r++){
        //Look column by column
        for(int c = 0; c < N; c++){
            //There's guaranteed to be just one non-zero element: the queen
            if(arr[r][c]){
                //Look up
                for(int up_row = r-1; up_row >=0; up_row--){
                    if(arr[up_row][c]){
                        return false;
                    }                    
                }
                //Look down
                for(int down_row = r+1; down_row < N; down_row++){
                    if(arr[down_row][c]){
                        return false;
                    }                    
                }
                //Look right
                for(int cc = c+1; cc < N; cc++){
                    if(arr[r][cc]){
                        return false;
                    }                    
                }
                //Look left
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
                    //Up and to the right, if possible
                    if(cr < N){
                        if(arr[down_row][cr]){
                            return false;
                        }
                    }
                    //Up and to the left, if possible
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
                //All the directions are clear, so we're done with this row!
                break;
            }
        }
    }
    
    return true;
}


void nqueens::_print_solution(const int arr[][COLS], int N){
    //Print row by row, across columns.
    //cout << "N = " << N << ":" << endl;
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


//This is a temp function. It'll fill with a known good 4x4 board.
void nqueens::_temp_fill(int arr[][COLS]){
    int good[4][4] = { {0,1,0,0}, 
                       {0,0,0,1},
                       {1,0,0,0},
                       {0,0,1,0}};
                        
    
    for(int r = 0; r < 4; r++){
        for(int c = 0; c < 4; c++){
            arr[r][c] = good[r][c];
        }
    } 
}

#if 0
void magicsquare::generate_square(int N){
    //Check that we can make a square this large
    //assert(N<=COLS);
	if (N > COLS) {
		return;
	}
    //Dynamically allocate a proper one
    int (*magic)[COLS] = new int[N][COLS];
	_zero_fill(magic, N);
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
	if (is_valid) {
		if (N <= MAX_PRINT) {
			_print_array(magic, N);
		}
		cout << "Sides: " << N << ", Magic Sum = " << sum << endl;
	}
	delete[] magic;
}

void magicsquare::_zero_fill(int arr[][COLS], int N) {
	//Fill the NxN square with zeros, because it'll be garbage otherwise
	for (int r = 0; r < N; r++) {
		for (int c = 0; c < N; c++) {
			//Put spaces between elements in a row. Don't worry about hanging space.
			arr[r][c] = 0;
		}
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
	int val = arr[r][c];
    if(val != 0){
        _move_down(cur_r, cur_c, r, c);
    }
    //At this point, the new r,c pair should be set
}
bool magicsquare::_validate_square(const int arr[][COLS], int N, int& sum){
	int check_sum = 0;
	//int same_sums = true;
	//Get sum of the first row
	for (int c = 0; c < N; c++) {
		check_sum += arr[0][c];
	}
	//Check remaining rows
	for (int r = 1; r < N; r++) {
		int cur_sum = 0;
		for (int c = 0; c < N; c++) {
			cur_sum += arr[r][c];
		}
		if (cur_sum != check_sum) {
			return false;
		}
	}
	//Check cols
	for (int c = 1; c < N; c++) {
		int cur_sum = 0;
		for (int r = 0; r < N; r++) {
			cur_sum += arr[r][c];
		}
		if (cur_sum != check_sum) {
			return false;
		}
	}
	//Check the two diagonals
	//Top left to bottom right
	int cur_sum = 0;
	for (int rc = 0; rc < N; rc++) {
		cur_sum += arr[rc][rc];
	}
	if (cur_sum != check_sum) {
		return false;
	}
	//Bottom left to top right
	 cur_sum = 0;
	 for (int c = 0; c < N; c++) {
		 cur_sum += arr[N - c - 1][c];
	 }
	 if (cur_sum != check_sum) {
		 return false;
	 }
	 //All sum checks passed, so update the sum and return true
	 sum = check_sum;    
	 return true;
}

void magicsquare::_print_array(const int arr[][COLS], int N){
    //Print out a square, NxN array
	//Figure out how wide the longest number will be
	int width = 0;
	for (int i = N*N; i > 0; i = i/10) {
		width++;
	}
    for(int r = 0; r < N; r++){
        for(int c = 0; c < N; c++){
            //Put spaces between elements in a row. Don't worry about hanging space.
            cout << setw(width+2) << left << arr[r][c] << " ";
        }
        //Put in a new line after a row is complete
        cout << endl;
    }
}
#endif

#if 0
//OUTPUT GOES HERE:

	
#endif