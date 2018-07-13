#include "bst.h"
#include <iostream>
#include"dna.h"
#include<string>
// defining the less than operator on a int
bool intLT(int &x, int &y) {
	return x < y;
}
// defining a less than operator on a double.
bool doubLT(double &x,double &y){
	return x<y;
}
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
// defining the less than operator in DNA sequences.
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
// defining the lessthan operator on the string.
bool stringsLT(std::string& x, std::string &y){
	return x<y;

}
int main() {
	// creating a vector of int , doubles , strings , DNA sequences.
	std::vector<int> v = {1, 5, 9, 2, 17, 392, 27, 346};
	std::vector<double> c = {1.54, 5.4444, 9.453432, 2.8877, 17.1234, 392.65, 27.555, 346.55};
	std::vector<std::string> q = {"r","t","d","s","q"};
	// calling the DNA constructor to create a vector of DNA sequences.
	std::vector<DNA> d = {DNA(">GATTA", "GGAATT"),DNA(">TTTTTAAA","GGTTTTTT")};
BST<int> b(v, &intLT);
//trying to see if the number is an int and checking to see if it's in the binary tree .
try{
	int z = b.find(1, &intLT);
	std::cout << z << std::endl;
}
//if the number is not in the binary tree then catch then display runtime_error,
catch(std::runtime_error){
	std::cout<<"Run time Error";
}
//trying to see if the number is an double and checking to see if it's in the binary tree.
	BST<double> e(c, &doubLT);
	try{
		double r = e.find(1.54, &doubLT);
		std::cout << r << std::endl;
}
//if the double is not in the binary tree then catch then catch it and display runtime_error,
catch(std::runtime_error){
	std::cout<<"Run time Error";
}

	BST<DNA> s(d, &seqLenLessThan);
//trying to see if the vector of DNA and checking to see if it's in the binary tree .
	try{
		DNA t = s.find(DNA(">GATTTTA", "GGGGAATT"), &seqLenLessThan);
		std::cout << t << std::endl;
}
catch(std::runtime_error){
	std::cout<<"Run time Error";
}
//trying to see if the vector of DNA and checking to see if it's in the binary tree .
	BST<DNA> f(d, &headerLessThan);
	try{
		DNA u = f.find(DNA(">GATTTATTTA", "GATTAAAAAA"), &headerLessThan);
		std::cout << u << std::endl;
	}
	//if the header DNA  is not in the binary tree then catch then catch it and display runtime_error,
	catch(std::runtime_error){
		std::cout<<"Run time Error";
	}

	BST<std::string> g(q, &stringsLT);
//trying to see if it's  string and checking to see if it's in the binary tree .
	try{
		std::string m = g.find("r", &stringsLT);
		std::cout << m << std::endl;
}
//if the string is not in the binary tree then catch then catch it and display runtime_error,
catch(std::runtime_error){
	std::cout<<"Run time Error";
}
	return 0;

}
// Throw an exception for find().
