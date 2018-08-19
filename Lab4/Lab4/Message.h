/**********************************
| Subject        : Workshop 4     |
| Name           : Sang Jun Park  |
| Student number : 112293170      |
| Date           : 2018.06.13     |
**********************************/
#include <iostream>
#include <string>

namespace sict 
{
	class Message
	{
		std::string f_str, s_str, t_str;

	public:
		Message(std::ifstream& in, char c);
		void display(std::ostream&) const;
	};
}
