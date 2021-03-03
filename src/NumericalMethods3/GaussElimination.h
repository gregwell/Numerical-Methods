#pragma once
#include <iostream>

using namespace std;

class Gauss {
private:

	int n; //the number of equations
	double **a;
	double *x;

public:
	void gaussElimination();

	~Gauss() {
		//delete[] x, y;
	}
};
