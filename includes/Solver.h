#ifndef _SOLVER_H_
# define _SOLVER_H_

#include <iostream>
#include <fstream>
#include <string>

/* Container #define for easier change */
#define Container SortedSLList<Balloon>

int ReadData(Container *sList, std::string filePath);
int SolveBalloonsProblem(Container *sList, std::string filePath);

#endif //_SOLVER_H_