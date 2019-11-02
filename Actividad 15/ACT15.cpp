// ACT15.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

struct nodo {
	int INFO;
	struct nodo* LFT;
	struct nodo* RHT;
};
typedef struct nodo NODE;
typedef struct nodo* Tree;

void AssignR(Tree a, int unDato) {
	if (a == NULL)
		cout << "El Arbol esta vacio" << endl;
	else if (a->RHT != NULL)
		cout << "Ya existe un sub Arbol derecho" << endl;
	else
		a->RHT = CreateTree(unDato);
}

void AssignL(Tree a, int unDato) {
	if (a == NULL)
		cout << "El Arbol esta vacio" << endl;
	else if (a->LFT != NULL)
		cout << "Ya existe un sub Arbol izquierdo" << endl;
	else
		a->LFT = CreateTree(unDato);
}

Tree CreateTree(int x) {
	Tree p = new NODE;
	p->INFO = x;
	p->LFT = NULL;
	p->RHT = NULL;
	return p;
}


int HGT(nodo* Rama) {
	if (Rama == NULL)
		return -1;
	int HeightL = HGT(Rama->LFT);
	int HeightR = HGT(Rama->RHT);

	int Max = (HeightL > HeightR) ? HeightL : HeightR;
	return(Max + 1);
}

void AddNode(Tree a) {
	int Num = 0;
	cout << "Que numero desea agregar?";
	cin >> Num;

	Tree p = a;

	while (true) {
		if (Num == p->INFO) {
			cout <<  Num << " ya existe." << endl;
			return;
		}
		else if (Num < p->INFO) {
			if (p->LFT == NULL)
				break;
			else
				p = p->LFT;
		}
		else {
			if (p->RHT == NULL)
				break;
			else
				p = p->RHT;
		}
	}

	if (Num < p->INFO)
		AssignL(p, Num);
	else
		AssignR(p, Num);
}


void OGNZ(Tree a) {
	if (a != NULL) {
		cout << " " << a->INFO;
		OGNZ(a->LFT);
		OGNZ(a->RHT);
	}
}
void DOGNZ(Tree a) {
	if (a != NULL) {
		DOGNZ(a->LFT);
		cout << " " << a->INFO;
		DOGNZ(a->RHT);
	}
}
void ORGANIZED(Tree a) {
	if (a != NULL) {
		ORGANIZED(a->LFT);
		ORGANIZED(a->RHT);
		cout << " " << a->INFO;
	}
}

void RunTree(Tree a) {
	cout << "PRE ordenado:"; OGNZ(a); cout << endl;
	cout << "IN ordenado:"; DOGNZ(a); cout << endl;
	cout << "POST ordenado:"; ORGANIZED(a); cout << endl;
}

int main() {
	int variable = 0;
	cout << "Valor raiz: ";
	cin >> variable;

	Tree Tree = CreateTree(variable);

	bool continuar = true;
	do {
		int opcion = 0;
		cout << "Menu: \n\t1) Agregar\n\t2) Recorrer"
			<< "\n\t3)Mostrar altura \n\t4)Salir\n\tOpcion elegida: ";
		cin >> opcion;
		switch (opcion) {
		case 1: AddNode(Tree);
			break;
		case 2: RunTree(Tree);
			break;
		case 3: cout << "La altura es: " << HGT(Tree) << endl;
			break;
		case 4: continuar = false;
			break;
		default: cout << "Opcion erronea!" << endl;
			break;
		}
	} while (continuar);

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
