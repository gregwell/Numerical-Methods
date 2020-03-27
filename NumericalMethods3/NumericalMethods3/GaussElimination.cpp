#include "pch.h"
#include <iostream>
#include <fstream>
#include "GaussElimination.h"


using namespace std;

void Gauss::gaussElimination() {

	ifstream fin("gauss.txt");
	fin >> n; 


	a = new double*[n];
	for (int i = 0; i < n; ++i)
		a[i] = new double[n+1];

	//before
	cout << "The matrix before pivotisation: (from file)\n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n+1; j++) {
			fin >> a[i][j];
			if (j > n-1) cout << "| ";
			cout << a[i][j] << "   ";
		}
		cout << "\n";
	}

	x = new double[n];

	for ( int i=0;i<n;i++)
		for (int k=i;k<n;k++)
			if (a[i][i]<a[k][i])
				for (int j = 0; j <= n; j++) {
					double temp = a[i][j];
					a[i][j] = a[k][j];
					a[k][j] = temp;
				}

	//before
	cout << "\nThe matrix after pivotisation:\n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n + 1; j++) {
			if (j > n - 1) cout << "| ";
			cout << a[i][j] << "   ";
		}
		cout << "\n";
	}

	for (int i =0; i<n-1;i++) // not going to the last row
		for (int k = i + 1; k < n; k++)
		{
			double mult = a[k][i] / a[i][i];
			for (int j = 0; j <= n; j++)
				a[k][j] = a[k][j] - mult * a[i][j];
		}


}
