// ACT6.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

//Busqueda Binaria

#include <iostream>
using namespace std;

int find(int* a, int s, int f, int q)
{
	int MID = (s + f) / 2;
	if (s > f) return -1;
	if (a[MID] == q) return MID;
	if (a[MID] > q) return find(a, s, MID - 1, q);
	if (a[MID] < q) return find(a, MID + 1, f, q);
}

int main()
{
	int a[8] = { 2,7,9, 10, 17, 18, 33, 42 };
	int Input;
	cout << "Que numero esta buscando? ";
	cin >> Input;
	cout << "Posicion en arreglo (si equivale a -1 el caracter no se encontro): " << find(a, 0, 7, Input);
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
