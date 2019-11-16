// Lab4Act7.cpp : This file contains the 'main' function. Program execution begins and ends there.
// ACT7

#include <iostream>

using namespace std;



struct Node {
	int Value;
	Node* sig;
};

Node* StartL = NULL;
int Counter = 0, PairCounter = 0, UnpairCounter = 0;

void FillList(int cant) {
	Node* Next, * s;
	int Num;

	cout << "Ingresa tus datos:" << endl;
	if (StartL == NULL) {
		Next = new Node;
		StartL = Next;
		cin >> Num;
		Next->Value = Num;
		Next->sig = NULL;
	}
	s = StartL;

	for (int i = 0; i < (cant - 1); i++) {
		Next = new Node;
		s->sig = Next;
		Next->sig = NULL;
		cin >> Num;
		Next->Value = Num;
		s = Next;
	}

	s = StartL;

	cout << "Lista:" << endl;
	while (s != NULL) {
		cout << s->Value << " ";
		s = s->sig;
	}
	cout << endl;
}

void Sum(Node* s) {
	if (s != NULL) {
		if (s->Value % 2 == 0)
			PairCounter = PairCounter + s->Value;
		else
			UnpairCounter = UnpairCounter + s->Value;
		Sum(s->sig);
	}
}

int main() {

	int cant;

	cout << "Cuantos numeros quieres ingresar?" << endl;
	cin >> cant;

	FillList(cant);
	Sum(StartL);

	cout << "Sumatoria de pares: " << PairCounter << endl;
	cout << "Sumatoria de impares: " << UnpairCounter << endl;

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
