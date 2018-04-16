/*------------
Author: Nikhil Ragde
Student #12
Due Date: April 17, 2018
file: ninetynine.cpp
*/

/*----------------------------------------------------------------
All includes here
-----------------------------------------------------------------*/
#include "ninetynine.h"

void ninetynine::sing(){
    // Array numbers
    const char* ones[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};    
    const char* tens[] = {"zero", "ten", "twenty", "thirty", "fourty", "fifty", "sixty", "seventy", "eighty", "ninety"};            
    const char* bottle_str[] = {"bottle", "bottles"};
    
    int num_bottles = 99;
    int ones_digit = 0;
    int tens_digit = 0;
    int bottle_type = 1;
    int verse = 0;
    int num_verses = 2;
    
    while (num_bottles > 0){
        // Do some bottle math
        ones_digit = num_bottles % 10; 
        tens_digit = num_bottles / 10;
        bottle_type = (num_bottles != 1) ? 1 : 0;
        
        // Write the number and the proper "bottle"
        if(num_bottles < 20){
            //0-10
            cout << ones[num_bottles];// << " " << bottle_str[bottle_type];
        }
        else {
            // 20+
            // Special case the ones with no written "ones" digit
            if(ones_digit == 0){
                cout << tens[tens_digit];// << " " << bottle_str[bottle_type];
            }
            else{
                cout << tens[tens_digit] << " " << ones[ones_digit];// << " " << bottle_str[bottle_type];
            }
        }
        
        cout << " " << bottle_str[bottle_type];

        // Write out the non-number specfic words
        switch(verse){
            case 0:
                //ninety nine bottles of beer on the wall,
                cout << " of beer on the wall," << endl;
                break;
            case 1:
                //ninety nine bottles of beer,
                //Take one down, pass it around,
                cout << " of beer," << endl << "Take one down, pass it around," << endl;
                // Decrement since we've "taken one down"
                num_bottles--;
                break;
            case 2:
                //This case is special only because of the double endl's
                //ninety eight bottles of beer on the wall,
                cout << " of beer on the wall," << endl << endl;
                break;
            default:
                cout << "\n";
                break;
        }
        verse = (verse >= num_verses) ? 0:(verse+1);
    }
    // Write out the explicit final line, which won't print within the loop
    cout << "zero bottles of beer on the wall";
}

#if 0
// This was the first version of the method above. Note that it's messier to read, but still works. 
// The approach above came after this was tested. This has been kept, for reference, if necessary in the future.
void ninetynine::sing2(){
    //tmp
    const char* ones[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};    
    const char* tens[10] = {"zero", "ten", "twenty", "thirty", "fourty", "fifty", "sixty", "seventy", "eighty", "ninety"};            
    const char* teens[10] = {"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
    const char* bottle_str[2] = {"bottle", "bottles"};
    // This is ugly, but the hardcoded-ness is necessary for this function
    int num_bottles = 99;
    int ones_digit = 0;
    int tens_digit = 0;
    int bottle_type = 1;
    while(num_bottles > 0){
    //for(num_bottles; num_bottles >= 0; num_bottles--){
        ones_digit = num_bottles % 10; 
        tens_digit = num_bottles / 10;
        bottle_type = (num_bottles != 1) ? 1 : 0;
        // Check for special ranges
        // Between 10-19, use the teens[] strings
        if(num_bottles >= 10 && num_bottles <= 19){
            cout << teens[ones_digit] << " " << bottle_str[bottle_type] << " of beer on the wall,\n" << teens[ones_digit] << " " << bottle_str[bottle_type] << " of beer," << endl;
        }
        // If less than then, only write the single digit
        else if (num_bottles < 10){
            cout << ones[ones_digit] << " " << bottle_str[bottle_type] << " of beer on the wall,\n" << ones[ones_digit]<< " " << bottle_str[bottle_type] << " of beer," << endl;
        }
        // For all other numbers, print the tens and the ones digit strings (unless the ones is 0)
        else {
            if(ones_digit == 0){
                cout << tens[tens_digit] << " " << bottle_str[bottle_type] << " of beer on the wall,\n" << tens[tens_digit] << " " << bottle_str[bottle_type] << " of beer," << endl;
            }
            else{
            cout << tens[tens_digit] << " " << ones[ones_digit] << " " << bottle_str[bottle_type] << " of beer on the wall,\n" << tens[tens_digit] << " " << ones[ones_digit]<< " " << bottle_str[bottle_type] << " of beer," << endl;
            }
        }
        // Print out the fixed line
        cout << "Take one down, pass it around," << endl;
        // Decrement
        num_bottles--;
        ones_digit = num_bottles % 10; 
        tens_digit = num_bottles / 10;
        bottle_type = (num_bottles != 1) ? 1 : 0;
        // Check for special ranges
        // Between 10-19, use the teens[] strings
        if(num_bottles >= 10 && num_bottles <= 19){
            //num_str = "Hi"
            cout << teens[ones_digit] << " " << bottle_str[bottle_type] << " of beer on the wall," << endl << endl;
        }        
        // If less than then, only write the single digit
        else if (num_bottles < 10){
            cout << ones[ones_digit] << " " << bottle_str[bottle_type] << " of beer on the wall," << endl << endl;
        }
        // For all other numbers, print the tens and the ones digit strings
        else {
            if(ones_digit == 0){
                cout << tens[tens_digit] << " " << bottle_str[bottle_type] << " of beer on the wall," << endl << endl;
            }
            else{
                cout << tens[tens_digit] << " " << ones[ones_digit] << " " << bottle_str[bottle_type] << " of beer on the wall," << endl << endl;
            }
            }
    }
    //cout << "Fin!" << endl;
}
#endif

#if 0
// OUTPUT GOES HERE:

#endif