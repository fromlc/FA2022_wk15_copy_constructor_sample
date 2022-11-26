//------------------------------------------------------------------------------
// MemoryTracker : class declaration
//      - displays instance memory allocation and deallocation
//      - class data is a single pointer to int
//      - constructor allocates requested bytes,
//      - destructor releases allocated memory
// Author: https://www.tutorialspoint.com/cplusplus/cpp_copy_constructor.htm
// Modified by: Prof. Linda C
//------------------------------------------------------------------------------
#ifndef MEMORYTRACKER_H
#define MEMORYTRACKER_H

#include <iostream>
using std::cout;
using std::ostream;

//------------------------------------------------------------------------------
// MemoryTracker
//------------------------------------------------------------------------------
class MemoryTracker {
private:
    int* pTrackAddress;

    friend ostream& operator<<(ostream& os, MemoryTracker& mt);

public:
    MemoryTracker(int len);                     // normal constructor
    MemoryTracker(const MemoryTracker& mt);     // copy constructor
    ~MemoryTracker();                           // destructor
    int getLength(void);                        // getter for debugging
    MemoryTracker& operator=(const MemoryTracker& m2);
};

//------------------------------------------------------------------------------
// overload stream insertion operator <<
//------------------------------------------------------------------------------
static ostream& operator<<(ostream& os, MemoryTracker& mt) {
    os << "Block Size " << *(mt.pTrackAddress) 
        << " at " << mt.pTrackAddress << '\n';
    return os;
}
#endif  // MEMORYTRACKER_H