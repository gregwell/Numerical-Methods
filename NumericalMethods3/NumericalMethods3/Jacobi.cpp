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
	for (int i = 0; i < n; i++)
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
		b[i] = a[i][n];   //ok
	
		//cout << b[i] <<" ";
	}

	double diagonal;
	double others;
	int test1=0;
	int test2=0;

	for (int i = 0; i < n; i++) {
		others = 0;
		for (int j = 0; j < n; j++) {

			if (i == j) diagonal = a[i][j];
			else others += a[i][j];
			
		}
		if (abs(diagonal) >= abs(others)) test1++;
		if (diagonal > others) test2++;
		
	}
	if (test1 == n && test2 > 0) {
		cout << "Matrix is diagonally dominant." << endl;
	}
	else {
		cout << "Matrix is not diagonally dominant. Use another matrix." << endl;
		return;
	}



	d = new double*[n];
	d_inv = new double*[n];
	l = new double*[n];
	u = new double*[n];
	m = new double*[n];


	for (int i = 0; i < n; ++i) {
	d[i] = new double[n];
	d_inv[i] = new double[n];
	l[i] = new double[n];
	u[i] = new double[n];
	m[i] = new double[n];
	}

for (int i = 0; i < n; i++) {
	for (int j = 0; j < n; j++) {
		d[i][j] = 0.0;
		d_inv[i][j] = 0.0;
		l[i][j] = 0.0;
		u[i][j] = 0.0;
	}
}

//1.2

	//D and D_inv
for (int i = 0; i < n; i++) {
	for (int j = 0; j < n; j++) {
		d[i][i] = a[i][i];
		d_inv[i][i] = 1 / a[i][i];
	}
}

//L
for (int i = 1; i < n; i++) {
	for (int j = 0; j < i; j++) {
		if (a[i][j] != 0) l[i][j] = a[i][j]; 
	}
}


//U
int temp = 0;
for (int i = 0; i < n  ; i++) {
	for (int j = n-1; j >temp ; j--) {
		if (a[i][j] != 0.0) u[i][j] = a[i][j];
	}
	temp++;
}

// Matrix m (minus )
for (int i = 0; i < n; i++) {
	for (int j = 0; j < n; j++) {
		if (i == j) m[i][j] = -1;
		else m[i][j] = 0;
		
	}
}


	//Display matrices:

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

	//Matrix D^(-1)
	cout << "The matrix D^(-1)\n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {

			if (j > n - 1) cout << "| ";
			cout << d_inv[i][j] << "   ";
		}
		cout << "\n";
	}

	x = new double*[ilimit+1];
	for (int i = 0; i < ilimit; i++) {
		x[i] = new double[n];
	}
	for (int i = 0; i < ilimit; i++) {
		for (int j = 0; j < n; j++) {
			x[i][j] = 0;
		}
	}

	for (int i = 1; i < ilimit+1; i++) {

		
		x[i] = sumVECTOR(multiplySQplusVECTOR(multiplySQ(multiplySQ(d_inv, m,n), sumSQ(l, u, n), n), x[i-1], n), multiplySQplusVECTOR(d_inv, b, n), n);

	}

	
	for (int i = 0; i < ilimit; i++) {
		cout << "Iteration no " << i + 1 << endl << "Solution: ";
		for (int j = 0; j < n; j++) {
			cout << x[i][j] << " ";
		}
		cout << endl << endl;
	}


}


