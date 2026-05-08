#ifndef BISECTION_H
#define BISECTION_H
#include <cmath>
#include <string>
#include "functions.h" // Here are the f(x, opcion) value. 
using namespace std;

double bisectionMethod(double xi, double xf, double step, double tol, int option)
{
	for(int i = xi; i <= xf; i += step)
	{
		cout<<f(i, 1)<<endl;
	}
	cout<<tol;
	cout<<option;
	return 0;
}

#endif
