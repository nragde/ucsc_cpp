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
//      void _print_arr(const int* arr, int num_elements, const char* title="", bool print2d=false, int rows=0, int cols=0);
//      int temp_arr[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
//      _print_arr(temp_arr, 9, "TEST", true, 3, 3);
      int total_elements = (_numitems+1)*(_bagsize+1);
      int value_arr[total_elements];
      int steal_arr[total_elements];
      _init_arr(value_arr, total_elements, -1);
      _init_arr(steal_arr, total_elements, -1);
      
      _max_value = _find_ans(value_arr, steal_arr, total_elements);
      
      //Print stuff!
      if(t){
          _print_output(value_arr, steal_arr, total_elements, t);
      }
      ans = _max_value;
  }
private:
  //You can have any number of private variables
    int ff[6][6];
    int** jj;
    
    //Constant values for formatting the printed output
    const int _print_width = 4;
//    const char* matrix_header = "----------------";
    const char* left_title_header = "-------------------------- ";
    const char* right_title_header = " ------------------------";
    
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
    
    void _init_arr(int* arr, int num_elements, int val=0);
    //const int *arr, because we don't want to change when printing
    void _print_arr(const int* arr, int num_elements, const char* title="", bool print2d=false, int rows=0, int cols=0);
    void _print_output(const int* value_arr, const int* steal_arr, const int total_elements, const char* title);
    void _print_vector(const vector<int>& vec, const char* delim="");
    
    void _set_2d_val(int* arr, int cur_num_items, int cur_bagsize, int value);
    int _get_2d_val(const int* arr, const int cur_num_items, const int cur_bagsize) const;
};



#endif

//EOF
