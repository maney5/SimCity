Project 1: SimCity

Authors:
Group 215-4
Mario Cortinas
Manuel Flores
Spencer Russell
Kirsten Guillory


How to Compile the Program:
Before you begin compiling the program, ensure that you have downloaded all the required files:

	main.cpp
	Makefile
	SimConfig.cpp
	SimConfig.h
	RegionFunctions.cpp
	RegionFunctions.h
	Cell.cpp
	Cell.h
	Industrial.cpp
	Industrial.h
	Commercial.cpp
	Commercial.h
	Residential.cpp
	Residential.h
	College.cpp
	College.h
	HighSchool.cpp
	HighSchool.h
	config1.txt*
	region1.csv**

		*note: the file name and contents of 'config1.txt' can be edited freely, so long as there is no white space after the ':' on each line
		**note: the file name and contents of 'region1.csv' can be edited freely, so long as there is no white space after each ','

You can use your preferred terminal or command prompt tool, such as PuTTY, for this project. Be sure to create 
a new directory where you can store all essential files. Once you are inside the program's directory, proceed 
to compile it using a C/C++ compiler. 

Type "make" to create an 'a.out' file that runs all required programs.
Then type "./a.out" to run the program.

	make
	./a.out

How to Run the Program:
You will prompted for the name of config file. Enter the name of the file with no whitespace before or after and hit ENTER.
The initial region state will be outputted to the terminal. 

If using the default files type "config1.txt" after "Enter config file name:" with no whiespace before or after and hit ENTER.

	config1.txt

The region will be ran until there are no changes between 2 consecutive timeLimit steps or until ran for timeLimit amount of time, whichever comes first. 

After simulation is ran. The user is then prompted to "Examine specific retangular area of region to analyze:", then prompted with x1 coord, y1 coord, x2 coord, and y2 coord in that order. These coordinates must make a retangular area and must be within the bounds of the region. Otherwise, an error is given to the user.

	Enter x1 coord: [int]
	Enter y1 coord: [int]
	Enter x2 coord: [int]
	Enter y2 coord: [int]

After user prompts, an analysis of the specified sub-region is outputted. This information includes the population of all Industrial region, all Commerical regions, all Residential regions, and all populations combined in that order.

Program ends.
