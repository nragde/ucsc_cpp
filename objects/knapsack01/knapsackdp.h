/*----------------------------------------------------------------
Copyright (c) 2018 Author: Jagadeesh Vasudevamurthy
file: knapsackdp.h
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
This file has knapsackdp class declaration
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
All includes here
-----------------------------------------------------------------*/
#ifndef knapsackdp_H
#define knapsackdp_H

#include "knapsackbase.h"

/*----------------------------------------------------------------
class knapsackdp concrete class
-----------------------------------------------------------------*/
class knapsackdp : public knapsackbase {
public:
  knapsackdp() {
    //YOU CANNOT ADD ANYTHING HERE
    testbed();
  }
  ~knapsackdp() {}
  knapsackdp(const knapsackdp& m) = delete;
  knapsackdp& operator = (const knapsackdp& m) = delete;
protected:
  void knapsack(const char* t, int bagsize, int numitem, const int* w, const int* v, int& ans) {
    //WRITE YOUR CODE. Populate ans
      _t = t;
      _bagsize = bagsize;
      _numitems = numitem;
      _weights = w;
      _values = v;
      _max_value = 0;
      //Initialize the arrays that hold values and info on stolen/not stolen
      int total_elements = (_numitems+1)*(_bagsize+1);
      int value_arr[total_elements];
      int steal_arr[total_elements];
      _init_arr(value_arr, total_elements, -1);
      _init_arr(steal_arr, total_elements, -1);
      //Use dynamic programming programming to find the best combo of items to steal, given a bag size
      _max_value = _find_ans(value_arr, steal_arr, total_elements);
      //Print stuff, if a title is provided
      if(t){
          _print_output(value_arr, steal_arr, total_elements);
      }
      //Save the maximum stolen value in the passed in answer variable
      ans = _max_value;
  }
private:
  //You can have any number of private variables
    //Constant values for formatting the printed output
    const int _print_width = 4;
    const char* left_title_header = "-------------------------- ";
    const char* right_title_header = " ------------------------";
    // Object-level variables for the inputted variables
    const char* _t;
    int _bagsize;
    int _numitems;
    const int* _weights;
    const int* _values;
    int _max_value;
    
  //You can have any number of private functions
    int _find_ans(int* value_arr, int* steal_arr, int num_elements);
    void _should_we_steal(int* value_arr, int cur_numitems, int cur_bagsize, int& cur_val, int& should_steal);
    int _get_stealable_value(const int* value_arr, int cur_numitems, int w) const;
    void _determine_items_values(const int* value_arr, const int* steal_arr, vector<int>& stolen_items, vector<int>& stolen_values);
    //Arr specfic functions
    void _init_arr(int* arr, int num_elements, int val=0);
    //const int *arr, because we don't want to change when printing
    void _print_arr(const int* arr, int num_elements, const char* title="", bool print2d=false, int rows=0, int cols=0);
    void _print_output(const int* value_arr, const int* steal_arr, const int total_elements);
    void _print_vector(const vector<int>& vec, const char* delim="");
    //Provide 2d indicies, get back value (the 1d conversion is done internally)
    void _set_2d_val(int* arr, const int cur_num_items, const int cur_bagsize, const int value);
    int _get_2d_val(const int* arr, const int cur_num_items, const int cur_bagsize) const;
};



#endif

//EOF
