/*----------------------------------------------------------------
Copyright (c) 2018 Author: Jagadeesh Vasudevamurthy
file: dealornodealtest.cpp

On linux:
g++ dealornodeal.cpp dealornodealtest.cpp
valgrind a.out

-----------------------------------------------------------------*/

/*----------------------------------------------------------------
This file tests dealornodeal object
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
All includes here
-----------------------------------------------------------------*/
#include "iset64.h"


void looped_thing(){
    for(int i = 0; i < 64; ++i){
        cout << i << ", ";
    }
    cout << endl;
}

void basic_sets(){
    cout << "--------------------- BASIC TESTS ---------------------" << endl;
    iset64 set1;
    int x[] = {1, 4, 5};
    iset64 b(x, sizeof(x)/sizeof(int));
    cout << "SET1: " << set1;
    cout << "B: "<< b;
    set1 = b;
    cout << "SET1: " << set1;
    iset64 bb(set1);
    cout << "BB: " << bb;
    cout << "--------------" << endl;
    iset64 c;
    if(c)
    {
        cout << "C is not empty!" << endl;
    }
    else{
        cout << "C is empty :*(" << endl;
    }
    iset64 d;
    if(!d)
    {
        cout << "C is empty!" << endl;
    }
    else{
        cout << "D is not empty :*(" << endl;
    }
    if(b){
        cout << "There's something in B" << endl;
    }
    else{
        cout << "NOTHING IN B" << endl;
    }
    cout << "-------------------------------------------------" << endl;
}

void equals_operators(){
    cout << "------------------- EQUALS --------------------" << endl;
    int x[] = {1, 4, 5};
    int len = sizeof(x)/sizeof(int);
    iset64 a(x, len);
    iset64 aa(a);
    int xs[] = {1, 3, 10};
    int lens = sizeof(xs)/sizeof(int);
    iset64 b(xs, lens);
    cout << "A: " << a;
    cout << "B: " << b;
    a += b;
    cout << "A (+b): " << a;
    a -= aa;
    cout << "A (-aa): " << a;
    cout << "-------------------------------------------------" << endl;
}

void unary_operators(){
    cout << "------------------- UNARY --------------------" << endl;
    int x[] = {1, 4, 5};
    int len = sizeof(x)/sizeof(int);
    iset64 a(x, len);
    int xs[] = {1, 4, 5};
    int lens = sizeof(xs)/sizeof(int);
    iset64 b(xs, lens);
    cout << "A == B : " << (a == b) << endl;
    int xss[] = {1, 3, 10, 4};
    int lenss = sizeof(xss)/sizeof(int);
    iset64 c(xss, lenss);
    cout << "C == B : " << (c == b) << endl;
    iset64 d;
    iset64 e;
    cout << "C == D : " << (c == d) << endl;
    cout << "D == E : " << (d == e) << endl;
    
    
    
    cout << "-------------------------------------------------" << endl;
}

void math_ops(){
    cout << "------------------- MATH --------------------" << endl;
    int x[] = {1, 4, 5};
    int len = sizeof(x)/sizeof(int);
    iset64 a(x, len);
    iset64 aa(a);
    int xs[] = {1, 3, 10, 4};
    int lens = sizeof(xs)/sizeof(int);
    iset64 b(xs, lens);
    cout << "A: " << a;
    cout << "B: " << b;
    iset64 ab = a+b;
    cout << "A+B: " << ab;
    iset64 a2 = a+60;
    cout << "A+60: " << a2;
    iset64 a3 = 26+b;
    cout << "26+A: " << a3;
    cout << "--------------" << endl;
    iset64 abb = a - b;
    cout << "A-B: " << abb;
    iset64 a4 = a - 5;
    cout << "A-5: " << a4;
    iset64 a5 = 5 - a;
    cout << "5-A: " << a5;
    cout << "--------------" << endl;
    iset64 abbb = a * b;
    cout << "A*B: " << abbb;
    iset64 a6 = a * 5;
    cout << "A*5: " << a6;
    iset64 a7 = 5 * a;
    cout << "5*A: " << a7;
    cout << "-------------------------------------------------" << endl;
}

void crements_flip(){
    cout << "------------------- [IN/DE]CREMENTS --------------------" << endl;
    int x[] = {0, 1, 2, 62, 63};
    int len = sizeof(x)/sizeof(int);
    iset64 a(x, len);
//    iset64 aa(a);
    int xs[] = {1, 3, 10, 4};
    int lens = sizeof(xs)/sizeof(int);
    iset64 b(xs, lens);
    cout << "A: " << a;
    cout << "B: " << b;
    iset64 aa = ++a;
    cout << "++A: " << aa;
    cout << "A: " << a;
    iset64 aaa = a++;
    cout << "A++: " << aaa;
    cout << "A: " << a;
    iset64 bb = --b;
    cout << "-------" << endl;
    cout << "B: " << b;
    cout << "--B: " << bb;
    iset64 bbb = b--;
    cout << "B--: " << bbb;
    cout << "B: " << b;
    cout << "BBB: " << bbb;
    cout << "B: " << b;
    iset64 bbbb = ~bbb;
    cout << "~BBB: " << bbbb;
    
}

/*----------------------------------------------------------------
test bed
-----------------------------------------------------------------*/
void testbed() {
//    looped_thing();
    basic_sets();
    unary_operators();
    equals_operators();
    math_ops();
    crements_flip();
}

/*----------------------------------------------------------------
main
-----------------------------------------------------------------*/
int main() {
//    iset64::makeShowOn();
    testbed();
    return 0;
}

//EOF


