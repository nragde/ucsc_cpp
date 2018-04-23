/*------------
Author: Nikhil Ragde
Student #12
Due Date: April 17, 2018
file: ninetynine.cpp
*/

/*----------------------------------------------------------------
All includes here
-----------------------------------------------------------------*/
#include "tommatsumoto.h"

// Value of letters:
float letter_vals[] = {1.0, .01, .02, .03, 2.0, .04, .05, .06, 3.0, .07, .08, .09, .10, .11, 4.0, .12, .13, .14, .15, .16, 5.0, .17, .18, .19, 6.0, .2};
const float DESIRED_COST = 25.0;

void tommatsumoto::find_words(){
  /*  1. NOTE THAT YOU ARE NOT INVENTING ANY ALGORITHM
2. YOU CAN ASSUME  LEGAL ENGLISH WORD < 1024 characters
3. NO MEMORY ALLOCATION OR String is required

Output as a comment, all the word that you found.
Your output must be in this format:

1. microminiaturized
2. unostentatious
Number of words that have a cost of 25$ = 2
Number of words worked on = 109583*/
    
int total_25_words = 0;
int total_words = 0;
    
//Open file
ifstream in("sys_words.txt");

if(!in){
    cout << "Cannot read file" << endl;
    return ;
}
char* word = "aaa";
do{
    //Read word
    in >> word;
    //char*& word = _get_word();
    //char* word = "unostentatious";
    if(!in.eof()){
        cout << "WORD: " << word;
        char* init_word = word;
        //char* word = "joyously";
        //Reset cost
        float word_price = 0;
        //For character in word
        char cur_char = *word;
        while(cur_char){
            //Figure out index

            //Figure out value
            float value = _character_price(cur_char);
                //Add value to current sum
            word_price += value;
            word++;
            cur_char = *word;
        }
        //Check if word's price is $25
        _check_word_price(word_price, total_25_words, init_word);

        //Increment total word count
        total_words++;
    }
    else{
        break;
    }
}while(true);

//Print out total number of $25 words
cout << "Number of words that have a cost of $25 = " << total_25_words << endl;
//Print out total number of words perused
cout << "Number of words worked on = " << total_words << endl;
    
    cout << "TEST" << endl;
}


void tommatsumoto::_check_word_price(float price, int& word_counter, char*& word){
    if(price == DESIRED_COST){
        //It is, so increment count for the $25
        word_counter++;
        //Print word
        cout << word_counter << ". " << word << endl;
    }
    else{
        cout << "NOT $25: " << price << endl;
    }
}

char tommatsumoto::_make_lower(const char cur_char){
    if (cur_char >= 'A' && cur_char <= 'Z'){
        return cur_char - 'A' + 'a';
    }
    // Assume it's lower already
    return cur_char;    
}


float tommatsumoto::_character_price(const char cur_char){
    // Make sure character is the right case (lower). Assumption: is a letter
    char lower_char = _make_lower(cur_char);
    // Adjust the int value, because it'll make indexing easier.
    int char_ind = lower_char - 'a';
    // Grab the value
    float cur_val = letter_vals[char_ind];
    // Return the value
    return cur_val;
}


static void read_file(){
    ifstream in("sys_words.txt");

    if(!in){
        cout << "Cannot read file" << endl;
    }
    else{
        char* word = "aaa";
        do{
            //Read word
            in >> word;
            if(!in.eof()){
                cout << "WORD: " << word;
            }
            else{
                break;
            }
        }while(true);
    }
}


#if 0
// OUTPUT GOES HERE:
#endif