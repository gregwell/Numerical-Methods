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
	cout << "Func 3: x^3+cos(x)" << endl;
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
	

	double width = (b - a) / n;

	//double random = 3 + (std::rand() % (63 - 25 + 1))

	for (int i = 0; i < n; i++) {
		rectangle_area += width * func4(a + i * width);
		trapezoid_area += width * (func4(a + i * width) + func4(a + i * width+width)) / 2;
		simpson_area += (a+(i+1)*width - (a+i*width)) / 6 * (func4(a + i * width) + 4 * func4((a + i * width + a + (i + 1)*width) / 2) + func4(a + (i + 1)*width));
		
	}
	simpson_area_one_interval = (b - a) / 6 * (func4(a) + 4 * func4((a + b) / 2) + func4(b));

	

	//Rectangular Rule
	cout << "Rectangular rule area=" << rectangle_area << endl;
	cout << "Trapezoidal rule area=" << trapezoid_area << endl;
	cout << "Simpson rule area(one interval only)=" << simpson_area_one_interval << endl;
	cout << "Simpson rule area=" << simpson_area << endl;
	//Trapezoidal Rule
}