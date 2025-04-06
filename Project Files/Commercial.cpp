#include "Commercial.h"
#include <iostream>
#include <vector>
using namespace std;

        //Recieving available goods and available workers
bool runCommercial(vector<vector<Cell>>& zone, int& workers, int& goods){ 
    int adjacentPowerlines = 0;
    int adjacentPop = 0;
    bool changed = false;
    
            //Begin running through double vectors
    for(int i = 0; i <zone.size(); ++i){
        for(int j = 0; j <zone[i].size(); ++j){

           if (zone[i][j].zoneType == "C") {
                adjacentPowerlines = 0;
                adjacentPop = 0;

                for (int I = -1; I <= 1; ++I) {
                    for (int J = -1; J <= 1; ++J) {
                        int Ii = i + I;
                        int Jj = j + J;

                    
                        if (Ii == i && Jj == j) {
                            continue;
                        }

                        // Checking if neightbor is within range
                        if (Ii >= 0 && Ii < zone.size() && Jj >= 0 && Jj < zone[Ii].size() ) {
                            if (zone[Ii][Jj].population >= 1) {
                                ++adjacentPop;
                            }

                            if (zone[Ii][Jj].zoneType == "T") {
                                ++adjacentPowerlines;
                            }
                        }
                    }
                }
            // Apply the rules based on the current cell's population, adjacent counts, and available workers and goods
                if (zone[i][j].population == 0 && adjacentPowerlines >= 1 && workers >= 1 && goods >= 1) {
                    zone[i][j].population += 1;
                    workers -= 1;
                    goods -= 1;
					changed = true;     //Apply changes for case 1
                } else if (zone[i][j].population == 0 && adjacentPop >= 1 && workers >= 1 && goods >= 1) {
                    zone[i][j].population += 1;
                    workers -= 1;
                    goods -= 1;
					changed = true;     //Apply changes for case 2
                } else if (zone[i][j].population == 1 && adjacentPop >= 2 && workers >= 1 && goods >= 1) {
                    zone[i][j].population += 1;
                    workers -= 1;
                    goods -= 1;
					changed = true;     //Apply chanes for case 3
                }
            }
        }

    }
    return changed;
}
    


