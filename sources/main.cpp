#include "SortedSLList.h" /* Container */
#include "Balloon.h" /* Data type */
#include "Solver.h" /* Solution finding functions */

int main(int argc, char *argv[])
{
	Container sList;
	int index;
	int status;

	index = 0;
	status = 0;

	/* Reading data fron file */
	status = ReadData(&sList, "data.in");
	if (0 != status)
	{
		std::cout << "ReadData failed with status " << status << "\n";
		return (status);
	}

	/* Printing data for easy console checkup */
	index = 0;
	for (auto it = sList.begin(); it != sList.end(); it++)
	{
		Balloon balloon = *it;
		std::cout << "Balloon " << index << ": " << balloon.getXCoordStart() << " " << balloon.getXCoordEnd() << "\n";
		index++;
	}

	/* Call SolveBalloonsProblem to find a sollution */
	status = SolveBalloonsProblem(&sList, "data.out");
	if (0 != status)
	{
		std::cout << "SolveBalloonsProblem failed with status " << status << "\n";
		return (status);
	}
	return (0);
}