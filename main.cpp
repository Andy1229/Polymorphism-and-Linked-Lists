#include "Individual.h"
#include "BinaryNode.h"
#include "Rearrange.h"
#include "BitFlip.h"

#include <iostream>
#include <string>
#include <cstdlib>

int main()
{
	std::string input;

	getline(std::cin,input);
	
	//separate input
	std::string binarystr1;
	std::string k1;
	std::string binarystr2;
	std::string k2;

	int x = 0;
	for (int i = 0; i < input.length(); ++i)
	{
		if (x == 0 && input[i] != ' ')
		{
			binarystr1 = binarystr1 + input[i];
		}
		else if ( x == 1  && input[i] != ' ')
		{
			k1 = k1 + input[i];
		}
		else if (x == 2  && input[i] != ' ')
		{
			binarystr2 = binarystr2 + input[i];
		}
		else if ( x == 3  && input[i] != ' ')
		{
			k2 = k2 + input[i];
		}
		else if (input[i] == ' ')
		{
			x=x+1;
		}
	}
	
	//calling classes and print result
	Individual* BF = new BitFlip(binarystr1);
	BF->mutate(atoi(k1.c_str()));
	std::cout << BF->getString() << " ";

	Individual* Rr = new Rearrange(binarystr2);
	Rr->mutate(atoi(k2.c_str()));
	std::cout << Rr->getString() << " ";

	std::cout << Rr->getMaxOnes() << std::endl;


    return 0;
}