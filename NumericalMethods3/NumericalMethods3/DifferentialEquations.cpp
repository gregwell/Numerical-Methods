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

	double v; // wartosc w kolejnym punkcie

	de1_formula();
	cout << "Warunek poczatkowy: y(" << xp << ")=" << yp << ", krok obliczen h=" << h << ", x koncowe xk=" << xk << endl;

	//euler
	while ((xk - xp) > h / 2.0) {
		v = yp + (h * de1(xp, yp));
		yp = v;
		xp += h;
		cout << "v(" << xp << ")=" << v << endl;
	}
	cout << "Rozwiazanie dla y(" << xk << ") to " << v << endl;

}