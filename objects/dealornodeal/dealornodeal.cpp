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
    for(int i = 0; i < case_list._maxsize; i++){
        // Check if current case is open
        suitcase* tmp = case_list._case_list[i];
        if(not tmp->is_opened() and not case_list._case_list[i]->is_first_picked()){
            o << tmp->get_number();
            if(i < case_list._maxsize-1){
                o << ", ";
            }
        }
    }
    o << "}" << endl;
    o << "Potential Winnings on the Board: {";
    for(int i = 0; i < case_list._maxsize; i++){
        //Print all of the available values on the board
        double cur_val = case_list._remaining_vals[i];
        if(cur_val != -1){
            o << "$" << fixed << setprecision(2) << cur_val;
            if(i < case_list._maxsize-1){
                o << ", ";
            }
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
    //cout << *s;
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

//double default_case_vals[] = {0.01, 1.0, 5.0, 10.0, 25.0, 50.0, 75.0, 100.0, 200.0, 300.0, 400.0, 500.0 750.0, 1000.0, 5000.0, 10000.0, 25000.0, 50000.0, 75000.0, 100000.0, 200000.0, 300000.0, 400000.0, 500000.0, 750000.0, 1000000.0};
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
//            list_of_suitcases _game_cases;
//        const unsigned int _num_cases;
//        unsigned int _rounds;
//        unsigned int* _cases_per_round;
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
    for(int round = 0; round < _rounds; round++){
        //Print out state at this point
        if(show()){
            cout << _game_cases;
        }
        //Figure out how many cases need to be opened this round
        int cases_in_round = _cases_per_round[round];
        if(show()){
            cout << "Pick " << cases_in_round << " Cases:" << endl;
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
        }
    }
    //Final banker's deal
    //Get the banker's deal
    double bankers_deal = _game_cases.get_banker_deal();
    //Ask deal or no deal (always no deal, so just note it)
    if(show()){
        cout << "Banker's deal: $" << fixed << setprecision(2) << bankers_deal << endl;
            cout << "Deal... or No Deal?\nWe're playing to the end... NO DEAL!" << endl;
    }
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
    
//    6	5	4	3	2	1	1	1	1
#ifdef DEBUG_AUTOMATED //|| DEBUG_INTERACTIVE
    _rounds = 9;
    _cases_per_round = new unsigned int[_rounds];
    int my_rounds[] = {6, 5, 4, 3, 2, 1, 1, 1, 1};
    for(int i = 0; i < _rounds; i++){
        
        _cases_per_round[i] = my_rounds[i];
    }
#elif OTHER_THING   
    //Last round has to be 1 case (to pick between the last one and the chosen one)
    int cases_we_want = _num_cases - 1; //Adjust for the first picked case
    //Sum up the remaining rounds from 1
    int rounds_case_sum = 0;
    int cases_per_round = 1;
    cases_we_want -= 1; //Adjust for the last round which is a 1
    int rounds_before_over = -1;
    for(int rr = 0; rr < _rounds-1; rr++){
        cases_per_round++; //@ start, increase for the current round (2) for the second one
        rounds_case_sum += cases_per_round;
        //If we've crossed the threshold, we need to adjust down
        if(rounds_case_sum > cases_we_want){
            rounds_before_over = rr;
            break;
        }
    }
    // If we're higher than cases_we_want, subtract off the top into end rounds of 1
    if(rounds_case_sum > cases_we_want){
        //We know how many rounds we went before we went over (rounds_before_over)
        //We know how how many cases were added in that round (cases_per_round)
        //We have more rounds left and we need to add rounds of 1 until we
    }
    // If we're lower than cases_we_want, add to the top of the early rounds
    else if (rounds_case_sum < cases_we_want){
        
    }
    else{
        assert(false && "exactly equal, what is this?");
    }
    //Per round: FLOOR((Total cases / remaining rounds) * 2)
    _cases_per_round = new unsigned int[_rounds];
    int round_ind = 0;
    unsigned int remaining_cases = _num_cases;
    for(int i = _rounds; i > 0; i--){
        //The int will chop off the decimals i.e. flooring it
        int current_cases_per_round(remaining_cases/i*2);
        remaining_cases -= current_cases_per_round;
        _cases_per_round[round_ind] = current_cases_per_round;
    }
    if(show()){
        //Print out the cases per round
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
        cout << _game_cases;
        cout << "Your saved case: " << _saved_case_num << endl;
    }
    
    while(!valid_input){
        if(interactive()){
            case_num = _get_user_input("Pick the case you want to take as winnings: ");
        }
        else{
            case_num = randomizer.get_random_number(0, _num_cases);
#ifdef DEBUG_AUTOMATED
//            cout << "Random Final Pick: " << case_num << endl;
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
//    double case_amount = _game_cases.open_case(case_num-1);
//    if(show()){
//        cout << "Opening case #" << case_num << " ($" << case_amount << ")" << endl;
//    }
    return case_num;
}


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

//Two constructors, one for ints and one for string
//Constructor for the ints input case
intmatrix2::intmatrix2(int row, int col, int val):
_rows(row), _cols(col), _arr(nullptr), _is_empty(true){
#ifdef DEBUG_PRINT_STATES
cout << "In the (int) constructor!" << endl;
#endif
//By default, we're initialized into an empty matrix
//Now determine if we a legitimate matrix definition
//Reasons for an Empty Matrix:
//If there are no inputs, row & col will be (defaulted to) 0
//If there's an invalid number for row or col (0 or negative)
if(not (row < 1 || col < 1)){
    //We've got a proper number of rows and cols, so we can fill it!
    _is_empty = false;
    //Keep track of the rows and cols, internally
    _rows = row;
    _cols = col;
    //Fill a matrix with the proper dimensions with the proper "val"
    int num_elements = row * col;
    _arr = new int[num_elements];
    for(int i = 0; i < num_elements; i++){
        _arr[i] = val;
    }
}

}

//Constructor for the string input case
intmatrix2::intmatrix2(const char* arr_str):
_rows(0), _cols(0), _arr(nullptr), _is_empty(true){
#ifdef DEBUG_PRINT_STATES
cout << "In the (char*) constructor!" << endl;
#endif
bool is_valid = _insert_str_vals(arr_str);
if(is_valid){
    _is_empty = false;
}
}

//Destructor
intmatrix2::~intmatrix2(){
#ifdef DEBUG_PRINT_STATES
cout << "In the destructor!" << endl;
#endif
//Run the helper function that'll free allocated heap memory
_release();    
}

//Copy constructor
intmatrix2::intmatrix2(const intmatrix2& mat){
#ifdef DEBUG_PRINT_STATES
cout << "In the copy constructor!" << endl;
#endif
_copy(mat);
}

//Equal operator
intmatrix2& intmatrix2::operator=(const intmatrix2& mat){
#ifdef DEBUG_PRINT_STATES
cout << "In the equal operator!" << endl;
#endif
//Guard against equalling yourself!
if(this != &mat){
    //Release the currently allocated heap stuff
    _release();
    //Now, just a deep copy is needed
    _copy(mat);
}
//"this" is a pointer. To return an object (ref), need to de-reference 
// the pointer (aka the "this" object)
return *this;
}

//Print operator (<<)
ostream& operator<<(ostream& o, const intmatrix2& mat){
#ifdef DEBUG_PRINT_STATES
cout << "In the print (<<) operator!" << endl;
#endif
//cout << "-------- " << str << " -----------" << endl;
if(mat._is_empty){
    //print out empty matrix
    o << "Empty matrix" << endl;
}
else{
    for(int r = 0; r < mat._rows; r++){
        for(int c = 0; c < mat._cols; c++){
            //Print out the 1D array as a 2D array
            o << setw(5) << mat._arr[r*mat._cols + c];
        }
        o << endl;
    }
}
//"o" is the referenced object, so we can directly return it (unlike "this")!
return o;
}

void intmatrix2::_release(){
//The only heap allocated data is our array of values
delete [] _arr;
}

//Copy constructor: just copys the values from the passed in matrix reference
void intmatrix2::_copy(const intmatrix2& orig_mat){
#ifdef DEBUG_PRINT_STATES
cout << "In _copy!" << endl;
#endif
_rows = orig_mat._rows;
_cols = orig_mat._cols;
_is_empty = orig_mat._is_empty;
//Copy the existing arr into a new one
_arr = new int[_rows*_cols];
for(int i = 0; i < _rows*_cols; i++){
    _arr[i] = orig_mat._arr[i];
}
}

bool intmatrix2::isEmpty() const{
return _is_empty;
}

bool intmatrix2::isEqual(const intmatrix2 that) const{
//Dimensions have to be the same
if ((this->_rows == that._rows) && (this->_cols == that._cols)){
    //Now check element by element. The values should be same for the same
    //(row,col) pairs. If even one is off, return false.
    for(int r = 0; r < this->_rows; r++){
        for(int c = 0; c < this->_cols; c++){
            if(this->_arr[r*(this->_cols)+c] != that._arr[r*that._cols+c]){
                return false;
            }
        }
    }
}
else{
    //If dimensions don't match, they necessarily cannot be equal
    return false;
}
//If we've made it this far, the checks have passed and we are equal
return true;
}

intmatrix2 intmatrix2::add(const intmatrix2 that) const{
//What happens if it's just a single number?
//Dimensions have to be the same
if ((this->_rows == that._rows) && (this->_cols == that._cols)){
    intmatrix2 sum_arr(this->_rows, this->_cols);
    for(int r = 0; r < this->_rows; r++){
        for(int c = 0; c < this->_cols; c++){
            int sum_val = this->_arr[this->_rcind(r,c)] + that._arr[that._rcind(r,c)];
            //sum_arr.set_arr_val(r,c, sum_val);
            sum_arr._arr[sum_arr._rcind(r,c)] = sum_val;
        }
    }
    return sum_arr;
}
//If the dimensions do NOT match, we need to return an empty matrix
intmatrix2 sum_arr;    
return sum_arr;
}

intmatrix2 intmatrix2::mult(const intmatrix2 that) const{
//Scalars are an edge case
//this matrix is a single, scalar value
if(this->_rows == 1 && this->_cols ==1){
    //Copy the inputted matrix, and apply the scalar to that
    intmatrix2 prod_arr(that);
    int scalar = this->_arr[0];
    for(int r = 0; r < prod_arr._rows; r++){
        for(int c = 0; c < prod_arr._cols; c++){
            prod_arr._arr[prod_arr._rcind(r,c)] *= scalar;
#ifdef DEBUG_1
            cout << prod_arr << endl;
#endif 
        }
    }
    return prod_arr;
}
//the inputted matrix is a single, scalar value
else if(that._rows == 1 && that._cols ==1){
    //Copy the current matrix, and apply the scalar to that
    intmatrix2 prod_arr(*this);
    int scalar = that._arr[0];
    for(int r = 0; r < prod_arr._rows; r++){
        for(int c = 0; c < prod_arr._cols; c++){
            prod_arr._arr[prod_arr._rcind(r,c)] *= scalar;
#ifdef DEBUG_1
            cout << prod_arr << endl;
#endif 
        }
    }
    return prod_arr;
}

//Do the dimension check
if(this->_cols == that._rows){
    //The dimensions match! Now do the math...
    //The _rows and _cols are set by the _rows of this and the _cols of that
    //Initialize to 0 to start with a clean matrix
    intmatrix2 prod_arr(this->_rows, that._cols, 0);
    //Multiply the corresponding row of THIS by the col of THAT
    //The first row of prod_arr requires the first row of THIS, and so on
    for(int r = 0; r < this->_rows; r++){
        //Get the row of THIS
        int this_row[this->_cols];
        for(int tc = 0; tc < _cols; tc++){
            this_row[tc] = this->_arr[this->_rcind(r,tc)];
        }
        //Now do the math for each col of THAT, by going down rows
        for(int cc = 0; cc < that._cols; cc++){
            int that_col[that._rows];
            for(int rr = 0; rr < that._rows; rr++){
                that_col[rr] = that._arr[that._rcind(rr,cc)];
            }
            //At this point, I have the current row and the current col
            int cur_num = 0;
            for(int ind = 0; ind < that._rows; ind++){
                int this_val = this_row[ind];
                int that_val = that_col[ind];
                int prod = this_val * that_val;
                cur_num += prod;
            }
            prod_arr._arr[prod_arr._rcind(r,cc)] = cur_num;
        }
    }
    return prod_arr;
}
//The dimensions do NOT allow for valid multiplication, so empty arr
intmatrix2 prod_arr;
return prod_arr;
}

//Helper function to convert an (r,c) pair to it's linearized value
//NOTE: must be called for the specific object when used in a function, or else
// "this"'s _rows and _cols will be used, resulting in potentially bad stuff
int intmatrix2::_rcind(int r, int c) const{
return r*_cols + c;
}

//Helper function to convert a numeric char '0'-'9' to it's int value of 0-9
int intmatrix2::_char_to_int(const char* int_str){
return int(*int_str - '0');
}

//A ridiculous function that both parses a matrix string to determine if it's
//valid and also sets up the array if it is for the current object
bool intmatrix2::_insert_str_vals(const char* arr_str){
const char* init_arr_str = arr_str; //shallow copy of beginning of char* arr
int num_rows = 0;
bool first_row = true;
int num_cols = 0;
int cur_col_num = 0;
bool within_number = false;

while(*arr_str){

    //Check what the current character is
    //Is it a space
    if(*arr_str == ' '){
        if(within_number){
            within_number = false;
            cur_col_num++;
            //cur_col_num = 0;
        }
    }
    //Is it a |
    else if (*arr_str == '|'){
        //The first row defines how many numbers are for "cols"
        if(within_number){
            within_number = false;
            cur_col_num++;
        }
        if(first_row){
            first_row = false;
            num_cols = cur_col_num;
        }
        //Every row must have the same number of columns
        if(!(num_cols == cur_col_num)){
            return false;
        }
        cur_col_num = 0;
        num_rows++;
    }
    //Is it a number?
    else if (*arr_str >= '0' && *arr_str <= '9'){
        within_number = true;

    }
    //If it's anything else, not valid
    else{
        return false;
    }
    arr_str++;
}
//Tweak the column count if the last character is a number
if(within_number){
    within_number = false;
    cur_col_num++;
}
//If it's a single row of numbers, make sure we mark that
if(num_rows == 0 && cur_col_num != 0){
    //num_rows++;
    num_cols = cur_col_num;
}
//Need to verify that the last row is also valid
if(!(num_cols == cur_col_num)){
        return false;
}
else{
    num_rows++;
}
//--------------------------------------------------
//At this point, we know the number of cols and rows
//If it's an empty string, the above may pass through without failing
if(num_rows == 0 || num_cols == 0){
    return false;
}
//We will now loop through the string, again, and add values as appropriate
int cur_num = 0;
_arr = new int[num_rows*num_cols];
_rows = num_rows;
_cols = num_cols;
int arr_ind = 0;
arr_str = init_arr_str;
while(*arr_str){
    //Check what the current character is
    //Is it a space
    if(*arr_str == ' '){
        //Space between numbers, so enter the current number into the next spot
        if(within_number){
            within_number = false;
            _arr[arr_ind++] = cur_num;
            cur_num = 0;
        }
    }
    //Is it a |
    else if (*arr_str == '|'){
        //The first row defines how many numbers are for "cols"
        if(within_number){
            within_number = false;
            _arr[arr_ind++] = cur_num;
            cur_num = 0;
        }
    }
    //Is it a number?
    else if (*arr_str >= '0' && *arr_str <= '9'){
        //Double digit number, so shift the current number left by one
        if(within_number){
            cur_num *= 10;
        }
        within_number = true;
        cur_num += _char_to_int(arr_str);

    }
    //If it's anything else, not valid
    else{
        return false;
    }
    arr_str++;
}
//Tweak the column count if the last character is a number
if(within_number){
    within_number = false;
    _arr[arr_ind++] = cur_num;
    cur_num = 0;
}

return true;
}

#endif

#if 0
//OUTPUT GOES HERE:

#endif
