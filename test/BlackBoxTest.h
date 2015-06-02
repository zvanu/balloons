/**************************************************************************************************\
| BlackBoxTest implementation                                                                      |
|**************************************************************************************************|
| Main methods:                                                                                    |
|   - testSet0                                                                                     |
|   - testSet1                                                                                     |
|   - testSet2                                                                                     |
| Extra functions defined:                                                                         |
|   - StartBlackBoxTest                                                                            |
|**************************************************************************************************|
| General rules used:                                                                              |
|   - All parameter variables start with capital letter (e.g 'Node').                              |
|   - Private or Protected variables have an underscore suffix.                                    |
|   - Some Operators, Constructors, Destructors, Setters or Getters are not specified              |
|   as the code itself is easy to understand.                                                      |
|**************************************************************************************************|
| Written by Ratiu Razvan - Marian, Group 916, Faculty of Computer Science, English specialization |
\**************************************************************************************************/

#ifdef TEST_ENABLED

#ifndef _BLACKBOXTEST_H_
# define _BLACKBOXTEST_H_

# include "SortedSLList.h"
# include "SortedDynamicVector.h"
# include <assert.h>

class BlackBoxTest
{
public:
	BlackBoxTest();
	~BlackBoxTest();

	void testSet0();
	void testSet1();
	void testSet2();
};

BlackBoxTest::BlackBoxTest()
{
	std::cout << "----------------------------------------------------------------\n";
	std::cout << "Starting Black Box Test phase\n";
	std::cout << "----------------------------------------------------------------\n";
	this->testSet0();
	this->testSet1();
	this->testSet2();
	std::cout << "Black Box Test phase completed with success!!!\n";
	std::cout << "----------------------------------------------------------------\n\n";
}

BlackBoxTest::~BlackBoxTest()
{
	;
}

void BlackBoxTest::testSet0()
{
	CONTAINER sList;
	ARROWCONTAINER aList;
	int status;

	/* Reading data from file */
	std::string inputFile = "testdata0";
	std::string inputFilePath = ".\\data\\test\\input\\" + inputFile + ".in";
	std::string outputFilePath = ".\\data\\test\\output\\" + inputFile + ".out";
	std::cout << "Testing file: " << inputFile << "\n";
	status = ReadData<CONTAINER>(&sList, inputFilePath);
	/* Error while reading data (will skip file after printing console message and file message) */
	if (0 != status)
	{
		std::cerr << "ReadData failed with status " << status << " on file " << inputFile + ".in" << "\n\n";
		std::fstream errout(outputFilePath, std::ios::out);
		errout << "ReadData failed with status " << status << "\n" << "See ErrorCodes.h for more details\n";
		errout.close();
		return;
	}

	/* Call SolveBalloonsProblem to find a solution */
	status = SolveBalloonsProblem<CONTAINER, ARROWCONTAINER>(&sList, &aList, outputFilePath);
	/* Error while solving data */
	if (0 != status)
	{
		std::cerr << "SolveBalloonsProblem failed with status " << status << "\n";
		std::fstream errout(outputFilePath, std::ios::out);
		errout << "SolveBalloonsProblem failed with status " << status << "\n" << "See ErrorCodes.h for more details\n";
		errout.close();
	}
	assert(aList.getAtIndex(0) == (float)(2.3));
	assert(aList.getAtIndex(1) == (float)(4.5));
	assert(aList.getAtIndex(2) == (float)(5.2));
	assert(aList.size() == 3);
}

void BlackBoxTest::testSet1()
{
	CONTAINER sList;
	ARROWCONTAINER aList;
	int status;

	/* Reading data from file */
	std::string inputFile = "testdata1";
	std::string inputFilePath = ".\\data\\test\\input\\" + inputFile + ".in";
	std::string outputFilePath = ".\\data\\test\\output\\" + inputFile + ".out";
	std::cout << "Testing file: " << inputFile << "\n";
	status = ReadData<CONTAINER>(&sList, inputFilePath);
	/* Error while reading data (will skip file after printing console message and file message) */
	if (0 != status)
	{
		std::cerr << "ReadData failed with status " << status << " on file " << inputFile + ".in" << "\n\n";
		std::fstream errout(outputFilePath, std::ios::out);
		errout << "ReadData failed with status " << status << "\n" << "See ErrorCodes.h for more details\n";
		errout.close();
		return;
	}

	/* Call SolveBalloonsProblem to find a solution */
	status = SolveBalloonsProblem<CONTAINER, ARROWCONTAINER>(&sList, &aList, outputFilePath);
	/* Error while solving data */
	if (0 != status)
	{
		std::cerr << "SolveBalloonsProblem failed with status " << status << "\n";
		std::fstream errout(outputFilePath, std::ios::out);
		errout << "SolveBalloonsProblem failed with status " << status << "\n" << "See ErrorCodes.h for more details\n";
		errout.close();
	}
	assert(aList.getAtIndex(0) == (float)(1.5));
	assert(aList.getAtIndex(1) == (float)(2.2));
	assert(aList.getAtIndex(2) == (float)(4.5));
	assert(aList.size() == 3);
}

void BlackBoxTest::testSet2()
{
	CONTAINER sList;
	ARROWCONTAINER aList;
	int status;

	/* Reading data from file */
	std::string inputFile = "testdata2";
	std::string inputFilePath = ".\\data\\test\\input\\" + inputFile + ".in";
	std::string outputFilePath = ".\\data\\test\\output\\" + inputFile + ".out";
	std::cout << "Testing file: " << inputFile << "\n";
	status = ReadData<CONTAINER>(&sList, inputFilePath);
	/* Error while reading data (will skip file after printing console message and file message) */
	if (0 != status)
	{
		std::cerr << "ReadData failed with status " << status << " on file " << inputFile + ".in" << "\n\n";
		std::fstream errout(outputFilePath, std::ios::out);
		errout << "ReadData failed with status " << status << "\n" << "See ErrorCodes.h for more details\n";
		errout.close();
		return;
	}

	/* Call SolveBalloonsProblem to find a solution */
	status = SolveBalloonsProblem<CONTAINER, ARROWCONTAINER>(&sList, &aList, outputFilePath);
	/* Error while solving data */
	if (0 != status)
	{
		std::cerr << "SolveBalloonsProblem failed with status " << status << "\n";
		std::fstream errout(outputFilePath, std::ios::out);
		errout << "SolveBalloonsProblem failed with status " << status << "\n" << "See ErrorCodes.h for more details\n";
		errout.close();
	}
	assert(aList.getAtIndex(0) == (float)(1.5));
	assert(aList.getAtIndex(1) == (float)(3.2));
	assert(aList.getAtIndex(2) == (float)(4.2));
	assert(aList.getAtIndex(3) == (float)(7.2));
	assert(aList.getAtIndex(4) == (float)(9.2));
	assert(aList.size() == 5);
}

void StartBlackBoxTest()
{
	BlackBoxTest();
}

#endif //_BLACKBOXTEST_H_

#else

void StartBlackBoxTest()
{
	;
}

#endif //TEST_ENABLED