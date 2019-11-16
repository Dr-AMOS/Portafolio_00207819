// Lab4Act3.cpp : This file contains the 'main' function. Program execution begins and ends there.
// ACT3

#include <iostream>
#include <string>
using namespace std;

struct Book {
	char Title[35];
	int PageNum;
	Book* sig;
};
typedef struct Book Libro;

Book AddInfo() {
	Book p;
	cin.ignore();
	cout << "Titulo: "; cin >> p.Title;
	cout << "Numero de paginas: "; cin >> p.PageNum;
	return p;
}

void ShowBook(Book p) {
	cout << "Titulo: " << p.Title << endl;
	cout << "Numeros de paginas del libro: " << p.PageNum << endl;
	cout << endl;
}

struct TNode  {
	Book dato;
	struct TNode* sig;
};
typedef struct TNode Nodo;
Nodo* DStart;

void AddStart(Book p) {
	Nodo* nuevo = new Nodo;
	nuevo->dato = p;
	nuevo->sig = DStart;

	DStart = nuevo;
}

void AddLast(Book p) {
	Nodo* Newode = new Nodo;
	Newode->dato = p;
	Newode->sig = NULL;

	if (DStart == NULL) {
		DStart = Newode;
	}
	else {
		Nodo* p = DStart;
		Nodo* q = NULL;
		while (p != NULL) {
			q = p;
			p = p->sig;
		}
		q->sig = Newode;
	}
}

void AddBook() {
	Book p = AddInfo();
	bool continuar = true;
	do {
		int opcion = 0;
		cout << "\t1) Al principio\n\t2) Al final \n";
		cin >> opcion;
		switch (opcion) {
		case 1: AddStart(p);  continuar = false;
			break;
		case 2: AddLast(p);   continuar = false;
			break;
		default: cout << "Opcion erronea!" << endl;
			break;
		}
	} while (continuar);
}

void ShowList() {
	Nodo* s = DStart;

	while (s != NULL) {
		ShowBook(s->dato);
		s = s->sig;
	}
}

void SearchPage(Book* lista, string nombre) {
	if (lista == NULL) {
		cout << "No existe" << endl;
		return;
	}
	else if (nombre == lista->Title) {
		cout << "Numero de paginas de " << lista->Title << " es: " << lista->PageNum << endl;
		return;
	}
	else {
		return SearchPage(lista->sig, nombre);
	}
}
int main() {
	Book* List = NULL;
	Book* New = NULL;
	string Name;
	DStart = NULL;
	bool continuar = true;
	do {
		int opcion = 0;
		cout << "Menu: \n\t1) Agregar Libro\n\t2) Ver Libros"
			<< "\n\t3) Buscar Libro" "\n\t4) Salir \n";
		cin >> opcion;
		switch (opcion) {
		case 1: cout << "Agregando..." << endl;
			New = new Book;
			cin.clear(); cin.ignore(1000, '\n');
			cout << "Titulo: "; cin >> New->Title;
			cout << "Numero de paginas: "; cin >> New->PageNum;

			New->sig = NULL;

			if (List == NULL) {
				List = New;
			}
			else {
				New->sig = List;
				List = New;
			}
			break;
		case 2: cout << "Mostrando..." << endl;
			if (List == NULL) {
				cout << "No se encontro un libro con ese nombre" << endl;
			}
			ShowList();
			break;
		case 3: cout << "Buscando..." << endl;
			cin.clear(); cin.ignore(1000, '\n');
			cout << "Digite el titulo del libro para saber su numero de paginas: "; getline(cin, Name);
			SearchPage(List, Name);
			break;
		case 4: continuar = false;
			break;
		default: cout << "Dato incorrecto!" << endl;
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
