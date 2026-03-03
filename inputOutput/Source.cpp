#include <iostream>

//algo más de impresion y lectura
using namespace std;
//using std::cin, std::cout, std::endl, std::cerr;

int main()
{
	int entero;
	double real;
	char palabra[] = R"delim(aqui puedo poner texto delimitado incluso con )" o
cambiando de línea o	tab	u	lan		do)delim";
	//notese como se concatenan cosas diferentes
	cout << "Un texto:" << palabra << endl;
	//notese la ausencia del & propia de C
	cin >> entero;
	//en la extracción de un flujo tambien hay concatenación
	cin >> real >> palabra;
	cout << "Real: " << real << "\nEntero: " << entero << "\n";
	cerr << "Palabra:" << palabra;
}