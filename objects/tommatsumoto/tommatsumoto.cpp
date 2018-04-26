/*------------
Author: Nikhil Ragde
Student #12
Due Date: April 24, 2018
file: tommatsumoto.cpp
*/

/*----------------------------------------------------------------
All includes here
-----------------------------------------------------------------*/
#include "tommatsumoto.h"

// Value of letters {a, b, c, d, e ... x, y, z}:
const double letter_vals[] = {1.0, .01, .02, .03, 2.0, .04, .05, .06, 3.0, .07, .08, .09, .10, .11, 4.0, .12, .13, .14, .15, .16, 5.0, .17, .18, .19, 6.0, .2};
// Desired cost of the words we're looking for
const double DESIRED_COST = 25.0;


void tommatsumoto::find_words(const char* filename){
/*  1. NOTE THAT YOU ARE NOT INVENTING ANY ALGORITHM
    2. YOU CAN ASSUME  LEGAL ENGLISH WORD < 1024 characters
    3. NO MEMORY ALLOCATION OR String is required

    Output as a comment, all the word that you found.
    Your output must be in this format:

    1. microminiaturized
    2. unostentatious
    Number of words that have a cost of 25$ = 2
    Number of words worked on = 109583*/

    //Counter for the matching words
    int total_25_words = 0;
    //Counter for the total words perused
    int total_words = 0;

    //Open file
    //const char* filename = "C:\\Users\\Nikhil\\Documents\\ucsc_cpp\\objects\\tommatsumoto\\sys_words.txt";
    ifstream in(filename);
    //Unable to open the specified file!!!
    if (!in) {
            cout << "Cannot read file!" << endl;
    }
    //File was opened
    else {
        // Note: this is ugly, but it'll do the job for storing words temporarily. No words are larger than 1024 letters.
        char word[1024];
        do {
            //Read word from file
            in >> word;
            //This isn't the final line, so do what you need with the current word
            if (!in.eof()) {
                //Determine the price of the current word
                double word_price = _calc_word_price(word);

                //Check if word's price is $25
                _check_word_price(word_price, total_25_words, word);

                //Increment total word count
                total_words++;
            }
            else {
                //Once we're done with all the words in the file, break out of the read file loop
                break;
            }
        } while (true);
    }
    //Print out total number of $25 words
    cout << "Number of words that have a cost of $25 = " << total_25_words << endl;
    //Print out total number of words perused
    cout << "Number of words worked on = " << total_words << endl;
}


void tommatsumoto::_check_word_price(double price, int& word_counter, const char* word){
    if(price == DESIRED_COST){
        //It is, so increment count for the $25
        word_counter++;
        //Print word
        cout << word_counter << ". " << word << endl;
    }
}


char tommatsumoto::_make_lower(const char cur_char){
    if (cur_char >= 'A' && cur_char <= 'Z'){
        return cur_char - 'A' + 'a';
    }
    // Assume it's lower already
    return cur_char;    
}


double tommatsumoto::_character_price(const char cur_char){
    // Make sure character is the right case (lower). Assumption: is a letter
    char lower_char = _make_lower(cur_char);
    // Adjust the int value, because it'll make indexing easier.
    int char_ind = lower_char - 'a';
    // Grab the value
    double cur_val = letter_vals[char_ind];
    // Return the value
    return cur_val;
}


double tommatsumoto::_calc_word_price(char* word){
    // Iterate through the characters
    double word_price = 0;
    for (char* cur_char = word; *cur_char; ++cur_char){
            //Figure out value
            double value = _character_price(*cur_char);
            //Add value to current sum
            word_price += value;
    }
    return word_price;
}

#if 0
//Test function
 void tommatsumoto::read_file(){
    //ifstream in("c:\\Users\\Nikhil\\Desktop\\wrds.txt");
    ifstream in("C:\\Users\\Nikhil\\Documents\\ucsc_cpp\\objects\\tommatsumoto\\sys_words.txt");
    //ifstream in(file_loc);
    if(!in){
        cout << "Cannot read file" << endl;
    }
    else{
	char word[1024];
        do{
            //char* word;
            //Read word
            in >> word;
            if(!in.eof()){
                cout << "WORD: " << word << endl;
            }
            else{
                in >> word;
                break;
            }
        }while(true);
    }
}
#endif

#if 0
// OUTPUT GOES HERE:
1. electromotivity
2. gynandrosporous
3. ornithocoprolite
4. paleophytologist
5. pterygospinous
6. siphonostomous
7. unostentatious
Number of words that have a cost of $25 = 7
Number of words worked on = 235886

1. bacteriochlorophyll
2. unostentatious
Number of words that have a cost of $25 = 2
Number of words worked on = 67598

1. antiproductively
2. bacteriochlorophyll
3. cryptanalytically
4. electromotivity
5. gynandrosporous
6. microminiaturized
7. nonincriminatory
8. nonlustrously
9. oligomerizations
10. ornithocoprolite
11. paleophytologist
12. pseudoallegoristic
13. pterygospinous
14. quasistationary
15. siphonostomous
16. supersexuality
17. unostentatious
Number of words that have a cost of $25 = 17
Number of words worked on = 515802

1. antiproductively
2. bacteriochlorophyll
3. cryptanalytically
4. electromotivity
5. gynandrosporous
6. microminiaturized
7. nonincriminatory
8. nonlustrously
9. ornithocoprolite
10. paleophytologist
11. pseudoallegoristic
12. pterygospinous
13. quasistationary
14. siphonostomous
15. unostentatious
Number of words that have a cost of $25 = 15
Number of words worked on = 370099

#endif