//#pragma once
#ifndef DEALORNODEAL_H
#define DEALORNODEAL_H

// Do the includes
#include "../util/util.h"

/*--------------------------------------------------------
class random number generator
----------------------------------------------------------*/
class Random {
public:
  Random() {srand((unsigned)time(0)); }
  int get_random_number(int a = 0, int b = 10000) const {
    int upper_bound, lower_bound;
    if(a < b) {
      upper_bound = b - a; lower_bound = a;
    }
    else if(a >= b) {
      upper_bound = a - b; lower_bound = b;
    }
    return(lower_bound + rand() % upper_bound);
  }

private:
  /* nobody can copy random or equal Random */
  Random(const Random& x);// = delete ;
  Random& operator=(const Random& x);// = delete ;
};

// Define the public and private methods for the object
class suitcase{
public:
    //Constructor
    suitcase(unsigned int num = 0, double val = 0.0);
    ~suitcase();
    //Note: no way to "close" a case once it's opened
    void open_case();
    //Access for private variables
    double get_value() const;
    unsigned int get_number() const;
    bool is_opened() const;
    //Need a set for when we shuffle cases in the game
    void set_value(double new_val);
    friend ostream& operator<<(ostream& o, const suitcase& one_case);
private:
    bool _opened;
    double _value;
    unsigned int _number;
    //No copy constructor or equal operator
    suitcase(const suitcase& temp);// = delete;
    suitcase& operator=(const suitcase& temp);// = delete;
};

//Crude linked list
class list_of_suitcases{
public:
    list_of_suitcases(double* case_values_list, unsigned int num_cases, unsigned int num_swaps = 1000);
    ~list_of_suitcases();
    //int get_num_cases(){return _num_cases;}
    double get_banker_deal();
    void open_case(int case_num);
    friend ostream& operator<<(ostream& o, const list_of_suitcases& case_list);
        void _shuffle_cases(int number_of_swaps = 1000);
    void _swap(int a, int b);
private:
    suitcase** _case_list; //A pointer to an array of suitcase objects
    double* _remaining_vals;
    unsigned int _index;
    unsigned int _maxsize;
    //int _num_cases;
    void _update_remaining_vals(suitcase* case_ptr);
//    void _shuffle_cases(int number_of_swaps = 1000);
//    void _swap(int a, int b);
    void _release();
    void _copy();
};


class dealornodeal{
    public:
        //Constructor
        dealornodeal(const unsigned int num_cases);
        ~dealornodeal();
        friend ostream& operator<<(ostream& o, const dealornodeal& game);
        //Game play
        void play();
        //Static methods to toggle the global settings
        static void makeShowOn(){_show = true;}
        static void makeShowOff(){_show = false;}
        static bool show(){return _show;}
        static void makeInteractiveOn(){_interactive = true;}
        static void makeInteractiveOff(){_interactive = false;}
        static bool interactive(){return _interactive;}
    private:
        //Show the debug print statements or not, off by default
        static bool _show;
        //Play the game interactively or not, off by default
        static bool _interactive;
        //No copy constructor or equal operator
        dealornodeal(const dealornodeal& dod);// = delete;
        dealornodeal& operator=(const dealornodeal& dod);// = delete;
        const unsigned int _num_cases;
};


#endif
