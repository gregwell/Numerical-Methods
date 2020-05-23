#include "pch.h"
#include <iostream>
#include <cmath>
#include "DifferentialEquations.h"

using namespace std;


int main()
{
	// y(xp) = yp ~ warunek poczatkowy // h ~krok obliczen // xk ~x koncowe
	solveDE(0, 0.1, 3, 0.3);

	system("pause");
	return 0;
}

