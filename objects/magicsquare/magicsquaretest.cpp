/*----------------------------------------------------------------
Copyright (c) 2018 Author: Nikhil Ragde
file: tommatsumototest.cpp

On linux:
g++ tommatsumoto.cpp tommatsumototest.cpp
valgrind a.out

-----------------------------------------------------------------*/

/*----------------------------------------------------------------
All includes here
-----------------------------------------------------------------*/
#include "magicsquare.h"

/*----------------------------------------------------------------
All includes here
-----------------------------------------------------------------*/
void testbed() {
    magicsquare ms;
	for (int n = 3; n < 150; n += 2) {
		ms.generate_square(n);
	}
}

/*----------------------------------------------------------------
main
-----------------------------------------------------------------*/
int main() {
  testbed() ;
  return 0 ;
}

#if 0
//OUTPUT GOES HERE:
6   1   8   
7   5   3   
2   9   4   
Sides: 3, Magic Sum = 15

15   8    1    24   17   
16   14   7    5    23   
22   20   13   6    4    
3    21   19   12   10   
9    2    25   18   11   
Sides: 5, Magic Sum = 65

28   19   10   1    48   39   30   
29   27   18   9    7    47   38   
37   35   26   17   8    6    46   
45   36   34   25   16   14   5    
4    44   42   33   24   15   13   
12   3    43   41   32   23   21   
20   11   2    49   40   31   22   
Sides: 7, Magic Sum = 175

45   34   23   12   1    80   69   58   47   
46   44   33   22   11   9    79   68   57   
56   54   43   32   21   10   8    78   67   
66   55   53   42   31   20   18   7    77   
76   65   63   52   41   30   19   17   6    
5    75   64   62   51   40   29   27   16   
15   4    74   72   61   50   39   28   26   
25   14   3    73   71   60   49   38   36   
35   24   13   2    81   70   59   48   37   
Sides: 9, Magic Sum = 369

66    53    40    27    14    1     120   107   94    81    68    
67    65    52    39    26    13    11    119   106   93    80    
79    77    64    51    38    25    12    10    118   105   92    
91    78    76    63    50    37    24    22    9     117   104   
103   90    88    75    62    49    36    23    21    8     116   
115   102   89    87    74    61    48    35    33    20    7     
6     114   101   99    86    73    60    47    34    32    19    
18    5     113   100   98    85    72    59    46    44    31    
30    17    4     112   110   97    84    71    58    45    43    
42    29    16    3     111   109   96    83    70    57    55    
54    41    28    15    2     121   108   95    82    69    56    
Sides: 11, Magic Sum = 671

Sides: 13, Magic Sum = 1105

Sides: 15, Magic Sum = 1695

Sides: 17, Magic Sum = 2465

Sides: 19, Magic Sum = 3439

Sides: 21, Magic Sum = 4641

Sides: 23, Magic Sum = 6095

Sides: 25, Magic Sum = 7825

Sides: 27, Magic Sum = 9855

Sides: 29, Magic Sum = 12209

Sides: 31, Magic Sum = 14911

Sides: 33, Magic Sum = 17985

Sides: 35, Magic Sum = 21455

Sides: 37, Magic Sum = 25345

Sides: 39, Magic Sum = 29679

Sides: 41, Magic Sum = 34481

Sides: 43, Magic Sum = 39775

Sides: 45, Magic Sum = 45585

Sides: 47, Magic Sum = 51935

Sides: 49, Magic Sum = 58849

Sides: 51, Magic Sum = 66351

Sides: 53, Magic Sum = 74465

Sides: 55, Magic Sum = 83215

Sides: 57, Magic Sum = 92625

Sides: 59, Magic Sum = 102719

Sides: 61, Magic Sum = 113521

Sides: 63, Magic Sum = 125055

Sides: 65, Magic Sum = 137345

Sides: 67, Magic Sum = 150415

Sides: 69, Magic Sum = 164289

Sides: 71, Magic Sum = 178991

Sides: 73, Magic Sum = 194545

Sides: 75, Magic Sum = 210975

Sides: 77, Magic Sum = 228305

Sides: 79, Magic Sum = 246559

Sides: 81, Magic Sum = 265761

Sides: 83, Magic Sum = 285935

Sides: 85, Magic Sum = 307105

Sides: 87, Magic Sum = 329295

Sides: 89, Magic Sum = 352529

Sides: 91, Magic Sum = 376831

Sides: 93, Magic Sum = 402225

Sides: 95, Magic Sum = 428735

Sides: 97, Magic Sum = 456385

Sides: 99, Magic Sum = 485199
	
#endif

//EOF
