/*------------
Author: Nikhil Ragde
Student #12
Due Date: May 1, 2018
file: nqueens.cpp
*/

/*----------------------------------------------------------------
All includes here
-----------------------------------------------------------------*/
#include "dealornodeal.h"
//#define DEBUG_PRINTS 1
//#define DEBUG_INTERACTIVE
//#define DEBUG_AUTOMATED 1
//#define DEBUG_ROUNDS

/*--------------------------------------------------------
 * SUITCASE
----------------------------------------------------------*/
//Constructor
suitcase::suitcase(unsigned int num, double val):
    _number(num), _opened(false), _value(val), _first_picked(false){
#ifdef DEBUG_PRINTS
    cout << "In suitcase constructor: #" << _number << ", Value $" << _value << ", Opened: " << _opened << endl;
#endif
    //We want the money value to be positive. Negative values are invalid
    assert(val>=0.0);
}
suitcase::~suitcase(){
#ifdef DEBUG_PRINTS
    cout << "In suitcase destructor: #" << _number << ", Value $" << setprecision(numeric_limits<double>::digits10) << _value << ", Opened: " << _opened << endl;
#endif
    _value = -0.01;
}
//To handle couts
ostream& operator<<(ostream& o, const suitcase& one_case){
    o << "Case #" << one_case._number << ": $" << fixed << setprecision(2) << one_case._value << " (" << ( (one_case._opened) ? "Opened)":"Unopened)") <<endl ;
    return o;
}
//Note: no way to "close" a case once it's opened
void suitcase::open_case(){
    _opened = true;
}
//The case value is private, so we need a function to return that value
double suitcase::get_value() const{
    return _value;
}
unsigned int suitcase::get_number() const{
    return _number;
}
bool suitcase::is_opened() const{
    return _opened;
}
void suitcase::set_value(double new_val){
    assert(new_val >= 0.0);
    _value = new_val;
}
bool suitcase::is_first_picked() const{
    return _first_picked;
}
void suitcase::set_first_picked(){
    _first_picked = true;
}


/*--------------------------------------------------------
 * LIST OF SUITCASES
----------------------------------------------------------*/
//Crude linked list
list_of_suitcases::list_of_suitcases(double* case_values_list, unsigned int num_cases, unsigned int num_swaps):
    _case_list(nullptr), _remaining_vals(case_values_list), _index(0), _maxsize(num_cases){
#ifdef DEBUG_PRINTS
    cout << "In list_of_suitcases constructor" << endl;
#endif
    _case_list = new suitcase*[_maxsize];
    //The assumption is that num_cases is the number of elements in case_values_list
    //assert(sizeof(case_values_list)/sizeof(case_values_list[0]) == num_cases && "Number of list elements and num_cases do not match");
    //Create new suitcases and insert into the list
    for(int i = 0; i < num_cases; i++){
        suitcase* s = new suitcase(i+1, _remaining_vals[i]);
        _case_list[i] = s;
    }
    //Now shuffle the cases to get the list prepped. 
    //Only allow this to happen at construction, so that it's not 
    //possible to shuffle once the game has started.
    _shuffle_cases(num_swaps);
}

list_of_suitcases::~list_of_suitcases(){
#ifdef DEBUG_PRINTS
    cout << "In list_of_suitcases destructor" << endl;
#endif
    _release();
}
ostream& operator<<(ostream& o, const list_of_suitcases& case_list){
    o << "Unopened Suitcases: {";
    bool is_first = true;
    for(int i = 0; i < case_list._maxsize; i++){
        // Check if current case is open
        suitcase* tmp = case_list._case_list[i];
        if(not tmp->is_opened() and not case_list._case_list[i]->is_first_picked()){
            if(!is_first){
                o << ", ";
            }
            o << tmp->get_number();
            is_first = false;
        }
    }
    o << "}" << endl;
    is_first = true;
    o << "Potential Winnings on the Board: {";
    for(int i = 0; i < case_list._maxsize; i++){
        //Print all of the available values on the board
        double cur_val = case_list._remaining_vals[i];
        if(cur_val != -1){
            if(!is_first){
                o << ", ";
            }
            o << "$" << fixed << setprecision(2) << cur_val;
            is_first = false;
        }
    }
    o << "}" << endl;
    return o;
}

