/*----------------------------------------------------------------
Copyright (c) 2018 Author: Jagadeesh Vasudevamurthy
file: knapsackdp.cpp
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
knapsackdp class
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
All includes here
-----------------------------------------------------------------*/
#include "knapsackdp.h"

//#define _DEBUG0         0

/*----------------------------------------------------------------
WRITE YOUR CODE BELOW
-----------------------------------------------------------------*/

int knapsackdp::_find_ans(int* value_arr, int* steal_arr, int num_elements){
    
    for(int cur_numitems = 0; cur_numitems <= _numitems; ++cur_numitems){
        for(int cur_bagsize = 0; cur_bagsize <= _bagsize; ++cur_bagsize){
#ifdef _DEBUG0
            cout << endl << endl << "NUM ITEMS: " << cur_numitems << ", CUR BAGSIZE: " << cur_bagsize << endl;
#endif
//            int index_in_1d = items*_numitems+bag;
            //If there are no items (items ==0) or if our bagsize is 0 (bag == 0)
            // it's impossible to steal anything
            // (i.e. the first row and first column should always be 0)
            if(cur_numitems == 0 or cur_bagsize == 0){
                _set_2d_val(value_arr, cur_numitems, cur_bagsize, 0);
                _set_2d_val(steal_arr, cur_numitems, cur_bagsize, 0);
#ifdef _DEBUG0
                //Print stuff!
                _print_arr(value_arr, num_elements, "----------- VALUE ARRAY -----------\n", true, _numitems+1, _bagsize + 1);
                _print_arr(steal_arr, num_elements, "----------- STEAL ARRAY -----------\n", true, _numitems+1, _bagsize + 1);
#endif
            }
            else{
#ifdef _DEBUG0
                //Print stuff!
                _print_arr(value_arr, num_elements, "----------- VALUE ARRAY -----------\n", true, _numitems+1, _bagsize + 1);
                _print_arr(steal_arr, num_elements, "----------- STEAL ARRAY -----------\n", true, _numitems+1, _bagsize + 1);
                cout << "DO THINGS" << endl;
#endif
                
                //Solve via the dynamic programming method if we have a non-zero bag size
                // or a non-zero number of items to choose from
                int cur_val = 0;
                int should_steal = 0;
                _should_we_steal(value_arr, cur_numitems, cur_bagsize, cur_val, should_steal);
                _set_2d_val(value_arr, cur_numitems, cur_bagsize, cur_val);
                _set_2d_val(steal_arr, cur_numitems, cur_bagsize, should_steal);
#ifdef _DEBUG0
                //Print stuff!
                _print_arr(value_arr, num_elements, "----------- VALUE ARRAY -----------\n", true, _numitems+1, _bagsize + 1);
                _print_arr(steal_arr, num_elements, "----------- STEAL ARRAY -----------\n", true, _numitems+1, _bagsize + 1);
#endif
            }
        }
    }
    
    //The bottom rightmost element in our "2D array" is the maximum value to steal with our given _bagsize
    return value_arr[num_elements-1];
}

void knapsackdp::_should_we_steal(int* value_arr, int cur_numitems, int cur_bagsize, int& cur_val, int& should_steal){
    //Get the info for the latest
    int cur_w = _weights[cur_numitems-1];
//    int cur_v = _values[cur_numitems-1];
    
    //Get the previous max value for this bag size
    int prev_max_value = _get_2d_val(value_arr, cur_numitems-1, cur_bagsize);
    bool we_stole = false;
    int this_item_max = 0;
    if(cur_w <= cur_bagsize){
        //We *may* be able to steal this current item
        this_item_max = _get_stealable_value(value_arr, cur_numitems, cur_bagsize);
        
        if(this_item_max >= prev_max_value){
            we_stole = true;
        }
    }
    
    if(we_stole){
        cur_val = this_item_max;
        should_steal = 1;
    }
    else{
        //We cannot steal this current item, so the max value here is whatever we previously found
        cur_val = prev_max_value;
        should_steal = 0;
    }
}

