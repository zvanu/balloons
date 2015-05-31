#include "SortedSLList.h"
#include "Balloon.h"
#include "Solver.h"

/*
	Read data from file. Row format must be "X_start' 'X_end"
	sList - Container
	filePath - Path to input file
	Return Value: 0 - Success / != 0 - Failure
*/
int ReadData(Container *sList, std::string filePath)
{
	std::fstream input(filePath, std::ios::in);
	float xCoordStart;
	float xCoordEnd;

	xCoordStart = 0;
	xCoordEnd = 0;

	if (NULL == sList)
	{
		std::cout << "ReadData -Invalid Parameter (sList)" << "\n";
		return (-1);
	}

	while (input >> xCoordStart >> xCoordEnd)
	{
		Balloon balloon(xCoordStart, xCoordEnd, false);
		sList->add(balloon);
	}
	input.close();
	return (0);
}

/*
	Set balloon arrow status to true for the balloons pierced by arrow
	sList - Container
	arrowCoord - X coordinate for arrow
*/
static void SetArrowStatus(Container *sList, float arrowCoord)
{
	if (NULL == sList)
	{
		std::cout << "SetArrowStatus - Invalid Parameter (sList)" << "\n";
		return;
	}

	for (auto it = sList->begin(); it != sList->end(); it++)
	{
		Balloon balloon = *it;
		if (arrowCoord >= balloon.getXCoordStart() &&
			arrowCoord <= balloon.getXCoordEnd())
		{
			balloon.setArrowStatus(true);
			*it = balloon;
		}
	}
}

/*
	Solve the arrow problem by parsing the list (already sorted by X_end) and piercing first one,
	then setting the status of the other balloons as pierced.
	sList - Container
	filePath - Path to output file
*/
int SolveBalloonsProblem(Container *sList, std::string filePath)
{
	std::fstream output(filePath, std::ios::out);
	int arrowCount;

	arrowCount = 0;

	if (NULL == sList)
	{
		std::cout << "SolveBalloonsProblem - Invalid Parameter (sList)" << "\n";
		return (-1);
	}

	for (auto it = sList->begin(); it != sList->end(); it++)
	{
		Balloon balloon = *it;
		if (false == balloon.getArrowStatus())
		{
			output << "Arrow found at coordinate " << balloon.getXCoordEnd() << "\n";
			arrowCount++;
			SetArrowStatus(sList, balloon.getXCoordEnd());
		}
	}
	output << "Total number of arrows: " << arrowCount << "\n";
	output.close();
	return 0;
}