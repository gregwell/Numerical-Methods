#include "pch.h"
#include <iostream>
#include <fstream>
#include "Integration.h"


using namespace std;

double func1(double x)
{
	return x*x*x + x*x + x;
}

void func1_formula() {
	cout << "Func 1: x^3 + x^2+ x" << endl;
}

double func2(double x)
{
	return x * x*x*x + x * x*x + x * x + x;
}

void func2_formula() {
	cout << "Func 2: x^4 + x^3 + x^2+ x" << endl;
}

double func3(double x)
{
	return cos(x);
}

void func3_formula() {
	cout << "Func 3: cos(x)" << endl;
}

double func4(double x)
{
	return x*x*x+cos(x);
}

void func4_formula() {
	cout << "Func 4: x^3+cos(x)" << endl;
}



//a - integration start, b-integration end, n- no of intervals
void RiemannSum(double a, double b, double n) 
{
	func4_formula();
	cout << "Integration between" << a << " and " << b << ", subintervals no: "<< n << endl;
	double rectangle_area = 0;
	double trapezoid_area = 0;
	double simpson_area = 0;
	double simpson_area_one_interval = 0;
	double monte_carlo_area = 0;
	double gaussian_area = 0;
	double gaussian_area_one_interval = 0;
	double gaussian_area_4points = 0;

	double width = (b - a) / n;

	//gaussian quadrature rule (2 nodes) variables START
	double x1 = -sqrt(3) / 3;
	double x2 = -x1;
	double A1 = 1;
	double A2 = 1;

	double t1_one_interval = (a + b) / 2 + x1 * (b - a) / 2;
	double t2_one_interval = (a + b) / 2 + x2 * (b - a) / 2;
	//gaussian quadrature rule (2nodes) variables END

	//gaussian quadrature rule (4 points) variables START
	//points:
	double d1 = -(1.0 / 35)*sqrt(525 + 70 * sqrt(30));
	double d2 = -(1.0 / 35)*sqrt(525 - 70 * sqrt(30));
	double d3 = (1.0 / 35)*sqrt(525 - 70 * sqrt(30));
	double d4 = (1.0/ 35)*sqrt(525 + 70 * sqrt(30));
	//weights:
	double B1 = (1.0 / 36) * (18 - sqrt(30));
	double B2 = (1.0 / 36)*(18 + sqrt(30));
	double B3 = (1.0 / 36)*(18 + sqrt(30));
	double B4 = (1.0 / 36)*(18 - sqrt(30));
	//gaussian quadrature rule (4 points) variables END


	//monte carlo pseudorandom numbers.
	double r1, r2, r3, f_r_avg= 0;

	for (int i = 0; i < n; i++) {
		rectangle_area += width * func4(a + i * width);
		trapezoid_area += width * (func4(a + i * width) + func4(a + (i+1)* width)) / 2;

		//simpson rule
		simpson_area += (width) / 6 * (func4(a + i * width) + 4 * func4((2*a+(2*i + 1)*width) / 2) + func4(a + (i + 1)*width)) ;

		//monte carlo rule
		r1 = width * ((double)rand() / (double)RAND_MAX) + a + i * width;
		r2 = width * ((double)rand() / (double)RAND_MAX) + a + i * width;
		r3 = width * ((double)rand() / (double)RAND_MAX) + a + i * width;

		f_r_avg = (func4(r1) + func4(r2) + func4(r3)) / 3;
		monte_carlo_area += width * f_r_avg;

		//2 points
		double t1 = (2 * a + (2 * i + 1)*width) / 2 + x1 * (width) / 2;
		double t2 = (2 * a + (2 * i + 1)*width) / 2 + x2 * (width) / 2;
		gaussian_area += width/2 * (func4(t1)+func4(t2));

		//4 points
		double p1 = (2 * a + (2 * i + 1)*width) / 2 + d1 * (width) / 2;
		double p2 = (2 * a + (2 * i + 1)*width) / 2 + d2 * (width) / 2;
		double p3 = (2 * a + (2 * i + 1)*width) / 2 + d3 * (width) / 2;
		double p4 = (2 * a + (2 * i + 1)*width) / 2 + d4 * (width) / 2;
		gaussian_area_4points += width / 2 * (func4(p1)*B1 + func4(p2)*B2 + func4(p3)*B3 + func4(p4)*B4);



	}
	simpson_area_one_interval = (b - a) / 6 * (func4(a) + 4 * func4((a + b) / 2) + func4(b));
	gaussian_area_one_interval = (b - a) / 2 * (func4(t1_one_interval) + func4(t2_one_interval));


	//Rectangular Rule
	cout << "Rectangular rule area=" << rectangle_area << endl;
	cout << "Trapezoidal rule area=" << trapezoid_area << endl;
	cout << "Simpson rule area(one interval only)=" << simpson_area_one_interval << endl;
	cout << "Simpson rule area=" << simpson_area << endl;
	cout << "Monte Carlo rule area=" << monte_carlo_area << endl;
	cout << "Gaussian quadrature rule area(one interval only)(2 points)=" << gaussian_area_one_interval << endl;
	cout << "Gaussian quadrature rule area(2 points)=" << gaussian_area << endl;
	cout << "Gaussian quadrature rule area(4 points)=" << gaussian_area_4points << endl;
	//Trapezoidal Rule
}