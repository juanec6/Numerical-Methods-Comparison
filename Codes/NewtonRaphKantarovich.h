#ifndef NEWTONRAPHSON_H
#define NEWTONRAPHSON_H

#include <cmath>
#include <string>
#include <vector>
#include <iostream>  // cout
#include <iomanip>   // setprecision
#include <cstdlib>
#include <fstream>
#include <algorithm>

#include "Functions.h" // Here are the f(x, opcion) value. 

double newtonRaphson(double xi, double xf, double step, double tol, int option)
{
    double x0, xn, xn1, dfx;
    int iter, maxIter = 150;
    double toleranciaRaiz = std::max(tol * 2, 1e-10);   // tolerancia para comparar raíces repetidas

    std::vector<double> raices, xValores, yValores;
	
	// Comienzo de iteraciones para encontrar múltiples raices usando el método de Newton-Raphson
	// usando la condición de Kantorovich
    for(double i = xi; i <= xf; i = i + step) 
    {
        x0 = i;

        // Condición de Kantorovich
        if(std::abs(f(x0, option) * ddf(x0, option)) < std::pow(std::abs(df(x0, option)), 2))
        {
            xn = x0;
            iter = 0;

            do
            {
                dfx = df(xn, option);
                if(fabs(dfx) < 1e-12) break; // Evita división por cero

                xn1 = xn - f(xn, option) / dfx; // Newton–Raphson

                // Criterio de parada
                if(std::fabs(xn1 - xn) <= tol) break;
                xn = xn1;
                iter++;
                if(iter > maxIter) break;
                
            } while(std::fabs(f(xn, option)) > tol);
            
            // Verificar que realmente es una raíz válida
            if(std::fabs(f(xn, option)) <= tol)
            {
                // Verificar si la raíz ya fue encontrada
                bool esNueva = true;
                for(int j = 0; j < raices.size(); j++)
                {
                    if(std::fabs(xn - raices[j]) < toleranciaRaiz)
                    {
                        esNueva = false;
                        break;
                    }
                }
                
                // Solo agregar si es una raíz nueva
                if(esNueva)
                {
                    raices.push_back(xn);
                }
            }
    	}
    } // Fin del método

    // Ordenar las raíces de menor a mayor
    std::sort(raices.begin(), raices.end());
    for(int i = 0; i < raices.size(); i++)
    {
    	// al parecer este código diverge en xf, entonces se ignorarán esos puntos
        std::cout << "Raíz " << i + 1 << ": " << raices[i] << std::endl;
    }

    return 0;
}

#endif
