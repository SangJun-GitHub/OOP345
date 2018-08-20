/**********************************
| Subject        : Workshop 6     |
| Name           : Sang Jun Park  |
| Student number : 112293170      |
| Date           : 2018.8.09      |
**********************************/

#ifndef W7_IPRODUCT_H
#define W7_IPRODUCT_H

#include <iostream>
#include <fstream>

namespace w7 
{
	class iProduct 
	{
	public:
		virtual double getCharge() const = 0;
		virtual void display(std::ostream& os) const = 0;
	};

	class Product : public iProduct
	{
	private:
		unsigned int productNum;
		double productCost;

	public:
		Product(const unsigned int _producNum, const double _productCost);
		
		double getCharge() const;
		void display(std::ostream& os) const;
	};

	class TaxableProduct : public iProduct 
	{
	private:
		unsigned int productNum;
		double productCost;
		char taxType;

	public:
		TaxableProduct(const unsigned int _producNum, const double _productCost, const char _taxType);
		
		double getCharge() const;
		void display(std::ostream& os) const;
	};

	std::ostream& operator<<(std::ostream& os, const iProduct& product);
	iProduct* readProduct(std::ifstream& is);
}
#endif