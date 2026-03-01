#include <iostream>
#include "bisection.h"
using namespace std;

int main()
{	
	//Variabls
	int option;
	
	//Menu Selection
	cout << "Please select a function to test:" << endl;
    cout << endl;
    cout << "1. f(x) = sin(x) + 0.5*sin(3x) + 0.25*sin(5x)" << endl;
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
	bisectionM(0, 180, 1, 0.1, option); // bisectionM(xi, xf, step, tol, option)
    return 0;
}