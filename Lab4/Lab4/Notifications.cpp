/**********************************
| Subject        : Workshop 4     |
| Name           : Sang Jun Park  |
| Student number : 112293170      |
| Date           : 2018.06.13     |
**********************************/
#include<iostream>
#include<fstream>
#include "Notifications.h"

using namespace std;

namespace sict {
	Notifications::Notifications(std::ifstream& in) 
	{
		m_messages.clear();
		if (in.is_open()) 
		{
			while (in.good())
			{
				Message line(in, '\n');
				if (m_messages.size() < 10)
					m_messages.push_back(line);
			}
		}
	}

	Notifications::Notifications(Notifications&&  rhs)
	{
		*this = move(rhs);
	}

	Notifications& Notifications::operator=(Notifications&& rhs)
	{
		if (this != &rhs)
		{
			m_messages = move(rhs.m_messages);
		}
		return *this;
	}

	Notifications::~Notifications() 
	{
		m_messages.clear();
	}

	void Notifications::display(std::ostream& os) const
	{
		for (size_t i = 0; i < m_messages.size(); i++)
			m_messages[i].display(os);
	}
}