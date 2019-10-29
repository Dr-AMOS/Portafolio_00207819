// ACT8.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

struct Tpila {
	float Elems[100];
	int top;
};
typedef struct Tpila Pila;

void initialize(Pila* s) {
	s->top = -1;
}

void Push(Pila* s, float e) {
	if (s->top < 99) {
		(s->top)++;
		s->Elems[s->top] = e;
	}
}

void Pop(Pila* s, float* e) {
	if (s->top >= 0) {
		*e = s->Elems[s->top];
		(s->top)--;
	}
}

bool Empty(Pila* s) {
	return s->top < 0;
}

float UlObtain1(Pila* s) {
	if (Empty(s))
		return -1;
	//Pila vacia
	float a = 0, b = 0;
	Pop(s, &a);
	if (Empty(s))
		return -1;
	//Un solo elemento
	Pop(s, &b);
	Push(s, a);
	Push(s, b);
	return a;
}

float UlObtain2(Pila* s) {
	if (Empty(s))
		return -1;
	//Pila vacia
	float a = 0, b = 0;
	Pop(s, &a);
	if (Empty(s))
		return -1;
	//Un solo elemento
	Pop(s, &b);
	Pop(s, &b);
	Pop(s, &b);
	Pop(s, &b);
	Pop(s, &b);
	return a;
}

int main()
{
	Pila unaPila;
	initialize(&unaPila);

	float y = 0;
	Push(&unaPila, 1.5);
	Push(&unaPila, 3.5);
	Push(&unaPila, 7.5);
	Push(&unaPila, 13.5);
	Push(&unaPila, 19.5);
	Push(&unaPila, 25.5);

	float Ultimo = UlObtain2(&unaPila);
	cout << "El ultimo valor es: " << Ultimo << endl;

	if (Empty(&unaPila))
		cout << "La pila esta vacia" << endl;

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
