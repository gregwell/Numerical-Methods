#pragma once
#include <iostream>

using namespace std;

class Newton {
private:
	int i; //the array indexes 
	int j;

	int n; //the number of data pairs
	double product; //performs the computation of product term
	double sum; //performs the summation
	double v; //represents the value of x at which the interpolation is to be carried out

	double *x; //represents the data pairs
	double *y;
public:
	void interpolation();

	~Newton() {
		delete[] x, y;
	}
};
