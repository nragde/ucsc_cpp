/*------------
Author: Nikhil Ragde
Student #12
Due Date: May 1, 2018
file: nqueens.cpp
*/

/*----------------------------------------------------------------
All includes here
-----------------------------------------------------------------*/
#include "nqueens.h"
//#define DEBUG 1
//#define DEBUGTEST 1


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

#if 0
//OUTPUT GOES HERE:
------------------------------------------------
SOLUTIONS FOR AN 4x4 BOARD: 
------------------------------------------------
Solution #1 for 4x4 Board:
-1--
---1
1---
--1-
Solution #2 for 4x4 Board:
--1-
1---
---1
-1--
------------------------
Total Solutions for an 4x4 Board: 2
------------------------------------------------
------------------------------------------------
SOLUTIONS FOR AN 8x8 BOARD: 
------------------------------------------------
Solution #1 for 8x8 Board:
1-------
----1---
-------1
-----1--
--1-----
------1-
-1------
---1----
Solution #2 for 8x8 Board:
1-------
-----1--
-------1
--1-----
------1-
---1----
-1------
----1---
Solution #3 for 8x8 Board:
1-------
------1-
---1----
-----1--
-------1
-1------
----1---
--1-----
Solution #4 for 8x8 Board:
1-------
------1-
----1---
-------1
-1------
---1----
-----1--
--1-----
Solution #5 for 8x8 Board:
-1------
---1----
-----1--
-------1
--1-----
1-------
------1-
----1---
Solution #6 for 8x8 Board:
-1------
----1---
------1-
1-------
--1-----
-------1
-----1--
---1----
Solution #7 for 8x8 Board:
-1------
----1---
------1-
---1----
1-------
-------1
-----1--
--1-----
Solution #8 for 8x8 Board:
-1------
-----1--
1-------
------1-
---1----
-------1
--1-----
----1---
Solution #9 for 8x8 Board:
-1------
-----1--
-------1
--1-----
1-------
---1----
------1-
----1---
Solution #10 for 8x8 Board:
-1------
------1-
--1-----
-----1--
-------1
----1---
1-------
---1----
Solution #11 for 8x8 Board:
-1------
------1-
----1---
-------1
1-------
---1----
-----1--
--1-----
Solution #12 for 8x8 Board:
-1------
-------1
-----1--
1-------
--1-----
----1---
------1-
---1----
Solution #13 for 8x8 Board:
--1-----
1-------
------1-
----1---
-------1
-1------
---1----
-----1--
Solution #14 for 8x8 Board:
--1-----
----1---
-1------
-------1
1-------
------1-
---1----
-----1--
Solution #15 for 8x8 Board:
--1-----
----1---
-1------
-------1
-----1--
---1----
------1-
1-------
Solution #16 for 8x8 Board:
--1-----
----1---
------1-
1-------
---1----
-1------
-------1
-----1--
Solution #17 for 8x8 Board:
--1-----
----1---
-------1
---1----
1-------
------1-
-1------
-----1--
Solution #18 for 8x8 Board:
--1-----
-----1--
-1------
----1---
-------1
1-------
------1-
---1----
Solution #19 for 8x8 Board:
--1-----
-----1--
-1------
------1-
1-------
---1----
-------1
----1---
Solution #20 for 8x8 Board:
--1-----
-----1--
-1------
------1-
----1---
1-------
-------1
---1----
Solution #21 for 8x8 Board:
--1-----
-----1--
---1----
1-------
-------1
----1---
------1-
-1------
Solution #22 for 8x8 Board:
--1-----
-----1--
---1----
-1------
-------1
----1---
------1-
1-------
Solution #23 for 8x8 Board:
--1-----
-----1--
-------1
1-------
---1----
------1-
----1---
-1------
Solution #24 for 8x8 Board:
--1-----
-----1--
-------1
1-------
----1---
------1-
-1------
---1----
Solution #25 for 8x8 Board:
--1-----
-----1--
-------1
-1------
---1----
1-------
------1-
----1---
Solution #26 for 8x8 Board:
--1-----
------1-
-1------
-------1
----1---
1-------
---1----
-----1--
Solution #27 for 8x8 Board:
--1-----
------1-
-1------
-------1
-----1--
---1----
1-------
----1---
Solution #28 for 8x8 Board:
--1-----
-------1
---1----
------1-
1-------
-----1--
-1------
----1---
Solution #29 for 8x8 Board:
---1----
1-------
----1---
-------1
-1------
------1-
--1-----
-----1--
Solution #30 for 8x8 Board:
---1----
1-------
----1---
-------1
-----1--
--1-----
------1-
-1------
Solution #31 for 8x8 Board:
---1----
-1------
----1---
-------1
-----1--
1-------
--1-----
------1-
Solution #32 for 8x8 Board:
---1----
-1------
------1-
--1-----
-----1--
-------1
1-------
----1---
Solution #33 for 8x8 Board:
---1----
-1------
------1-
--1-----
-----1--
-------1
----1---
1-------
Solution #34 for 8x8 Board:
---1----
-1------
------1-
----1---
1-------
-------1
-----1--
--1-----
Solution #35 for 8x8 Board:
---1----
-1------
-------1
----1---
------1-
1-------
--1-----
-----1--
Solution #36 for 8x8 Board:
---1----
-1------
-------1
-----1--
1-------
--1-----
----1---
------1-
Solution #37 for 8x8 Board:
---1----
-----1--
1-------
----1---
-1------
-------1
--1-----
------1-
Solution #38 for 8x8 Board:
---1----
-----1--
-------1
-1------
------1-
1-------
--1-----
----1---
Solution #39 for 8x8 Board:
---1----
-----1--
-------1
--1-----
1-------
------1-
----1---
-1------
Solution #40 for 8x8 Board:
---1----
------1-
1-------
-------1
----1---
-1------
-----1--
--1-----
Solution #41 for 8x8 Board:
---1----
------1-
--1-----
-------1
-1------
----1---
1-------
-----1--
Solution #42 for 8x8 Board:
---1----
------1-
----1---
-1------
-----1--
1-------
--1-----
-------1
Solution #43 for 8x8 Board:
---1----
------1-
----1---
--1-----
1-------
-----1--
-------1
-1------
Solution #44 for 8x8 Board:
---1----
-------1
1-------
--1-----
-----1--
-1------
------1-
----1---
Solution #45 for 8x8 Board:
---1----
-------1
1-------
----1---
------1-
-1------
-----1--
--1-----
Solution #46 for 8x8 Board:
---1----
-------1
----1---
--1-----
1-------
------1-
-1------
-----1--
Solution #47 for 8x8 Board:
----1---
1-------
---1----
-----1--
-------1
-1------
------1-
--1-----
Solution #48 for 8x8 Board:
----1---
1-------
-------1
---1----
-1------
------1-
--1-----
-----1--
Solution #49 for 8x8 Board:
----1---
1-------
-------1
-----1--
--1-----
------1-
-1------
---1----
Solution #50 for 8x8 Board:
----1---
-1------
---1----
-----1--
-------1
--1-----
1-------
------1-
Solution #51 for 8x8 Board:
----1---
-1------
---1----
------1-
--1-----
-------1
-----1--
1-------
Solution #52 for 8x8 Board:
----1---
-1------
-----1--
1-------
------1-
---1----
-------1
--1-----
Solution #53 for 8x8 Board:
----1---
-1------
-------1
1-------
---1----
------1-
--1-----
-----1--
Solution #54 for 8x8 Board:
----1---
--1-----
1-------
-----1--
-------1
-1------
---1----
------1-
Solution #55 for 8x8 Board:
----1---
--1-----
1-------
------1-
-1------
-------1
-----1--
---1----
Solution #56 for 8x8 Board:
----1---
--1-----
-------1
---1----
------1-
1-------
-----1--
-1------
Solution #57 for 8x8 Board:
----1---
------1-
1-------
--1-----
-------1
-----1--
---1----
-1------
Solution #58 for 8x8 Board:
----1---
------1-
1-------
---1----
-1------
-------1
-----1--
--1-----
Solution #59 for 8x8 Board:
----1---
------1-
-1------
---1----
-------1
1-------
--1-----
-----1--
Solution #60 for 8x8 Board:
----1---
------1-
-1------
-----1--
--1-----
1-------
---1----
-------1
Solution #61 for 8x8 Board:
----1---
------1-
-1------
-----1--
--1-----
1-------
-------1
---1----
Solution #62 for 8x8 Board:
----1---
------1-
---1----
1-------
--1-----
-------1
-----1--
-1------
Solution #63 for 8x8 Board:
----1---
-------1
---1----
1-------
--1-----
-----1--
-1------
------1-
Solution #64 for 8x8 Board:
----1---
-------1
---1----
1-------
------1-
-1------
-----1--
--1-----
Solution #65 for 8x8 Board:
-----1--
1-------
----1---
-1------
-------1
--1-----
------1-
---1----
Solution #66 for 8x8 Board:
-----1--
-1------
------1-
1-------
--1-----
----1---
-------1
---1----
Solution #67 for 8x8 Board:
-----1--
-1------
------1-
1-------
---1----
-------1
----1---
--1-----
Solution #68 for 8x8 Board:
-----1--
--1-----
1-------
------1-
----1---
-------1
-1------
---1----
Solution #69 for 8x8 Board:
-----1--
--1-----
1-------
-------1
---1----
-1------
------1-
----1---
Solution #70 for 8x8 Board:
-----1--
--1-----
1-------
-------1
----1---
-1------
---1----
------1-
Solution #71 for 8x8 Board:
-----1--
--1-----
----1---
------1-
1-------
---1----
-1------
-------1
Solution #72 for 8x8 Board:
-----1--
--1-----
----1---
-------1
1-------
---1----
-1------
------1-
Solution #73 for 8x8 Board:
-----1--
--1-----
------1-
-1------
---1----
-------1
1-------
----1---
Solution #74 for 8x8 Board:
-----1--
--1-----
------1-
-1------
-------1
----1---
1-------
---1----
Solution #75 for 8x8 Board:
-----1--
--1-----
------1-
---1----
1-------
-------1
-1------
----1---
Solution #76 for 8x8 Board:
-----1--
---1----
1-------
----1---
-------1
-1------
------1-
--1-----
Solution #77 for 8x8 Board:
-----1--
---1----
-1------
-------1
----1---
------1-
1-------
--1-----
Solution #78 for 8x8 Board:
-----1--
---1----
------1-
1-------
--1-----
----1---
-1------
-------1
Solution #79 for 8x8 Board:
-----1--
---1----
------1-
1-------
-------1
-1------
----1---
--1-----
Solution #80 for 8x8 Board:
-----1--
-------1
-1------
---1----
1-------
------1-
----1---
--1-----
Solution #81 for 8x8 Board:
------1-
1-------
--1-----
-------1
-----1--
---1----
-1------
----1---
Solution #82 for 8x8 Board:
------1-
-1------
---1----
1-------
-------1
----1---
--1-----
-----1--
Solution #83 for 8x8 Board:
------1-
-1------
-----1--
--1-----
1-------
---1----
-------1
----1---
Solution #84 for 8x8 Board:
------1-
--1-----
1-------
-----1--
-------1
----1---
-1------
---1----
Solution #85 for 8x8 Board:
------1-
--1-----
-------1
-1------
----1---
1-------
-----1--
---1----
Solution #86 for 8x8 Board:
------1-
---1----
-1------
----1---
-------1
1-------
--1-----
-----1--
Solution #87 for 8x8 Board:
------1-
---1----
-1------
-------1
-----1--
1-------
--1-----
----1---
Solution #88 for 8x8 Board:
------1-
----1---
--1-----
1-------
-----1--
-------1
-1------
---1----
Solution #89 for 8x8 Board:
-------1
-1------
---1----
1-------
------1-
----1---
--1-----
-----1--
Solution #90 for 8x8 Board:
-------1
-1------
----1---
--1-----
1-------
------1-
---1----
-----1--
Solution #91 for 8x8 Board:
-------1
--1-----
1-------
-----1--
-1------
----1---
------1-
---1----
Solution #92 for 8x8 Board:
-------1
---1----
1-------
--1-----
-----1--
-1------
------1-
----1---
------------------------
Total Solutions for an 8x8 Board: 92
------------------------------------------------

#endif
