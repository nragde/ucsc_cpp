//#pragma once
#ifndef ISET64_H
#define ISET64_H

// Do the includes
#include "../util/util.h"

/*--------------------------------------------------------
class integer set (integers between 0 and 63)
----------------------------------------------------------*/
class iset64{
public:
    iset64(const int arr[] = nullptr, int length = 0);
    ~iset64();
    iset64(const iset64& set);
    iset64& operator=(const iset64& set);
    friend ostream& operator<<(ostream& o, const iset64& set);
    //Operators
    friend iset64& operator++(iset64& set);
    friend iset64 operator++(iset64& set, int post);
    friend iset64& operator--(iset64& set);
    friend iset64 operator--(iset64& set, int post);
    friend iset64 operator~(iset64& set);
    friend bool operator!(const iset64& set);
    operator bool() const;
    //Binary operators
    friend iset64 operator+(const iset64& a, const iset64& b);
    friend iset64 operator+(const iset64& a, int b);
    friend iset64 operator+(int a, const iset64& b);
    friend iset64 operator-(const iset64& a, const iset64& b);
    friend iset64 operator-(const iset64& a, int b);
    friend iset64 operator-(int a, const iset64& b);
    friend iset64 operator*(const iset64& a, const iset64& b);
    friend iset64 operator*(const iset64& a, int b);
    friend iset64 operator*(int a, const iset64& b);
    //Equals
    friend iset64& operator +=(iset64& a, const iset64& b);
    friend iset64& operator +=(iset64& a, int b);
    friend iset64& operator -=(iset64& a, const iset64& b);
    friend iset64& operator -=(iset64& a, int b);
    friend iset64& operator *=(iset64& a, const iset64& b);
    friend iset64& operator *=(iset64& a, int b);
    //Relational
    friend bool operator==(const iset64& a, const iset64& b);
    //Comparisons
    //Statics
    static void set_display(bool state){_show = state;}
    
    static void makeShowOn(){_show = true;}
    static void makeShowOff(){_show = false;}
    static bool show(){return _show;} 
private:
    //Variables
    int* _arr;
    int _len;
    //Helper functions
    void _release();
    void _copy(const iset64& set);
    void _alloc(const int x[], int len);
    void _init_arr(const int x[], int len);
    void _zero_fill_arr();
    //Statics
    static bool _show;
};




#endif
