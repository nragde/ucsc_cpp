//#pragma once
#ifndef NINETYNINE_H
#define NINETYNINE_H

// Do the includes
#include "../util/util.h"

// Define the public and private methods for the object
class ninetynine {
	public:
            //enum Ones {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
            enum Ones {zero, one, two, three, four, five, six, seven, eight, nine};
            const char* ones[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
            //const char* tens[] = {"twenty", "thirty", "fourty", "fifty", "sixty", "seventy", "eighty", "ninety"};            
            const char* tens[10] = {"zero", "ten", "twenty", "thirty", "fourty", "fifty", "sixty", "seventy", "eighty", "ninety"};            
            const char* teens[10] = {"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
            const char* bottle_str[2] = {"bottle", "bottles"};
            void sing();
            void sing2();
	private:
            
};

#endif
