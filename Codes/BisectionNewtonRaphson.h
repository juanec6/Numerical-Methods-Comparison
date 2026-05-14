#ifndef BISECTIONNEWTONRAPHSON_H
#define BISECTIONNEWTONRAPHSON_H
#include <cmath>
#include <string>
#include <cmath>
#include <string>
#include <vector>
#include <iostream>  // cout
#include <iomanip>   // setprecision
#include <cstdlib>
#include <fstream>
#include <algorithm>
#include "Functions.h" // Here are the f(x, opcion) value. 

double newtonBisection(double xi, double xf, double step, double tol, int option)
{
	double a, b, m, x0, xn, xn1, dfx; // Variables para ambos métodos
	int iter, maxIter = 150; // Condición de parada 
	std::vector<double> raices, xValores, yValores;
	
	// Busquedad de raíces por inervalos usando métodos híbridos
	/* Siento que el propósito de los métodos híbridos es que en cada en el primer método que empiece a iterar
	   tenga una tolerancia más alta que la del segundo método, el cual ya refinaría mucho más la raíz partiendo de condiciones iniciales más pulidas.
	   Mi problema acá es que solo tengo una tolerancia, la cuál será la misma para ambos métodos.	
	La clave es que el primer método solo es que necesita acercarse a la zona de convergencia del segundo método, no encontrar la raíz exacta.
	Factor fijo interno (10x) para la tolerancia de bisección
	*/
	
}

#endif
