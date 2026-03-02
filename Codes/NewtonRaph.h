#ifndef NEWTONRAPHSON_H
#define NEWTONRAPHSON_H
#include <cmath>
#include <string>
#include <vector>
#include "functions.h" // Here are the f(x, opcion) value. 
using namespace std;

struct NewtonRaphsonResult // a structure is created because the function returns different kind of variables
{
	vector<double> roots;
    int totalIterations;
    double absoluteError; // |x* - x_approx|
    double relativeError; // |x* - x_approx| / |x*|
    double residual; 		// |f(x_approx)|
};

NewtonRaphsonResult newtonRaphson(double xi, double xf, double step, double tol, int option)
{
	// Varabiales for iterations
	double x0; // initial condition.
	double xn; // previos x
	double xn1; // next x (n+1) 
	
	// Function to evaluate and its derivative
	double fx;
	double dfx;
	
	// Convergence Check
	int numIterations; // Number of iterations to reach tolerance.
	double convergenceOrder; // THIS WILL HANDLED LATER.
	double convergenceRate; // THIS WILL BE ALSO HANDLED LATER.
	
	// iteration things
	int maxIter = 100;
	double rootTol = 1e-10;
	
	// results to return
	NewtonRaphsonResult result;
	
	for(double i = xi; i<=xf; i += step)
	{
		xn = i; // This makes the initial condition to be the start of the interval.
		numIterations = 0;
		do
		{
			// Checks for f = 0
			dfx = df(xn, option);
			if(dfx == 0) break;
			xn1 = xn - f(xn, option)/dfx;
			xn = xn1;
			numIterations++;
			// Stop Criteria
			if(numIterations > maxIter) break;
		} while(fabs(f(xn, option)) > tol);
	}
	
 	 // If converges, it is necessary to check for duplicates
	if(fabs(f(xn, option)) <= tol) 
	{
	    bool repeatedRoot = false;
	    
	    // Verify if this root already exists 
	    for(int j = 0; j < result.roots.size(); j++) 
		{
	        if(fabs(result.roots[j] - xn) <= rootTol)
			{
	            repeatedRoot = true;
	            break;
	        }
	    }
	    
	    // If there is not a repeated root, is pushed into the vector
	    if(!repeatedRoot) 
		{
	        result.roots.push_back(xn);
	        result.totalIterations = numIterations;
	        result.absoluteError = fabs(xn1 - xn);
	        if(xn != 0) 
			{
			    result.relativeError = fabs(xn1 - xn) / fabs(xn);
			} else {
			    result.relativeError = 0;
			}
	    }
	}
	return result;
}

#endif
