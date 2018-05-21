/*----------------------------------------------------------------
Copyright (c) 2018 Author: Jagadeesh Vasudevamurthy
file: intmatrix2test.cpp

On linux:
g++ intmatrix2.cpp intmatrix2test.cpp
valgrind a.out

-23174-- REDIR: 0x3e7b87b800 (libc.so.6:free) redirected to 0x4a06acd (free)
==23174== 
==23174== HEAP SUMMARY:
==23174==     in use at exit: 0 bytes in 0 blocks
==23174==   total heap usage: 149 allocs, 149 frees, 75,520 bytes allocated
==23174== 
==23174== All heap blocks were freed -- no leaks are possible
==23174== 
==23174== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 4 from 4)
--23174-- 
--23174-- used_suppression:      4 U1004-ARM-_dl_relocate_object /tools/baton/valgrind/3.12.0/lib/valgrind/default.supp:1413
==23174== 
==23174== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 4 from 4)
[jag@xsjrdevl100 intmatrix2]$ 

-----------------------------------------------------------------*/

/*----------------------------------------------------------------
This file test intmatrix2 object
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
All includes here
-----------------------------------------------------------------*/
#include "dealornodeal.h"

/*----------------------------------------------------------------
test bed
-----------------------------------------------------------------*/
void testbed() {
  //intmatrix2::makeShowOn() ;
    cout << "TEST!" << endl;
}

/*----------------------------------------------------------------
main
-----------------------------------------------------------------*/
int main() {
  testbed();
  return 0;
}

//EOF


