#include <iostream>
using namespace std;

int Search(int, int*, int);
int Cont=0;
void FArr(int *, int);
void SArr(int*, int);
void IArr(int*, int*);

int main() {
	int num, Z;
	cout << "Cuantos numeros deseas ingresar? ";
	cin >> num;
	int  Arr[num];
	FArr(Arr, num - 1);
	cout << endl;
	SArr(Arr, num - 1);
	cout << endl;
	IArr(Arr, &Arr[num - 1]);
	cout << endl;
	SArr(Arr, num - 1);
	cout<<endl;
	cout<<endl;
	cout<<endl;
	cout<<"Que valor deseas encontrar? ";
	cin>>Z;
	cout<<"El valor que has escogido se repite "<< Search(Z, Arr, num - 1)<<" veces";

	}

int Search(int Z, int *p, int num){
    
        if (num >= 0) {
		if(Z==*p){
		    
		    Cont++;
		    
		}
		Search(Z, p + 1, num - 1);
		
	}
	return Cont;
}

void FArr(int* p, int num) {
	if (num >= 0) {
		cin >> *p;
		FArr(p + 1, num - 1);
	}
}

void SArr(int* p, int num) {
	if (num >= 0) {
		cout << *p << " ";
		SArr(p + 1, num - 1);
	}
}
void IArr(int* p, int* r) {
	int T;
	if (p < r) {
		T = *p;
		*p = *r;
		*r = T;
		IArr(p + 1, r - 1);
	}
}