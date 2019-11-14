// ACT13.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;

enum Genre { Ciencia_Ficcion, Aventura, Suspenso, Romance, Drama };

struct TBook {
	int isbn;
	string Titulo;
	string Autor;
	Genre Genero;
	bool Espanol;
};
typedef struct TBook Book;

int hack = 0;

Book AskBook() {
	Book p;

	cout << "ISBN: "; cin >> p.isbn;
	cin.ignore();
	cout << "Titulo: "; getline(cin, p.Titulo);
	cout << "Autor: "; getline(cin, p.Autor);

	bool continuar = true;
	do {
		char opcion = 0;
		cout << "Genero (Ciencia_Ficcion, Aventura, Suspenso, Romance, Drama) ingrese solo la primera letra en minuscula: ";
		cin >> opcion;
		switch (opcion) {
		case 'c': p.Genero = Ciencia_Ficcion;   continuar = false;
			break;
		case 'a': p.Genero = Aventura;   continuar = false;
			break;
		case 's': p.Genero = Suspenso;   continuar = false;
			break;
		case 'r': p.Genero = Romance;   continuar = false;
			break;
		case 'd': p.Genero = Drama;   continuar = false; hack++;
			break;
		default: cout << "Ingrese una opcion valida" << endl;
			break;
		}
	} while (continuar);

	continuar = true;
	do {
		char letra = 0;
		cout << "Espanol (s/n): ";
		cin >> letra;
		switch (letra) {
		case 's':
		case 'S': p.Espanol = true;   continuar = false;
			break;
		case 'n':
		case 'N': p.Espanol = false;   continuar = false;
			break;
		default: cout << "Opcion erronea!" << endl;
			break;
		}
	} while (continuar);

	return p;
}

void ShowB(Book p) {
	cout << "ISBN: " << p.isbn << endl;
	cout << "Titulo: " << p.Titulo << endl;
	cout << "Autor: " << p.Autor << endl;

	cout << "Genero: ";
	switch (p.Genero) {
	case Ciencia_Ficcion: cout << "Ciencia ficcion" << endl;
		break;
	case Aventura: cout << "Aventura" << endl;
		break;
	case Suspenso: cout << "Policial" << endl;
		break;
	case Romance: cout << "Romance" << endl;
		break;
	case Drama: cout << "Drama" << endl;
		break;
	}

	cout << "Idioma: " << (p.Espanol ? "Espanol" : "Otro") << endl;
	cout << endl;
}

struct TNodo {
	Book dato;
	struct TNodo* sig;
};
typedef struct TNodo Nodo;
Nodo* pInicio;

void insertarInicio(Book p) {
	Nodo* nuevo = new Nodo;
	nuevo->dato = p;
	nuevo->sig = pInicio;

	pInicio = nuevo;
}

void insertarFinal(Book p) {
	Nodo* nuevo = new Nodo;
	nuevo->dato = p;
	nuevo->sig = NULL;

	if (pInicio == NULL) {
		pInicio = nuevo;
	}
	else {
		Nodo* p = pInicio;
		Nodo* q = NULL;
		while (p != NULL) {
			q = p;
			p = p->sig;
		}
		q->sig = nuevo;
	}
}

void insertarDespuesDe(Book p) {
	int InputISBN = 0;
	cout << "ISBN del libro: ";
	cin >> InputISBN;

	Nodo* s = pInicio;

	while (s != NULL && (s->dato).isbn != InputISBN)
		s = s->sig;
	if (s == NULL) {
		cout << "El libro no existe" << endl;
		return;
	}

	Nodo* nuevo = new Nodo;
	nuevo->dato = p;
	nuevo->sig = s->sig;

	s->sig = nuevo;
	cout << "El libro a sido agregado" << endl;
}

void insertarAntesDe(Book p) {
	int unISBN = 0;
	cout << "ISBN del libro: ";
	cin >> unISBN;

	Nodo* s = pInicio, * q = NULL;

	while (s != NULL && (s->dato).isbn != unISBN) {
		q = s;
		s = s->sig;
	}
	if (s == NULL) {
		cout << "El libro no existe " << endl;
		return;
	}

	Nodo* nuevo = new Nodo;
	nuevo->dato = p;
	nuevo->sig = s;

	if (q == NULL)
		pInicio = nuevo;
	else
		q->sig = nuevo;
	cout << "El libro ha sido agregado" << endl;
}

