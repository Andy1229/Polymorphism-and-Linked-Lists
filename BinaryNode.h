#include <iostream>

#ifndef _BinaryNode_H
#define _BinaryNode_H

//BinaryNode class, which are a base class
class BinaryNode
{
private:

	bool Value;
	BinaryNode* nextValue;	

public:
	
	//Constructors
	BinaryNode();
	BinaryNode(bool,BinaryNode*);
	
	//set and get next value
	void setNext(BinaryNode*);
	BinaryNode* getNext();
	

	//set and get next value
	void setValue(bool);
	bool getValue();
	

};

#endif // _BinaryNode_H

