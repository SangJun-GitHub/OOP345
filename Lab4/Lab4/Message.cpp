/**********************************
| Subject        : Workshop 4     |
| Name           : Sang Jun Park  |
| Student number : 112293170      |
| Date           : 2018.06.13     |
**********************************/
#include<iostream>
#include<fstream>
#include<string>
#include "Message.h"

using namespace std;

namespace sict 
{
	Message::Message(std::ifstream& in, char c) 
	{
		string line;
		size_t size = 0;
		size_t space;
		size_t at;
		getline(in, line, c);
		if (line.find(' ') != string::npos)
		{
			if (line.find('@') == string::npos)
			{
				size = line.length();
				space = line.find(' ');
				f_str = line.substr(0, space);
				space++;
				t_str = line.substr(space, size);
			} else {
				size = line.length();
				space = line.find(' ');
				f_str = line.substr(0, space);
				at = line.find('@');
				space = line.find(' ', at);
				at++;
				s_str = line.substr(at, space - at);
				space++;
				t_str = line.substr(space, size);
			}
		} else {
			return;
		}
	}

	void Message::display(std::ostream& os) const
	{	
		if (f_str.empty() || t_str.empty()) 
		{
			os << endl;
		} else {
			os << "Message" << endl;
			os << " User  : " << f_str << endl;
			if (s_str[0] != '\0') 
				os << " Reply : " << s_str << endl;
			os << " Tweet : " << t_str << endl;
			os << endl;
		}
	}
}