void agregarLibro() {
	Book p = AskBook();
	bool continuar = true;
	do {
		int opcion = 0;
		cout << "t1) Al principio\n\t2) Al final" << endl;
		cout << "t3) Despues de\n\t4) Antes de" << endl;
		cout << "tOpcion elegida: " << endl;
		cin >> opcion;
		switch (opcion) {
		case 1: insertarInicio(p);  continuar = false;
			break;
		case 2: insertarFinal(p);   continuar = false;
			break;
		case 3: insertarDespuesDe(p);   continuar = false;
			break;
		case 4: insertarAntesDe(p);   continuar = false;
			break;
		default: cout << "Ingrese una opcion valida" << endl;
			break;
		}
	} while (continuar);
}

void ShowL() {
	Nodo* s = pInicio;

	while (s != NULL) {
		ShowB(s->dato);
		s = s->sig;
	}
}

void mostrarListaEspanol() {
	Nodo* s = pInicio;

	while (s != NULL) {
		if (s->dato.Espanol == true) {
			ShowB(s->dato);
		}
		s = s->sig;
	}
}

void ShowL_CF() {
	Nodo* s = pInicio;

	while (s != NULL) {
		if (s->dato.Genero == Ciencia_Ficcion) {
			ShowB(s->dato);
		}
		s = s->sig;
	}
}

void DeleteB() {
	int unISBN = 0;
	cout << "Ingrese el ISBN del libro para que sea eliminado: ";
	cin >> unISBN;

	Nodo* p = pInicio, * q = NULL;

	while (p != NULL && (p->dato).isbn != unISBN) {
		q = p;
		p = p->sig;
	}
	if (p == NULL) {
		cout << "No existe" << endl;
		return;
	}
	if (q == NULL)
		pInicio = p->sig;
	else
		q->sig = p->sig;
	delete(p);
	cout << "El libro ha sido eliminado" << endl;
}

void DeleteBD() {


	Nodo* p = pInicio, * q = NULL;

	while (p != NULL && (p->dato).Genero != Drama) {
		q = p;
		p = p->sig;
	}
	if (p == NULL) {
		return;
	}
	if (q == NULL)
		pInicio = p->sig;
	else
		q->sig = p->sig;
	delete(p);
	cout << "El libro ha sido eliminado" << endl;
}

bool buscarLibro() {
	int unISBN = 0;
	cout << "Ingrese el ISBN de libro para la busqueda: ";
	cin >> unISBN;

	Nodo* s = pInicio;

	while (s != NULL && (s->dato).isbn != unISBN)
		s = s->sig;

	return (s != NULL);
}

int main() {
	pInicio = NULL;

	bool continuar = true;
	do {
		int opcion = 0;
		cout << "Menu: \n\t1) Agregar Libro\n\t2) Ver Libros"
			<< "\n\t3) Eliminar libro\n\t4) Buscar Libro"
			<< "\n\t5) Buscar libros en espanol\n\t6) Buscar libros de ciencia ficcion\n\t7) Eliminar todos los libros de misterio\n\t8) Salir\n\tOpcion elegida: ";
		cin >> opcion;
		switch (opcion) {
		case 1: cout << "Agregando..." << endl;
			agregarLibro();
			break;
		case 2: cout << "Listando..." << endl;
			ShowL();
			break;
		case 3: cout << "Eliminando..." << endl;
			DeleteB();
			break;
		case 4: cout << "Buscando..." << endl;
			if (buscarLibro())
				cout << "El libro SI se encuentra" << endl;
			else
				cout << "El libro NO se encuentra" << endl;

			break;
		case 5: cout << "Listando..." << endl;
			mostrarListaEspanol();
			break;
		case 6: cout << "Listando..." << endl;
			ShowL_CF();
			break;
		case 7: cout << "Eliminando..." << endl;
			for (int i = 0; i < hack; i++) {
				DeleteBD();
			}
			break;
		case 8: continuar = false;
			break;
		default: cout << "Ingrese una opcion valida" << endl;
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
