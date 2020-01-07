#include "BinaryNode.h"

#include <iostream>
#include <string>
#include <cstdlib>

#ifndef _Individual_H
#define _Individual_H

//Individual class, which is a base class
class Individual
{
private :
	BinaryNode* Head;
	void deleteBinaryNode();

public:

	//Constructor
	Individual();
	Individual(int);	
	Individual(BinaryNode*);
	Individual(std::string);
	virtual void mutate(int);
	//Destructor
	~Individual();
	

	std::string getString(); //representation of the binarynode list
	BinaryNode* getFirstBit(); //returns a pointer to the first BinaryNode in the list.
	void setFirstBit(BinaryNode*); //The function takes in a pointer to a BinaryNode and update the first BinaryNode in the list

	unsigned int getMaxOnes(); //The function returns the longest consecutive sequence of `1'
	int getLength(); //The function returns the length of the list.
	
	
};

#endif // _Individual_H
