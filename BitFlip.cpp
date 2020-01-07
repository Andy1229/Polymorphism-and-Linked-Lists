#include "BitFlip.h"
#include "Individual.h"
#include "BinaryNode.h"

BitFlip::BitFlip(){}

BitFlip::BitFlip(int length):Individual(length){}

BitFlip::BitFlip(BinaryNode* newList):Individual(newList){}

BitFlip::BitFlip(std::string code):Individual(code){}

BitFlip::~BitFlip(){}

void BitFlip::mutate(int newk)
{
	int len = getLength();

	if (newk > 0 && len > 0)
	{
		int bNum = newk % len;

		if (bNum == 0)
		{
			bNum = len;
		}

		BinaryNode* bList = getFirstBit();
		int i = 1;
		while (i < bNum)
		{
			bList = bList->getNext();
			i++;
		}

		bool value = bList->getValue();
		bList->setValue(value?0:1);

	}
}