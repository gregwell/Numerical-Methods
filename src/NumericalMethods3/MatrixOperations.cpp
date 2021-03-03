#include "pch.h"
#include <iostream>
#include <fstream>
#include "MatrixOperations.h"


using namespace std;


double** multiplySQ(double **m1, double **m2, int n) {
	double** result = new double*[n];
	for (int i = 0; i < n; i++) {
		result[i] = new double[n];
	}
	for (int i = 0; i < n; i++) {
		result[i] = new double[n];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				result[i][j] = 0;
				for (int k = 0; k < n; k++) {
					result[i][j] += m1[i][k] * m2[k][j];
				}
			}
		}
	}
	return result;
}

double* multiplySQplusVECTOR(double** m1, double* m2, int n) {
	double* result = new double[n];
	for (int i = 0; i < n; i++) {
		result[i] = 0;
		for (int j = 0; j < n; j++) {
			result[i] += m1[i][j] * m2[j];
		}
	}
	return result;
}

double** sumSQ(double** m1, double** m2, int n) {
	double** result = new double*[n];
	for (int i = 0; i < n; i++) {
		result[i] = new double[n];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			result[i][j] = m1[i][j] + m2[i][j];
		}
	}
	return result;
}

double* sumVECTOR(double* m1, double* m2, int n) {
	double* result = new double[n];
	for (int i = 0; i < n; i++) {
		result[i] = m1[i] + m2[i];

	}
	return result;
}