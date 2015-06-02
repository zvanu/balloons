#include <time.h>
#include "Solver.h" /* Solution finding functions */

/* Comment the following define if you want to disable BlackBox Testing */
#define TEST_ENABLED
#include "..\test\BlackBoxTest.h"

int main(int argc, char *argv[])
{
	int index;
	int status;
	int count;

	index = 0;
	status = 0;
	count = 0;

	StartBlackBoxTest();

	for (int index = 1; index < argc; index++)
	{
		/* Local container inside 'for', must be reset after each loop */
		CONTAINER sList;
		ARROWCONTAINER aList;

		clock_t parsingStartTime = clock(); /* Compute time */
		/* Reading data from file */
		std::string inputFile(argv[index]);
		std::string inputFilePath = ".\\data\\input\\" + inputFile + ".in";
		std::string outputFilePath = ".\\data\\output\\" + inputFile + ".out";
		status = ReadData<CONTAINER>(&sList, inputFilePath);
		/* Error while reading data (will skip file after printing console message and file message) */
		if (0 != status)
		{
			std::cerr << "ReadData failed with status " << status << " on file " << inputFile + ".in" << "\n\n";
			std::fstream errout(outputFilePath, std::ios::out);
			errout << "ReadData failed with status " << status << "\n" << "See ErrorCodes.h for more details\n";
			errout.close();
			continue;
		}

		/* Printing data for easy console checkup */
		std::cout << "----------------------------------------------------------------\n";
		std::cout << "File: " << inputFile << ".in\n";
		std::cout << "----------------------------------------------------------------\n";
		count = 0;
		for (auto it = sList.begin(); it != sList.end(); it++)
		{
			Balloon balloon = *it;
			std::cout << "Balloon " << count << ": " << balloon.getXCoordStart() << " " << balloon.getXCoordEnd() << "\n";
			count++;
		}

		clock_t solveStartTime = clock(); /* Compute time */
		/* Call SolveBalloonsProblem to find a solution */
		status = SolveBalloonsProblem<CONTAINER, ARROWCONTAINER>(&sList, &aList, outputFilePath);
		/* Error while solving data */
		if (0 != status)
		{
			std::cerr << "SolveBalloonsProblem failed with status " << status << "\n";
			std::fstream errout(outputFilePath, std::ios::out);
			errout << "SolveBalloonsProblem failed with status " << status << "\n" << "See ErrorCodes.h for more details\n";
			errout.close();
			continue;
		}
		std::cout << "Solving algorithm finished in: " << double(clock() - solveStartTime) / (double)CLOCKS_PER_SEC << " seconds." << "\n";
		std::cout << "File parsing finished in: " << double(clock() - parsingStartTime) / (double)CLOCKS_PER_SEC << " seconds." << "\n";
		std::cout << "----------------------------------------------------------------\n\n";
	}

	return (0);
}