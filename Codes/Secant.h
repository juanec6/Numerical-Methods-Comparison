#ifndef SECANT_H
#define SECANT_H
#include <cmath>
#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <fstream>
#include <windows.h>
#include <algorithm>
#include "Functions.h" // Here are the f(x, opcion) value. 

double secantMethod(double xi, double xf, double step, double tol, int option)
{
	double x0, x1, x2; // x2 es el nuevo valor
	int iter, maxIter = 150; // para la condición de parada 
	std::vector<double> raices, xValores, yValores;
	
	// Búsqueda de raíces por intervalos
	for(double i = xi; i <= xf; i = i + step)
	{
		x0 = i;
		x1 = i + step; // Segundo punto inicial
		
		// Se verifica la condición f(x0)*f(x1) < 0
		if(f(x0, option)*f(x1, option) < 0)
		{
			iter = 0;
			do
			{
				// Fórmula de la secante: x2 = x1 - f(x1)*(x1 - x0)/(f(x1) - f(x0))
				x2 = x1 - f(x1, option)*(x1 - x0)/(f(x1, option) - f(x0, option));
				
				// Actualización de valores para la siguiente iteración
				x0 = x1;
				x1 = x2;
				
				iter++;
			} while(std::fabs(f(x2, option)) > tol && iter < maxIter);
			
			raices.push_back(x2);
		}
	}
	
	// Imprime las raíces en main
	for(int i = 0; i < raices.size(); i++)
	{
		std::cout << "Raíz " << i + 1 << ": " << raices[i] << std::endl;
	}
	
	return 0;	
}
#endif
