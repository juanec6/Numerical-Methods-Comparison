// Functions to display, to evaluate, first and second derivates.
#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <iostream>
#include <cmath>
#include <string>
using namespace std;

// Strings to display in console.
string function_str(int option)
{
	switch(option)
	{
		case 1: return "f(x) = sin(x) + 0.5*sin(3x) + 0.25*sin(5x)";
	    case 2: return "f(x) = sin(50x)*exp(-x^2/100)";
	    case 3: return "f(x) = sin(x) + sin(3x)";
	    case 4: return "f(x) = sin(x)*cos(x)";
	    case 5: return "f(x) = sin(x)*(x-2)*(x+3)";
	    case 6: return "f(x) = cos(x) - exp(-x/10)";
	    case 7: return "f(x) = cos(x)";
	    default: return "Function not defined";
	}
}

// Actual functions to be evaluated
double f(double x, int option)
{
	switch(option)
	{
		case 1: return sin(x) + 0.5*sin(3.0*x) + 0.25*sin(5.0*x);
        case 2: return sin(50.0*x)*exp(-(pow(x, 2))/100.00);
        case 3: return sin(x) + sin(3.0*x);
        case 4: return sin(x)*cos(x);
        case 5: return sin(x)*(x-2.0)*(x+3.0);
        case 6: return cos(x) - exp(-x/10.0);
        case 7: return cos(x);
        default: return 0;
	}
}

// For some numerical methods we need first and second derivatives
// First derivative of f
double df(double x, int option)
{
	switch(option)
	{
		case 1: return cos(x) + 1.5*cos(3.0*x) + 1.25*cos(5.0*x);
        case 2: return exp(-(x*x)/100.0)*(50.0*cos(x*50.0) - 0.02*x*sin(50.0*x));
        case 3: return cos(x) + 3.0*cos(3.0*x);
        case 4: return pow(cos(x), 2) - pow(sin(x), 2);
        case 5: return (-6.0 + x + pow(x, 2))*cos(x) + (1.0 + 2.0*x)*sin(x);
        case 6: return exp(-x/10.0)/10.0 - sin(x);
        case 7: return -sin(x);
        default: return 0;	
	}
}

//second derivative of f
double ddf(double x, int option)
{
	switch(option)
	{
		case 1: return -sin(x) - 4.5*sin(3.0*x) - 6.25*sin(5.0*x);
	    case 2: return ( exp(-pow(x, 2) / 100.0) *
	                   ( (pow(x, 2) - 6250050.0) * sin(50.0*x) - 5000.0*x*cos(50.0*x) )
	                   ) / 2500.0;
	    case 3: return -sin(x) - 9.0*sin(3.0*x);
	    case 4: return -4.0*cos(x)*sin(x);
	    case 5: return ((-pow(x, 2) - x + 8.0)*sin(x)) + ((4.0*x + 2.0)*cos(x));
	    case 6: return -cos(x) - (exp(-x/10.0)/100.0);
	    case 7: return -cos(x);
	    default: return 0;	
	}
}

#endif