#pragma once
#include <iostream>


using namespace std;

//struct Data
//{
//	int x, y;
//};
//
//double interpolate(Data f[], int xi, int n);

class Lagrange {
private:
	int i; //the array indexes 
	int j; 

	int n; //the number of data pairs
	double mult; //performs the computation involved in Li(x), defined by equation [26]
	double sum; //performs the summation in equation [25]
	double z; //represents the calue of x at which the interpolation is to be carried out

	double *x; //represents the data pairs
	double *y;
public:
	void interpolation();
	~Lagrange() {
		delete[] x, y;
	}
};

void huj();