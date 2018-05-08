//#pragma once
#ifndef INTMATRIX1_H
#define INTMATRIX1_H

// Do the includes
#include "../util/util.h"

// Define the public and private methods for the object
class intmatrix1 {
    public:
        //void init();
        void init(int row = 0, int col = 0, int val = 0);
        void init(const char* arr_str);
        void fini();
        bool isEmpty();
        bool isEqual(intmatrix1 a);
        intmatrix1 add(intmatrix1 a);
        intmatrix1 mult(intmatrix1 a);
        void print(const char * str);
        int get_rows();
        int get_cols();
        int get_arr_val(int row, int col);
        void set_arr_val(int row, int col, int val);
    private:
        bool _is_empty;
        int _rows;
        int _cols;
        int* _arr;
        bool _valid_init_str(const char* arr_str);
        bool _insert_str_vals(const char* arr_str);
        int _char_to_int(const char* int_str);
        
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