int knapsackdp::_get_stealable_value(const int* value_arr, int cur_numitems, int w) const{
    int this_val = 0;
    //Get the info for the latest
    int cur_w = _weights[cur_numitems-1];
    int cur_v = _values[cur_numitems-1];
    this_val += cur_v;
    w -= cur_w;
    int max_remaining = _get_2d_val(value_arr, cur_numitems-1, w);
    this_val += max_remaining;
    return this_val;
}

void knapsackdp::_set_2d_val(int* arr, int cur_num_items, int cur_bagsize, int value){
    int index_in_1d = cur_num_items * (_bagsize+1) + cur_bagsize;
    arr[index_in_1d] = value;
}

int knapsackdp::_get_2d_val(const int* arr, const int cur_num_items, const int cur_bagsize) const{
    int index_in_1d = cur_num_items * (_bagsize+1) + cur_bagsize;
    return arr[index_in_1d];
}

void knapsackdp::_init_arr(int* arr, int num_elements, int val){
    for(int i = 0; i < num_elements; ++i){
        arr[i] = val;
    }
}

//const int *arr, because we don't want to change when printing
void knapsackdp::_print_arr(const int* arr, int num_elements, const char* title, bool print2d, int rows, int cols){
    if(print2d){
        // print as 2d
        assert(num_elements == rows*cols);
        cout << title ;
        for(int r = 0; r < rows; ++r){
            for(int c = 0; c < cols; ++c){
                int index_1d = r*cols + c;
                cout << setw(_print_width)<< arr[index_1d];
            }
            cout << endl;
        }
        
    }
    else{
        //Print as 1 row
        cout << title ;
        //Print the array as a 1D array
        for(int i = 0; i < num_elements; ++i){
            cout << setw(_print_width) << arr[i];
        }
        cout << endl;
    }
}

void knapsackdp::_print_output(const int* value_arr, const int* steal_arr, const int total_elements, const char* title){
    //Print stuff!
    cout << left_title_header << title << right_title_header << endl;
    _print_arr(value_arr, total_elements, "------------ V matrix ----------------\n", true, _numitems+1, _bagsize + 1);
    _print_arr(steal_arr, total_elements, "------------ k matrix ----------------\n", true, _numitems+1, _bagsize + 1);
    //Print out the indices (manually)
    cout << "i = ";
    for(int i = 1; i <= _numitems; ++i){
        cout << setw(_print_width) << i;
    }
    cout << endl;
    _print_arr(_weights, _numitems, "w = ");
    _print_arr(_values, _numitems, "v = ");
//    cout << "Max Value of " << _max_value << " can obtained from items {" << 3,1 << "} that has values {" << 4+5 << "=" << _max_value<<"}" << endl;
    vector<int> stolen_items, stolen_values;
    _determine_items_values(value_arr, steal_arr, stolen_items, stolen_values);
    cout << "Max Value of " << _max_value << " can obtained from items {";
    _print_vector(stolen_items, ",");
    cout << "} that has values {";
    _print_vector(stolen_values, "+");
    cout << "=" << _max_value <<"}" << endl;

}

void knapsackdp::_determine_items_values(const int* value_arr, const int* steal_arr, vector<int>& stolen_items, vector<int>& stolen_values){
    //Start at last row and last column
//    for(int cur_num_items = _numitems)
//    int cur_r = _numitems;
//    int cur_c = _bagsize;
    //Get the info for the latest
    int cur_bagsize = _bagsize;
    for(int cur_num_items = _numitems; cur_num_items > 0; --cur_num_items){
        int cur_w = _weights[cur_num_items-1];
        int cur_v = _values[cur_num_items-1];
        
        int did_steal = _get_2d_val(steal_arr, cur_num_items, cur_bagsize);
        if(did_steal){
            stolen_items.push_back(cur_num_items);
            stolen_values.push_back(cur_v);
            cur_bagsize -= cur_w;
        }
    }
}

void knapsackdp::_print_vector(const vector<int>& vec, const char* delim){
    for(int i = 0; i < vec.size();){
        cout << vec[i];
        if(++i != vec.size()){
            cout << delim;
        }
    }
}
//EOF
