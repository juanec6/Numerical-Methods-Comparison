#ifndef REGULAFALSI_H
#define REGULAFALSI_H
#include <cmath>
#include <string>
#include <vector>
#include "Functions.h" // Here are the f(x, opcion) value. 
using namespace std;

double regulaFalsiMethod(double xi, double xf, double step, double tol, int option)
{
	// Variables necesarias.
	double xr, x0, x1;
	int iter = 0, maxIter = 150;
	vector<double> raices, xValues, yValues;
	
	// Regula falsi implementation
	for(double i = xi; i <=xf; i = i + step)
	{
		x0 = i;
		x1 = i + step;
		if(f(x0, option)*f(x1, option) < 0)
		{
			do
			{
				xr = x1 - (f(x1, option)*(x1 - x0))/(f(x1, option) - f(x0, option));
				if(f(x0, option)*f(xr, option) < 0)
				{
					x1 = xr;
				} else {
					x0 = xr;
				}
				iter++;
			} while(abs(x1 - x0) > tol && iter < maxIter);
			
			// Se redondea la raíz a cero si:
			if(abs(xr) < 1e-10)
			{
				xr = 0;
			}
			raices.push_back(xr);
		}
	}
	
	// Imprime las raíces en main
	for(int i = 0; i < raices.size(); i++)
	{
		std:cout << "Raíz " << i + 1 << ": " << raices[i] << std::endl;
	}
	return 0;
}

#endif
