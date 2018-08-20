/**********************************
| Subject        : Workshop 5     |
| Name           : Sang Jun Park  |
| Student number : 112293170      |
| Date           : 2018.06.20     |
**********************************/
#include <iostream>
#include <fstream>
#include <string>
#include "Grades.h"

namespace sict
{
	Grades::Grades(std::string FileName)
	{
		std::ifstream in(FileName);
		if (in.is_open())
		{
			std::string line;
			while (std::getline(in, line))
				size++;

			m_grades = new double[size];
			m_students = new std::string[size];
			in.clear();
			in.seekg(0);

			for (size_t i = 0; i < size; i++)
			{
				in >> m_students[i];
				in.ignore(1, ' ');
				in >> m_grades[i];
				in.ignore(1, '\n');
			}
			in.close();
		} else {
			throw std::string("Couldn't open the file '" + FileName + "'\n");
		}
	}
}