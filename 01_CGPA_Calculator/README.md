# CGPA Calculator (C++)

A console-based CGPA calculator built using C++17. It accepts multiple semesters, course names, grade points and credit hours, then calculates each semester GPA and the overall credit-weighted CGPA.

## Features
- Supports 1 to 12 semesters and 1 to 20 courses per semester.
- Validates numeric input and uses a 10-point grade scale.
- Displays each course's grade point and credits.
- Calculates semester GPA and cumulative CGPA using credit weighting.
- Uses readable structures, functions and standard C++ containers.

## Formula
- Course weighted points = Grade Point × Credit Hours
- Semester GPA = Total weighted points in semester ÷ Total semester credits
- Overall CGPA = Total weighted points across all entered semesters ÷ Total credits across all entered semesters

## Compile and run (Windows / MinGW)
```bash
g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o cgpa_calculator.exe
cgpa_calculator.exe
```

## Important
Use the grade-point scale and credit values provided by your institution. This program uses a 10-point grade-point scale. Enter every completed semester to calculate a cumulative CGPA; entering only one semester makes the displayed CGPA equal to that semester's GPA.



