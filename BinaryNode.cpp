#include "BinaryNode.h"

//Constructors
BinaryNode::BinaryNode()
{
	Value = 0 ;
	nextValue = NULL;
}

BinaryNode::BinaryNode(bool val, BinaryNode* next)
{
	Value = val;
	nextValue = next;
}


//set and get Value and NextValue 
void BinaryNode::setNext(BinaryNode* next)
{
	nextValue=next;
}

BinaryNode* BinaryNode::getNext()
{
	return nextValue;
}

void BinaryNode::setValue(bool val)
{
	Value = val;
}

bool BinaryNode::getValue()
{	
	return Value;
}
