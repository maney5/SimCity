#include "RegionFunctions.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

vector<vector<Cell>> ReadInRegion(SimConfig config, vector<vector<Cell>>& region) {		//takes in config (holding data from config file) and the 2D vector (region)
	ifstream regionFile(config.regionFileName);	//opens the file using ifstream
    
	//checks if the file can open properly. If not, provide the user with an error
    if (!regionFile.is_open()) {
        cout << "Failed to open region file" << endl;
		return region;
    }

	string line;
	Cell cell;
	string cellChar;
	//keep reading in the file until the end of the file
    while (getline(regionFile, line)) {
		vector<Cell> row;	//make a temp row to store data from file
		istringstream lineStream(line);	//obtain a whole line from the file 
		
		//looks for ',' to seperate data
		while(getline(lineStream, cellChar, ',')) { 
			cell.zoneType = cellChar;	//once cell (R = residential, C = commercial, etc), make that cell store the character 
			row.push_back(cell); 	//add the specific cell to the row
		}
		region.push_back(row);	//push the entire row in the 2D vector, region
    }
    regionFile.close();	//closes the file once done
	return region;	//return entire 2D vector, region
}

void DisplayRegion(const vector<vector<Cell>>& region) {	//takes in the 2D vector, region
	//cycles through the entire 2D vector
	for (const auto& row : region) {
        for (const auto& cell : row) {
            if (cell.population > 0) {
				cout << cell.population << " ";	//outputs population if the population is greater than 0
			} else {
				cout << cell.zoneType << " ";	//outputs the character (R,C,I,T, etc) if population is 0
			}
        }
        cout << endl;
    }
	cout << endl;
}

void CheckAdjacenctPowerlines(vector<vector<Cell>>& region) {	//takes in the 2D vector, region
	//cycles through the entire region
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
					//checks if the region is within bounds
					if (Ii >= 0 && Ii < region.size() && Jj >= 0 && Jj < region[Ii].size()) {
						if (region[Ii][Jj].population >= 1) {
							region[i][j].adjacentPopulation++;	//updates adjacentPopulation if any are found around cell
						}

						if (region[Ii][Jj].zoneType == "T") {
							region[i][j].adjacentPowerlines++;	//updates adjacentPowerlines if any are found around cell 
						}
					}
				}
			}
        }
    }
}

void CheckAdjacentPop(vector<vector<Cell>>& region) {
	for (int i = 0; i < region.size(); ++i) {
        for (int j = 0; j < region[i].size(); ++j) 
		{
			region[i][j].adjacentPopulation = 0;
            // Check the population of the current cell
            if(region[i][j].zoneType == "I" || region[i][j].zoneType == "C" || region[i][j].zoneType == "R") {
                // Calculate the number of neighboring cells with population
                for (int I = -1; I <= 1; ++I) {
                    for (int J = -1; J <= 1; ++J) {
                        int Ii = i + I;
                        int Jj = j + J;

                        // Ignore the current cell itself
                        if (Ii == i && Jj == j) {
                            continue;
                        }
                        // Check if the neighbor is within the region bounds
                        if (Ii >= 0 && Ii < region.size() && Jj >= 0 && Jj < region[Ii].size()) {
                            if (region[Ii][Jj].population >= 1) {
                                region[i][j].adjacentPopulation+=region[Ii][Jj].population;
                            }
                        }
                    }
                }
			}
		}
	}
}

