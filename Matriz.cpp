#include <iostream>
using namespace std;

void fun(int *p){
	cout << "Funcion" << endl;
	cout << p << endl;
	cout << *p << endl;
	cout << *(p+1*3+1) << endl;
}

int main(){
	int valor = 100;
    int *puntero= &valor;
    int **doble = &puntero;

    cout << "Valor: " << valor << endl;
    cout << "Puntero: " << *puntero << endl;
    cout << "Doble: " << **doble << endl;
    
    cout << "Desreferenciando" << endl;
    int *pnuevo = *doble;
    int voriginal = *pnuevo;
    cout << voriginal << endl;
	
	int m[2][3] = {{6,7,3},{4,9,1}};

	cout << "*(*m+i*3+j)" << endl;
	cout << **m << endl;
	cout << *(*m+1) << endl;
	cout << *(*m+2) << endl;
	cout << *(*m+3) << endl;
	cout << *(*m+1*3+1) << endl;
	cout << *(*m+1*3+2) << endl;
	
	cout << "*(*(m+i)+j)" << endl;
	cout << *(*(m+0)+0) << endl;
	cout << *(*(m+0)+1) << endl;
	cout << *(*(m+0)+2) << endl;
	cout << *(*(m+1)+0) << endl;
	cout << *(*(m+1)+1) << endl;
	cout << *(*(m+1)+2) << endl;
	
	fun(*m);
}
