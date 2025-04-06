#ifndef SIMCONFIG_H
#define SIMCONFIG_H

#include <string>
using namespace std;

class SimConfig {
	public:
		string regionFileName;
		int refreshRate;
		int timeLimit;
		float percentGradHigh;
		float percentHighEmploy;
		float percentGradCollege;
		float percentCollegeEmploy;
		bool collegeExists;
		bool highSchoolExists;

		SimConfig();
};

SimConfig ReadConfig(const string& file);

#endif
