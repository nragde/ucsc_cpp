/*----------------------------------------------------------------
Copyright (c) 2018 Author: Jagadeesh Vasudevamurthy
file: dealornodealtest.cpp

On linux:
g++ dealornodeal.cpp dealornodealtest.cpp
valgrind a.out

-----------------------------------------------------------------*/

/*----------------------------------------------------------------
This file tests dealornodeal object
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
    cout << "----------------------------------------------------------------------" <<endl;
    cout << "TEST LIST OF SUITCASES" << endl;
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
//    list3._swap(1,4);
//    cout << list3;
    cout << "--------------" <<endl;
    cout << "LIST2:\n" << list2;
    cout << "LIST3:\n" << list3;
    for(int i = 0; i < 7; i++){
        list2.open_case(i);
        list3.open_case(i);
        if(list2){
            cout << "LIST2:\n" << list2;}
        if(list3){
        cout << "LIST3:\n" << list3;}
    }
    cout << "FINALLY:" <<endl;
    cout << list2;
    cout << list3;
    cout << "----------------------------------------------------------------------" <<endl;
    
}

void test_play_interactive(){
    double default_case_vals[] = {0.01, 1.0, 5.0, 10.0, 25.0, 50.0, 75.0, 100.0, 200.0, 300.0, 400.0, 500.0, 750.0, 1000.0, 5000.0, 10000.0, 25000.0, 50000.0, 75000.0, 100000.0, 200000.0, 300000.0, 400000.0, 500000.0, 750000.0, 1000000.0};
    dealornodeal::makeShowOn();
    dealornodeal::makeInteractiveOn();
    int num_cases = sizeof(default_case_vals)/sizeof(default_case_vals[0]);
    dealornodeal game1(num_cases, default_case_vals, 5);
    game1.play();
    cout << "----------------------------------------------------------------------------" << endl;
}

void test_play_automatically(){
    double default_case_vals[] = {0.01, 1.0, 5.0, 10.0, 25.0, 50.0, 75.0, 100.0, 200.0, 300.0, 400.0, 500.0, 750.0, 1000.0, 5000.0, 10000.0, 25000.0, 50000.0, 75000.0, 100000.0, 200000.0, 300000.0, 400000.0, 500000.0, 750000.0, 1000000.0};
    int num_cases = sizeof(default_case_vals)/sizeof(default_case_vals[0]);
    dealornodeal::makeShowOn();
    dealornodeal::makeInteractiveOff();
    dealornodeal game1(num_cases, default_case_vals, 9);
    game1.play();
    cout << "----------------------------------------------------------------------------" << endl;
}

void test_play_until_winning(double DESIRED_WINNINGS){
    assert(DESIRED_WINNINGS == 0.01 || DESIRED_WINNINGS == 1000000.0); //Only max or min, to prevent infinite loops
    double winnings = 0.0;
    int total_games = 0;
    cout << "Play Deal or No Deal until the winnings are $" << fixed << setprecision(2) << DESIRED_WINNINGS << endl;
    while(winnings != DESIRED_WINNINGS){
        dealornodeal::makeShowOff();
        dealornodeal::makeInteractiveOff();
        
        double default_case_vals[] = {0.01, 1.0, 5.0, 10.0, 25.0, 50.0, 75.0, 100.0, 200.0, 300.0, 400.0, 500.0, 750.0, 1000.0, 5000.0, 10000.0, 25000.0, 50000.0, 75000.0, 100000.0, 200000.0, 300000.0, 400000.0, 500000.0, 750000.0, 1000000.0};
        int num_cases = sizeof(default_case_vals)/sizeof(default_case_vals[0]);
        dealornodeal auto_bankrupt_game(num_cases, default_case_vals, 9);
        winnings = auto_bankrupt_game.play();
        total_games++;
        
        cout << "Game #" << total_games << ", Won: $" << fixed << setprecision(2) << winnings << endl;
    }
    cout << "It took " << total_games << " games to win $" << fixed << setprecision(2) << DESIRED_WINNINGS << "!"<< endl;
    cout << "----------------------------------------------------------------------------" << endl;
}

void test_random_class(){
    Random randomizer;
    int i = 0;
    int min = 50;
    int max = -1;
    
    while(i < 10000){
        int mynum=randomizer.get_random_number(1, 26);
//        cout << mynum << ", ";
        i++;
        if(mynum < min){ min = mynum;}
        if(mynum>max){max = mynum;}
    }
    cout << "\nMAX: "<<max<<"\nMIN: "<<min<<endl;
}

/*----------------------------------------------------------------
test bed
-----------------------------------------------------------------*/
void testbed() {
    //Play the game interactively
    test_play_interactive();
    //Play a game automatically
    test_play_automatically();
    //Play until you get the smallest amount of money
    test_play_until_winning(0.01);
    //Play until you become a millionaire
    test_play_until_winning(1000000.0);
}

/*----------------------------------------------------------------
main
-----------------------------------------------------------------*/
//These are static variables because otherwise the random number seeding was getting messed up
Random dealornodeal::randomizer;
Random list_of_suitcases::randomizer;
int main() {
    testbed();
    return 0;
}

//EOF