//True if at least one is unopened
//False if all are opened
list_of_suitcases::operator bool() const{
    bool at_least_one_unopened = false;
    for(int i = 0; i < _maxsize; i++){
        if(not _case_list[i]->is_opened()){
            at_least_one_unopened = true;
            break;
        }
    }
    return at_least_one_unopened;
}

//For the banker's deal, return the average of the unopened boxes
double list_of_suitcases::get_banker_deal(){
    double total_case_sum = 0.0;
    double num_unopened = 0;
    for(int i = 0; i < _maxsize; i++){
        if(not _case_list[i]->is_opened()){
            total_case_sum += _case_list[i]->get_value();
            num_unopened++;
        }
    }   
    return total_case_sum/num_unopened;
}
void list_of_suitcases::_release(){
    //Free each suitcase
    for(int i = 0; i < _maxsize; i++){
        delete _case_list[i];
    }
    //Then free the list
    delete [] _case_list;
    //Clean up the variables, just for completeness
    _case_list = nullptr;
    _maxsize = 0;
    
}
double list_of_suitcases::open_case(int case_num){
    assert(case_num >= 0 && case_num < _maxsize);
    suitcase* s = _case_list[case_num];
    s->open_case();
    _update_remaining_vals(s);
    return s->get_value();
}

void list_of_suitcases::set_first_picked(int case_num){
    assert(case_num > 0 && case_num <= _maxsize);
    _case_list[case_num-1]->set_first_picked();
}

bool list_of_suitcases::is_opened(int case_num){
    return _case_list[case_num]->is_opened();
}

void list_of_suitcases::_update_remaining_vals(suitcase* case_ptr){
    for(int i = 0; i < _maxsize; i++){
        if(_remaining_vals[i] == case_ptr->get_value()){
            _remaining_vals[i] = -1;
        }
    }
}
void list_of_suitcases::_shuffle_cases(int number_of_swaps){
    //Randomly swap case values number_of_swaps times
//    Random randomizer;
    for(int i = 0; i < number_of_swaps; i++){
        int caseA = randomizer.get_random_number(0, _maxsize-1);
        int caseB = randomizer.get_random_number(0, _maxsize-1);
        _swap(caseA, caseB);
    }
}
void list_of_suitcases::_swap(int a, int b){
#ifdef DEBUG_PRINTS_SWAP
    cout << "In list_of_suitcases _SWAP:" << endl;
#endif
    //Make sure we're swapping in valid numbers
    assert(a < _maxsize && a >= 0);
    assert(b < _maxsize && b >= 0);
    if(a != b){
#ifdef DEBUG_PRINTS_SWAP
        cout << "A: " << *_case_list[a];
        cout << "B: " << *_case_list[b];
#endif
        //Get value of a
        double a_val = _case_list[a]->get_value();
#ifdef DEBUG_PRINTS_SWAP
        cout << "A_Val: $" << a_val << endl;
#endif
        //Set to value of b
        _case_list[a]->set_value(_case_list[b]->get_value());
        //Set value of b to that which was previously a
        _case_list[b]->set_value(a_val);
#ifdef DEBUG_PRINTS_SWAP
        cout << "SWAPPED" << endl;
        cout << "A: " << *_case_list[a];
        cout << "B: " << *_case_list[b];
#endif
    }
}
void list_of_suitcases::get_case(int case_num){
    suitcase* a = _case_list[case_num];
    cout << a->is_first_picked();
    cout << *a;    
}

/*--------------------------------------------------------
DEAL OR NO DEAL
 * ----------------------------------------------------------*/
bool dealornodeal::_show = false;
bool dealornodeal::_interactive = true;
//Constructor
dealornodeal::dealornodeal(const unsigned int num_cases, double* case_values_list, unsigned int num_rounds):
 _num_cases(num_cases), _rounds(num_rounds), _game_cases(case_values_list, num_cases){
    if(show()){
        cout << "In dealornodeal constructor! " << endl;
        cout << _game_cases;
    }
    assert(_num_cases > 2 && "Please provide more cases.");
    assert(_rounds > 0);
    //Determine cases per round
    _determine_cases_per_round();
}

