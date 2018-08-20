/**********************************
| Subject        : Workshop 5     |
| Name           : Sang Jun Park  |
| Student number : 112293170      |
| Date           : 2018.06.20     |
**********************************/
#include <iostream>
#include <fstream>
#include <string>
#include <functional>

namespace sict
{
	class Grades
	{
		size_t size;
		double* m_grades;
		std::string* m_students;

	public:
		Grades() : m_students(nullptr), m_grades(0), size(0) {}
		Grades(std::string FileName);
		template <class F>
		void displayGrades(std::ostream& os, F g) const 
		{
			for (size_t i = 0; i < size; i++)
			{
				os << m_students[i] << "  " << m_grades[i] << "0 " << g(m_grades[i]) << std::endl;
			}
		};
	};
}