#include "SimConfig.h"
#include <iostream>
#include <fstream>
#include <sstream>

SimConfig::SimConfig() {
    regionFileName = "";
    refreshRate = 0;
   	timeLimit = 0;
	percentGradHigh = 0.0;
	percentHighEmploy = 0.0;
	percentGradCollege = 0.0;
	percentCollegeEmploy = 0.0;
	collegeExists = false;
	highSchoolExists = false;
}

SimConfig ReadConfig(const string& file) {
	SimConfig config;
	ifstream configFile(file);  //opens the file given from user prompt
	
	//displays error if file cannot be found
	if(!configFile.is_open()) {
		cout << "Failed to open region file" << endl;
		return config;
	}

	string lineData;
	int counter = 1;  //counter to track whether region layout, time limit, or refresh rate is being stored
	char charToFind = ':';  //looking to store data after ':'
	char currChar;
	bool isFound = false;  //tracks if ':' has been found

	while (configFile.get(currChar) && !configFile.eof()) {
		if (isFound) {
			if (currChar == '\n') {
				switch(counter) {
					case 1: config.regionFileName = lineData; break;
                    case 2: config.timeLimit = stoi(lineData); break;
                    case 3: config.refreshRate = stoi(lineData); break;
                    case 4: config.percentGradHigh = stof(lineData); break;
                    case 5: config.percentHighEmploy = stof(lineData); break;
                    case 6: config.percentGradCollege = stof(lineData); break;
                    case 7: config.percentCollegeEmploy = stof(lineData); break;
                    default: break;
				}
				lineData.clear();
				counter++;
				isFound = false;

			} else {
				lineData += currChar;
			}
		} else if (currChar == charToFind) {
			isFound = true;
		}
	}

	configFile.close();
	return config;
}
