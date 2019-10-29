// ACT2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
int main()
{
	int N = 0, i = 0;
	float Num[100], SUM = 0.0, MED, MEDI;
	cout << "¿Cuantos numeros deseas ocupar? " << endl;
	cin >> N;
	while (N > 100 || N <= -100)
	{
		cout << "Solo puede ingresar hasta 100 numeros" << endl;
		cout << "Ingrese un numero diferente: ";
	}
	for (i = 0; i < N; ++i)

	{
		cout << " Ingrese el numero " << i + 1 << " : ";
		cin >> Num[i];
	}
	if (N % 2 == 0) {
		MEDI = Num[N / 2 - 1] + Num[N / 2];
		MED = MEDI / 2;
	}
	else {
		MED = Num[N / 2];
	}

	cout << "La mediana es: " << MED;
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
