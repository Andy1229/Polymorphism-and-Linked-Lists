#include "Individual.h"
#include "BinaryNode.h"

//The Individual class only need to know the address of the BinaryNode sitting in the head of the list.

// Constructor and Destructor
Individual::Individual(){}

Individual::Individual(int length)
{
	if (length > 0)
	{
		Head = new BinaryNode();
		BinaryNode* cList = Head;

		for (int i = 1; i < length; ++i)
		{
			BinaryNode* next = new BinaryNode();
			cList -> setNext(next);
			cList = next;
		}
	}
}

Individual::Individual(BinaryNode* newList)
{
	if (newList == NULL)
	{
		Head=NULL;
	}
	else
	{
		BinaryNode* nList = newList;
		Head = new BinaryNode();
		BinaryNode* cList = Head;
		while (nList != NULL)
		{
			cList->setValue(nList->getValue());
			if(nList->getNext()==NULL)
			{
				break;
			}
			nList = nList->getNext();
			cList->setNext(new BinaryNode());
			cList = cList->getNext();
		}
	}

}

Individual::Individual(std::string code)
{
	std::string v = "";
	v += code[0];

	Head = new BinaryNode(atoi(v.c_str()),NULL);

	BinaryNode* cList = Head;

	for (unsigned int i = 1; i < code.size(); ++i)
	{
		std::string svalue="";
		svalue += code[i];
		BinaryNode* next = new BinaryNode(atoi(svalue.c_str()),NULL);
		cList->setNext(next);
		cList = next;
	}
}


Individual::~Individual(){}

void Individual::mutate(int newk){}

std::string Individual::getString()
{
	int len = getLength();
	char s[len+1];

	BinaryNode* cList = Head;
	for (int i = 0; i < len; ++i)
	{
		s[i] = cList->getValue() + '0';
		cList = cList->getNext();
	}
	s[len]='\0';
	return s;
}

BinaryNode* Individual::getFirstBit()
{
	return Head;
}

void Individual::setFirstBit(BinaryNode* newHead)
{
	if(newHead!=NULL)
	{
		newHead->setNext(Head);
		Head = newHead;
	}
}

void Individual::deleteBinaryNode()
{
	BinaryNode* cList = Head;
	BinaryNode* p = NULL;
	while(cList != NULL)
	{
		p = cList;
		cList = cList->getNext();

		delete p;
	}

	Head=NULL;
}



//return longest consecutive sequence of `1'
unsigned int Individual::getMaxOnes()
{
	int max = 0;
	std::string s = getString();
	int counter = 0;

	for (unsigned int i = 0; i < s.size(); ++i)
	{
		if(s[i]=='0')
		{
			if(counter > max)
			{
				max = counter;
			}

			counter = 0;
		}
		else
		{
			counter = counter + 1;
		}
	}

	if (counter > max)
	{
		return counter;
	}
	
	return max;
}

//return length of list
int Individual::getLength()
{
	int len = 0;
	BinaryNode* cList = Head;
	while (cList != NULL)
	{
		len = len + 1;
		cList = cList->getNext();
	}

	return len;
}



