/*------------
Author: Nikhil Ragde
Student #12
Due Date: April 10, 2018
file: reverse.cpp
*/

#include "reverse.h"

unsigned long reverse1::r(unsigned long n) {
	// Algorithm:
	// Get remainder when divided by 10 (current digit)
	// Multiply reversed number by 10 and add current digit
	// Divide the original number by 10 to "eliminate" the current digit
	// Repeat until the "original number" has been divided down to 0

	// The max value of an unsigned long:
	int size_ul = sizeof(unsigned long);
	unsigned long max_ul_val = (unsigned long)(pow(2, sizeof(unsigned long) * 8) - 1);
	// Create long long variables for the modified original number and the reversed number
	unsigned long long reversed = 0;
	unsigned long long remainingn = (unsigned long long)n;
	// Reverse the unsigned long long
	while (remainingn > 0) {
		int cur_digit = remainingn % 10;
		reversed = (reversed * 10) + cur_digit;
		remainingn /= 10;
	}
	// If the reversed number is too large for an unsigned long, return 0
	if (reversed > max_ul_val) {
		return 0;
	}
	return (unsigned long)reversed;
}

unsigned long reverse1::firstFail() {
	// The max value of an unsigned long:
	int size_ul = sizeof(unsigned long);
	unsigned long max_ul_val = (unsigned long)(pow(2, sizeof(unsigned long)*8) - 1);

	// THE LAST GUARANTEED NUMBER TO FIT? Has 9 digits
	unsigned long long find_max = 999999999;
	unsigned long long reversed = 0;
	//unsigned long long max_ull_val = (unsigned long long)(pow(2, sizeof(unsigned long long) * 8) - 1);
	unsigned long first_failure_value = 0;

	for (find_max; find_max < max_ul_val; find_max++) {
		first_failure_value = (unsigned long)find_max;
		reversed = 0;
		unsigned long long remainingn = find_max;
		// Reverse the unsigned long long
		while (remainingn > 0) {
			int cur_digit = remainingn % 10;
			reversed = (reversed * 10) + cur_digit;
			remainingn /= 10;
		}
		if (reversed > max_ul_val) {
			// This is an unsigned long!
			return first_failure_value;
		}
	}
}


#if 0
// OUTPUT OF THE CONSOLE FOR reverse.cpp
n = 0 = 0 Expected = 0
n = 1 = 1 Expected = 1
n = 10 = 1 Expected = 1
n = 9 = 9 Expected = 9
n = 1000 = 1 Expected = 1
n = 4294967294 = 0 Expected = 0
n = 4294967295 = 0 Expected = 0
n = 4294967293 = 3927694924 Expected = 3927694924
n = 176160752 = 257061671 Expected = 257061671
n = 1234567 = 7654321 Expected = 7654321
n = 765432 = 234567 Expected = 234567
The first long number for which reverse fails = 1000000005
All reverse tests passed.You are amazing
Press any key to continue . . .
#endif
