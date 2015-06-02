/**************************************************************************************************\
| Solver implementations (NOT A CLASS)                                                             |
|**************************************************************************************************|
| Functions:                                                                                       |
|   - ReadData (reads data from a file)							                                   |
|   - SetArrowStatus (see specification for more details)			                               |
|   - SolveBalloonsProblem (see specification for more details)							           |
|**************************************************************************************************|
| Written by Ratiu Razvan - Marian, Group 916, Faculty of Computer Science, English specialization |
\**************************************************************************************************/

#ifndef _SOLVER_H_
# define _SOLVER_H_

#include <iostream>
#include <fstream>
#include <string>
#include "SortedSLList.h" /* Container */
#include "SortedDynamicVector.h" /* Container */
#include "Balloon.h"
#include "ErrorCodes.h"

/*
	Defines for easy change of containers 
	!!! WARNING !!!
		Only modify 'MAINCONTAINER'. Other modifications may result in undefined behaviour
		Switch between:
			Containers::SortedDynamicVector
			Containers::SortedSLList
*/
#define MAINCONTAINER Containers::SortedDynamicVector
#define CONTAINER MAINCONTAINER<Balloon>
#define ARROWCONTAINER MAINCONTAINER<float>

/*
	Read data from file. Row format must be "X_start' 'X_end"
		sList - Container
		filePath - Path to input file
	Return Value: 0 - Success / != 0 - Failure
	PRECOND: sList is not NULL
*/
template <typename Container>
int ReadData(Container *SList, std::string InputFilePath)
{
	std::fstream input(InputFilePath, std::ios::in);
	float xCoordStart;
	float xCoordEnd;

	xCoordStart = 0;
	xCoordEnd = 0;

	if (NULL == SList)
	{
		std::cout << "ReadData - Invalid Parameter (SList)" << "\n";
		return (ERR_STATUS_INVALID_PARAMETER);
	}

	while (input >> xCoordStart >> xCoordEnd)
	{
		if (xCoordStart > xCoordEnd)
		{
			std::cerr << "Invalid set of data in file " << InputFilePath + ".in" << "\n";
			return (ERR_STATUS_INVALID_DATASET);
		}
		Balloon balloon(xCoordStart, xCoordEnd, false);
		SList->add(balloon);
	}
	input.close();
	return (0);
}

/*
	Set balloon arrow status to true for the balloons pierced by arrow
		sList - Container
		arrowCoord - X coordinate for arrow
	PRECOND: sList is not NULL
*/
template <typename Container>
static void SetArrowStatus(Container *SList, float ArrowCoord)
{
	if (NULL == SList)
	{
		std::cout << "SetArrowStatus - Invalid Parameter (SList)" << "\n";
		return;
	}

	for (auto it = SList->begin(); it != SList->end(); it++)
	{
		Balloon balloon = *it;
		if (ArrowCoord >= balloon.getXCoordStart() &&
			ArrowCoord <= balloon.getXCoordEnd())
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
	PRECOND: sList is not NULL
*/
template <typename Container, typename ArrowContainer>
int SolveBalloonsProblem(Container *SList, ArrowContainer *AList, std::string InputFilePath)
{
	std::fstream output(InputFilePath, std::ios::out);
	int arrowCount;

	arrowCount = 0;
	if (NULL == SList)
	{
		std::cerr << "SolveBalloonsProblem - Invalid Parameter (SList)" << "\n";
		return (ERR_STATUS_INVALID_PARAMETER);
	}
	if (NULL == AList)
	{
		std::cerr << "SolveBalloonsProblem - Invalid Parameter (AList)" << "\n";
		return (ERR_STATUS_INVALID_PARAMETER);
	}

	/* Pretty printing in file*/
	output << "----------------------------------------------------------------\n";
	output << "File: " << InputFilePath << ".in\n";
	output << "----------------------------------------------------------------\n";
	for (auto it = SList->begin(); it != SList->end(); it++)
	{
		Balloon balloon = *it;
		if (false == balloon.getArrowStatus())
		{
			output << "Arrow found at coordinate " << balloon.getXCoordEnd() << "\n";
			AList->add(balloon.getXCoordEnd());
			arrowCount++;
			SetArrowStatus(SList, balloon.getXCoordEnd());
		}
	}
	output << "Total number of arrows: " << arrowCount << "\n";
	output.close();
	return 0;
}

#endif //_SOLVER_H_