#include <iostream>
#include "SortedSLList.h"
#include "Balloon.h"
#include "Status.h"
#include "SortedList.h"

int main(int argc, char *argv[])
{
	int index;

	SortedSLList<int> sList = SortedSLList<int>();
	sList.Add(5);
	sList.Add(4);
	sList.Add(2);
	sList.Add(3);
	sList.Add(1);
	sList.Add(6);
	sList.Add(4);
	sList.Add(1);
	sList.Add(6);
	index = 0;
	while (index < sList.Size())
	{
		std::cout << sList.GetAtIndex(index) << " ";
		index++;
	}
	return (0);
}