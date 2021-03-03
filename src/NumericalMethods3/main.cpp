#include "pch.h"
#include <iostream>
#include <cmath>
#include "DifferentialEquations.h"

using namespace std;


int main()
{
	// yp(xp) = yp ~ warunek poczatkowy // h ~krok obliczen // xk ~x koncowe
	//kolejnosc: xp,yp,h,xk
	solveDE(0, 0.1, 3, 0.3);

	system("pause");
	return 0;
}

