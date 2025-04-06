#ifndef REGIONFUNCTIONS_H
#define REGIONFUNCTIONS_H
#include <vector>
#include "Cell.h"
#include "SimConfig.h"
#include "Commercial.h"
#include "Residential.h"
#include "Industrial.h"
#include "HighSchool.h"
#include "College.h"
#include "SimConfig.h"
using namespace std;

vector<vector<Cell>> ReadInRegion(SimConfig config, vector<vector<Cell>>& region);

void DisplayRegion(const vector<vector<Cell>>& region);

void CheckAdjacenctPowerlines(vector<vector<Cell>>& region);

void CheckAdjacentPop(vector<vector<Cell>>& zone);

void RunCity(SimConfig config, vector<vector<Cell>>& region); 

void AnalyzeRegion(const vector<vector<Cell>>& region, int x1, int x2, int y1, int y2); 

#endif
