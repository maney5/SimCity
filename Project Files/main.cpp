#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "SimConfig.h"
#include "RegionFunctions.h"
#include "Cell.h"
using namespace std;


int main() {
	//read in config file
	string configFilePath;
	cout << "Enter config file name: "; 
	getline(cin, configFilePath);
	vector<vector<Cell>> region;
	SimConfig config = ReadConfig(configFilePath);  //reads the config file using function from SimConfig.cpp

	//read in region file
	region = ReadInRegion(config, region);

	//display inital state
	cout << endl;
	cout << "Displaying intial region:" << endl;
	DisplayRegion(region);
	cout << endl;

	cout << "	Running City:" << endl;
	RunCity(config, region);

	char runAnalysisUserChoice;
	cout << "Would you like to analyze a region? (Type 'Y' for yes): ";
	cin >> runAnalysisUserChoice;
	if (runAnalysisUserChoice == 'Y' || runAnalysisUserChoice == 'y') {
		cout << "Examine specific retangular area of region to analyze:" << endl;
		bool isValidArea = false;
		int x1, x2, y1, y2;
		while (!isValidArea) {
			cout << "Enter x1 coord:";
			cin >> x1;
			cout << "Enter y1 coord:";
			cin >> y1;
			cout << "Enter x2 coord:";
			cin >> x2;
			cout << "Enter y2 coord:";
			cin >> y2;
			if (x1 >= 0 && y1 >= 0 && x2 < region[0].size() && y2 < region.size() && x1 <= x2 && y1 <= y2) {
					isValidArea = true;
				} else {
					cout << "Region coordinates are invalid." << endl;
				}
		}
		AnalyzeRegion(region, x1, x2, y1, y2);
	} else {
		cout << "End of Project. Thank you" << endl;
	}

	return 0;
}
