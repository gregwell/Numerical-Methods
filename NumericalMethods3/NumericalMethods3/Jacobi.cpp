#include "pch.h"
#include <iostream>
#include <fstream>
#include "Jacobi.h"


using namespace std;

void Jacobi::Calculate() {

	//1.1
	ifstream fin("jacobi.txt");
	fin >> n; //number of equations


	a = new double*[n];
	for (int i = 0; i < n; ++i)
		a[i] = new double[n + 1];


	cout << "The matrix from file\n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n + 1; j++) {
			fin >> a[i][j];
			if (j > n - 1) cout << "| ";
			cout << a[i][j] << "   ";
		}
		cout << "\n";
	}

	fin >> ilimit; //number of iterations

	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			d[i][j] = 0;
			l[i][j] = 0;
		}
	}



	//1.2


		//D
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			d[i][i] = a[i][i];
		}
	}

	//L
	for (int i = 1; i < n + 1; i++) {
		for (int j = 0; j <= i; j++) {

			//once for i=1 (j=0)
			l[i][j] = -a[i][j];
			//l[1][0] = a[1][0];

			//twice for i=2 (j=0,1)
			l[i][j] = -a[i][j];
			//l[1][0] = a[1][0];
			//l[1][1] = a[1][1];

			//twice for i=3 (j=0,1,2)
			l[i][j] = -a[i][j];
			//l[2][0] = a[2][0];
			//l[2][1] = a[2][1];
			//l[2][2] = a[2][3];

		}
	}

	//U
	for (int i = 0; i < n ; i++) {
		for (int j = 0; j <= i; j++) {

			//once for i=1 (j=0)
			l[i][j] = -a[i][j];
			//l[1][0] = a[1][0];

			//twice for i=2 (j=0,1)
			l[i][j] = -a[i][j];
			//l[1][0] = a[1][0];
			//l[1][1] = a[1][1];

			//twice for i=3 (j=0,1,2)
			l[i][j] = -a[i][j];
			//l[2][0] = a[2][0];
			//l[2][1] = a[2][1];
			//l[2][2] = a[2][3];

		}
	}

}
