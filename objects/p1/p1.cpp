/*------------
Author: Nikhil Ragde
Student #12
Due Date: April 10, 2018
file: p1.cpp
*/

#include "p1.h"

// Function definitions
void p1::print_usa() {
	// Print hardcoded spacing
	cout << "XXX   XXX  XXXX X   XXX" << endl;
	cout << " X     X  X    XX     X" << endl;
	cout << " X     X  X     X    X X" << endl;
	cout << " X     X  X          X X" << endl;
	cout << " X     X   XXX      X   X" << endl;
	cout << " X     X      XX    X   X" << endl;
	cout << " X     X        X   XXXXX" << endl;
	cout << " X     X  X     X  X     X" << endl;
	cout << " XX   XX  XX    X  X     X" << endl;
	cout << "   XXX    X XXXX  XXX   XXX" << endl;
}

void p1::print_n_n2_n3() {
	// Print out header row
	cout << "n  n^2  n^3" << endl;
	for (int i = 0; i < 10; i++) {
		// Do the powers, without the pow() function
		int n2 = i * i;
		int n3 = n2 * i;
		//std::setw(number) sets the width of the next thing
		//std::right orients the text to the right of the setw[idth]
		cout << i << setw(5) << right << n2 << setw(5) << right << n3 << endl;
	}
}

void p1::a_power_b() {
	// Print the header row. The widths are fixed such that the table prints out nicely for the last column
	cout << "a" << setw(3) << right << "b" << setw(9) << right << "a^b" << endl;
	for (int a = 1; a < 8; a++) {
		int b = a + 1;
		int a_raised_to_b = a;
                for(int i = 0; i < b; i++){
                    a_raised_to_b *= a;
                }
		cout << a << setw(3) << right << b << setw(9) << right << a_raised_to_b << endl;
	}
}

void p1::two_power_n() {
	// Print the header row. Widths selected so that 2^20 still fits.
	// Aligned right
	cout << setw(2) << left << "n" << setw(10) << right << "2^n" << endl;
	for (int n = 0; n <= 20; n++) {
		//int twototheN = pow(2, n);
		cout << setw(2) << left << n << setw(10) << right << (1<<n) << endl;
	}
}

void p1::a1(int start, int end) {
	// All couts should be oriented to the left
	for (int i = start; i <= end; i++) {
		for (int cur_line_num = start; cur_line_num <= i; cur_line_num++) {
			//cout << setw(2) << left << cur_line_num << " ";
			cout << cur_line_num << " ";
		}
		// Add new line at the end of a row
		cout << endl;
	}
}

void p1::a2(int start, int end) {
	//cout << "test\n";
	int max_line_width = (end-start) * 2+1;
	// Align couts to the right
	// Do this (end-start) times
	for (int i = start; i <= end; i++) {
		int print_num = i;
		int num_nums = i - start;
		// Determine where to print the FIRST number
		int line_width = max_line_width - (num_nums * 2);
		cout << setw(line_width) << right << print_num << " ";
		print_num--;
		// Print the rest of the numbers with just a space in between
		for (print_num; print_num >= start; print_num--) {
			//cout << setw(2) << left << print_num << " ";
			cout << print_num << " ";
		}
		// Start a new line
		cout << endl;
	}
}

void p1::a3(int start, int end) {
	// Choose the "last number printed" as the outer loop variable
	for (int last_num = end; last_num >= start; last_num--) {
		for (int cur_num = start; cur_num <= last_num; cur_num++) {
			cout << cur_num << " ";
		}
		cout << endl;
	}
}

void p1::a4(int start, int end) {
	// Choose the "last number printed" as the outer loop variable
	int max_line_width = (end - start) * 2 + 1;
	for (int last_num = end; last_num >= start; last_num--) {
		// Determine where to print the FIRST number
		int num_nums = last_num - start;
		int line_width = max_line_width - (num_nums * 2);
		int print_num = start;
		cout << setw(line_width) << right << print_num << " ";
		print_num++;
		// Print the rest of the numbers
		for (print_num; print_num <= last_num; print_num++) {
			cout << print_num << " ";
		}
		// Add a new line at the end of the row
		cout << endl;
	}
}

#if 0
// OUTPUT FOR p1.cpp
// NOTE: The formatting looks proper in the Console output.

XXX   XXX  XXXX X   XXX
X     X  X    XX     X
X     X  X     X    X X
X     X  X          X X
X     X   XXX      X   X
X     X      XX    X   X
X     X        X   XXXXX
X     X  X     X  X     X
XX   XX  XX    X  X     X
  XXX    X XXXX  XXX   XXX



n  n ^ 2  n ^ 3
0    0    0
1    1    1
2    4    8
3    9   27
4   16   64
5   25  125
6   36  216
7   49  343
8   64  512
9   81  729



a  b      a^b
1  2        1
2  3        8
3  4       81
4  5     1024
5  6    15625
6  7   279936
7  8  5764801



n        2 ^ n
0          1
1          2
2          4
3          8
4         16
5         32
6         64
7        128
8        256
9        512
10      1024
11      2048
12      4096
13      8192
14     16384
15     32768
16     65536
17    131072
18    262144
19    524288
20   1048576



3
3 4
3 4 5
3 4 5 6
3 4 5 6 7
3 4 5 6 7 8



3
4 3
5 4 3
6 5 4 3
7 6 5 4 3
8 7 6 5 4 3



3 4 5 6 7 8
3 4 5 6 7
3 4 5 6
3 4 5
3 4
3



3 4 5 6 7 8
3 4 5 6 7
3 4 5 6
3 4 5
3 4
3



Press any key to continue . . .
#endif
