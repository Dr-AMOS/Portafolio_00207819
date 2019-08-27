#include <iostream>
using namespace std;

struct cicloLectivo{
	int correlativo;
	int anio;
};

int main()
{
	struct cicloLectivo actual;
	actual.correlativo = 2;
	actual.anio = 2019;
		
	struct cicloLectivo *p = &actual;
	
	cout << "Modificando correlativo\n";
	actual.correlativo = 3;
	cout << "Modificando anio\n";
	(*p).anio = 2020;
	
	cout << actual.correlativo << "/" <<
		actual.anio << endl;
	cout << (*p).correlativo << "/" <<
		(*p).anio << endl;
}