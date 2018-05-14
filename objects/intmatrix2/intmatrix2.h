//#pragma once
#ifndef INTMATRIX2_H
#define INTMATRIX2_H

// Do the includes
#include "../util/util.h"

// Define the public and private methods for the object
class intmatrix2 {
    public:
        //Two constructors, one for ints and one for string
        intmatrix2(int row = 0, int col = 0, int val = 0);
        intmatrix2(const char* arr_str);
        //Destructor
        ~intmatrix2();
        //Copy constructor
        intmatrix2(const intmatrix2& mat);
        //Equal operator
        intmatrix2& operator=(const intmatrix2& mat);
        //Print operator (<<)
        friend ostream& operator<<(ostream& o, const intmatrix2& mat);
        //Functions
        bool isEmpty() const;
        bool isEqual(const intmatrix2 a) const;
        intmatrix2 add(const intmatrix2 mat) const;
        intmatrix2 mult(const intmatrix2 mat) const;
    private:
        //Vars
        bool _is_empty;
        int _rows;
        int _cols;
        int* _arr;
        //Helper functions
        void _release();
        void _copy(const intmatrix2& orig_mat);
        bool _insert_str_vals(const char* arr_str);
        int _char_to_int(const char* int_str);
        int _rcind(int r, int c) const;
};

#endif
