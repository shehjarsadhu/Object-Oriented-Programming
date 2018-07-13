#ifndef _sort_h
#define _sort_h
#include <vector>
#include "dna.h"

/*
Returns true if item1's sequence is shorter than item2's, false otherwise
*/
bool seqLenLessThan(DNA& item1, DNA& item2);

/*
Returns true if item1's header is lexicographically before item2's, false otherwise
*/
bool headerLessThan(DNA& item1, DNA& item2);

/*
Sorts a vector of DNA objects based on a comparator function.
The comparator function takes two DNA objects and returns true if and only if
the first DNA object should be ordered before the second DNA object.
*/
std::vector<DNA> sort(std::vector<DNA>, bool comparator(DNA&, DNA&));

#endif