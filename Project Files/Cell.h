#ifndef CELL_H
#define CELL_H
#include <string>
#include "SimConfig.h"
using namespace std;

class Cell {
public:
    string zoneType = " ";
    int population = 0;
    int availableWorkers = 0;
	int assignedWorkers = 0;
    int adjacentPopulation = 0;
	int adjacentGoods = 0;
	int adjacentPowerlines = 0;
    int unEduPop = 0;
    int highEduPop = 0;
    int collegeEduPop = 0;
    int xCoord = -1;
	int yCoord = -1;
    bool operator==(const Cell& cell) const;
};

#endif