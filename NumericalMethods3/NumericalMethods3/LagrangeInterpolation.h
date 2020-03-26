#pragma once
#include <iostream>


using namespace std;

class Lagrange {
private:
	int i; //the array indexes 
	int j; 

	int n; //the number of data pairs
	double polynomial; //performs the computation involved in li(x)
	double sum; //performs the summation
	double v; //represents the value of x at which the interpolation is to be carried out

	double *x; //represents the data pairs
	double *y;
public:
	void interpolation();

	~Lagrange() {
		delete[] x, y;
	}
};
