#include "pch.h"
#include <iostream>
#include <fstream>
#include "Jacobi.h"
#include "MatrixOperations.h"


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

	b = new double[n];
	for (int i = 0; i < n; i++) {
		b[i] = a[i][n];
		cout << b[i] <<" ";
	}

	d = new double*[n];
	l = new double*[n];
	u = new double*[n];


	for (int i = 0; i < n; ++i) {
	d[i] = new double[n];
	l[i] = new double[n];
	u[i] = new double[n];
}

for (int i = 0; i < n; i++) {
	for (int j = 0; j < n; j++) {
		d[i][j] = 0.0;
		l[i][j] = 0.0;
		u[i][j] = 0.0;
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
for (int i = 1; i < n; i++) {
	for (int j = 0; j < i; j++) {
		if (a[i][j] != 0) l[i][j] = -a[i][j];
	}
}


//U
int temp = 0;
for (int i = 0; i < n  ; i++) {
	for (int j = n-1; j >temp ; j--) {
		if (a[i][j] != 0.0) u[i][j] = -a[i][j];
	}
	temp++;
}






	//Read matrices:

	cout << "The matrix D\n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			
			if (j > n - 1) cout << "| ";
			cout << d[i][j] << "   ";
		}
		cout << "\n";
	}

	cout << "The matrix L\n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			
			if (j > n - 1) cout << "| ";
			cout << l[i][j] << "   ";
		}
		cout << "\n";
	}

	cout << "The matrix U\n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			
			if (j > n - 1) cout << "| ";
			cout << u[i][j] << "   ";
		}
		cout << "\n";
	}



}


