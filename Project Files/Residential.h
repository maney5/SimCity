#ifndef RESIDENTIAL_H
#define RESIDENTIAL_H
#include <vector>
#include "Cell.h"
#include "College.h"
#include "HighSchool.h"
using namespace std;

//boolean function named 'runResidential' that takes a reference to a 2D vector of 'Cell' objects
bool runResidential(vector<vector<Cell>>& region, int& availableWorkers, SimConfig config, int& unEduPop, int& highEduPop, int& collegeEduPop);

#endif
