//#pragma once
#ifndef DEALORNODEAL_H
#define DEALORNODEAL_H

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

class suitcase{
public:
    //Constructor
    suitcase(double val = 0);
    //Note: no way to "close" a case once it's opened
    void open_case();
    double get_value();
    friend ostream& operator<<(ostream& o, const suitcase& one_case);
private:
    bool _opened;
    double _value;
};

//Crude linked list
class list_of_suitcases{
public:
    list_of_suitcases(int num = 26);
    ~list_of_suitcases();
    //int get_num_cases(){return _num_cases;}
    double get_banker_deal();
    friend ostream& operator<<(ostream& o, const list_of_suitcases& case_list);
private:
    suitcase** _case_list; //An array of pointers to suitcase objects
    int _size;
    int _maxsize;
    //int _num_cases;
    void _release();
    void _copy();
};


class dealornodeal{
    public:
        //Constructor
        dealornodeal(const unsigned int num_cases = 26, double* money_vals = _default_case_vals, int rounds = 7);
        ~dealornodeal();
        friend ostream& operator<<(ostream& o, const dealornodeal& game);
        void play();
        //Static methods to toggle the global settings
        static void makeShowOn(){_show = true;}
        static void makeShowOff(){_show = false;}
        static bool show(){return _show;}
        static void makeInteractiveOn(){_interactive = true;}
        static void makeInteractiveOff(){_interactive = false;}
        static bool interactive(){return _interactive;}
    private:
//        double _default_case_vals[26] = {0.01, 1.0, 5.0, 10.0, 25.0, 50.0, 75.0, 100.0, 200.0, 300.0, 400.0, 500.0 750.0, 1000.0, 5000.0, 10000.0, 25000.0, 50000.0, 75000.0, 100000.0, 200000.0, 300000.0, 400000.0, 500000.0, 750000.0, 1000000.0};
        double  _default_case_vals[1] = {0.01};
        const unsigned int _num_cases;
        double* _case_values;
        const int _rounds;
        list_of_suitcases _game_cases;
        
        
        //Show the debug print statements or not, off by default
        static bool _show;
        //Play the game interactively or not, off by default
        static bool _interactive;
        //No copy constructor or equal operator
        dealornodeal(const dealornodeal& dod);// = delete;
        dealornodeal& operator=(const dealornodeal& dod);// = delete;
};


#endif
