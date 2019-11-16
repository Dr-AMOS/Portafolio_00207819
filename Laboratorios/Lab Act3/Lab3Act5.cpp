// Lab3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//ACT5

#include <iostream>
#include <time.h>

using namespace std;

struct Node {
	int Value;
	Node* sig;
};

void FillList(int);
void ShowList(void);
void InvertList(Node*, Node*);

Node* LStart = NULL, * p = NULL;

int main(void) {
	int Input;

	cout << "Cuantos numeros deseas ingresar? ";
	cin >> Input;
	FillList(Input);

	cout << "Lista:" << endl;
	ShowList();

	cout << "Lista invertida: " << endl;
	InvertList(LStart, NULL);

	ShowList();

	return 0;
}

void FillList(int n) {
	srand(time(NULL));
	Node* Newode, * s;

	if (LStart == NULL) {
		Newode = new Node;
		LStart = Newode;
		LStart->Value = rand() % 100 + 1;
		LStart->sig = NULL;
	}

	s = LStart;

	for (int i = 0; i < n - 1; i++)
	{
		Newode = new Node;
		s->sig = Newode;
		s = Newode;
		s->sig = NULL;
		s->Value = rand() % 100 + 1;
	}
}

void ShowList(void) {
	Node* s = LStart;

	while (s != NULL)
	{
		cout << s->Value << " ";
		s = s->sig;
	}
	cout << endl;
}

void InvertList(Node* s, Node* p) {

	if (s != NULL) {
		InvertList(s->sig, s);
		s->sig = p;
	}
	else
	{
		LStart = p;
	}
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
