#include "pch.h"
#include <iostream>
#include <fstream>
#include "DifferentialEquations.h"


using namespace std;


double de1(double x, double y)
{
	return x * x + y;
}

void de1_formula() {
	cout << "Func 1: x^2 + y" << endl;
}

// y(xp) = yp // warunek poczatkowy // n- liczba krokow obliczen // xk - x koncowe
void solveDE(double xp, double yp, int n, double xk) {

	double h = (xk - xp) / n; // wielkosc pojedynczego kroku
	cout << "Licza krkokow: " << n << endl;

	de1_formula();
	cout << "Warunek poczatkowy: y(" << xp << ")=" << yp << ", krok obliczen h=" << h << ", x koncowe xk=" << xk << endl;

	double xp_t = xp;
	double xk_t = xk;
	double yp_t = yp;

	//euler
	double a = xp;
	double b = xk;
	double c = yp;
	while ((b - a) > h / 2.0) {
		c += (h * de1(a, c));
		a += h;
		cout << "v(" << a << ")=" << c << endl;
	}
	cout << "Rozwiazanie Eulera dla y(" << a << ") to " << c << endl;

	//RK2
	double k1;
	double k2;
	double phi;

	while ((xk - xp) > h / 2.0) {
		k1 = de1(xp, yp);
		k2 = de1(xp + h, yp + h * k1);
		phi = 0.5 * (k1 + k2);
		yp += h * phi;
		xp += h;
		cout << "v(" << xp << ")=" << yp << endl;
	}
	cout << "Rozwiazanie RK2 dla y(" << xp << ") to " << yp << endl;


	//RK4
	double p1;
	double p2;
	double p3;
	double p4;
	double theta;

	while ((xk_t - xp_t) > h / 2.0) {
		p1 = de1(xp_t, yp_t);
		p2 = de1(xp_t + 0.5*h, yp_t + 0.5 * h * p1);
		p3 = de1(xp_t + 0.5*h, yp_t + 0.5 * h * p2);
		p4 = de1(xp_t + h, yp_t + h * p3);
		theta = (1.0 / 6) * (p1 + 2 * p2 + 2 * p3 + p4);
		yp_t += h * theta;
		xp_t += h;
		cout << "v(" << xp_t << ")=" << yp_t << endl;
	}
	cout << "Rozwiazanie RK4 dla y(" << xp_t << ") to " << yp_t << endl;


}