dealornodeal::~dealornodeal(){
    if(show()){
        cout << "In dealornodeal destructor! " << endl;
    }
    _release();
}
ostream& operator<<(ostream& o, const dealornodeal& game){
    return o;

}
double dealornodeal::play(){
    //cout.precision(2);
    //# suitcases, money in cases, and rounds have been inputted in the constructor
    //Pick a case
    _pick_safe_case();
#ifdef DEBUG_INTERACTIVE
    _game_cases.get_case(_saved_case_num);
    _game_cases.get_case(_saved_case_num-1);
    _game_cases.get_case(_saved_case_num+1);
#endif
    //Now, play each round. There should be just two cases left
    for(int round = 0; round < _rounds-1; round++){
        //Print out state at this point
        if(show()){
            cout << _game_cases;
        }
        //Figure out how many cases need to be opened this round
        int cases_in_round = _cases_per_round[round];
        if(show()){
            cout << "Pick " << cases_in_round << " Case(s):" << endl;
        }
        //Open the proper number of cases for this round
        for(int cur_case = 0; cur_case < cases_in_round; cur_case++){
//            int cur_case_num = _pick_a_case();
            _pick_a_case();
            //_game_cases.open_case(cur_case_num);
            if(show()){
                cout << _game_cases;
            }
        }
        //Get the banker's deal
        double bankers_deal = _game_cases.get_banker_deal();
        //Ask deal or no deal (always no deal, so just note it)
        if(show()){
            cout << "Banker's deal: $" << fixed << setprecision(2) << bankers_deal << endl;
            cout << "Deal... or No Deal?\nWe're playing to the end... NO DEAL!" << endl;
            cout << "----------" << endl;
        }
    }
    //Final banker's deal completed in loop above
    //Pick which one you'll keep (your case or the other case)
    int winning_case = _pick_final_case();
    //This is the winnings!
    double winning_amount = _game_cases.open_case(winning_case-1);
    if(show()){
        cout << "You opened case #" << winning_case << " to win $" << fixed << setprecision(2) << winning_amount << endl;
    }
    return winning_amount;
}

void dealornodeal::_release(){
    delete [] _cases_per_round;
}

void dealornodeal::_determine_cases_per_round(){
    assert(_rounds > 0);
    //The last round HAS to be 1 case (so that it's that case and the chosen case)
    
#ifdef DEBUG_AUTOMATED
    //    6	5	4	3	2	1	1	1	1
    //Temporary, to get games going
    _rounds = 9;
    _cases_per_round = new unsigned int[_rounds];
    int my_rounds[] = {6, 5, 4, 3, 2, 1, 1, 1, 1};
    for(int i = 0; i < _rounds; i++){
        
        _cases_per_round[i] = my_rounds[i];
    }
#else
    //Last round has to be 1 case (to pick between the last one and the chosen one)
    int cases_we_want = _num_cases - 1; //Adjust for the first picked case
    cases_we_want -= 1; //Adjust for the last round which is a 1
    //The last round is always a "pick one", so we need to figure out how many that is
    _cases_per_round = new unsigned int[_rounds - 1]; 
    unsigned int val = _rounds - 1;
    for(int i = 0; i < _rounds -1; i++){
        _cases_per_round[i] = val--; 
    }
#ifdef DEBUG_ROUNDS
    _print_arr(_cases_per_round, _rounds-1);
#endif
    
    //Check the sum. If it's under what we want, then we'll add stuff until we're good
    //If the sum is over what we want, we'll subtract until we're good
    if(_sum_arr(_cases_per_round, _rounds-1) > cases_we_want){
        //Subtract from the rounds until we reach the proper number
        while(_sum_arr(_cases_per_round, _rounds-1) != cases_we_want){
            //Subtract one case to a single round and see if we've met the case. If not, keep going.
            for(int i = 0; i < _rounds -1; i++){
                //Do not subtract if the round is already for just a single case
                if(_cases_per_round[i] != 1){  
                    _cases_per_round[i] -= 1;
                }
                if(_sum_arr(_cases_per_round, _rounds-1) == cases_we_want){
                    break;
                }
#ifdef DEBUG_ROUNDS
                _print_arr(_cases_per_round, _rounds-1);
#endif
            }
        }

    }
    else if(_sum_arr(_cases_per_round, _rounds-1) < cases_we_want){
        //Add to the rounds until we reach the proper number
        while(_sum_arr(_cases_per_round, _rounds-1) != cases_we_want){
            //Add one case to a single round and see if we've met the case. If not, keep going.
            for(int i = 0; i < _rounds -1; i++){
                _cases_per_round[i] += 1;
                if(_sum_arr(_cases_per_round, _rounds-1) == cases_we_want){
                    break;
                }
#ifdef DEBUG_ROUNDS
                _print_arr(_cases_per_round, _rounds-1);
#endif
            }
            
        }
    }
#ifdef DEBUG_ROUNDS
    _print_arr(_cases_per_round, _rounds-1);
#endif
    //If the sum is equal, then we've coincidentally found the proper number and we're good to go!    
#endif
}

