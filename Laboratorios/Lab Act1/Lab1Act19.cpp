// Lab1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//ACT19

#include<iostream>

using namespace std;

struct Nums {
	int RealSum;
	int ComplexSum;
	int RealN1;
	int RealN2;
	int ComplexN1;
	int ComplexN2;
};

int main() {
	struct Nums Sum;

	cout << "Introduzca la parte real del numero: " << endl;
	cout << "Parte Real del primer numero:  ";
	cin >> Sum.RealN1;
	cout << "Parte Real del segundo numero:  ";
	cin >> Sum.RealN2;

	cout << "Introduzca la parte imaginaria " << endl;
	cout << "Parte Imaginaria del primer numero:  ";
	cin >> Sum.ComplexN1;
	cout << "Parte imaginaria del segundo numero:  ";
	cin >> Sum.ComplexN2;


	Sum.RealSum = Sum.RealN1 + Sum.RealN2;
	Sum.ComplexSum = Sum.ComplexN1 + Sum.ComplexN2;

	cout << "El resultado es: " << Sum.RealSum << " + " << Sum.ComplexSum << " i " << endl;

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
