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
    const char* tens[] = {"zero", "ten", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};            
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
        
        // Write the number
        if(num_bottles < 20){
            //0-10
            cout << ones[num_bottles];
        }
        else {
            // 20+
            // Special case the ones with no written "ones" digit
            if(ones_digit == 0){
                cout << tens[tens_digit];
            }
            else{
                cout << tens[tens_digit] << " " << ones[ones_digit];
            }
        }
        
        //Write out the proper plurality of "bottle"
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
                //ninety eight bottles of beer on the wall,
                //This case is special only because of the double endl's
                cout << " of beer on the wall," << endl << endl;
                break;
            default:
                cout << "\n";
                break;
        }
        //Increment the non-numeric phrase. If we've finished a stanza, reset to 0
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
ninety nine bottles of beer on the wall,
ninety nine bottles of beer,
Take one down, pass it around,
ninety eight bottles of beer on the wall,

ninety eight bottles of beer on the wall,
ninety eight bottles of beer,
Take one down, pass it around,
ninety seven bottles of beer on the wall,

ninety seven bottles of beer on the wall,
ninety seven bottles of beer,
Take one down, pass it around,
ninety six bottles of beer on the wall,

ninety six bottles of beer on the wall,
ninety six bottles of beer,
Take one down, pass it around,
ninety five bottles of beer on the wall,

ninety five bottles of beer on the wall,
ninety five bottles of beer,
Take one down, pass it around,
ninety four bottles of beer on the wall,

ninety four bottles of beer on the wall,
ninety four bottles of beer,
Take one down, pass it around,
ninety three bottles of beer on the wall,

ninety three bottles of beer on the wall,
ninety three bottles of beer,
Take one down, pass it around,
ninety two bottles of beer on the wall,

ninety two bottles of beer on the wall,
ninety two bottles of beer,
Take one down, pass it around,
ninety one bottles of beer on the wall,

ninety one bottles of beer on the wall,
ninety one bottles of beer,
Take one down, pass it around,
ninety bottles of beer on the wall,

ninety bottles of beer on the wall,
ninety bottles of beer,
Take one down, pass it around,
eighty nine bottles of beer on the wall,

eighty nine bottles of beer on the wall,
eighty nine bottles of beer,
Take one down, pass it around,
eighty eight bottles of beer on the wall,

eighty eight bottles of beer on the wall,
eighty eight bottles of beer,
Take one down, pass it around,
eighty seven bottles of beer on the wall,

eighty seven bottles of beer on the wall,
eighty seven bottles of beer,
Take one down, pass it around,
eighty six bottles of beer on the wall,

eighty six bottles of beer on the wall,
eighty six bottles of beer,
Take one down, pass it around,
eighty five bottles of beer on the wall,

eighty five bottles of beer on the wall,
eighty five bottles of beer,
Take one down, pass it around,
eighty four bottles of beer on the wall,

eighty four bottles of beer on the wall,
eighty four bottles of beer,
Take one down, pass it around,
eighty three bottles of beer on the wall,

eighty three bottles of beer on the wall,
eighty three bottles of beer,
Take one down, pass it around,
eighty two bottles of beer on the wall,

eighty two bottles of beer on the wall,
eighty two bottles of beer,
Take one down, pass it around,
eighty one bottles of beer on the wall,

eighty one bottles of beer on the wall,
eighty one bottles of beer,
Take one down, pass it around,
eighty bottles of beer on the wall,

eighty bottles of beer on the wall,
eighty bottles of beer,
Take one down, pass it around,
seventy nine bottles of beer on the wall,

seventy nine bottles of beer on the wall,
seventy nine bottles of beer,
Take one down, pass it around,
seventy eight bottles of beer on the wall,

seventy eight bottles of beer on the wall,
seventy eight bottles of beer,
Take one down, pass it around,
seventy seven bottles of beer on the wall,

seventy seven bottles of beer on the wall,
seventy seven bottles of beer,
Take one down, pass it around,
seventy six bottles of beer on the wall,

seventy six bottles of beer on the wall,
seventy six bottles of beer,
Take one down, pass it around,
seventy five bottles of beer on the wall,

seventy five bottles of beer on the wall,
seventy five bottles of beer,
Take one down, pass it around,
seventy four bottles of beer on the wall,

seventy four bottles of beer on the wall,
seventy four bottles of beer,
Take one down, pass it around,
seventy three bottles of beer on the wall,

seventy three bottles of beer on the wall,
seventy three bottles of beer,
Take one down, pass it around,
seventy two bottles of beer on the wall,

seventy two bottles of beer on the wall,
seventy two bottles of beer,
Take one down, pass it around,
seventy one bottles of beer on the wall,

seventy one bottles of beer on the wall,
seventy one bottles of beer,
Take one down, pass it around,
seventy bottles of beer on the wall,

