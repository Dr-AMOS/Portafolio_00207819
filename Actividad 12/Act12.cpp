// Act12.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;

struct ORDR {
	int FQ;
	int REV;
	int CHSS;
	string DGH;
};
typedef struct ORDR Order;

Order QueueOrder() {
	Order p;
	cout << "Cuantas pupusas de frijol con queso?  "; cin >> p.FQ;
	cout << "Cuantas pupusas revueltas? ";   cin >> p.REV;
	cout << "Cuentas pupusas de queso? "; cin >> p.CHSS;
	cout << "Que tipo de maza: Arroz o maiz? "; cin >> p.DGH;
	return p;
}

void ShowOrder(Order p) {
	cout << "Frijol con queso: " << p.FQ << endl;
	cout << "Revueltas: " << p.REV << endl;
	cout << "Queso: " << p.CHSS << endl;
	cout << "Masa: " << p.DGH << endl;
}

vector<Order> lista;

void AddOrder() {
	Order p = QueueOrder();
	bool continuar = true;
	do {
		int opcion = 0;
		cout << "\t1) Al principio\n\t2) Al final"
			<< "\n\tOpcion elegida: ";
		cin >> opcion;
		switch (opcion) {
		case 1: lista.insert(lista.begin(), p);
			continuar = false;
			break;
		case 2: lista.push_back(p);
			continuar = false;
			break;
		default: cout << "Opcion erronea!" << endl;
			break;
		}
	} while (continuar);
}

void mostrarLista() {
	for (int i = 0; i < lista.size(); i++)
		ShowOrder(lista[i]);
}

void menu() {
	cout << " 1. Agregar orden                          " << endl;
	cout << " 2. Mostrar orden                          " << endl;;
	cout << " 5. Salir                                 " << endl;

	cout << "\n Ingrese una opcion: ";
}

int main() {

	int op;

	do
	{
		menu();  cin >> op;

		switch (op)
		{
		case 1:
			cout << "\n Agregando orden " << endl;
			AddOrder();
			break;


		case 2:

			cout << "\n\n Mostrar orden \n\n";
			mostrarLista();
			break;
		}

		cout << endl << endl;
		system("pause");  system("cls");

	} while (op != 3);


	return 0;
}