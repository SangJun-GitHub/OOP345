/**********************************
| Subject        : Milestone 1    |
| Name           : Sang Jun Park  |
| Student number : 112293170      |
| Date           : 2018.7.26      |
**********************************/
#include "NeuralNetwork.h"

using namespace std;

namespace m1 {

		double NeuralNetwork::_sgim(double val) {
			return 1. / (1. + exp(-val));
		}

		double NeuralNetwork::_sgim_deriv(double val) {
			return val* (1. - val);
		}

		void NeuralNetwork::think(vector<double>& out,
			vector<vector<double>>& in) {
			multiply(out, in, values);
			for (auto& _e : out) _e = _sgim(_e);
		}

		double NeuralNetwork::think(vector<double>& input) {
			return _sgim(inner_product(input.begin(), input.end(), values.begin(), 0.));
		}

		void NeuralNetwork::train(vector<vector<double>>& in, 
			vector<double>& out, 
			int nums) {
			vector<double> output(in.size());
			vector<double> error(in.size());
			vector<double> doSomething(in[0].size());
			vector<vector<double>> results;

			transpose(results, in);
			for (int i = 0; i<nums; i++) {
				think(output, in);
				transform(out.begin(), out.end(), output.begin(), error.begin(), [](double t, double o) { return t - o; });
				transform(error.begin(), error.end(), output.begin(), output.begin(), [this](double e, double o) { return e * _sgim_deriv(o); });
				multiply(doSomething, results, output);
				transform(values.begin(), values.end(), doSomething.begin(), values.begin(), [](double w, double a) { return w + a; });
			}
		}


}