// Lab3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//ACT1

#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;

struct Node {
	int Value;
	Node* sig;
};

void ShowListP(void);
void ShowListI(void);
void ShowListInverted(Node*);
void FillList(int);
void ShowList(void);

Node* Start = NULL;

int main(void) {
	int n;

	cout << "Que tantos numeros desea guardar? ";
	cin >> n;
	FillList(n);
	cout << "Lista:" << endl;
	ShowList();
	cout << "Lista solo pares:" << endl;
	ShowListP();
	cout << "Lista solo impares:" << endl;
	ShowListI();
	cout << "Mostrando lista en sentido inverso:" << endl;
	ShowListInverted(Start);
	cout << endl;

	return 0;
}

void FillList(int n) {
	srand(time(NULL));
	Node* New, * s;

	if (Start == NULL) {
		New = new Node;
		Start = New;
		Start->Value = rand() % 100 + 1;
		Start->sig = NULL;
	}

	s = Start;

	for (int i = 0; i < n - 1; i++)
	{
		New = new Node;
		s->sig = New;
		s = New;
		s->sig = NULL;
		s->Value = rand() % 100 + 1;
	}
}

void ShowList(void) {
	Node* s = Start;

	while (s != NULL)
	{
		cout << s->Value << " ";
		s = s->sig;
	}
	cout << endl;
}

void ShowListP(void) {
	Node* s = Start;

	while (s != NULL)
	{
		if (s->Value % 2 == 0)
			cout << s->Value << " ";
		s = s->sig;
	}
	cout << endl;
}

void ShowListI(void) {
	Node* s = Start;

	while (s != NULL)
	{
		if (s->Value % 2 != 0)
			cout << s->Value << " ";
		s = s->sig;
	}
	cout << endl;
}

void ShowListInverted(Node* s) {
	if (s != NULL) {
		ShowListInverted(s->sig);
		cout << s->Value << " ";
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
