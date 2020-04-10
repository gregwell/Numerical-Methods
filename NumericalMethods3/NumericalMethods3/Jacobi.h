#pragma once
#include <iostream>

using namespace std;

class Jacobi {
private:

	int n; //the number of equations -from file
	int ilimit; //the numbers of iterations -from file
	double **a;
	double *b;
	double **d;
	double **l;
	double **u;
	double *x;

public:
	void Calculate();

	~Jacobi() {
		//delete[] x, y;
	}
};
