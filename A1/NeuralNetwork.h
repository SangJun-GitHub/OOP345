/**********************************
| Subject        : Milestone 1    |
| Name           : Sang Jun Park  |
| Student number : 112293170      |
| Date           : 2018.7.26      |
**********************************/
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <vector>
#ifndef NEURALNETWORK_HEADER
#define NEURALNETWORK_HEADER


using namespace std;

namespace m1 {

	class NeuralNetwork {
	public:
		vector<double> values;
		NeuralNetwork() {
			srand(1);
			values.resize(3);
			for (auto& value : values)
				value = 2. * rand() / double(RAND_MAX) - 1;

		};
		double _sgim(double);
		double _sgim_deriv(double);
		void train(vector<vector<double>>&, vector<double>&, int);
		void think(vector<double>&, vector<vector<double>>&);
		double think(vector<double>&);
	};

	void display(vector<double>& list);
	void display(vector<vector<double>>& list);
	void transpose(vector<vector<double>>& y, vector<vector<double>>& x);
	void multiply(vector<double>& y, vector<vector<double>>& m, vector<double>& x);
}
#endif 