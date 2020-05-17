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


//a - integration start, b-integration end, n- no of intervals
void RiemannSum(double a, double b, double n) 
{
	func1_formula();
	cout << "Integration between" << a << " and " << b << ", subintervals no: "<< n << endl;
	double rectangle_area = 0;
	double trapezoid_area = 0;
	double simpson_area = 0;
	

	double width = (b - a) / n;



	for (int i = 0; i < n; i++) {
		rectangle_area += width * func1(a + i * width);
		trapezoid_area += width * (func1(a + i * width) + func1(a + i * width+width)) / 2;
		
		//first interval
	//	a = 
	//	b = 
		simpson_area += (a + i * width + (i + 1)*width - a) / 6 * (func1(a + i * width) + 4 * func1((a + i * width + a + (i + 1)*width) / 2) + func1(a + (i + 1)*width));
		cout << "i= " << i << ",    value=" << simpson_area << ",     a=" << a + i * width << " ,    b=" << a + (i + 1)*width << ",     width= "<<width<<" ,   simpsonarea="<<simpson_area<< endl;



		//simpson_area += (b - a) / 6 * (func1(a) + 4 * func1((a + b) / 2) + func1(b));
		//simpson_area_OLD += (a+i*width+width - a+i*width) / 6 * (func1(a + i * width) + 4 * func1(a + i*width + width/2) + func1(a+i*width+width));
	}
	//simpson_area = (b - a) / 6 * (func1(a) + 4 * func1((a + b) / 2) + func1(b));

	//Rectangular Rule
	cout << "Rectangular rule area=" << rectangle_area << endl;
	cout << "Trapezoidal rule area=" << trapezoid_area << endl;
	cout << "Simpson rule area=" << simpson_area << endl;
	//Trapezoidal Rule
}