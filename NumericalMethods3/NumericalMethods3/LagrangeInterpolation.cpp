#include "pch.h"
#include <iostream>
#include <fstream>
#include "LagrangeInterpolation.h"


using namespace std;

//double interpolate(Data f[], int xi, int n)
//{
//	double result = 0; // Initialize result 
//
//	for (int i = 0; i < n; i++)
//	{
//		// Compute individual terms of above formula 
//		double term = f[i].y;
//		for (int j = 0; j < n; j++)
//		{
//			if (j != i)
//				term = term * (xi - f[j].x) / double(f[i].x - f[j].x);
//		}
//
//		// Add current term to result 
//		result += term;
//	}
//
//	return result;
//}

void Lagrange::interpolation() {

	ifstream fin("lagrange.txt");
	fin >> n;

	x = new double[n];
	y = new double[n];
	cout << "3"<< n << endl;

	for (i = 0; i < n; i++) {
		fin >> x[i] >> y[i];
		cout << "to jes x od i" << x[i] << endl;
		cout << "to jes y od i" << y[i] << endl;
	}
	cout << "4" << endl;
	fin.close();

	cout << "\n Enter value at which interpolation is to be carried out: ";
	cin >> z;

	sum = 0.0;

	for (i = 0; i < n; i++) {
		mult = 1.0;
		for (j = 0; j < n; j++) {
			if (j != i) {
				mult *= (z - x[j]) / (x[i] - x[j]);
			}
		}
		sum += mult * y[i];
	}
	cout << "\nInterpolated value = " << sum << endl;
}

void huj() {
	cout << "huj!!!!!" << endl;
}