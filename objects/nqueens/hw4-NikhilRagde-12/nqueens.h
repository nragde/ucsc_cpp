//#pragma once
#ifndef NQUEENS_H
#define NQUEENS_H

// Do the includes
#include "../util/util.h"

// Define the public and private methods for the object
class nqueens {
    public:
        void generate_boards(int N);
    private:
        static const int COLS = 8;
        int _find_queen(const int arr[][COLS], int row, int N);
        void _zero_fill_row(int arr[][COLS], int row, int N);
        void _zero_fill(int arr[][COLS], int N);
        bool _check_square(const int arr[][COLS], int r, int c, int N);
        bool _validate_solution(const int arr[][COLS], int N);
        void _print_solution(const int arr[][COLS], int N);
        void _print_array(const int arr[][COLS], int N);
        void _temp_fill(int arr[][COLS]);
};

#endif
