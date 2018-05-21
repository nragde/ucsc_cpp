/*----------------------------------------------------------------
Copyright (c) 2018 Author: Jagadeesh Vasudevamurthy
file: intmatrix2test.cpp

On linux:
g++ intmatrix2.cpp intmatrix2test.cpp
valgrind a.out

-23174-- REDIR: 0x3e7b87b800 (libc.so.6:free) redirected to 0x4a06acd (free)
==23174== 
==23174== HEAP SUMMARY:
==23174==     in use at exit: 0 bytes in 0 blocks
==23174==   total heap usage: 149 allocs, 149 frees, 75,520 bytes allocated
==23174== 
==23174== All heap blocks were freed -- no leaks are possible
==23174== 
==23174== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 4 from 4)
--23174-- 
--23174-- used_suppression:      4 U1004-ARM-_dl_relocate_object /tools/baton/valgrind/3.12.0/lib/valgrind/default.supp:1413
==23174== 
==23174== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 4 from 4)
[jag@xsjrdevl100 intmatrix2]$ 

-----------------------------------------------------------------*/

/*----------------------------------------------------------------
This file test intmatrix2 object
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
All includes here
-----------------------------------------------------------------*/
#include "dealornodeal.h"

void test_suitcases(){
    suitcase case1(1, .01);
    cout << case1;
    suitcase case2(26, 1000000);
    case2.open_case();
    cout << case2;
    case1.set_value(5.0);
    cout << case1;
    cout << case1.get_number() << endl;
}

void test_list_of_suitcases(){
    double boxes[] = {0.1, 10.0, 100.0, 1000.0, 10000.0, 100000.0, 1000000.0};
    int boxes_size = sizeof(boxes)/sizeof(boxes[0]);
    list_of_suitcases list1(boxes, boxes_size);
    //Print them
    cout << list1;
    //Open a box;
    list1.open_case(3);
    cout << list1;
    //Get a deal
    double deal = list1.get_banker_deal();
    cout << "DEAL: $" << deal << endl;
    double boxes1[] = {0.1, 10.0, 100.0, 1000.0, 10000.0, 100000.0, 1000000.0};
    double boxes2[] = {0.1, 10.0, 100.0, 1000.0, 10000.0, 100000.0, 1000000.0};
    list_of_suitcases list2(boxes1, boxes_size, 600);
    list_of_suitcases list3(boxes2, boxes_size, 600000);
    cout << "--------------" <<endl;
    cout << list3;
    list3._swap(1,4);
    cout << list3;
    cout << "--------------" <<endl;
    for(int i = 0; i < 7; i++){
        list2.open_case(i);
        list3.open_case(i);
    }
    cout << list2;
    cout << list3;
    
}

void test_deal_or_no_deal(){
    
}
//
//void test_double_arr(){
//    double boxes[] = {0.1, 10.0, 100.0, 1000.0, 10000.0, 100000.0, 1000000.0};
//    for(int i = *boxes; i; i++){
//        cout << i;
//    }
//}

/*----------------------------------------------------------------
test bed
-----------------------------------------------------------------*/
void testbed() {
  //intmatrix2::makeShowOn() ;
    //cout << "Test bed:" << endl;
//    test_suitcases();
    test_list_of_suitcases();
    //test_double_arr();
    //test_deal_or_no_deal();
    //Play the game interactively
    //Play a game automatically
    //Turn off show and interactive
    //Play until you get the smallest amount of money
    //Play until you become a millionaire
}

/*----------------------------------------------------------------
main
-----------------------------------------------------------------*/
int main() {
    testbed();
    return 0;
}

//EOF


