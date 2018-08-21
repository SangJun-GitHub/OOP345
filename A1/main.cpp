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
#include "NeuralNetwork.h"

using namespace std;
using namespace m1;


int main() {
	NeuralNetwork instance;
	cout << "Random starting synaptic weights: ";
	display(instance.values);
	vector<vector<double>> tranings = 
	{
		{ 0, 0, 1 },
		{ 1, 1, 1, },
		{ 1, 0, 1 },
		{ 0, 1, 1 }
	};
	vector<double> training_results = {
		{ 0, 1, 1, 0 }
	};
	instance.train(tranings, training_results, 10000);
	cout << "New synaptic weights after training: ";
	display(instance.values);
	cout << "Considering new situation [1, 0, 0] -> ?: ";
	vector<double> input = { 1, 0, 0 };
	cout << setprecision(8) << instance.think(input) << "\n";
	return 0;
}