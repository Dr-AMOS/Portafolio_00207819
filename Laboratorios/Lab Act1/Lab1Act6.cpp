// Lab1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;

string Invert(string* oracion, int tamano) {
	string Frase = *oracion;
	string Inverted = "";
	for (int i = tamano - 1; i >= 0; i--) {
		Inverted += Frase[i];
	}
	return Inverted;
}

int main() {
	string frase = "";

	cout << "Escriba un oracion: ";
	getline(cin, frase);
	int tamano = frase.length();

	cout << "Oracion invertida: " << Invert(&frase, tamano) << endl;

	return 0;
}
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
