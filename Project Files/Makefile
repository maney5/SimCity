a.out: main.o Cell.o SimConfig.o RegionFunctions.o Residential.o Commercial.o Industrial.o College.o HighSchool.o
	g++ main.o Cell.o SimConfig.o RegionFunctions.o Residential.o Commercial.o Industrial.o College.o HighSchool.o -o a.out

main.o: main.cpp
	g++ -c main.cpp

Cell.o: Cell.cpp Cell.h
	g++ -c Cell.cpp

SimConfig: SimConfig.cpp SimConfig.h
	g++ -c SimConfig.cpp

RegionFunctions.o: RegionFunctions.cpp RegionFunctions.h
	g++ -c RegionFunctions.cpp

Residential.o: Residential.cpp Residential.h
	g++ -c Residential.cpp

Commercial.o: Commercial.cpp Commercial.h
	g++ -c Commercial.cpp

Industrial.o: Industrial.cpp Industrial.h
	g++ -c Industrial.cpp

College.o: College.cpp College.h
	g++ -c College.cpp

HighSchool.o: HighSchool.cpp HighSchool.h
	g++ -c HighSchool.cpp

clean:
	rm *.o a.out
