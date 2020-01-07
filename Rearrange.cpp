#include "Individual.h"
#include "BinaryNode.h"
#include "Rearrange.h"

Rearrange::Rearrange(){}

Rearrange::Rearrange(int length):Individual(length){}

Rearrange::Rearrange(BinaryNode* newList):Individual(newList){}

Rearrange::Rearrange(std::string code):Individual(code){}

Rearrange::~Rearrange(){}

void Rearrange::mutate(int newk)
{
	int len = getLength();

	if (newk > 1 && len > 1)
	{
		int bNum = newk % len;

		if (bNum == 0)
		{
			bNum = len;
		}

		BinaryNode* cList = getFirstBit();
		BinaryNode* p = NULL;

		for (int i = 0; i <= len-bNum; ++i)
		{
			while (cList->getNext() != NULL)
			{
				p = cList;
				cList = cList->getNext();
			}

			p->setNext(NULL);
			setFirstBit(cList);

		}

	}
}