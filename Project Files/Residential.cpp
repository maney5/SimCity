#include "Residential.h"
#include <iostream>
#include <vector>
using namespace std;

//boolean function that takes a reference to a 2D vector of 'Cell' objects
bool runResidential(vector<vector<Cell>>& region, int& availableWorkers, SimConfig config, int& unEduPop, int& highEduPop, int& collegeEduPop){
	//declares variables
	int adjacentPowerlines = 0;
	int population = 0;
	int adjacentPopulation = 0;
	bool changed = false;
	int i;
	int j;
		//nested for loops used to iterate over the rows and columns of the 'region' grid
    	for(int i = 0; i < region.size(); ++i) {
				if (changed) { continue; }
        	for(int j = 0; j < region[i].size(); ++j){	
				if (changed) { continue; }
				//nested for loops, calculates the indices of neighboring cells
				if (region[i][j].zoneType == "R") {
					adjacentPowerlines = 0;
					adjacentPopulation = 0;

					for (int I = -1; I <= 1; ++I) {
						for (int J = -1; J <= 1; ++J) {
							int Ii = i + I;
							int Jj = j + J;

                    
							if (Ii == i && Jj == j) {
								continue;
							}

							// Checking if neightbor is within range
							if (Ii >= 0 && Ii < region.size() && Jj >= 0 && Jj < region[Ii].size() ) {
								if (region[Ii][Jj].population >= 1) {
									++adjacentPopulation;
								}

								if (region[Ii][Jj].zoneType == "T") {
									++adjacentPowerlines;
								}
							}
						}
					}
					// Apply the rules based on the current cell's population and adjacent counts
					if (region[i][j].population == 0 && adjacentPowerlines >= 1) {
						if (config.collegeExists == true) {
							int popGradCollege = static_cast<int>(region[i][j].highEduPop * config.percentGradCollege);		//find number of ppl that graduate college
							region[i][j].collegeEduPop += popGradCollege; collegeEduPop += popGradCollege;	//add that amount to current amount of ppl with college level of education
							region[i][j].highEduPop -= popGradCollege; highEduPop -= popGradCollege;	//subtract that amount from high school level pop
						}
						if (config.highSchoolExists == true) {
							int popGradHigh = static_cast<int>(region[i][j].unEduPop * config.percentGradHigh);		//find number of ppl that graduate college
							region[i][j].highEduPop += popGradHigh; highEduPop += popGradHigh;	//add that amount to current amount of ppl with college level of education
							region[i][j].unEduPop -= popGradHigh; unEduPop -= popGradHigh;	//subtract that amount from high school level pop
						}
						region[i][j].population += 1;
						region[i][j].unEduPop += 1;
						unEduPop++;
						availableWorkers++;
						changed = true;     //Apply changes for case 1
					} else if (region[i][j].population == 0 && adjacentPopulation >= 1) {
						if (config.collegeExists == true) {
							int popGradCollege = static_cast<int>(region[i][j].highEduPop * config.percentGradCollege);		//find number of ppl that graduate college
							region[i][j].collegeEduPop += popGradCollege; collegeEduPop += popGradCollege;	//add that amount to current amount of ppl with college level of education
							region[i][j].highEduPop -= popGradCollege; highEduPop -= popGradCollege;	//subtract that amount from high school level pop
						}
						if (config.highSchoolExists == true) {
							int popGradHigh = static_cast<int>(region[i][j].unEduPop * config.percentGradHigh);		//find number of ppl that graduate college
							region[i][j].highEduPop += popGradHigh; highEduPop += popGradHigh;	//add that amount to current amount of ppl with college level of education
							region[i][j].unEduPop -= popGradHigh; unEduPop -= popGradHigh;	//subtract that amount from high school level pop
						}
						region[i][j].population += 1;
						region[i][j].unEduPop += 1;
						unEduPop++;
						availableWorkers++;
						changed = true;     //Apply changes for case 2
					} else if (region[i][j].population == 1 && adjacentPopulation >= 2) {
						if (config.collegeExists == true) {
							int popGradCollege = static_cast<int>(region[i][j].highEduPop * config.percentGradCollege);		//find number of ppl that graduate college
							region[i][j].collegeEduPop += popGradCollege; collegeEduPop += popGradCollege;	//add that amount to current amount of ppl with college level of education
							region[i][j].highEduPop -= popGradCollege; highEduPop -= popGradCollege;	//subtract that amount from high school level pop
						}
						if (config.highSchoolExists == true) {
							int popGradHigh = static_cast<int>(region[i][j].unEduPop * config.percentGradHigh);		//find number of ppl that graduate college
							region[i][j].highEduPop += popGradHigh; highEduPop += popGradHigh;	//add that amount to current amount of ppl with college level of education
							region[i][j].unEduPop -= popGradHigh; unEduPop -= popGradHigh;	//subtract that amount from high school level pop
						}
						region[i][j].population += 1;
						region[i][j].unEduPop += 1;
						unEduPop++;
						availableWorkers++;
						changed = true;     //Apply chanes for case 3
					} else if (region[i][j].population == 2 && adjacentPopulation >= 8) {
						if (config.collegeExists == true) {
							int popGradCollege = static_cast<int>(region[i][j].highEduPop * config.percentGradCollege);		//find number of ppl that graduate college
							region[i][j].collegeEduPop += popGradCollege; collegeEduPop += popGradCollege;	//add that amount to current amount of ppl with college level of education
							region[i][j].highEduPop -= popGradCollege; highEduPop -= popGradCollege;	//subtract that amount from high school level pop
						}
						if (config.highSchoolExists == true) {
							int popGradHigh = static_cast<int>(region[i][j].unEduPop * config.percentGradHigh);		//find number of ppl that graduate college
							region[i][j].highEduPop += popGradHigh; highEduPop += popGradHigh;	//add that amount to current amount of ppl with college level of education
							region[i][j].unEduPop -= popGradHigh; unEduPop -= popGradHigh;	//subtract that amount from high school level pop
						}
						region[i][j].population += 1;
						region[i][j].unEduPop += 1;
						unEduPop++;
						availableWorkers++;
						changed = true;     //Apply chanes for case 4
					} else if (region[i][j].population == 3 && adjacentPopulation >= 18) {
						if (config.collegeExists == true) {
							int popGradCollege = static_cast<int>(region[i][j].highEduPop * config.percentGradCollege);		//find number of ppl that graduate college
							region[i][j].collegeEduPop += popGradCollege; collegeEduPop += popGradCollege;	//add that amount to current amount of ppl with college level of education
							region[i][j].highEduPop -= popGradCollege; highEduPop -= popGradCollege;	//subtract that amount from high school level pop
						}
						if (config.highSchoolExists == true) {
							int popGradHigh = static_cast<int>(region[i][j].unEduPop * config.percentGradHigh);		//find number of ppl that graduate college
							region[i][j].highEduPop += popGradHigh; highEduPop += popGradHigh;	//add that amount to current amount of ppl with college level of education
							region[i][j].unEduPop -= popGradHigh; unEduPop -= popGradHigh;	//subtract that amount from high school level pop
						}
						region[i][j].population += 1;
						region[i][j].unEduPop += 1;
						unEduPop++;
						availableWorkers++;
						changed = true;     //Apply chanes for case 5
					} else if (region[i][j].population == 4 && adjacentPopulation >= 32) {
						if (config.collegeExists == true) {
							int popGradCollege = static_cast<int>(region[i][j].highEduPop * config.percentGradCollege);		//find number of ppl that graduate college
							region[i][j].collegeEduPop += popGradCollege; collegeEduPop += popGradCollege;	//add that amount to current amount of ppl with college level of education
							region[i][j].highEduPop -= popGradCollege; highEduPop -= popGradCollege;	//subtract that amount from high school level pop
						}
						if (config.highSchoolExists == true) {
							int popGradHigh = static_cast<int>(region[i][j].unEduPop * config.percentGradHigh);		//find number of ppl that graduate college
							region[i][j].highEduPop += popGradHigh; highEduPop += popGradHigh;	//add that amount to current amount of ppl with college level of education
							region[i][j].unEduPop -= popGradHigh; unEduPop -= popGradHigh;	//subtract that amount from high school level pop
						}
						region[i][j].population += 1;
						region[i][j].unEduPop += 1;
						unEduPop++;
						availableWorkers++;
						changed = true;     //Apply chanes for case 6
					}
        	} 
			
    	}
	}

    return changed;
}

