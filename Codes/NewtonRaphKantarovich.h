#ifndef NEWTONRAPHSON_H
#define NEWTONRAPHSON_H
#include <cmath>
#include <string>
#include <vector>
#include <iostream>  // Added for cout
#include <iomanip>  // Para setprecision
#include <cstdlib>
#include <fstream>
#include <fstream>
#include <algorithm>
#include <sstream>
#include <thread>

#include "Functions.h" // Here are the f(x, opcion) value. 

using namespace std;

double newtonRaphson(double xi, double xf, double step, double tol, int option)
{
	double x0, xn, xn1;
	int iter, maxIter = 150;
	
    for(double i = xi; i <= xf; i = i + step) 
    {
    	x0 = i;
        if(abs(f(x0, option) * ddf(x0, option)) < pow(abs(df(x0, option)), 2)) // Condición de Kantarovich
        {
        	xn = x0;
		}
    }
    return 0; 
}
#endif