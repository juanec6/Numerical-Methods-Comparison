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
    double toleranciaRaiz = 1e-10;   // tolerancia para comparar raíces repetidas

    std::vector<double> raices, xValores, yValores;
    std::vector<double> raicesD;

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
                if(dfx == 0) break;

                xn1 = xn - f(xn, option) / dfx; // Newton–Raphson

                // Criterio de parada
                if(std::fabs(xn1 - xn) <= tol) break;

                xn = xn1;
                iter++;

                if(iter > maxIter) break;

            } while(std::fabs(f(xn, option)) > tol);
        }
        raices.push_back(xn);
    } // Fin del método

    // Limpieza de duplicados
    for(int i = 0; i < raices.size(); i++)
    {
        for(int j = i + 1; j < raices.size();)
        {
            if(raices[j] == raices[i])
            {
                raices.erase(raices.begin() + j);
            }
            else
            {
                j++;
            }
        }
    }

    std::cout << "Raíces encontradas:" << std::endl;
    for(int i = 0; i < raices.size(); i++)
    {
        std::cout << "Raíz " << i << ": " << raices[i] << std::endl;
    }

    return 0;
}

#endif