//takes in config (holding data from config file) and the 2D region vector
void RunCity(SimConfig config, vector<vector<Cell>>& region) {
	int currentTimeStep = 1;
	bool hasChanged = true;
	int workers = 0;
	int goods = 0;
	int unEduPop = 0;
	int highEduPop = 0;
	int collegeEduPop = 0;
	int sameStateCounter = 0;	//keeps track of if the region stays the same through 2 consec

    CheckAdjacenctPowerlines(region);

	//checks if any changes happened between 2 consecutive time steps or if currentTimeStep is less than the timeLimit set in config file, whichever comes first
	while (hasChanged && currentTimeStep <= config.timeLimit) {
        hasChanged = false;
        
		//run residential cells and check for changes
        bool residentialChange = runResidential(region, workers, config, unEduPop, highEduPop, collegeEduPop);
        hasChanged = hasChanged || residentialChange;
        
        //run industrial cells and check for changes
        //bool industrialChange = updateIndustrial(region, workers);	//COMMENTED OUT SO CODE CAN RUN
        //hasChanged = hasChanged || industrialChange;					//COMMENTED OUT SO CODE CAN RUN
        
        // run commercial cells and check for changes
        bool commercialChange = runCommercial(region, workers, goods);	
        hasChanged = hasChanged || commercialChange;
		
		if (config.collegeExists == false) {
			bool collegeExists = runCollege(region, config);
		}

		if (config.highSchoolExists == false) {
			bool highSchoolExists = runHighSchool(region, config);
		}

		if (sameStateCounter == 0) {
			if (currentTimeStep == config.timeLimit) {
				cout << "	Reached final time step: " << config.timeLimit << endl;
				cout << "	Outputting final state:" << endl;
				DisplayRegion(region);
			} else {
				if (hasChanged == true) {
					// Display the state of the region at each time step depending on refreshRate in config file
					if (currentTimeStep % config.refreshRate == 0) {
						cout << "Time Step: " << currentTimeStep << endl;
						cout << "Available Workers: " << workers << endl;
						cout << "Available Goods: " << goods << endl;
						cout << "UnEduPop:" << unEduPop << endl;
						cout << "HighEduPop:" << highEduPop << endl;
						cout << "CollegeEduPop:" << collegeEduPop << endl;
						DisplayRegion(region);
					}
				} else if (hasChanged == false) {
					sameStateCounter++;
					cout << "Time Step: " << currentTimeStep << endl;
					cout << "Available Workers: " << workers << endl;
					cout << "Available Goods: " << goods << endl;
					cout << "UnEduPop:" << unEduPop << endl;
					cout << "HighEduPop:" << highEduPop << endl;
					cout << "CollegeEduPop:" << collegeEduPop << endl;
					DisplayRegion(region);
				}
			}
		} else if (sameStateCounter == 1) {
			cout << endl;
			cout << "No changed has occurred in 2 consecutive time steps. Displaying final output:" << endl;
			cout << "Time Step: " << currentTimeStep << endl;
			cout << "Available Workers: " << workers << endl;
			cout << "Available Goods: " << goods << endl;
			cout << "UnEduPop:" << unEduPop << endl;
			cout << "HighEduPop:" << highEduPop << endl;
			cout << "CollegeEduPop:" << collegeEduPop << endl;
			DisplayRegion(region);
			cout << "	Ended at time step " << currentTimeStep << endl;
			cout << endl;
			break;
		}

		currentTimeStep++;	//advances currentTimeStep by 1
    }
}

void AnalyzeRegion(const vector<vector<Cell>>& region, int x1, int x2, int y1, int y2) {
	int numRows = region.size();
    int numCols = region[0].size();
    int totalIndustrialPop = 0;
	int totalCommericalPop = 0;
	int totalResidentialPop = 0;
	int totalPop = 0;

	//runs through 2D starting and ending from retangular area specific by user in main.cpp 
    for (int i = y1; i <= y2; ++i) {
        for (int j = x1; j <= x2; ++j) {
            const Cell& cell = region[i][j];
			if(cell.zoneType == "I") {
				totalIndustrialPop += cell.population;	//increases industrialPop if any industrial cells are found
			} else if (cell.zoneType == "C") {
				totalCommericalPop += cell.population;	//increases commercialpop if any industrial cells are found
			} else if (cell.zoneType == "R") {
				totalResidentialPop += cell.population;	//increases residentialPop if any industrial cells are found
			}
        }
    }
	totalPop = totalIndustrialPop + totalCommericalPop + totalResidentialPop;	//adds all populations together 
	cout << endl;

	//displays analysis populations
    cout << "Analysis of Specified Region:" << endl;
	cout << "Total Industrial Population: " << totalIndustrialPop << endl;
	cout << "Total Commercial Population: " << totalCommericalPop << endl;
	cout << "Total Residential Population: " << totalResidentialPop << endl;
    cout << "Total Population: " << totalPop << endl;
}

