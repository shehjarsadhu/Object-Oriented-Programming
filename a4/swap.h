#ifndef _swap_h
#define _swap_h

#include <vector>

/*
Takes a std::vector, and two indices.
Swaps the elements of the vector at those two indices.
*/
template <typename T> void swap(std::vector<T> &v, size_t i, size_t j) {
		T temp = v[i];
		v[i] = v[j];
		v[j] = temp;

}


#endif
