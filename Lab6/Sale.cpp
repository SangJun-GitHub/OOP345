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
#include "Sale.h"

namespace w7 
{
	Sale::Sale(const char* fileName) 
	{
		std::ifstream file(fileName);
		while (file.good()) 
		{
			iProduct* iproduct = readProduct(file);
			products.push_back(iproduct);
		}
	}

	void Sale::display(std::ostream& os) 
	{
		float totalCost = 0;
		os << "Product No      Cost Taxable\n";
		os << std::fixed << std::setprecision(2);

		for (auto product : products) 
		{
			os << *product;
			totalCost += product->getCharge();
		}
		os << "Total" << std::setw(10) << std::right << totalCost << '\n';
	}
}