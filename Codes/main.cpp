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
#include "Bisection.h"
#include "NewtonRaphKantarovich.h"
#include "Secant.h"
#include "Functions.h"

using namespace std;

// The methods used in this program are created in libraries, the parameters of each function used in the library are numericalMethod(xi, xf, step, tol, option)
int main()
{	system("chcp 65001 > nul");
	cout << "¡¡¡ DISCLAIMER: ESTE PROGRAMA SOLO SIRVE CON FUNCIONES CONTINUAS!!!" << endl;
	cout << endl;
	cout << "----- COMPARACIÓN DE MÉTODOS NUMÉRICOS SIMPLES CON MÉTODOS NUMÉRICOS HÍBRIDOS -----" << endl;
	cout << endl;
	cout << "Este programa reune la comparación de los siguientes mnétodos numéricos, utilizando algoritmos que permite a su vez," << endl;
	cout << "encontrar múltiples raíces, y métricas:" << endl;
	cout << endl;
	cout << "MÉTODOS NUMÉRICOS CLÁSICOS" << endl;
	cout << "	- Método de Newton-Raphson usando la condición de Kantarovich para encontrar múltiples raíces." << endl;
	cout << "	- Método de Bisección para múltiples raíces." << endl;
	cout << "	- Método de la Secante para múltiples raíces." << endl;
	cout << "	- Método Regula Falsi para múltiples raíces." << endl;
	cout << endl;
	cout << "MÉTODOS NUMÉRICOS HÍBRIDOS" << endl;
	cout << "	- Método híbrido Newton-Raphson/Bisección usando la condición de Kantarovich para múltiples raíces." << endl;
	cout << "	- Método híbrido de Bisección/Secante para múltiples raíces." << endl;
	cout << "	- Método híbrido de la Secante/Regula Falsi para múltiples raíces." << endl;
	cout << "	- Método híbrido de Regula Falsi/Newton-Rapshon con la condición de Kantarovich para múltiples raíces." << endl;
	cout << endl;
	cout << "La comparación se realizará obteniendo las siguientes métricas:" <<endl;
	cout << "	- Iteraciones." << endl;
	cout << "	- Error Absoluto." << endl;
	cout << "	- Error Relativo." << endl;
	cout << "	- Evaluaciones en f(x)." << endl;
	cout << "	- Evaluaciones en df(x)." << endl;
	cout << "	- Evaluaciones en ddf(x)." << endl;
	cout << "	- CPU Time." << endl;
	cout << "	- Raíces Encontradas." << endl;
	cout << "	- Raíces Esperadas." << endl;
	cout << "	- Raíces duplicadas." << endl;
	cout << "	- Reason for Stopping." << endl;
	cout << endl;
	cout << "Cada método está guardado dentro de una librería, las cuales son incluidas dentro de este programa." << endl;
	cout << endl;
	
	//Variabls
	int option;
	double xi, xf, step, tol;
	
	//Menu Selection
	cout << "Por favor ingrese una función para evaluar:" << endl;
    cout << endl;
    cout << "1. f(x) = sin(x) + 0.5*sin(3x) + 0.25*sin(5x)"  << endl;
    cout << "2. f(x) = sin(50x)*exp(-x^2/100)"               << endl;
    cout << "3. f(x) = sin(x) + sin(3x)"                     << endl;
    cout << "4. f(x) = sin(x)*cos(x)"                        << endl;
    cout << "5. f(x) = sin(x)*(x-2)*(x+3)"                   << endl;
    cout << "6. f(x) = cos(x) - exp(-x/10)"                  << endl;
    cout << "7. f(x) = cos(x)"                               << endl;
    cout << endl;
    cout << "Ingrese un número del 1 al 7: ";
	cin >> option;
	cout << "Función elegida: " << function_str(option) << endl;
	cout << endl;
	cout << endl;
	
	//Parameters input
	cout << " -- INGRESO DE PARÁMETROS -- " << endl;
	cout << "Ingrese xi (valor inicial de x para barrido en f(x)): ";
	cin >> xi;
	cout << "Ingrese xf (valor final de x para barrido en f(x)): ";
	cin >> xf;
	cout << "Ingrese el paso/step (discretización del dominio): ";
	cin >> step;
	cout << "Ingrese la tolerancia que necesita para la comparación: ";
	cin >> tol;
	if(tol > step || tol == step)
	{
		cout << endl;
		cout << "¡La tolerancia no puede ser menor ni igual que el step!"<<endl;
		cout << "Ingrese la tolerancia que necesita para la comparación: ";
		cin >> tol;
	}
	cout << fixed << setprecision(6);
	// NEWTON RAPHSON
	cout << endl;
	cout << "Raices encontradas para Newton Raphson (temporal)" << endl;
	cout << endl;
	newtonRaphson(xi, xf, step, tol, option);
	cout << endl;
	// BISECTION
	cout << endl;
	cout << "Raices encontradas para el Método de Bisección (temporal)" << endl;
	cout << endl;
	bisectionMethod(xi, xf, step, tol, option);
	cout << endl;
	// SECANT
	cout << endl;
	cout << "Raices encontradas para el Método de la Secante (temporal)" << endl;
	cout << endl;
	secantMethod(xi, xf, step, tol, option);
	cout << endl;
	cout << "Press enter to finish";
	cin.ignore(); // Limpia el buffer del último Enter
	cin.get();    // Espera un Enter


    return 0;
}
