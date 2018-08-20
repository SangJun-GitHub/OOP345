// Workshop 5 - Lambda Expression
// w5.cpp
// Chris Szalwinski
// 2018-05-23

#include <iostream>
#include "Grades.h"
#include "Letter.h"
using namespace sict;

int main(int argc, char* argv[]) {
	std::cout << "Command Line : ";
	for (int i = 0; i < argc; i++) {
		std::cout << argv[i] << ' ';
	}
	std::cout << std::endl;

	if (argc == 1) {
		std::cerr <<
			"\n*** Insufficient number of arguments ***\n";
		std::cerr << "Usage: " << argv[0] << " fileName \n";
		return 1;
	}
	else if (argc != 2) {
		std::cerr << "\n*** Too many arguments ***\n";
		std::cerr << "Usage: " << argv[0] << " fileName \n";
		return 2;
	}


	sict::Grades grades(argv[1]);
	// lambda expression for converting to letter 
	auto letter = [](double point)->std::string
	{
		std::string Grade;

		if (point >= 90)
			Grade = "A+";
		else if (point >= 80)
			Grade = "A";
		else if (point >= 75)
			Grade = "B+";
		else if (point >= 70)
			Grade = "B";
		else if (point >= 65)
			Grade = "C+";
		else if (point >= 60)
			Grade = "C";
		else if (point >= 55)
			Grade = "D+";
		else if (point >= 50)
			Grade = "D";
		else
			Grade = "F";
		return Grade;
	};

	grades.displayGrades(std::cout, letter);

	// report the error message
	std::cerr << argv[0] << ": Failed to open file "
		<< argv[1] << "\n";
	return 2;
}