//------------------------------------------------------------------------------
// FA2022_wk15_copy_constructor_sample.cpp
// 
// Copy constructor demo
// 
// Author: https://www.tutorialspoint.com/cplusplus/cpp_copy_constructor.htm
// Modified by: Prof. Linda C
//------------------------------------------------------------------------------
#include <iostream>

#include "MemoryTracker.h"

//------------------------------------------------------------------------------
// using symbols
//------------------------------------------------------------------------------
using std::cout;

//------------------------------------------------------------------------------
// entry point
//------------------------------------------------------------------------------
int main() {

    cout << "declare m1(10): ";
    MemoryTracker m1(10);       // This calls the normal constructor

    cout << "declare m2 = m1: ";
    MemoryTracker m2 = m1;      // This calls the copy constructor

    cout << "display m1: ";
    cout << m1;
    cout << "display m2: ";
    cout << m2;

    cout << "at end of main(): m1 and m2 going out of scope\n";

    return 0;
}

