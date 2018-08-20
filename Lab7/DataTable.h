/**********************************
| Subject        : Workshop 7     |
| Name           : Sang Jun Park  |
| Student number : 112293170      |
| Date           : 2018.8.09      |
**********************************/

#include <iostream>
#include <functional>
#include <algorithm>
#include <fstream>
#include <vector>
#include <iomanip>
#include <numeric>
#include <cmath>

using namespace std;

namespace w8 
{
	template<class T>
	class DataTable 
	{
	private:
		vector<T> x_value;
		vector<T> y_value;

		size_t size = 0;

		int x;
		int y;

		T x_sum = 0; 
		T y_sum = 0; 
		T xx_sum = 0; 
		T xy_sum = 0;
		T y_mean = 0;
		T y_sigma = 0;

	public:

		DataTable() {}

		DataTable(ifstream& file, const int _x, const int _y) 
		{
			x = _x;
			y = _y;
			
			T x, y;
			while (file >> x >> y) 
			{
				x_value.push_back(move(x));
				y_value.push_back(move(y));
				++size;
			}
			if (x_value.empty() || y_value.empty()) 
				throw string("Error");

			if (!size) 
				throw string("No data");

			x_sum = accumulate(x_value.begin(), x_value.end(), (T)0);
			y_sum = accumulate(y_value.begin(), y_value.end(), (T)0);

			auto square_elements = [](T x, T y) { return x + y * y; };

			xx_sum = accumulate(x_value.begin(), x_value.end(), (T)0, square_elements);
			y_mean = y_sum / size;

			for (size_t i = 0; i < size; i++) 
				xy_sum += x_value.at(i) * y_value.at(i);

		}

		T mean() const 
		{
			return y_mean;
		}

		T sigma() const 
		{
			vector<T> y_tf;
			y_tf.resize(size);

			transform(y_value.begin(), y_value.end(), y_tf.begin(), [&](T y) 
			{
				return pow((y - y_mean), (T) 2);
			});

			auto sum = accumulate(y_tf.begin(), y_tf.end(), (T)0);		
			auto ssd = sqrt(sum / (size - 1));

			return ssd;
		}

		T median() const 
		{
			vector<T> y_st(y_value);
			sort(y_st.begin(), y_st.end());
			int index = (int)size / 2;

			return y_st.at(index);
		}

		void regression(T& slope, T& y_intercept) const
		{
			slope = ((size*xy_sum)-(x_sum*y_sum)) / ((size*xx_sum)-(x_sum*x_sum));
			y_intercept = (y_sum - (slope*x_sum)) / size;
		}

		void display(ostream& os) const 
		{
			os << fixed << setprecision(y);
			os << right << setw(7) << "x";
			os << right << setw(7) << "y" << endl;
			for (size_t i = 0; i < size; i++) 
			{
				os << right << setw(7) << x_value.at(i);
				os << right << setw(7) << y_value.at(i) << endl;
			}
		}
	};

	template<typename T>
	ostream& operator<<(ostream& os, const DataTable<T>& table) 
	{
		table.display(os);
		return os;
	}
}