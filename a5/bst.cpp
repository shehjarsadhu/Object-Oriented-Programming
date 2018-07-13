#include "bst.h"
#include <string>
#include "dna.h"
#include <stdexcept>
#include <iostream>

template <typename T>
BST<T>::BST()
{
	/*
	slightly ugly: because we don't have a parameter of type T,
	we have to call new and dereference the pointer.
	Other constructors should NOT do this.
	*/
	this->content = *(new T);  // ->
	this->left = nullptr;
	this->right = nullptr;

}

template <typename T>
BST<T>::~BST()
{
	// Recursively call delete on left and right subtrees.
	if (this->left != nullptr) delete(this->left);
	if (this->right != nullptr) delete(this->right);
}

/*
FILL IN THE MISSING METHODS!
*/
/*
Vector constructor.
Given a vector<T> and a comparator function,
inserts every element of the vector into a BST.
The comparator is used to determine a "less-than" relationship.
The BST object returned by this constructor is the
root of the binary search tree.
*/
template <typename T>
BST<T>::BST(T content)
{
	this->content = content;  // ->
	this->left = nullptr;
	this->right = nullptr;

}

template <typename T>
BST<T>::BST(std::vector<T> contents, bool comparator(T&, T&))
{
	this->content = contents[0];  // ->
	this->left = nullptr;
	this->right = nullptr;
	//goes throught the size of the content.
	for(unsigned int i = 1;i<contents.size();i++){
		// inserts the content at ith position.
		this->insert(contents[i],comparator);
	}

}
/*
getter for the content field
*/
template <typename T>
T BST<T>::getContent()
{
	return this->content;
}

/*
Performs a binary search on the BST, given a comparator function.
Returns the content of the BST node if a match is found.
Throws a std::runtime_error if no matching item can be found.
This uses a notion of equality based on the "less-than" comparator:
(a == b) if and only if !(a<b) && !(b<a)
*/
template <typename T>
T BST<T>::find(T query, bool comparator(T&, T&))
{
// checks to see if the comparator is less than content if it is then returns it.
	if(comparator(query,this->content))
	{
		// throws a run time error when left node is a nullptr.
		if(this->left == nullptr)
		{
			throw std::runtime_error("Invalid node");
		}
		// calls the fin function recurssively.
		return this->left->find(query,comparator);

	}
	// checks to see if content is less than query
	else if(comparator(this->content,query))
	{
		// throws a run time error when the right node of the tree  is pointing to nothing.
		if(this->right == nullptr){
			throw std::runtime_error("Invalid node");
		}
		return this->right->find(query,comparator);

	}
	// checking if query is equal to c.
	else
	{
		return this->getContent();
	}

}
/*
Inserts element x, of type T, into the BST.
This preserves the BST invariant:
a left child is always less than its parent, while
a right child is always not less than its parent.
This relies on the "less-than" comparator.
*/
template <typename T>
void BST<T>::insert(T x, bool comparator(T&, T&))
{
	bool notAdded = true;
// creating the root node of the binary tree.
	BST *s = this;
	while(notAdded== true)
	{
		// Checks to see if x of type T is less than s ptr to content.
		if(comparator(x,s->content))
		{
			/*check to see if s is a nullptr if it is,only
			 then insert s at the position.*/
			if(s->left == nullptr){
				s->left = new BST<T>(x);
				/* when the node is inserted in the tree we exit
				 out of the loop by setting notAdded to false*/
				notAdded = false;

			}
			s = s->left;
			/*condition to check if x is greater than then insert to the
			right of the binary tree if the node is pointing to a nullptr.
			*/}
		else if(!comparator(x,s->content))
		{
			if(s->right == nullptr)
			{
				// creates a new node on the right side of the binary tree.
				s->right = new BST<T>(x);
				//  setting the counter to false to come out of the loop if the node gets inserted..
				notAdded = false;
			}
			s= s->right;
		}
	}
}
/*
Instantiate this template class for four types.
This is to allow the separation between interface and implementation.
*/
template class BST<int>;
template class BST<double>;
template class BST<std::string>;
template class BST<DNA>;
