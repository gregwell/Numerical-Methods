#include "pch.h"
#include <iostream>
#include <fstream>
#include "NewtonMethod.h"


using namespace std;

void findRoot(double x0, double precision) 
{
	

	cout << "f = cos(x)" << endl;

	double x = x0;
	cout << "Starting point x= " << x << ", precision= " << precision << endl;
	double y = f(x);
	cout << "\ny= "<<y << endl;
	int i = 0;

	while (abs(y) > precision) {
		x = x - y / fd(x);
		y = f(x);
		cout << ++i <<". x= " << x << ", y= "<<y<<endl;
	}
	cout << fixed<< "Func value:" << y << endl;

}

double f(double x)
{
	return cos(x*x+2*x);
}

double fd(double x)
{
	return -2 * (x + 1)*sin(x*(x + 2));
}

