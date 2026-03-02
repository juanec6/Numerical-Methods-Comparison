#include <iostream>
#include <cmath>
#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <fstream>
#include <windows.h>
#include <algorithm>
#include <sstream>
#include <thread>
#include "bisection.h"
#include "NewtonRaph.h"

using namespace std;

// The methods used in this program are created in libraries, the parameters of each function used in the library are numericalMethod(xi, xf, step, tol, option)
int main()
{	system("chcp 65001 > nul");

	//Variabls
	int option;
	double xi, xf, step, tol;
	
	//Menu Selection
	cout << "Please select a function to test:" << endl;
    cout << endl;
    cout << "1. f(x) = sin(x) + 0.5*sin(3x) + 0.25*sin(5x)"  << endl;
    cout << "2. f(x) = sin(50x)*exp(-x^2/100)"               << endl;
    cout << "3. f(x) = sin(x) + sin(3x)"                     << endl;
    cout << "4. f(x) = sin(x)*cos(x)"                        << endl;
    cout << "5. f(x) = sin(x)*(x-2)*(x+3)"                   << endl;
    cout << "6. f(x) = cos(x) - exp(-x/10)"                  << endl;
    cout << "7. f(x) = cos(x)"                               << endl;
    cout << endl;
    cout << "(Enter a number from 1 to 7): ";
	cin >> option;
	cout << "Function chosen: " << function_str(option) << endl;
	
	//Results get from library NewtonRaph
	NewtonRaphsonResult res = newtonRaphson(-10, 10, 0.1, 0.01, 1);

	cout << "Roots found: " << res.roots.size() << endl;
	for(int i = 0; i < res.roots.size(); i++) {
	    cout << "  Root " << i+1 << ": " << res.roots[i] << endl;
	}
	cout << "Total iterations: " << res.totalIterations << endl;
	cout << "Absolute error:   " << res.absoluteError << endl;
	cout << "Relative error:   " << res.relativeError << endl;
	cout << "Residual:         " << res.residual << endl;
    return 0;
}
