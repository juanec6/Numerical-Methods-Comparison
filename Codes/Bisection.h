#ifndef BISECTION_H
#define BISECTION_H
#include <cmath>
#include <string>
#include <vector>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <fstream>
#include <windows.h>
#include <algorithm>
#include "Functions.h" // Here are the f(x, opcion) value. 

double bisectionMethod(double xi, double xf, double step, double tol, int option)
{
	double a, b, m; // m es el valor medio
	int iter, maxIter = 150; // para la condición de parada 
	std::vector<double> raices, xValores, yValores;
	
	// Búsqueda de raíces por intervalos
    for(double i = xi; i <= xf; i = i + step)
    {
    	a = i;
    	b = i + step; // Esto es para verificar el siguiente valor de f
    	
    	//Se verifica la condición f(a)*f(b) < 0
    	if(f(a, option)*f(b, option) < 0)
    	{
    		do
    		{
    			m = (a+b)/2; // Valor medio entre a y b
    			
    			//Se verifica la condición f(a)*f(m) < 0
    			if(f(a, option)*f(m, option) < 0)
    			{
    				b = m;
				} else {
					a = m;
				}
			} while(std::fabs((b-a)/2) > tol);
			raices.push_back(m);
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
