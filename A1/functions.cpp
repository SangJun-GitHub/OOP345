/**********************************
| Subject        : Milestone 1    |
| Name           : Sang Jun Park  |
| Student number : 112293170      |
| Date           : 2018.7.26      |
**********************************/
#include "NeuralNetwork.h"

using namespace std;

namespace m1 {
	void display(vector<double>& values) {
		for (auto col : values) {
			cout << col << " ";
		}
		cout << "\n";
	}

	void display(vector<vector<double>>& values) {
		for (auto row : values) {
			display(row);
		}
	}

	void transpose(vector<vector<double>>& y, vector<vector<double>>& x) {
		size_t rows = x.size();
		size_t cols = x[0].size();
		y.resize(cols);
		for (auto& _e : y) {
			_e.resize(rows);
		}

		for (size_t row = 0; row < rows; row++) {
			for (size_t col = 0; col < cols; col++) {
				y[col][row] = x[row][col];
			}
		}	
	}

	void multiply(vector<double>& y, vector<vector<double>>& m, vector<double>& x) {
		for (size_t i = 0; i<m.size(); i++)
			y[i] = inner_product(m[i].begin(), m[i].end(), x.begin(), 0.);
	}
}
