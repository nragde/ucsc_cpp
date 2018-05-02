/*----------------------------------------------------------------
Copyright (c) 2018 Author: Nikhil Ragde
file: nqueenstest.cpp

On linux:
g++ nqueens.cpp nqueenstest.cpp
valgrind a.out

-----------------------------------------------------------------*/

/*----------------------------------------------------------------
All includes here
-----------------------------------------------------------------*/
#include "nqueens.h"

/*----------------------------------------------------------------
All includes here
-----------------------------------------------------------------*/
void testbed() {
    nqueens nqObj;
    //Find all solutions for 4x4 and 8x8 boards
    for(int N = 4; N <= 8; N += 4){
        cout << "------------------------------------------------" << endl;
        cout << "SOLUTIONS FOR AN " << N << "x" << N << " BOARD: " << endl;
        cout << "------------------------------------------------" << endl;
        nqObj.generate_boards(N);
        cout << "------------------------------------------------" << endl;
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
------------------------------------------------
SOLUTIONS FOR AN 4x4 BOARD: 
------------------------------------------------
Solution #1 for 4x4 Board:
-1--
---1
1---
--1-
Solution #2 for 4x4 Board:
--1-
1---
---1
-1--
------------------------
Total Solutions for an 4x4 Board: 2
------------------------------------------------
------------------------------------------------
SOLUTIONS FOR AN 8x8 BOARD: 
------------------------------------------------
Solution #1 for 8x8 Board:
1-------
----1---
-------1
-----1--
--1-----
------1-
-1------
---1----
Solution #2 for 8x8 Board:
1-------
-----1--
-------1
--1-----
------1-
---1----
-1------
----1---
Solution #3 for 8x8 Board:
1-------
------1-
---1----
-----1--
-------1
-1------
----1---
--1-----
Solution #4 for 8x8 Board:
1-------
------1-
----1---
-------1
-1------
---1----
-----1--
--1-----
Solution #5 for 8x8 Board:
-1------
---1----
-----1--
-------1
--1-----
1-------
------1-
----1---
Solution #6 for 8x8 Board:
-1------
----1---
------1-
1-------
--1-----
-------1
-----1--
---1----
Solution #7 for 8x8 Board:
-1------
----1---
------1-
---1----
1-------
-------1
-----1--
--1-----
Solution #8 for 8x8 Board:
-1------
-----1--
1-------
------1-
---1----
-------1
--1-----
----1---
Solution #9 for 8x8 Board:
-1------
-----1--
-------1
--1-----
1-------
---1----
------1-
----1---
Solution #10 for 8x8 Board:
-1------
------1-
--1-----
-----1--
-------1
----1---
1-------
---1----
Solution #11 for 8x8 Board:
-1------
------1-
----1---
-------1
1-------
---1----
-----1--
--1-----
Solution #12 for 8x8 Board:
-1------
-------1
-----1--
1-------
--1-----
----1---
------1-
---1----
Solution #13 for 8x8 Board:
--1-----
1-------
------1-
----1---
-------1
-1------
---1----
-----1--
Solution #14 for 8x8 Board:
--1-----
----1---
-1------
-------1
1-------
------1-
---1----
-----1--
Solution #15 for 8x8 Board:
--1-----
----1---
-1------
-------1
-----1--
---1----
------1-
1-------
Solution #16 for 8x8 Board:
--1-----
----1---
------1-
1-------
---1----
-1------
-------1
-----1--
Solution #17 for 8x8 Board:
--1-----
----1---
-------1
---1----
1-------
------1-
-1------
-----1--
Solution #18 for 8x8 Board:
--1-----
-----1--
-1------
----1---
-------1
1-------
------1-
---1----
Solution #19 for 8x8 Board:
--1-----
-----1--
-1------
------1-
1-------
---1----
-------1
----1---
Solution #20 for 8x8 Board:
--1-----
-----1--
-1------
------1-
----1---
1-------
-------1
---1----
Solution #21 for 8x8 Board:
--1-----
-----1--
---1----
1-------
-------1
----1---
------1-
-1------
Solution #22 for 8x8 Board:
--1-----
-----1--
---1----
-1------
-------1
----1---
------1-
1-------
Solution #23 for 8x8 Board:
--1-----
-----1--
-------1
1-------
---1----
------1-
----1---
-1------
Solution #24 for 8x8 Board:
--1-----
-----1--
-------1
1-------
----1---
------1-
-1------
---1----
Solution #25 for 8x8 Board:
--1-----
-----1--
-------1
-1------
---1----
1-------
------1-
----1---
Solution #26 for 8x8 Board:
--1-----
------1-
-1------
-------1
----1---
1-------
---1----
-----1--
Solution #27 for 8x8 Board:
--1-----
------1-
-1------
-------1
-----1--
---1----
1-------
----1---
Solution #28 for 8x8 Board:
--1-----
-------1
---1----
------1-
1-------
-----1--
-1------
----1---
Solution #29 for 8x8 Board:
---1----
1-------
----1---
-------1
-1------
------1-
--1-----
-----1--
Solution #30 for 8x8 Board:
---1----
1-------
----1---
-------1
-----1--
--1-----
------1-
-1------
Solution #31 for 8x8 Board:
---1----
-1------
----1---
-------1
-----1--
1-------
--1-----
------1-
Solution #32 for 8x8 Board:
---1----
-1------
------1-
--1-----
-----1--
-------1
1-------
----1---
Solution #33 for 8x8 Board:
---1----
-1------
------1-
--1-----
-----1--
-------1
----1---
1-------
Solution #34 for 8x8 Board:
---1----
-1------
------1-
----1---
1-------
-------1
-----1--
--1-----
Solution #35 for 8x8 Board:
---1----
-1------
-------1
----1---
------1-
1-------
--1-----
-----1--
Solution #36 for 8x8 Board:
---1----
-1------
-------1
-----1--
1-------
--1-----
----1---
------1-
Solution #37 for 8x8 Board:
---1----
-----1--
1-------
----1---
-1------
-------1
--1-----
------1-
Solution #38 for 8x8 Board:
---1----
-----1--
-------1
-1------
------1-
1-------
--1-----
----1---
Solution #39 for 8x8 Board:
---1----
-----1--
-------1
--1-----
1-------
------1-
----1---
-1------
Solution #40 for 8x8 Board:
---1----
------1-
1-------
-------1
----1---
-1------
-----1--
--1-----
Solution #41 for 8x8 Board:
---1----
------1-
--1-----
-------1
-1------
----1---
1-------
-----1--
Solution #42 for 8x8 Board:
---1----
------1-
----1---
-1------
-----1--
1-------
--1-----
-------1
Solution #43 for 8x8 Board:
---1----
------1-
----1---
--1-----
1-------
-----1--
-------1
-1------
Solution #44 for 8x8 Board:
---1----
-------1
1-------
--1-----
-----1--
-1------
------1-
----1---
Solution #45 for 8x8 Board:
---1----
-------1
1-------
----1---
------1-
-1------
-----1--
--1-----
Solution #46 for 8x8 Board:
---1----
-------1
----1---
--1-----
1-------
------1-
-1------
-----1--
Solution #47 for 8x8 Board:
----1---
1-------
---1----
-----1--
-------1
-1------
------1-
--1-----
Solution #48 for 8x8 Board:
----1---
1-------
-------1
---1----
-1------
------1-
--1-----
-----1--
Solution #49 for 8x8 Board:
----1---
1-------
-------1
-----1--
--1-----
------1-
-1------
---1----
Solution #50 for 8x8 Board:
----1---
-1------
---1----
-----1--
-------1
--1-----
1-------
------1-
Solution #51 for 8x8 Board:
----1---
-1------
---1----
------1-
--1-----
-------1
-----1--
1-------
Solution #52 for 8x8 Board:
----1---
-1------
-----1--
1-------
------1-
---1----
-------1
--1-----
Solution #53 for 8x8 Board:
----1---
-1------
-------1
1-------
---1----
------1-
--1-----
-----1--
Solution #54 for 8x8 Board:
----1---
--1-----
1-------
-----1--
-------1
-1------
---1----
------1-
Solution #55 for 8x8 Board:
----1---
--1-----
1-------
------1-
-1------
-------1
-----1--
---1----
Solution #56 for 8x8 Board:
----1---
--1-----
-------1
---1----
------1-
1-------
-----1--
-1------
Solution #57 for 8x8 Board:
----1---
------1-
1-------
--1-----
-------1
-----1--
---1----
-1------
Solution #58 for 8x8 Board:
----1---
------1-
1-------
---1----
-1------
-------1
-----1--
--1-----
Solution #59 for 8x8 Board:
----1---
------1-
-1------
---1----
-------1
1-------
--1-----
-----1--
Solution #60 for 8x8 Board:
----1---
------1-
-1------
-----1--
--1-----
1-------
---1----
-------1
Solution #61 for 8x8 Board:
----1---
------1-
-1------
-----1--
--1-----
1-------
-------1
---1----
Solution #62 for 8x8 Board:
----1---
------1-
---1----
1-------
--1-----
-------1
-----1--
-1------
Solution #63 for 8x8 Board:
----1---
-------1
---1----
1-------
--1-----
-----1--
-1------
------1-
Solution #64 for 8x8 Board:
----1---
-------1
---1----
1-------
------1-
-1------
-----1--
--1-----
Solution #65 for 8x8 Board:
-----1--
1-------
----1---
-1------
-------1
--1-----
------1-
---1----
Solution #66 for 8x8 Board:
-----1--
-1------
------1-
1-------
--1-----
----1---
-------1
---1----
Solution #67 for 8x8 Board:
-----1--
-1------
------1-
1-------
---1----
-------1
----1---
--1-----
Solution #68 for 8x8 Board:
-----1--
--1-----
1-------
------1-
----1---
-------1
-1------
---1----
Solution #69 for 8x8 Board:
-----1--
--1-----
1-------
-------1
---1----
-1------
------1-
----1---
Solution #70 for 8x8 Board:
-----1--
--1-----
1-------
-------1
----1---
-1------
---1----
------1-
Solution #71 for 8x8 Board:
-----1--
--1-----
----1---
------1-
1-------
---1----
-1------
-------1
Solution #72 for 8x8 Board:
-----1--
--1-----
----1---
-------1
1-------
---1----
-1------
------1-
Solution #73 for 8x8 Board:
-----1--
--1-----
------1-
-1------
---1----
-------1
1-------
----1---
Solution #74 for 8x8 Board:
-----1--
--1-----
------1-
-1------
-------1
----1---
1-------
---1----
Solution #75 for 8x8 Board:
-----1--
--1-----
------1-
---1----
1-------
-------1
-1------
----1---
Solution #76 for 8x8 Board:
-----1--
---1----
1-------
----1---
-------1
-1------
------1-
--1-----
Solution #77 for 8x8 Board:
-----1--
---1----
-1------
-------1
----1---
------1-
1-------
--1-----
Solution #78 for 8x8 Board:
-----1--
---1----
------1-
1-------
--1-----
----1---
-1------
-------1
Solution #79 for 8x8 Board:
-----1--
---1----
------1-
1-------
-------1
-1------
----1---
--1-----
Solution #80 for 8x8 Board:
-----1--
-------1
-1------
---1----
1-------
------1-
----1---
--1-----
Solution #81 for 8x8 Board:
------1-
1-------
--1-----
-------1
-----1--
---1----
-1------
----1---
Solution #82 for 8x8 Board:
------1-
-1------
---1----
1-------
-------1
----1---
--1-----
-----1--
Solution #83 for 8x8 Board:
------1-
-1------
-----1--
--1-----
1-------
---1----
-------1
----1---
Solution #84 for 8x8 Board:
------1-
--1-----
1-------
-----1--
-------1
----1---
-1------
---1----
Solution #85 for 8x8 Board:
------1-
--1-----
-------1
-1------
----1---
1-------
-----1--
---1----
Solution #86 for 8x8 Board:
------1-
---1----
-1------
----1---
-------1
1-------
--1-----
-----1--
Solution #87 for 8x8 Board:
------1-
---1----
-1------
-------1
-----1--
1-------
--1-----
----1---
Solution #88 for 8x8 Board:
------1-
----1---
--1-----
1-------
-----1--
-------1
-1------
---1----
Solution #89 for 8x8 Board:
-------1
-1------
---1----
1-------
------1-
----1---
--1-----
-----1--
Solution #90 for 8x8 Board:
-------1
-1------
----1---
--1-----
1-------
------1-
---1----
-----1--
Solution #91 for 8x8 Board:
-------1
--1-----
1-------
-----1--
-1------
----1---
------1-
---1----
Solution #92 for 8x8 Board:
-------1
---1----
1-------
--1-----
-----1--
-1------
------1-
----1---
------------------------
Total Solutions for an 8x8 Board: 92
------------------------------------------------

#endif

//EOF