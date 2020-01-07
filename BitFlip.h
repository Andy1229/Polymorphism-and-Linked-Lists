#include "Individual.h"
#include "BinaryNode.h"

#include <iostream>
#include <string>

//BitFlip class, which is a derive class
class BitFlip: public Individual
{

public:
	
	BitFlip();
	BitFlip(int);
	BitFlip(BinaryNode*);
	BitFlip(std::string);
	~BitFlip();

	virtual void mutate(int);

};

