#include "Industrial.h"
#include <string>
#include <vector>
#include <iostream>

bool updateIndustrial(vector<vector<Cell>>& region, int& workers){
    int adjacentPowerlines = 0;
	int population = 0;
	int adjacentPopulation = 0;
	bool changed = false;
	int i;
	int j;
	Cell& cellCurrent = region[i][j];
    for(int i = 0; i < region.size(); ++i) {
        for(int j = 0; j < region[i].size(); ++j){	
			 for (int I = -1; I <= 1; ++I) {
				for (int J = -1; J <= 1; ++J) {
				    int Ii = i + I;
				    int Jj = j + J;
				    // Ignore the current cell itself
				    if (Ii == i && Jj == j) {
				    	continue;
					}
					if (Ii >= 0 && Ii < region.size() && Jj >= 0 && Jj < region[Ii].size()) {
					    if (region[Ii][Jj].population >= 1) {
						    region[i][j].adjacentPopulation++;
					    }
					    if (region[Ii][Jj].zoneType == "T") {
						    region[i][j].adjacentPowerlines++;
					    }
				    }
			    }
		    }
    	}
    }
	if(cellCurrent.population == 0 && adjacentPowerlines >= 1 && workers >= 2){
		cellCurrent.population += 1;
        changed = true;
    }
    else if(cellCurrent.population == 0 && adjacentPopulation >= 1 && workers >= 2) {
		cellCurrent.population += 1;
		changed = true;
	}
	else if(cellCurrent.population == 1 && adjacentPopulation >= 2 && workers >= 2) {
        cellCurrent.population += 1;
        changed = true;
    }
	else if(cellCurrent.population == 2 && adjacentPopulation >= 4 && workers >= 2) {
        cellCurrent.population += 1;
        changed = true;
	}

    return changed;
}