int dealornodeal::_sum_arr(unsigned int arr[], int len){
    int mysum = 0;
    for(int i = 0; i < len; i++){
        mysum += arr[i];
    }
    return mysum;    
}

void dealornodeal::_print_arr(unsigned int arr[], int len){
    for(int i = 0; i < len; i++){
        cout << arr[i] << ", ";
    }
    cout << endl;
}

void dealornodeal::_pick_safe_case(){
    bool valid_num = false;
    unsigned int case_num;
//    Random randomizer; //Do this one, or else seeding will mess up
    while(!valid_num){
        if(interactive()){
            case_num = _get_user_input("Please pick a case: ");
        }
        else{
            //Automatically pick a case to save off
            case_num = randomizer.get_random_number(0, _num_cases-1);
        }
        if(case_num > 0 && case_num <= _num_cases){
            valid_num = true;
        }
    }
    _saved_case_num = case_num;
    _game_cases.set_first_picked(_saved_case_num);
    if(show()){
        cout << "Saved case #" << _saved_case_num << endl;
    }
}

int dealornodeal::_pick_a_case(){
    int case_num;
    bool valid_input = false;
//    Random randomizer; //Do this here, or else seeding will mess up
    while(!valid_input){
        if(interactive()){
            case_num = _get_user_input("Pick a case to open: ");
        }
        else{
            case_num = randomizer.get_random_number(0, _num_cases);
        }
        //We should have a number, so check that it's a valid one
        if(case_num>0 && case_num <= _num_cases){
            //The number itself is correct, so check if the case is already open
            //It also cannot be the case that was initially saved off
            if(!_game_cases.is_opened(case_num-1) and case_num!= _saved_case_num){
                //Not opened, so we're good to go
                valid_input = true;
            }
        }
        //If valid_input is still false, get another number!
    }
    double case_amount = _game_cases.open_case(case_num-1);
    if(show()){
        cout << "Opening case #" << case_num << " ($" << fixed << setprecision(2) << case_amount << ")" << endl;
    }
    return case_num;    
}

int dealornodeal::_pick_final_case(){
    int case_num;
    bool valid_input = false;
//    Random randomizer; //Do this here, or else seeding will mess up
    //The pick is for which one is the winnings
    if(show()){
        cout << "Your saved case: " << _saved_case_num << endl;
        cout << _game_cases;
    }
    
    while(!valid_input){
        if(interactive()){
            case_num = _get_user_input("Pick the case you want to take as winnings: ");
        }
        else{
            case_num = randomizer.get_random_number(0, _num_cases);
#ifdef DEBUG_AUTOMATED
            cout << "Random Final Pick: " << case_num << endl;
#endif
        }
        //We should have a number, so check that it's a valid one
        if(case_num>0 && case_num <= _num_cases){
            //The number itself is correct, so check if the case is already open
            if(!_game_cases.is_opened(case_num-1)){
                //Not opened, so we're good to go
                valid_input = true;
            }
        }
        //If valid_input is still false, get another number!
    }
    
    return case_num;
}

//This is a helpfer function to get user input. Taken from a stackoverflow answer, cited below.
int dealornodeal::_get_user_input(const char* prompt_str){
    //https://stackoverflow.com/questions/10828937/how-to-make-cin-take-only-numbers
    //https://stackoverflow.com/questions/19223360/implicit-instantiation-of-undefined-template-stdbasic-stringchar-stdchar
    string line;
    int input;
    cout << prompt_str;
    while (getline(cin, line))
    {
        //Make sure the entire cin can be converted into an int. If not, keep asking.
        stringstream ss(line);
        if (ss >> input)
        {
            if (ss.eof())
            {   // Success
                break;
            }
        }
        cout << "Error, please try again!\n" << prompt_str;
    }
    return input;    
}

#if 0
//OUTPUT GOES HERE:

#endif
