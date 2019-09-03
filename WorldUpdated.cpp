
#include <iostream>
#include <string>
#include<stdlib.h>
#include<time.h>
#include<fstream>

using namespace std;


struct pais {
	string Name[5];
	string Capital[5];
	int Population[5];
	int AgeAvg[5];
};

int main() {

	struct pais Continent[5];
	bool FullData = false;
	int opc, opc2, opc3;

Menu:
	if (FullData == false)
	{
		cout << "Selecciona la accion que deseas realizar:" << endl << endl;
		cout << "1. Ingresar datos" << endl << endl;
		cout << "Opcion seleccionada: ";

		cin >> opc;
	}
	else if (FullData == true)
	{
		cout << "Selecciona la accion que deseas realizar:" << endl << endl;
		cout << "1. Ingresar datos" << endl;
		cout << "2. Calcular poblacion de un continente" << endl;
		cout << "3. Encontar capital con mayor poblacion" << endl;
		cout << "4. Calcular el promedio de edad mundial" << endl << endl;
		cout << "Opcion seleccionada: ";

		cin >> opc;
	}


	if (opc == 1) {
		for (int i = 0; i <= 4; i++) {
			for (int j = 0; j <= 4; j++) {
				cout << "Ingresa el nombre del pais " << j + 1 << " del continente " << i + 1 << endl;
				cin >> Continent[i].Name[j];

				cout << "Ingresa la capital del pais " << j + 1 << " del continente " << i + 1 << endl;
				cin >> Continent[i].Capital[j];

				cout << "Ingresa el numero de habitantes del pais " << j + 1 << " del continente " << i + 1 << endl;
				cin >> Continent[i].Population[j];

				cout << "Ingresa la edad promedio de los habitantes del pais " << j + 1 << " del continente " << i + 1 << endl;
				cin >> Continent[i].AgeAvg[j];
			}
		}
		FullData = true;
		system("CLS");
		goto Menu;
	}

	else if (opc == 2) {
		cout << "Selecciona el continente para calcular la poblacion total:" << endl << endl;
		cout << "1. Continente 1" << endl;
		cout << "2. Continente 2" << endl;
		cout << "3. Continente 3" << endl;
		cout << "4. Continente 4" << endl;
		cout << "5. Continente 5" << endl << endl;
		cout << "Opcion seleccionada: ";

		cin >> opc2;

		int PopTot = 0;

		if (opc2 == 1)
		{
			for (int i = 0; i <= 4; i++) {
				PopTot = PopTot + Continent[opc2 - 1].Population[i];
			}

		}
		else if (opc2 == 2)
		{
			for (int i = 0; i <= 4; i++) {
				PopTot = PopTot + Continent[opc2 - 1].Population[i];
			}
		}
		else if (opc2 == 3)
		{
			for (int i = 0; i <= 4; i++) {
				PopTot = PopTot + Continent[opc2 - 1].Population[i];
			}
		}
		else if (opc2 == 4)
		{
			for (int i = 0; i <= 4; i++) {
				PopTot = PopTot + Continent[opc2 - 1].Population[i];
			}
		}
		else if (opc2 == 5)
		{
			for (int i = 0; i <= 4; i++) {
				PopTot = PopTot + Continent[opc2 - 1].Population[i];
			}
		}

		cout << "La poblacion total del continente " << opc2 << " es: " << PopTot << " habitantes";
	}
	else if (opc == 3)

	{
		int MaxPop;
		int ii = 0, jj = 0;
		MaxPop = Continent[0].Population[0];
		for (int i = 0; i <= 4; i++) {
			for (int j = 0; j <= 4; j++) {
				if (Continent[i].Population[j] > MaxPop) {
					MaxPop = Continent[i].Population[j];
					ii = i;
					jj = j;
				}

			}
		}
		cout << "La capital con mayor poblacion es: " << Continent[ii].Capital[jj] << " con " << MaxPop << " habitantes" << endl;
	}
	else if (opc == 4)
	{
		int sumedad = 0;

		double AgeAvg;
		for (int i = 0; i <= 4; i++) {
			for (int j = 0; j <= 4; j++) {
				sumedad = sumedad + Continent[i].AgeAvg[j];
			}

		}
		AgeAvg = sumedad / 25;
		cout << "La edad promedio mundial es " << AgeAvg << " años" << endl;
	}

	cout << endl << endl << "Seleccione la accion que desea realizar:" << endl << endl;
	cout << "1. Regresar al menu principal" << endl;
	cout << "2. Salir" << endl << endl;
	cout << "Opcion seleccionada: ";
	cin >> opc3;

	if (opc3 == 1) {
		system("CLS");
		goto Menu;
	}

	getchar();
	return 0;
}