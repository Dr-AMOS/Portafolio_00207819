// Act11.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int Queue[5];
int Front = -1, Back = -1, n = 5;

void QI(int val) {
	if ((Front == 0 && Back == n - 1) || (Front == Back + 1)) {
		cout << "Overflow" << endl;
		return;
	}
	if (Front == -1) {
		Front = 0;
		Back = 0;
	}
	else {
		if (Back == n - 1)
			Back = 0;
		else
			Back = Back + 1;
	}
	Queue[Back] = val;
}
void QE() {
	if (Front == -1) {
		cout << "Underflow" << endl;

		return;
	}
	cout << "Acaba de eliminar: " << Queue[Front] << endl;

	if (Front == Back) {
		Front = -1;
		Back = -1;
	}
	else {
		if (Front == n - 1)
			Front = 0;
		else
			Front = Front + 1;
	}
}
void QS() {
	int f = Front, r = Back;
	if (Front == -1) {
		cout << "La cola esta vacia" << endl;
		return;
	}
	cout << "La cola contiene a: " << endl;
	if (f <= r) {
		while (f <= r) {
			cout << Queue[f] << " ";
			f++;
		}
	}
	else {
		while (f <= n - 1) {
			cout << Queue[f] << " ";
			f++;
		}
		f = 0;
		while (f <= r) {
			cout << Queue[f] << " ";
			f++;
		}
	}
	cout << endl;
}
int main() {

	int Character, Value;
	cout << "Presione 1 para - Insertar un elemento" << endl;
	cout << "Presione 2 para - Borrar un elemento" << endl;
	cout << "Presione 3 para - Mostrar Cola" << endl;
	cout << "Presione 4 para - Salir" << endl;

	do {
		cout << "Ingrese su opcion: " << endl;
		cin >> Character;
		switch (Character) {
		case 1:
			cout << "Numero a insertar: " << endl;
			cin >> Value;
			QI(Value);
			break;

		case 2:
			QE();
			break;

		case 3:
			QS();
			break;

		case 4:
			cout << "Salir" << endl;
			break;

		default: cout << "Ingrese una opcion valida" << endl;

		}
	}

	while (Character != 4);
	return 0;
}
