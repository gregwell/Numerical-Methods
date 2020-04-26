#include "pch.h"
#include <iostream>
#include <fstream>
#include "Bisection.h"


using namespace std;

void f1()
{

	double a, b;
	double precision;

	cout << "f1(x) = cos(x^3 - 3x)\n";

	cout << "Insert interval start:";
	cin >> a;
	cout << "Insert interval end: ";
	cin >> b;
	cout << "Insert precision: (for example 0.01): ";
	cin >> precision;

	double y1 = cos(a * a * a - 3 * a);
	double y2 = cos(b * b * b - 3 * b);

	if (y1*y2 >= 0) {
		cout << " Wrong interval" << endl;
		return;
	}

	double x = (a + b) / 2;
	double y = cos(x * x * x - 3 * x);

	cout << "f1(" << a << ") = " << y1 << endl;
	cout << "f1(" << b << ") = " << y2 << endl;
	cout << "x = " << x << endl;
	cout << "f1(" << x << ") = " << y << endl;

	int i = 1;
	while ((b - a) >= precision)
	{
		if (y > 0)
			a = (a + b) / 2;

		else
			b = (a + b) / 2;

		cout << "\nIteration:" << i++ <<": interval: <" << a << "," << b << ">, interval length: " << b - a << endl << endl;

		x = (a + b) / 2;
		y = cos(x * x * x - 3 * x);
		y1 = cos(a * a * a - 3 * a);
		y2 = cos(b * b * b - 3 * b);

		cout << "f1(" << a << ") = " << y1 << endl;
		cout << "f1(" << b << ") = " << y2 << endl;
		cout << "x = " << x << endl;
		cout << "f1(" << x << ") = " << y << endl;
	}

	cout << "\n\nValue of f1 with declared precision "<<precision<<": f1(" << x << ") = " << y << endl;
}




void f2()
{

	double a, b;
	double precision;

	cout << "f1(x) = log(x^2 + 2x)\n";

	cout << "Insert interval start:";
	cin >> a;
	cout << "Insert interval end: ";
	cin >> b;
	cout << "Insert precision: (for example 0.01): ";
	cin >> precision;

	double y1 = log(a * a + 2 * a);
	double y2 = log(b * b + 2 * b);

	if (y1*y2 >= 0) {
		cout << " Wrong interval" << endl;
		return;
	}

	double x = (a + b) / 2;
	double y = log(x * x + 2 * x);

	cout << "f1(" << a << ") = " << y1 << endl;
	cout << "f1(" << b << ") = " << y2 << endl;
	cout << "x = " << x << endl;
	cout << "f1(" << x << ") = " << y << endl;

	int i = 1;
	while ((b - a) >= precision)
	{
		if (y < 0)
			a = (a + b) / 2;

		else
			b = (a + b) / 2;

		cout << "\nIteration:" << i++ << ": interval: <" << a << "," << b << ">, interval length: " << b - a << endl << endl;

		x = (a + b) / 2;
		y = log(x * x + 2 * x);
		y1 = log(a * a + 2 * a);
		y2 = log(b * b + 2 * b);

		cout << "f1(" << a << ") = " << y1 << endl;
		cout << "f1(" << b << ") = " << y2 << endl;
		cout << "x = " << x << endl;
		cout << "f1(" << x << ") = " << y << endl;
	}

	cout << "\n\nValue of f1 with declared precision " << precision << ": f1(" << x << ") = " << y << endl;
}


void f3()
{

	double a, b;
	double precision;

	cout << "f3(x) = log(x^2 + 2x)\n";

	cout << "Insert interval start:";
	cin >> a;
	cout << "Insert interval end: ";
	cin >> b;
	cout << "Insert precision: (for example 0.01): ";
	cin >> precision;

	double y1 = log(a * a *a);
	double y2 = log(b * b *b);



	double x = (a + b) / 2;
	double y = log(x * x * x);

	cout << "f1(" << a << ") = " << y1 << endl;
	cout << "f1(" << b << ") = " << y2 << endl;
	cout << "x = " << x << endl;
	cout << "f1(" << x << ") = " << y << endl;

	if (y1*y2 >= 0) {
		cout << " Wrong interval" << endl;
		return;
	}

	int i = 1;
	while ((b - a) >= precision)
	{
		if (y < 0)
			a = (a + b) / 2;

		else
			b = (a + b) / 2;

		cout << "\nIteration:" << i++ << ": interval: <" << a << "," << b << ">, interval length: " << b - a << endl << endl;

		x = (a + b) / 2;
		y = log(x * x * x);
		y1 = log(a * a * a);
		y2 = log(b * b * b);

		cout << "f1(" << a << ") = " << y1 << endl;
		cout << "f1(" << b << ") = " << y2 << endl;
		cout << "x = " << x << endl;
		cout << "f1(" << x << ") = " << y << endl;
	}

	cout << "\n\nValue of f1 with declared precision " << precision << ": f1(" << x << ") = " << y << endl;
}

