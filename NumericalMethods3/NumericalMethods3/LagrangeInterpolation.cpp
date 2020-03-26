#include "pch.h"
#include <iostream>
#include <fstream>
#include "LagrangeInterpolation.h"


using namespace std;



void Lagrange::interpolation() {

	ifstream fin("lagrange.txt");
	fin >> n; //the first line in the file is the number of pairs

	x = new double[n];
	y = new double[n];
	cout << "Reading " << n << " data pairs from file.." << endl;

	for (i = 0; i < n; i++) {
		fin >> x[i] >> y[i]; //file format: each line: "x[i] y[i]"
		cout << "x=  "<< x[i] <<", y=" << y[i] << endl;
	}

	fin.close();

	cout << "Enter value..  ";
	cin >> v;

	sum = 0.0;

	for (i = 0; i < n; i++) {
		polynomial = 1.0;
		for (j = 0; j < n; j++) { //li(x)
			if (j != i) {
				polynomial *= (v - x[j]) / (x[i] - x[j]);
			}
		} //the sum of found polynomials multiplied by corresponding values
		sum += polynomial * y[i];
	}
	cout << "\nInterpolated value = " << sum << endl;
}

