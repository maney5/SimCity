# Project: SimCity
> Imported from Project Folder; Fall 2023

## Description
Simulates a city based on external and continuously changing variables such as population, power, pollution, city zones, and roads.

> [!NOTE]
> Project consisted of 4 people.
> My responsibilities included Simconfig, Residential zones, and coordinate analysis, which were all implemented.
> Other group members did not fully implement other responsibilities - such as Industrial, Pollution, etc. 

Below is an example of an output:
```
Displaying initial region:

    T # T T T
I I I - C C T
I I I - C C T P
I I I - C C T
- - - - - - # -
H c - R R R T
    - R R R
    - R R R

Running City:

Time Step: 1
Available Workers: 1
Available Goods: 0
UnEduPop:1
HighEduPop:0
CollegeEduPop:0

      T # T T T
  I I I - C C T
  I I I - C C T P
  I I I - C C T
  - - - - - - # -
  H c - R R 1 T
      - R R R
      - R R R

...

Reached final time step: 20
Outputting final state:

      T # T T T
  I I I - C C T
  I I I - C C T P
  I I I - C C T
  - - - - - - # -
  H c - 2 2 2 T
      - 2 3 2
      - 2 2 2

Would you like to analyze a region? (Type 'Y' for yes): Y
Examine specific retangular area of region to analyze:
Enter x1 coord:0
Enter y1 coord:0
Enter x2 coord:7
Enter y2 coord:7

Analysis of Specified Region:
Total Industrial Population: 0
Total Commercial Population: 0
Total Residential Population: 19
Total Population: 19
```

