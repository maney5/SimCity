#include "HighSchool.h"
#include <iostream>
#include <vector>

bool runHighSchool(vector<vector<Cell>>& region, SimConfig config) {
	bool highSchoolExists = false;	//keeps track if highschool exists in region

	//cycles through the region
	for(int i = 0; i < region.size(); ++i) {
		for(int j = 0; j < region[i].size(); ++j){	
			if (region[i][j].zoneType == "H") {		//high school zone found
				if (region[i][j].unEduPop > 0) {
					config.highSchoolExists = true;
				}
			}
        }
    }
	return highSchoolExists;
}
