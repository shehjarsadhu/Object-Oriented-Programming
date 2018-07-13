
#include "dna.h"
#include "swap.h"
#include <vector>
bool seqLenLessThan(DNA& item1, DNA& item2) {
/*
Checking to see if the length of the item 1 sequence
is less than the item 2 sequence returns true if it is else returns false
*/

	if (item1.getSequence().length()<item2.getSequence().length())
	{
		return true;
	}
	else
	{
		return false;
	}
}
/*
Funtion of the type bool i.e returns true or false
Checking to see if the length of the item 1 header is less than the item 2 header.
 */
/*
Function checks if the header of item 1 is less than header of item two
lexicographically.

*/
bool headerLessThan(DNA& item1, DNA& item2) {
	if (item1.getHeader()<item2.getHeader())
	{
		return true;
	}
	else
	{
		return false;
	}
}
std::vector<DNA> sort(std::vector<DNA>, bool comparator(DNA, DNA));
/*
Partition function
Takes 4 parameters  a DNA vector a comparator function and 2 ints start and finish.
Returns the index of the pivot
 */
 int partition(std::vector<DNA>& v, bool comparator(DNA&, DNA&), int start, int finish){
	/*
	Creating the pivot of the type DNA
	for the sequence in the DNA class
	*/
	DNA pivot =  v[start];
	int i = start + 1;
	int j = finish;
	// Performing the quick sort.
	while (true) {
		// Loop to compare the pivot and the values in the vector.
		while (i < j && comparator(v[i], pivot)) i++;
		while (i < j && !comparator(v[j], pivot)) j--;

		if (i == j)
		{
			break;
		}
/*
Calling the swap function from swap.h which performs the swap.
Takes 3 parameters a vector of type T and 2 ints.
*/
	swap(v,i,j);
}
	if(!comparator(v[i] , pivot))
	{
		return start;
	}
	v[start] = v[i];
	v[i] = pivot;
	return i;
}
/*
Quick sort function.
Takes 4 parameters a vector of DNA a bool comparator and 2 ints start and finish.
*/
void quicksort(std::vector<DNA>& v, bool comparator(DNA&, DNA&), int start, int finish) {
	if (start >= finish){
		return;
	}
	/* Calling the partition function.
       Giving the partition function a boundry for
	   the start and the end of the vector.
	*/
	int boundary = partition(v , comparator , start, finish);

	quicksort(v,comparator , start , boundary - 1);
	quicksort(v,comparator , boundary + 1 , finish);
}

std::vector<DNA> sort(std::vector<DNA> v, bool comparator(DNA&, DNA&)) {
	std::vector<DNA> vcopy = v;
	quicksort(vcopy, comparator, 0, vcopy.size() - 1);
	return vcopy;
}
