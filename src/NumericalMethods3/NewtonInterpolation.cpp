#include "pch.h"
#include <iostream>
#include <fstream>
#include "NewtonInterpolation.h"


using namespace std;



void Newton::interpolation() {

	ifstream fin("newton.txt");
	fin >> n; //the first line in the file is the number of pairs

	x = new double[n];
	y = new double[n];
	cout << "Reading " << n << " data pairs from file.." << endl;

	for (i = 0; i < n; i++) {
		fin >> x[i] >> y[i]; //file format: each line: "x[i] y[i]"
		cout << "x=  " << x[i] << ", y=" << y[i] << endl;
	}

	fin.close();

	cout << "Enter value..  ";
	cin >> v;


	sum = y[0];

	cout << "The [0] b coefficient is 0" << endl;

	for (i = 1; i < n; i++)
	{

		for (j = 0; j < i; j++)
			y[i] = (y[i] - y[j]) / (x[i] - x[j]);

		cout << "The ["<<i<<"] b coefficient is " << y[i] << endl;
	}
			

	for (i = 1; i < n; i++)
	{
		product = 1;

		for (j = 0; j < i; j++)
			product *= v - x[j];
		
		sum += y[i] * product;

	}


	cout << "\nInterpolated value = " << sum << endl;
}

