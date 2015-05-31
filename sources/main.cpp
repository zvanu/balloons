#include "AbstractSortedList.h"
#include "SortedSLList.h"
#include "Balloon.h"
#include "Solver.h"

int main(int argc, char *argv[])
{
	Container sList;
	int index;
	int status;

	index = 0;
	status = 0;

	status = ReadData(&sList, "data.in");
	if (0 != status)
	{
		std::cout << "ReadData failed with status " << status << "\n";
		return (status);
	}

	index = 0;
	for (auto it = sList.begin(); it != sList.end(); it++)
	{
		Balloon balloon = *it;
		std::cout << "Balloon " << index << ": " << balloon.getXCoordStart() << " " << balloon.getXCoordEnd() << "\n";
		index++;
	}
	status = SolveBalloonsProblem(&sList, "data.out");
	if (0 != status)
	{
		std::cout << "SolveBalloonsProblem failed with status " << status << "\n";
		return (status);
	}
	return (0);
}