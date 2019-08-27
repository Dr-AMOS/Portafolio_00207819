#include <iostream>
using namespace std;

int main()
{
	int valor = 5;
	int *puntero = &valor;
	
	int **doble = &puntero;
	
	cout << "valor: " << valor << endl;
	cout << "Valor mediante puntero: " <<   *puntero << endl;
	cout << "valor mediante puntero doble: " << **doble << endl;
	
	return 0;
}