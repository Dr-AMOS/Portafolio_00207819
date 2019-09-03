#include <iostream>
using namespace std;
int Product(int, int);


int main()
{
 int Num1,Num2, Tot;

 cout << "Introduce un número: ";
 cin >> Num1;
 cout << "Introduzca segundo número: ";
 cin >> Num2;
 Tot=Product(Num1,Num2);
 cout << "El Producto es: " << Tot << endl;
 
 return 0;

}

int Product(int A, int B)
{
 if(A==0 or B==0)
   return 0;
  else
   {
    return A + Product(A, B -1);
   }

}