seventy bottles of beer on the wall,
seventy bottles of beer,
Take one down, pass it around,
sixty nine bottles of beer on the wall,

sixty nine bottles of beer on the wall,
sixty nine bottles of beer,
Take one down, pass it around,
sixty eight bottles of beer on the wall,

sixty eight bottles of beer on the wall,
sixty eight bottles of beer,
Take one down, pass it around,
sixty seven bottles of beer on the wall,

sixty seven bottles of beer on the wall,
sixty seven bottles of beer,
Take one down, pass it around,
sixty six bottles of beer on the wall,

sixty six bottles of beer on the wall,
sixty six bottles of beer,
Take one down, pass it around,
sixty five bottles of beer on the wall,

sixty five bottles of beer on the wall,
sixty five bottles of beer,
Take one down, pass it around,
sixty four bottles of beer on the wall,

sixty four bottles of beer on the wall,
sixty four bottles of beer,
Take one down, pass it around,
sixty three bottles of beer on the wall,

sixty three bottles of beer on the wall,
sixty three bottles of beer,
Take one down, pass it around,
sixty two bottles of beer on the wall,

sixty two bottles of beer on the wall,
sixty two bottles of beer,
Take one down, pass it around,
sixty one bottles of beer on the wall,

sixty one bottles of beer on the wall,
sixty one bottles of beer,
Take one down, pass it around,
sixty bottles of beer on the wall,

sixty bottles of beer on the wall,
sixty bottles of beer,
Take one down, pass it around,
fifty nine bottles of beer on the wall,

fifty nine bottles of beer on the wall,
fifty nine bottles of beer,
Take one down, pass it around,
fifty eight bottles of beer on the wall,

fifty eight bottles of beer on the wall,
fifty eight bottles of beer,
Take one down, pass it around,
fifty seven bottles of beer on the wall,

fifty seven bottles of beer on the wall,
fifty seven bottles of beer,
Take one down, pass it around,
fifty six bottles of beer on the wall,

fifty six bottles of beer on the wall,
fifty six bottles of beer,
Take one down, pass it around,
fifty five bottles of beer on the wall,

fifty five bottles of beer on the wall,
fifty five bottles of beer,
Take one down, pass it around,
fifty four bottles of beer on the wall,

fifty four bottles of beer on the wall,
fifty four bottles of beer,
Take one down, pass it around,
fifty three bottles of beer on the wall,

fifty three bottles of beer on the wall,
fifty three bottles of beer,
Take one down, pass it around,
fifty two bottles of beer on the wall,

fifty two bottles of beer on the wall,
fifty two bottles of beer,
Take one down, pass it around,
fifty one bottles of beer on the wall,

fifty one bottles of beer on the wall,
fifty one bottles of beer,
Take one down, pass it around,
fifty bottles of beer on the wall,

fifty bottles of beer on the wall,
fifty bottles of beer,
Take one down, pass it around,
forty nine bottles of beer on the wall,

forty nine bottles of beer on the wall,
forty nine bottles of beer,
Take one down, pass it around,
forty eight bottles of beer on the wall,

forty eight bottles of beer on the wall,
forty eight bottles of beer,
Take one down, pass it around,
forty seven bottles of beer on the wall,

forty seven bottles of beer on the wall,
forty seven bottles of beer,
Take one down, pass it around,
forty six bottles of beer on the wall,

forty six bottles of beer on the wall,
forty six bottles of beer,
Take one down, pass it around,
forty five bottles of beer on the wall,

forty five bottles of beer on the wall,
forty five bottles of beer,
Take one down, pass it around,
forty four bottles of beer on the wall,

forty four bottles of beer on the wall,
forty four bottles of beer,
Take one down, pass it around,
forty three bottles of beer on the wall,

forty three bottles of beer on the wall,
forty three bottles of beer,
Take one down, pass it around,
forty two bottles of beer on the wall,

forty two bottles of beer on the wall,
forty two bottles of beer,
Take one down, pass it around,
forty one bottles of beer on the wall,

forty one bottles of beer on the wall,
forty one bottles of beer,
Take one down, pass it around,
forty bottles of beer on the wall,

forty bottles of beer on the wall,
forty bottles of beer,
Take one down, pass it around,
thirty nine bottles of beer on the wall,

thirty nine bottles of beer on the wall,
thirty nine bottles of beer,
Take one down, pass it around,
thirty eight bottles of beer on the wall,

thirty eight bottles of beer on the wall,
thirty eight bottles of beer,
Take one down, pass it around,
thirty seven bottles of beer on the wall,

thirty seven bottles of beer on the wall,
thirty seven bottles of beer,
Take one down, pass it around,
thirty six bottles of beer on the wall,

