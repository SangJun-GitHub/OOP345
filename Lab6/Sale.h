/**********************************
| Subject        : Workshop 6     |
| Name           : Sang Jun Park  |
| Student number : 112293170      |
| Date           : 2018.8.09      |
**********************************/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include "iProduct.h"

namespace w7 
{
	class Sale 
	{
	private:
		std::vector<iProduct*> products;

	public:
		Sale(const char* fileName);
		void display(std::ostream& os);
	};
}