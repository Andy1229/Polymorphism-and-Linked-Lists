#include "Individual.h"
#include "BinaryNode.h"

#include <iostream>
#include <string>

//Rearrange class, which is a derive class
class Rearrange: public Individual
{
public:
	
	Rearrange();
	Rearrange(int);
	Rearrange(BinaryNode*);
	Rearrange(std::string);
	~Rearrange();

	virtual void mutate(int);

};
