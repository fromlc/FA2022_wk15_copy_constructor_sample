//------------------------------------------------------------------------------
// MemoryTracker : class definition
//      - displays instance memory allocation and deallocation
//      - class data is a single pointer to int
//      - constructor allocates requested bytes,
//      - destructor releases allocated memory
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
// constructor
//------------------------------------------------------------------------------
MemoryTracker::MemoryTracker(int len) {
    
    // allocate memory block to track
    pTrackAddress = new int[len];

    cout << "Normal constructor allocating " << len
        << " ints at " << pTrackAddress << '\n';

    memset(pTrackAddress, '=', len * sizeof(int));
    *pTrackAddress = len;
}

//------------------------------------------------------------------------------
// copy constructor
//------------------------------------------------------------------------------
MemoryTracker::MemoryTracker(const MemoryTracker& obj) {
    cout << "Copy constructor allocating " << *(obj.pTrackAddress)
        << " ints at ";

    pTrackAddress = new int;
    *pTrackAddress = *obj.pTrackAddress; // copy the value

    cout << pTrackAddress << '\n';

}

//------------------------------------------------------------------------------
// destructor
//------------------------------------------------------------------------------
MemoryTracker::~MemoryTracker(void) {
    cout << "Freeing memory at " << pTrackAddress << '\n';
    delete[] pTrackAddress;
}

//------------------------------------------------------------------------------
// getter for debug access
//------------------------------------------------------------------------------
int MemoryTracker::getLength() {
    return *pTrackAddress;
}