thirty six bottles of beer on the wall,
thirty six bottles of beer,
Take one down, pass it around,
thirty five bottles of beer on the wall,

thirty five bottles of beer on the wall,
thirty five bottles of beer,
Take one down, pass it around,
thirty four bottles of beer on the wall,

thirty four bottles of beer on the wall,
thirty four bottles of beer,
Take one down, pass it around,
thirty three bottles of beer on the wall,

thirty three bottles of beer on the wall,
thirty three bottles of beer,
Take one down, pass it around,
thirty two bottles of beer on the wall,

thirty two bottles of beer on the wall,
thirty two bottles of beer,
Take one down, pass it around,
thirty one bottles of beer on the wall,

thirty one bottles of beer on the wall,
thirty one bottles of beer,
Take one down, pass it around,
thirty bottles of beer on the wall,

thirty bottles of beer on the wall,
thirty bottles of beer,
Take one down, pass it around,
twenty nine bottles of beer on the wall,

twenty nine bottles of beer on the wall,
twenty nine bottles of beer,
Take one down, pass it around,
twenty eight bottles of beer on the wall,

twenty eight bottles of beer on the wall,
twenty eight bottles of beer,
Take one down, pass it around,
twenty seven bottles of beer on the wall,

twenty seven bottles of beer on the wall,
twenty seven bottles of beer,
Take one down, pass it around,
twenty six bottles of beer on the wall,

twenty six bottles of beer on the wall,
twenty six bottles of beer,
Take one down, pass it around,
twenty five bottles of beer on the wall,

twenty five bottles of beer on the wall,
twenty five bottles of beer,
Take one down, pass it around,
twenty four bottles of beer on the wall,

twenty four bottles of beer on the wall,
twenty four bottles of beer,
Take one down, pass it around,
twenty three bottles of beer on the wall,

twenty three bottles of beer on the wall,
twenty three bottles of beer,
Take one down, pass it around,
twenty two bottles of beer on the wall,

twenty two bottles of beer on the wall,
twenty two bottles of beer,
Take one down, pass it around,
twenty one bottles of beer on the wall,

twenty one bottles of beer on the wall,
twenty one bottles of beer,
Take one down, pass it around,
twenty bottles of beer on the wall,

twenty bottles of beer on the wall,
twenty bottles of beer,
Take one down, pass it around,
nineteen bottles of beer on the wall,

nineteen bottles of beer on the wall,
nineteen bottles of beer,
Take one down, pass it around,
eighteen bottles of beer on the wall,

eighteen bottles of beer on the wall,
eighteen bottles of beer,
Take one down, pass it around,
seventeen bottles of beer on the wall,

seventeen bottles of beer on the wall,
seventeen bottles of beer,
Take one down, pass it around,
sixteen bottles of beer on the wall,

sixteen bottles of beer on the wall,
sixteen bottles of beer,
Take one down, pass it around,
fifteen bottles of beer on the wall,

fifteen bottles of beer on the wall,
fifteen bottles of beer,
Take one down, pass it around,
fourteen bottles of beer on the wall,

fourteen bottles of beer on the wall,
fourteen bottles of beer,
Take one down, pass it around,
thirteen bottles of beer on the wall,

thirteen bottles of beer on the wall,
thirteen bottles of beer,
Take one down, pass it around,
twelve bottles of beer on the wall,

twelve bottles of beer on the wall,
twelve bottles of beer,
Take one down, pass it around,
eleven bottles of beer on the wall,

eleven bottles of beer on the wall,
eleven bottles of beer,
Take one down, pass it around,
ten bottles of beer on the wall,

ten bottles of beer on the wall,
ten bottles of beer,
Take one down, pass it around,
nine bottles of beer on the wall,

nine bottles of beer on the wall,
nine bottles of beer,
Take one down, pass it around,
eight bottles of beer on the wall,

eight bottles of beer on the wall,
eight bottles of beer,
Take one down, pass it around,
seven bottles of beer on the wall,

seven bottles of beer on the wall,
seven bottles of beer,
Take one down, pass it around,
six bottles of beer on the wall,

six bottles of beer on the wall,
six bottles of beer,
Take one down, pass it around,
five bottles of beer on the wall,

five bottles of beer on the wall,
five bottles of beer,
Take one down, pass it around,
four bottles of beer on the wall,

four bottles of beer on the wall,
four bottles of beer,
Take one down, pass it around,
three bottles of beer on the wall,

three bottles of beer on the wall,
three bottles of beer,
Take one down, pass it around,
two bottles of beer on the wall,

two bottles of beer on the wall,
two bottles of beer,
Take one down, pass it around,
one bottle of beer on the wall,

one bottle of beer on the wall,
one bottle of beer,
Take one down, pass it around,
zero bottles of beer on the wall
#endif

//EOF
