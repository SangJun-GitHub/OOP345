/**********************************
| Subject        : Workshop 6     |
| Name           : Sang Jun Park  |
| Student number : 112293170      |
| Date           : 2018.8.09      |
**********************************/

#include <iostream>
#include <fstream>
#include <iomanip>
#include "iProduct.h"

namespace w7 
{
	Product::Product(const unsigned int _productNum, const double _productCost)
	{
		productNum = _productNum;
		productCost = _productCost;
	}

	double Product::getCharge() const 
	{
		return productCost;
	}

	void Product::display(std::ostream& os) const 
	{
		os << std::setw(10) << std::right;
		os << productNum;
		os << std::setw(10) << std::right;
		os << productCost << '\n';
	}

	TaxableProduct::TaxableProduct(const unsigned int _productNum, const double _productCost, const char _taxType)
	{
		productNum = _productNum;
		productCost = _productCost;
		taxType = _taxType;
	}

	double TaxableProduct::getCharge() const 
	{
		double taxRate = 1;
		if (taxType == 'H') {
			taxRate = 1.13;
		} else if(taxType == 'P') {
			taxRate = 1.08;
		}
		return productCost * taxRate;
	}

	void TaxableProduct::display(std::ostream& os) const 
	{
		os << std::setw(10) << std::right << productNum << std::setw(10) << std::right << productCost;
		os << ' ';
		if (taxType == 'H') {
			os << "HST";
		} else if(taxType == 'P') {
			os << "PST";
		}
		os << '\n';
	}

	std::ostream& operator<<(std::ostream& os, const iProduct& product) {
		product.display(os);
		return os;
	}

	iProduct* readProduct(std::ifstream& is) {
		int _productNum;
		double _productCost;
		char _taxType;

		is >> _productNum >> _productCost;
		if (is.get() != '\n') {
			is.get(_taxType);
			return new TaxableProduct(_productNum, _productCost, _taxType);
		} else {
			return new Product(_productNum, _productCost);
		}
	}
}