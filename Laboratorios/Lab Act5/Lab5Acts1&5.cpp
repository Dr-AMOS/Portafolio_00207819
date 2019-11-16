// Lab5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

struct NodeList {
	int Value;
	NodeList* sig;
};
struct Node {
	int dato;
	Node* hI;
	Node* hD;
};


typedef struct Node Node; //I know, pointless, but whatever
typedef struct Node* Tree;

Node* Ptree = NULL;
NodeList* Pstart = NULL;


void AddLeft(Tree, int);
void AddRight(Tree, int);
void AddNode(Tree);
void Search(int, Tree);
Tree CreateTree(int);
void In_Order(Node*);
void Fin_Order(int);
void DenominatedList(void);
void EX1(void);
void EX5(void);
void RunList(void);
void rbol2(Node**, int);

int main() {
	int chose;
	while (true) {
		cout << "Que ejercicio deseas correr: " << endl << "1) EX1 \n5) EX5" << endl;
		cin >> chose;
		switch (chose) {
		case 1:
			EX1();
			break;
		case 5:
			EX5();
			break;
		default:  cout << "Opcion no valida" << endl;
			break;
		}
	}
	return 0;
}

void AddLeft(Tree a, int dato) {
	if (a == NULL)
		cout << "Arbol vacio" << endl;
	else if (a->hI != NULL)
		cout << "Sub-Arbol existe" << endl;
	else
		a->hI = CreateTree(dato);
}
void AddRight(Tree a, int dato) {
	if (a == NULL)
		cout << "Arbol vacio" << endl;
	else if (a->hD != NULL)
		cout << "Sub-Arbol existe" << endl;
	else
		a->hD = CreateTree(dato);
}
void AddNode(Tree a) {
	int num = 0;
	cout << "Agregar numero" << endl;
	cin >> num;

	Tree p = a;

	while (true) {
		if (num == p->dato) {
			cout << "Error: " << num << "Existente" << endl;
			return;
		}
		else if (num < p->dato) {
			if (p->hI == NULL) {
				break;
			}
			else {
				p = p->hI;
			}
		}
		else {
			if (p->hD == NULL)
				break;
			else
				p = p->hD;
		}
	}
	if (num < p->dato)
		AddLeft(p, num);
	else
		AddRight(p, num);
}
void Search(int datoA, Tree a) {
	if (!a)
		cout << "No existe" << endl;
	else {
		Fin_Order(a->dato);
		if (a->dato == datoA)
			cout << "Si existe" << endl;
		else if (datoA < a->dato)
			Search(datoA, a->hI);
		else
			Search(datoA, a->hD);
	}
}
void Fin_Order(int dato) {
	NodeList* p, * q;
	NodeList* nuevo = new NodeList;
	nuevo->Value = dato;
	nuevo->sig = NULL;
	if (Pstart == NULL) {
		Pstart = nuevo;
	}
	else {
		p = Pstart;
		q = NULL;
		while (p != NULL) {
			q = p;
			p = p->sig;
		}
		q->sig = nuevo;
	}
}
void DenominatedList(void) {
	NodeList* s = Pstart;
	while (s != NULL) {
		cout << s->Value << " ";
		s = s->sig;
	}
}
void EX1(void) {
	int var = 0;
	cout << "Valor Raiz: " << endl;
	cin >> var;
	int datoB;

	Tree Arbol = CreateTree(var);
	bool cont = true;
	do {
		int op = 0;
		cout << "Menu: \n1) Agregar \n2)Buscar nodo\n3) Salir" << endl;
		cout << "Opcion elegida: ";
		cin >> op;
		switch (op) {
		case 1:
			AddNode(Arbol);
			break;
		case 2:
			cout << "Num que quiere encontrar: " << endl;
			cin >> datoB;
			Search(datoB, Arbol);
			DenominatedList();
			cout << endl;
			break;
		case 3:
			cont = false;
			break;
		default:
			cout << "Opcion erronea" << endl;
			break;
		}
	} while (cont);
}
void EX5(void) {
	char ans;
	int dato;
	cout << "Desea insertar un dato s/n? ";
	cin >> ans;
	while (ans == 's') {
		cout << "Digite el dato";
		cin >> dato;
		Fin_Order(dato);
		cout << "Desea meter otro dato? s/n ";
		cin >> ans;
	}
	RunList();
	DenominatedList();
	cout << endl;
	In_Order(Ptree);

}
void RunList(void) {
	NodeList* s = Pstart;
	while (s != NULL) {
		rbol2(&Ptree, s->Value);
		s = s->sig;
	}
}
void rbol2(Node** p, int dato) {
	if (!(*p)) {
		*p = new Node;
		(*p)->dato = dato;
		(*p)->hI = (*p)->hD = NULL;
	}
	else
		if (dato < (*p)->dato) {
			rbol2(&((*p)->hI), dato);
		}
		else
			if (dato > (*p)->dato) {
				rbol2(&((*p)->hD), dato);
			}
			else
				cout << "El nodo ya existe\n";
}
Tree CreateTree(int x) {
	Tree p = new Node;
	p->dato = x;
	p->hI = NULL;
	p->hD = NULL;

	return p;
}
void In_Order(Node* a) {
	if (a != NULL) {
		In_Order(a->hI);
		cout << " " << a->dato;
		In_Order(a->hD);
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
