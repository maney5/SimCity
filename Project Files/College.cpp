#include "College.h"
#include <iostream>
#include <vector>

bool runCollege(vector<vector<Cell>>& region, SimConfig config) {
	bool collegeExists = false;	//keeps track if highschool exists in region
	
	//cycles through the region
	for(int i = 0; i < region.size(); ++i) {
		for(int j = 0; j < region[i].size(); ++j){	
			if (region[i][j].zoneType == "c"){		//college zone found
				config.collegeExists = true;
			}
		}
	}
	return collegeExists;
}
