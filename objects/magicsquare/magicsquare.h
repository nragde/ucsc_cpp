//#pragma once
#ifndef MAGICSQUARE_H
#define MAGICSQUARE_H

// Do the includes
#include "../util/util.h"

// Define the public and private methods for the object
class magicsquare {
    public:
        void generate_square(int N);
    private:
        static const int COLS = 100;
        void _zero_fill(int arr[][COLS], int N);
        void _move_up(int& r, int N);
        void _move_left(int& c, int N);
        void _move_down(int originalr, int originalc, int& r, int& c);
        void _move_diagonally(int arr[][COLS], int& r, int& c, int N);
        bool _validate_square(const int arr[][COLS], int N, int& sum);
        void _print_array(const int arr[][COLS], int N);
};

#endif
