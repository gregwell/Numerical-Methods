#include "pch.h"
#include <iostream>
#include <fstream>
#include "NewtonMethod.h"


using namespace std;
//newton method (tangent)
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


//newton-raphson method
double eq1(double x1, double x2) {
	return x1 * x1*x1 + 2*x2*x2;
}

double eq2(double x1, double x2) {
	return 4 * x1 + sin(x2);
}


//jacobian j[ii]
double j11(double x1, double x2) {
	return 3 * x1 *x1;
}

double j12(double x1, double x2) {
	return 4 * x2;
}

double j21(double x1, double x2) {
	return 4;
}

double j22(double x1, double x2) {
	return cos(x2);
}

//(it -number of iterations
void findRootNR(int it)
{
	double *X = new double[2];
	cout << "starting point:" << endl;
	cout << "x: ";
	cin >> *X;
	cout << "y: ";
	cin >> *(X + 1);

	cout << "eq1= " << eq1(*X, *(X + 1)) << ", eq2:" << eq2(*X, *(X + 1))<<endl;
	double x1, x2;
	for (int i = 0; i < it; i++) {
		x1 = *X;
		x2 = *(X + 1);
		double OWM = 1 / (j11(x1,x2)*j22(x1,x2) - j12(x1,x2)*j21(x1,x2)); //odwrotnosc wyznacznika macierzy
		*X = x1 - OWM * (eq1(x1, x2)*j22(x1,x2) - eq2(x1, x2)*j12(x1,x2));
		*(X + 1) = x2 - OWM * (eq2(x1, x2)*j11(x1,x2) - eq1(x1, x2)*j21(x1,x2));

		cout << "It no:" << i + 1 << "      x: " << eq1(*X, *(X + 1)) << "    y: " << eq2(*X, *(X + 1)) << endl;
	}

	cout <<"Solution: eq1= " << eq1(*X, *(X + 1)) << ", eq2:" << eq2(*X, *(X + 1));
}
