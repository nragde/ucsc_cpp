//#pragma once
#ifndef INTMATRIX1_H
#define INTMATRIX1_H

// Do the includes
#include "../util/util.h"

// Define the public and private methods for the object
class intmatrix1 {
    public:
        void init(int row = 0, int col = 0, int val = 0);
        void init(const char* arr_str);
        void fini();
        bool isEmpty();
        bool isEqual(intmatrix1 a);
        intmatrix1 add(intmatrix1 a);
        intmatrix1 mult(intmatrix1 a);
        void print(const char * str);
        //The following are public functions to get/set private elements
        int get_rows();
        int get_cols();
        int get_arr_val(int row, int col);
        void set_arr_val(int row, int col, int val);
        void raw_set_arr_val(int ind, int val);
    private:
        bool _is_empty;
        int _rows;
        int _cols;
        int* _arr;
        bool _insert_str_vals(const char* arr_str);
        int _char_to_int(const char* int_str);
};

#endif
