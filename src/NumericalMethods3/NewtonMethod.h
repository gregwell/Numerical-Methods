#pragma once
#include <iostream>

using namespace std;

void findRoot(double x0, double precision);

//newton raphson
void findRootNR(int it);

double f(double x);
double fd(double x);