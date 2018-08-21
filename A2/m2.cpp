/**********************************
| Subject        : Assignment 2   |
| Name           : Sang Jun Park  |
| Student number : 112293170      |
| Date           : 2018.8.16      |
**********************************/

#include <algorithm>   
#include <cmath>       
#include <cstdlib>     
#include <iomanip>     
#include <iostream>    
#include <numeric>     
#include <vector>      

using namespace std;

void print(vector<double>& _vector);
void print(vector<vector<double>>& _matrix);
void matTranspose(vector<vector<double>>& x, vector<vector<double>>& y);
void matMult(vector<double>& outcome, vector<vector<double>>& _matrix, vector<double>& _vector);

int main(){
	auto  sigmoid = [](double x) { return 1. / (1. + exp(-x)); };
	auto  sigmoid_d = [](double x) { return 1. * (1. - x); };
	vector<vector<double>> input1 = { { 0, 0, 1 }, { 0, 1, 1 }, { 1, 0, 1 }, { 1, 1, 1 } };
	vector<double> input2 = { 0, 0, 1, 1 };

	srand(1);
	vector<double> _vector(input1[0].size());
	for (auto& _val : _vector) {
		_val = 2. * rand() / double(RAND_MAX) - 1.;
	}
	auto copy = input1;
	vector<vector<double>> matix;
	vector<double>  adjustments(_vector.size());
	vector<double>  outcome(input2.size());
	vector<double>  outcome_error(input2.size());
	int maxNum = 7000;

	for (int i= 0; i<maxNum; i++) {
		matMult(outcome, copy, _vector);
		for (auto& element : outcome) {
			element = sigmoid(element);
		}
		transform(input2.begin(),input2.end(),outcome.begin(),outcome_error.begin(),
			[](double y, double outcome) { return y - outcome; });
		vector<double>  outcome_delta(input2.size());
		transform(outcome_error.begin(), outcome_error.end(), outcome.begin(), outcome_delta.begin(), 
			[sigmoid_d](double e, double outcome) { return e * sigmoid_d(outcome); });
		matMult(adjustments, matix, outcome_delta);
		transform(adjustments.begin(),adjustments.end(),_vector.begin(),_vector.begin(),[](double a, double s) {return a + s; });
	}

	cout << "Traning _vector";
	print(_vector);
	cout << "Traning _outcome:" << endl;
	print(outcome);

	getchar();
}

void print(vector<double>& _vector) {
	for (auto col : _vector) {
		cout << setprecision(8) << col << " ";
	}
	cout << "\n";
}

void print(vector<vector<double>>& _matrix) {
	for (auto row : _matrix) {
		print(row);
	}
}
void matTranspose(vector<vector<double>>& x, vector<vector<double>>& y) {
	size_t rows = y.size();
	size_t cols = y[0].size();
	x.resize(cols);
	for (auto& _val : x) {
		_val.resize(rows);
	}
	for (size_t r=0; r<rows; r++) {
		for (size_t c=0; c<cols; c++) {
			y[c][r] = x[r][c];
		}
	}
}

void matMult(vector<double>& outcome, vector<vector<double>>& _matrix, vector<double>& _vector) {
	for (size_t i = 0; i<_matrix.size(); i++) {
		outcome[i] = inner_product(_matrix[i].begin(), _matrix[i].end(), _vector.begin(), double(0));
	}
};
