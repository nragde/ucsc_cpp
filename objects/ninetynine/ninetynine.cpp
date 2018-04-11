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

void ninetynine::sing2(){
    int num_bottles = 99;
    int ones_digit = 0;
    int tens_digit = 0;
    int bottle_type = 1;
    int verse = 0;
    while(num_bottles > 0){
        //Do first numbers
        //Do static line and subtract
        //Do third set of numbers
                
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

#if 0
// OUTPUT GOES HERE:
#endif