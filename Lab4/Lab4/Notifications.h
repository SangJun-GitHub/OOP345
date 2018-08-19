/**********************************
| Subject        : Workshop 4     |
| Name           : Sang Jun Park  |
| Student number : 112293170      |
| Date           : 2018.06.13     |
**********************************/
#include <iostream>
#include <vector>
#include "Message.h"

namespace sict 
{
	class Notifications
	{
		std::vector <Message> m_messages;

	public:
		Notifications(std::ifstream& rhs);
		Notifications(Notifications&&);
		Notifications& operator=(Notifications&& rhs);
		~Notifications();
		void display(std::ostream& os) const;
	};
}