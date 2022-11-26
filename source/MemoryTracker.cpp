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
//      - called on assignment operation: m2 = m1 where m2 does not yet exist
//      - m1 is the existing instance
//      - "this" is m2, the new instance
//------------------------------------------------------------------------------
MemoryTracker::MemoryTracker(const MemoryTracker& m1) {
    // get block length to allocate
    int len = *(m1.pTrackAddress);

    cout << "Copy constructor allocating " << len << " ints at ";

    // allocate memory for m2
    pTrackAddress = new int[len];

    // copy block length and data from this instance
    memcpy(pTrackAddress, m1.pTrackAddress, len * sizeof(int));

    // display the address of allocated memory
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

//------------------------------------------------------------------------------
// overload assignment operator =
//      called on m1 = m2 assignment where m1 already exists
//------------------------------------------------------------------------------
MemoryTracker& MemoryTracker::operator=(const MemoryTracker& m2) {
    if (this != &m2) {
        delete[] pTrackAddress;

        pTrackAddress = m2.pTrackAddress;
    }
    return *this;
}
